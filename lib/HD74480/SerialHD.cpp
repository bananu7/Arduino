#include "SerialHD.hpp"

SerialHD::SerialHD(Sender sender)
    : sender(sender)
{
}

void SerialHD::write4bits(uint8_t value) {
    for (int i = 4; i < 8; i++)
    {
        //we put the four bits in the _bit_string
        bitWrite(_bitString, i, ((value >> (i - 4)) & 0x01)); 
    }
    //and send it out
    spiSendOut();
    pulseEnable();
}

void SerialHD::pulseEnable() {
    bitWrite(_bitString, _enable_pin, LOW); 
    spiSendOut();
    delayMicroseconds(1); 
    bitWrite(_bitString, _enable_pin, HIGH); 
    spiSendOut();
    delayMicroseconds(1);    // enable pulse must be >450ns
    bitWrite(_bitString, _enable_pin, LOW); 
    spiSendOut();
    delayMicroseconds(40);   // commands need > 37us to settle
}

void SerialHD::spiSendOut() {
    serial.send(_bitString);
}

void SerialHD::send(uint8_t value, uint8_t mode) {
    bitWrite(_bitString, _rs_pin, mode); //set RS to mode
    spiSendOut();
    
    //we are not using RW with SPI so we are not even bothering
    //or 8BITMODE so we go straight to write4bits
    write4bits(value>>4);
    write4bits(value);    
}