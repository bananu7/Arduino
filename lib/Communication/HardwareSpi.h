#pragma once

class HardwareSpi {
public:
    static void start();
    static void transmit(byte b);
    static void end();
};
