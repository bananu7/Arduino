#pragma once
#include "HD44780.h"

#include "../Communication/Sender.hpp"

class SerialHD : public HD44780 {
public:
    SerialHD(Sender sender);
    void spiSendOut();

    void initSPI(uint8_t _ssPin);

private:
    Sender sender;

    uint8_t _bitString; //for SPI  bit0=not used, bit1=RS, bit2=RW, bit3=Enable, bits4-7 = DB4-7

    void write4bits(uint8_t) override;
    void pulseEnable() override;
    void spiSendOut();
};