#pragma once
#include "HardwareSpi.h"

template<int latchPin>
class LedPanel {
    byte state = 0;
    OutDevice<HardwareSpi, latchPin> device;

    void setLed(const int n, const bool on) {
        if (on) {
            state |= 1 << n;
        } else {
            state &= ~(1 << n);
        }
    }
public:
    void data(bool b1, bool b2, bool b3, bool b4, bool s1, bool s2) {
        setLed(1, b1);
        setLed(2, b2);
        setLed(6, b3);
        setLed(7, b4);

        setLed(4, s1);
        setLed(5, !s1);

        setLed(0, s2);
        setLed(3, !s2);
    }

    void present() {
        device.transmit(state);
    }
};
