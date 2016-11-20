#pragma once

#include "Structure.h"
#include "SerialComs.hpp"
#include "Utilities.hpp"

#include <Communication.h>
#include <Maxim.h>
#include <SerialHD.hpp>

class GameConnection {
    unsigned long deadtime, deadtimeOld, controlTime, controlTimeOld;
    unsigned long now;

    boolean connected = false;
    VesselData vesselData;
    SerialComs comm;

    Maxim* m;
    SerialHD* lcd;

    int input() {
        int returnValue = -1;
        now = millis();

        auto result = comm.KSPBoardReceiveData();
        if (result.status) {
            deadtimeOld = now;

            switch(result.typeOfPacket) {
            case SerialComs::ReadResult::TypeOfPacket::HandShakePacket:
                lcd->clear();
                lcd->print("Handshake");
                handshake(result.handShakePacket);
                break;
            case SerialComs::ReadResult::TypeOfPacket::VesselData:
                lcd->clear();
                lcd->print("Data");
                // Copy it over the previous state
                vesselData = result.vesselData;
                //Indicators(vesselData);

                int32_t ap = vesselData.AP * 10;
                int32_t pe = vesselData.PE * 10;
                m->writeNumber(ap, 0);
                m->writeNumber(pe, 1);

                lcd->clear();
                lcd->print("SAS: " + String(vesselData.getControlStatus(AGSAS) ? "0" : "1"));
                lcd->setCursor(0, 1);
                lcd->print("Stage " + String(vesselData.CurrentStage) + "/" + String(vesselData.TotalStage));

                break;
            }

            //We got some data, turn the green led on
            //digitalWrite(GLED,HIGH);
            connected = true;
        }
        else { //if no message received for a while, go idle
            deadtime = now - deadtimeOld;
            if (deadtime > IDLETIMER) {
                deadtimeOld = now;
                connected = false;
                //LEDSAllOff();
            }
        }

        return returnValue;
    }

    void handshake(HandShakePacket handShakePacket){
        //digitalWrite(GLED,HIGH);

        handShakePacket.id = 0;
        handShakePacket.M1 = 3;
        handShakePacket.M2 = 1;
        handShakePacket.M3 = 4;

        comm.KSPBoardSendData(reinterpret_cast<uint8_t*>(&handShakePacket), sizeof(handShakePacket));
    }


    void output() {
        now = millis();
        controlTime = now - controlTimeOld;
        if (controlTime > CONTROLREFRESH){
            controlTimeOld = now;

            if (connected) {
            //    controls();
            }
        }
    }

    void controls() {
        ControlPacket controlPacket;

        if (digitalRead(SASPIN))  //--------- This is how you do main controls
            controlPacket.setMainControl(ControlElement::SAS, true);
        else
            controlPacket.setMainControl(ControlElement::SAS, false);

        if (digitalRead(RCSPIN))
            controlPacket.setMainControl(ControlElement::RCS, true);
        else
            controlPacket.setMainControl(ControlElement::RCS, false);

        /*if (digitalRead(CG1PIN))   //--------- This is how you do control groups
            controlPacket.setControlGroup(1, true);
        else
            controlPacket.setControlGroup(1, false);*/

        //This is an example of reading analog inputs to an axis, with deadband and limits
        controlPacket.Throttle = constrain(map(analogRead(THROTTLEPIN),THROTTLEDB,1024-THROTTLEDB,0,1000),0, 1000);

        comm.KSPBoardSendData(reinterpret_cast<uint8_t*>(&controlPacket), sizeof(controlPacket));
    }

    void controlsInit() {
        //pinMode(SASPIN, INPUT_PULLUP);
        //pinMode(RCSPIN, INPUT_PULLUP);
       // pinMode(CG1PIN, INPUT_PULLUP);
    }

public:
    void setup() {
        Serial.begin(38400);

        //initLEDS();
        controlsInit();

        //LEDSAllOff();

        m = new Maxim(make_sender(comm::HardwareSpi(), comm::MultiplexLatcher<4, comm::MultiplexLatcherPins<2,3,4>::pins, 5>()));

        lcd = new SerialHD(make_sender(comm::HardwareSpi(), comm::MultiplexLatcher<6, comm::MultiplexLatcherPins<2,3,4>::pins, 5>()));
        lcd->begin(16, 2);
        lcd->clear();
        lcd->print("Setup finished");
    }

    void update()
    {
        input();
        output();
    }

    inline VesselData const& getVesselData() { return vesselData; }
};
