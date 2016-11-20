#pragma once

/*
This is a library that supports the Maxim 7219 chip which can control
7-segment displays or LED matrices. The library also supports daisy-chaining several units
together.
*/

#include <inttypes.h>
#include "../Communication/Sender.hpp"

class Maxim {
    enum CodeB : byte{
        // 0 to 9 are regular values 0-9;
        Hyphen = 0b00001010,
        E = 0b00001011,
        H = 0b00001100,
        L = 0b00001011,
        P = 0b00001110,
        Blank = 0b00001111
    };

    comm::Sender sender;
    
    void writeDigit(int place, byte digit, int screen, bool dot = false);

public:
    Maxim(comm::Sender sender);

    void writeNumber(int32_t number, int screen);
};
