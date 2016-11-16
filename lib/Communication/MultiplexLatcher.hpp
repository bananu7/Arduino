#pragma once

namespace comm {

namespace detail {
    struct MultiplexLatcherPins {
        const int p0;
        const int p1;
        const int p2;
    };    
}

template<int P0, int P1, int P2>
struct MultiplexLatcherPins {
    static constexpr detail::MultiplexLatcherPins pins = { P0, P1, P2 };
};

template<int deviceNumber, detail::MultiplexLatcherPins const& pins, int offPin>
class MultiplexLatcher {
    static_assert(deviceNumber >= 0, "The device number must be a non-negative number in range 0-6.");
    static_assert(deviceNumber < 7, "This latcher supports up to 7 devices, ranging 0-6.");

    void selectDevice(int device) {
        digitalWrite(offPin, LOW);
        digitalWrite(pins.p0, device & (1 << 0));
        digitalWrite(pins.p1, device & (1 << 1));
        digitalWrite(pins.p2, device & (1 << 2));
        digitalWrite(offPin, HIGH);
    }

public:
    MultiplexLatcher() {
        pinMode(pins.p0, OUTPUT);
        pinMode(pins.p1, OUTPUT);
        pinMode(pins.p2, OUTPUT);
        pinMode(offPin, OUTPUT);
        digitalWrite(offPin, LOW);
    }

    void on() {
        selectDevice(deviceNumber);
    }

    void off() {
        selectDevice(7);
    }
};

}
