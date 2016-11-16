#pragma once
#include <SPI.h>

namespace comm {

class HardwareSpi {
public:
    void beginTransmission();
    void endTransmission();
    void transmit(byte b);
};

}
