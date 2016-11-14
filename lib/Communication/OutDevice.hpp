#pragma once

template<class Transport, int pin>
class Sender {
public:
    Sender() {
        pinMode(pin, OUTPUT);
    }

    inline void send(byte b) {
        digitalWrite(pin, LOW);

        Transport::start();
        Transport::transmit(b);
        Transport::end();

        digitalWrite(pin, HIGH);
    }
};
