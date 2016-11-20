#include "Maxim.h"

Maxim::Maxim(comm::Sender sender)
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

void Maxim::writeDigit(int place, byte digit, int screen, bool dot) {
    if (dot) {
        digit |= 0b10000000;
    }

    if (screen == 1) {
      sender.send(place, digit, 0,  0); 
    }
    else {
      sender.send(0, 0, place, digit); 
    }
}

void Maxim::writeNumber(int32_t number, int screen) {
    // 0 is kind of a special case
    if (number == 0) {
        for (int i = 2; i <= 8; ++i) {
            writeDigit(i, 0x7f, screen);
        }

        writeDigit(1, 0, screen);
        return;
    }

    // if the number is negative, we need to 
    int usedDigits = 8;

    if (number < 0) {
        usedDigits = 7;
        writeDigit(8, CodeB::Hyphen, screen);
        number = -number;
    }

    for (int i = 1; i <= usedDigits; ++i) {
        if (number != 0) {
            int digit = number % 10;
            writeDigit(i, digit, screen);
            number = number / 10;    
        } else {
            // Fill in blank
            writeDigit(i, CodeB::Blank, screen);
        }
    }
}
