#pragma once

/*
This is a library that supports the Maxim 7219 chip which can control
7-segment displays or LED matrices. The library also supports daisy-chaining several units
together.
*/

#include <inttypes.h>
#include "../Communication/Sender.hpp"

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

public:
    Maxim(comm::Sender sender)
        : sender(sender)
    {
        // disable shutdown
        sender.send(0x0c, 0x01, 0x0c, 0x01);

        // set decode
        sender.send(0x09, 0xff, 0x09, 0xff);

        // disable demo
        sender.send(0xff, 0x00, 0xff, 0x00);

        // scan limit to all digits
        sender.send(0x0b, 0x07, 0x0b, 0x07);

        // intensity
        sender.send(0x0a, 0x00, 0x00, 0x00);
        sender.send(0x00, 0x00, 0x0a, 0x00);

        for (int i = 1; i <= 8; ++i) {
            sender.send(i, 0x7f, i, 0x7f);
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
                //writeDigit(i, 0x7f, screen);
                writeDigit(i, 0x0, screen);
            }
        }
    }
};
