#include "maxim.h"
#include <SPI.h>

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
//const int latchPin = 10;

void shiftOutSPI(byte d, byte d2) {
    SPI.begin();
    //set clockDivider to SPI_CLOCK_DIV2 by default which is 8MHz
    const int clockDivider = SPI_CLOCK_DIV2;
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


void shiftOutSPI4(byte d, byte d2, byte d3, byte d4) {
    SPI.begin();
    //set clockDivider to SPI_CLOCK_DIV2 by default which is 8MHz
    const int clockDivider = SPI_CLOCK_DIV2;
    SPI.setClockDivider(clockDivider);
    
    //set data mode to SPI_MODE0 by default
    const int dataMode = SPI_MODE0;
    SPI.setDataMode(dataMode);
    
    //set bitOrder to MSBFIRST by default
    const int bitOrder = MSBFIRST; 
    SPI.setBitOrder(bitOrder);
    SPI.transfer(d);
    SPI.transfer(d2);
    SPI.transfer(d3);
    SPI.transfer(d4);
    // if you are daisychaining, add 2nd, 3rd SPI.transfer(next_byte_of_data )

    SPI.end();
}

void selectDevice(int n) {
  digitalWrite(2, n & (1 << 0));
  digitalWrite(3, n & (1 << 1));
  digitalWrite(4, n & (1 << 2));
}

void latchAndWrite(byte b1, byte b2) {
    //digitalWrite(latchPin, LOW);
    selectDevice(4);
    // shift out the bits:

    //delay(10);
    //shiftOut(dataPin, clockPin, MSBFIRST, b1);
    //shiftOut(dataPin, clockPin, MSBFIRST, b2);
    shiftOutSPI(b1, b2);

    //delay(10);
    //take the latch pin high so the LEDs will light up:
    //digitalWrite(latchPin, HIGH);
    selectDevice(1);
    // pause before next value:

    //delay(50);
}


void latchAndWrite2(byte b1, byte b2, byte b3, byte b4) {
    //digitalWrite(latchPin, LOW);
    selectDevice(4);
    // shift out the bits:

    delay(1);
    //shiftOut(dataPin, clockPin, MSBFIRST, b1);
    //shiftOut(dataPin, clockPin, MSBFIRST, b2);
    shiftOutSPI4(b1, b2, b3, b4);

    delay(1);
    //take the latch pin high so the LEDs will light up:
    //digitalWrite(latchPin, HIGH);
    selectDevice(1);
    // pause before next value:

    delay(1);
}

void Maxim::setupMaxim() {
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
  latchAndWrite2(0x0c, 0x01, 0x0c, 0x01);
  delay(1);

  // set decode
  latchAndWrite2(0x09, 0xff, 0x09, 0xff);
  delay(1);

  // disable demo
  latchAndWrite2(0xff, 0x00, 0xff, 0x00);

  // scan limit to all digits
  latchAndWrite2(0x0b, 0x07, 0x0b, 0x07);
  delay(1);

  // intensity
  latchAndWrite2(0x0a, 0x00, 0x00, 0x00);
  latchAndWrite2(0x00, 0x00, 0x0a, 0x00);

  for (int i = 1; i <= 8; ++i) {
    latchAndWrite(i, 0x7f);
    delay(1);
  }

  //Serial.write("setup\n");
}

void writeDigit(int place, int digit, int screen) {
    if (screen == 1) {
      latchAndWrite2(place, digit, 0,  0); 
    }
    else {
      latchAndWrite2(0, 0, place, digit); 
    }
}

void Maxim::writeNumber(int32_t number, int screen) {
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

