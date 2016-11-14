#pragma once

class HardwareSpi {
public:
    void beginTransmission();
    void transmit(byte b);
    void endTransmission();
};
