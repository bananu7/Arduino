#include <SPI.h>

namespace maxim {

/*
DS (pin 14) --------------- (blue wire)   -------- arduino MOSI #11
SH_CP | SRCK (pin 11) ----- (yellow wire) -------- arduino SCK #13
ST_CP | RCK (pin 12) ------ (green wire)  -------- arduino SS #10
*/

////Pin connected to DS of 74HC595
const int dataPin = 11;
//Pin connected to SH_CP of 74HC595
const int clockPin = 13;
//Pin connected to ST_CP of 74HC595
const int latchPin = 10;

void shiftOutSPI(byte d, byte d2) {
    SPI.begin();
    //set clockDivider to SPI_CLOCK_DIV2 by default which is 8MHz
    const int clockDivider = SPI_CLOCK_DIV4;
    SPI.setClockDivider(clockDivider);
    
    //set data mode to SPI_MODE0 by default
    const int dataMode = SPI_MODE0;
    SPI.setDataMode(dataMode);
    
    //set bitOrder to MSBFIRST by default
    const int bitOrder = MSBFIRST; 
    SPI.setBitOrder(bitOrder);
    SPI.transfer(d);
        SPI.transfer(d2);
    // if you are daisychaining, add 2nd, 3rd SPI.transfer(next_byte_of_data )

    SPI.end();
}

void latchAndWrite(byte b1, byte b2) {
    digitalWrite(latchPin, LOW);
    // shift out the bits:
    
    //shiftOut(dataPin, clockPin, MSBFIRST, b1);
    //shiftOut(dataPin, clockPin, MSBFIRST, b2);
    shiftOutSPI(b1, b2);
    
    //take the latch pin high so the LEDs will light up:
    digitalWrite(latchPin, HIGH);
    // pause before next value:

    delay(1);
}

void setup() {
  //set pins to output so you can control the shift register
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

  // disable shutdown
  latchAndWrite(0x0c, 0x01);
  delay(1);

  // set decode
  latchAndWrite(0x09, 0xff);
  delay(1);

  // disable demo
  latchAndWrite(0xff, 0x00);

  // scan limit to all digits
  latchAndWrite(0x0b, 0x07);
  delay(1);

  for (int i = 1; i <= 8; ++i) {
    latchAndWrite(i, 0x00);
    delay(1);
  }
}

void writeDigit(int place, int digit) {
    latchAndWrite(place,  digit);
}

void writeNumber(int32_t number) {
    for (int i = 1; i <= 8; ++i) {
        if (number != 0) {
            int digit = number % 10;
            writeDigit(i, digit);
            number = number / 10;    
        } else {
            // Fill in blank
            writeDigit(i, 0x7f);
        }
    }
}

}