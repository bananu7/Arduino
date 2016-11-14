#pragma once

template<int P0, int P1, int P2>
struct MultiplexLatcherPins {
    static constexpr auto p1 = P1;
    static constexpr auto p2 = P2;
    static constexpr auto p3 = P3;
};

template<int deviceNumber, MultiplexLatcherPins pins>
class MultiplexLatcher {
    static_assert(deviceNumber >= 0, "The device number must be a non-negative number in range 0-6.");
    static_assert(deviceNumber < 7, "This latcher supports up to 7 devices, ranging 0-6.");

    void selectDevice(int device) {
        digitalWrite(pins::p1, n & (1 << 0));
        digitalWrite(pins::p2, n & (1 << 1));
        digitalWrite(pins::p3, n & (1 << 2));
    }

public:
    void on() {
        selectDevice(deviceNumber);
    }
    void off() {
        selectDevice(7);
    }
};
