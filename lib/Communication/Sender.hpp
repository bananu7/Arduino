#pragma once
#include <Arduino.h>

namespace comm {

template<class Transport, class Latcher>
class Sender {
    Transport transport;
    Latcher latcher;

public:
    Sender(Transport transport, Latcher latcher)
        : transport(transport)
        , latcher(latcher)
    {
    }

    inline void send(byte b) {
        latcher.on();
        transport.beginTransmission();
        transport.transmit(b);
        transport.endTransmission();
        latcher.off();
    }

    inline void send(byte a, byte b) {
        latcher.on();
        transport.beginTransmission();
        transport.transmit(a);
        transport.transmit(b);
        transport.endTransmission();
        latcher.off();
    }

    inline void send(byte a, byte b, byte c, byte d) {
        latcher.on();
        transport.beginTransmission();
        transport.transmit(a);
        transport.transmit(b);
        transport.transmit(c);
        transport.transmit(d);
        transport.endTransmission();
        latcher.off();
    }

    /*template<int n>
    inline void send(byte bytes[n]) {
        latcher.on();
        transport.beginTransmission();
        for (int i = 0; i < n; ++i) {
            transport.transmit(bytes[i]);
        }
        transport.endTransmission();
        latcher.off();
    }*/
};

template<class Transport, class Latcher>
inline Sender<Transport, Latcher> make_sender(Transport transport, Latcher latcher) {
    return { transport, latcher };
}

}
