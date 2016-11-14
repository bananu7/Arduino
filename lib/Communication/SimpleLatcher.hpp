#pragma once

template<int pin>
class SimpleLatcher {
public:
    SimpleLatcher() {
        pinMode(pin, OUTPUT);
    }

    void on() const {
        digitalWrite(pin, LOW);
    }

    void off() const {
        digitalWrite(pin, HIGH);
    }
};
