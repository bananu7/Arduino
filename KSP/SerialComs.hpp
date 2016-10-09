#pragma once
#include "Structure.h"

class SerialComs {
public:
    struct ReadResult {
        bool status;

        enum class TypeOfPacket {
            HandShakePacket,
            VesselData
        } typeOfPacket;

        union {
            HandShakePacket handShakePacket;
            VesselData vesselData;
        };

        ReadResult()
            : status(false)
        {
        }
    };

private:
    uint8_t rx_len;
    uint16_t * address;
    byte buffer[256]; //address for temporary storage and parsing buffer
    uint8_t structSize;
    uint8_t rx_array_inx;  //index for RX parsing buffer
    uint8_t calc_CS;       //calculated Chacksum
    int id;

public:
    //This shit contains stuff borrowed from EasyTransfer lib
    inline ReadResult KSPBoardReceiveData() {
        ReadResult result;

        if ((rx_len == 0)&&(Serial.available()>3)){
          while(Serial.read()!= 0xBE) {
            if (Serial.available() == 0)
              return result;  
          }
          if (Serial.read() == 0xEF){
            rx_len = Serial.read();   
            id = Serial.read(); 
            rx_array_inx = 1;

            switch(id) {
            case 0:
              structSize = sizeof(HandShakePacket);
              address = reinterpret_cast<uint16_t*>(&result.handShakePacket);
              break;
            case 1:
              structSize = sizeof(VesselData);   
              address = reinterpret_cast<uint16_t*>(&result.vesselData);
              break;
            }
          }

          //make sure the binary structs on both Arduinos are the same size.
          if(rx_len != structSize){
            rx_len = 0;
            return result;
          }   
        }

        if(rx_len != 0){
          while(Serial.available() && rx_array_inx <= rx_len){
            buffer[rx_array_inx++] = Serial.read();
          }
          buffer[0] = id;

          if(rx_len == (rx_array_inx-1)){
            //seem to have got whole message
            //last uint8_t is CS
            calc_CS = rx_len;
            for (int i = 0; i<rx_len; i++){
              calc_CS^=buffer[i];
            } 

            if(calc_CS == buffer[rx_array_inx-1]){//CS good
              memcpy(address,buffer,structSize);
              rx_len = 0;
              rx_array_inx = 1;

              // Success
              result.status = true;
              return result;
            }
            else{
              //failed checksum, need to clear this out anyway
              rx_len = 0;
              rx_array_inx = 1;
              return result;
            }
          }
        }

        return result;
    }

    inline void KSPBoardSendData(uint8_t * address, uint8_t len){
        uint8_t CS = len;
        Serial.write(0xBE);
        Serial.write(0xEF);
        Serial.write(len);

        for(int i = 0; i<len; i++){
            CS^=*(address+i);
            Serial.write(*(address+i));
        }

        Serial.write(CS);
    }

};
