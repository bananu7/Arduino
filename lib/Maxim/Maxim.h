#pragma once

/*
This is a library that supports the Maxim 7219 chip which can control
7-segment displays or LED matrices. The library also supports daisy-chaining several units
together.
*/

#include <inttypes.h>
#include "../Communication/Sender.hpp"

template<class Sender>
class Maxim {
    Sender sender;
    
    void writeDigit(int place, int digit, int screen) {
        if (screen == 1) {
          sender.send(place, digit, 0,  0); 
        }
        else {
          sender.send(0, 0, place, digit); 
        }
    }

public:
    Maxim(Sender sender)
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
        sender.send(0x0a, 0x00, 0x00, 0x00);
        sender.send(0x00, 0x00, 0x0a, 0x00);

        for (int i = 1; i <= 8; ++i) {
            sender.send(i, 0x7f);
            delay(1);
        }
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

template<typename Sender>
static Maxim<Sender> make_maxim(Sender sender) {
    return { sender };
}

