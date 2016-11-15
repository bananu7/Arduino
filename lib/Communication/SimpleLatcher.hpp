#pragma once

namespace comm {

/*
This is a simple latcher class that toggles the pin on and off.
*/

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

}