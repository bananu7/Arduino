#pragma once
#include <Arduino.h>

namespace comm {

class SenderI {
public:
    virtual void send(byte b) = 0;
    virtual void send(byte a, byte b) = 0;
    virtual void send(byte a, byte b, byte c, byte d) = 0;
    virtual ~SenderI() = default;
};

template<class Transport, class Latcher>
class TemplateSender : public SenderI {
    Transport transport;
    Latcher latcher;

public:
    TemplateSender(Transport transport, Latcher latcher)
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

class Sender {
    SenderI* impl;
public:
    Sender(SenderI* impl) : impl(impl) { }
    //~Sender() { delete impl; }

    inline void send(byte b) { impl->send(b); }
    inline void send(byte a, byte b) { impl->send(a, b); }
    inline void send(byte a, byte b, byte c, byte d) { impl->send(a,b,c,d); }
};

template<class Transport, class Latcher>
inline Sender make_sender(Transport transport, Latcher latcher) {
    return Sender(new TemplateSender<Transport, Latcher> { transport, latcher });
}

}
