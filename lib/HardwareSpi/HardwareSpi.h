#pragma once

class HardwareSpi {
public:
    static void start();
    static void transmit(byte b);
    static void end();
};

template<class Transport, int pin>
class OutDevice {
public:
    OutDevice() {
        pinMode(pin, OUTPUT);
    }

    void transmit(byte b) {
        digitalWrite(pin, LOW);

        Transport::start();
        Transport::transmit(b);
        Transport::end();

        digitalWrite(pin, HIGH);
    }
};
