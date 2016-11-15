#pragma once

/*
This is a library that supports the Maxim 7219 chip which can control
7-segment displays or LED matrices. The library also supports daisy-chaining several units
together.
*/

#include <inttypes.h>
#include "../Communication/Sender.hpp"

namespace maxim {

enum class Command : byte {
    Shutdown = 0x0c,
    Decode = 0x09,
    Demo = 0xff,
    Intensity = 0x0a,
    Noop = 0
};

class Maxim {
    comm::Sender sender;
    
    void writeDigit(int place, int digit, int screen) {
        if (screen == 1) {
          sender.send(place, digit, 0,  0); 
        }
        else {
          sender.send(0, 0, place, digit); 
        }
    }

    void sendCommand(Command c, byte data, int screen) {
        if (screen == 0) {
            sender.send(static_cast<byte>(Command::Noop), 0, static_cast<byte>(c), data);
        } else {
            sender.send(static_cast<byte>(c), data, static_cast<byte>(Command::Noop), 0);
        }
    }
public:
    Maxim(comm::Sender sender)
        : sender(sender)
    {
        delay(10);
        //set pins to output so you can control the shift register

        //pinMode(clockPin, OUTPUT);
        //digitalWrite(clockPin, LOW);

        // demux
        pinMode(2, OUTPUT);
        pinMode(3, OUTPUT);
        pinMode(4, OUTPUT);

        //Serial.begin(9600);

        // disable shutdown
        sender.send(0x0c, 0x01, 0x0c, 0x01);
        delay(1);

        // set decode
        sender.send(0x09, 0xff, 0x09, 0xff);
        delay(1);

        // disable demo
        sender.send(0xff, 0x00, 0xff, 0x00);

        // scan limit to all digits
        sender.send(0x0b, 0x07, 0x0b, 0x07);
        delay(1);

        // intensity
        setIntensity(0, 0);
        setIntensity(0, 1);

        for (int i = 1; i <= 8; ++i) {
            sender.send(i, 0x7f);
            delay(1);
        }
    }

    void setIntensity(byte intensity, int screen) {
        sendCommand(Command::Intensity, intensity, screen);
    }

    void writeNumber(int32_t number, int screen) {
        for (int i = 1; i <= 8; ++i) {
            if (number != 0) {
                int digit = number % 10;
                writeDigit(i, digit, screen);
                number = number / 10;    
            } else {
                // Fill in blank
                writeDigit(i, 0x7f, screen);
            }
        }
    }
};

}
