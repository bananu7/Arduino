#pragma once

template<class Transport, class Latcher>
class Sender {
    Transport const& transport;
    Latcher const& latcher;

public:
    Sender(Transport const& transport, Latcher const& latcher)
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

    template<int n>
    inline void send(byte bytes[n]) {
        latcher.on();
        transport.beginTransmission();
        for (int i = 0; i < n; ++i) {
            transport.transmit(bytes[i]);
        }
        transport.endTransmission();
        latcher.off();
    }
};
