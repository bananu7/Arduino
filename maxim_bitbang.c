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
const int latchPin = 10;

void shiftOutSPI(byte d) {
    SPI.begin();
    //set clockDivider to SPI_CLOCK_DIV2 by default which is 8MHz
    const int clockDivider = SPI_CLOCK_DIV16;
    SPI.setClockDivider(clockDivider);
    
    //set data mode to SPI_MODE0 by default
    const int dataMode = SPI_MODE0;
    SPI.setDataMode(dataMode);
    
    //set bitOrder to MSBFIRST by default
    const int bitOrder = MSBFIRST; 
    SPI.setBitOrder(bitOrder);
    //Serial.print("writing ");
    //Serial.println(i);
  
    //Serial.println("transfer");
    SPI.transfer(d);
    // if you are daisychaining, add 2nd, 3rd SPI.transfer(next_byte_of_data )

    SPI.end();
}

void latchAndWrite(byte b1, byte b2) {
    digitalWrite(latchPin, LOW);
    // shift out the bits:
    
    shiftOut(dataPin, clockPin, MSBFIRST, b1);
    shiftOut(dataPin, clockPin, MSBFIRST, b2);
    //shiftOutSPI(b1);
    //shiftOutSPI(b2);
    
    //take the latch pin high so the LEDs will light up:
    digitalWrite(latchPin, HIGH);
    // pause before next value:

    delay(500);
}

void setup() {
  //set pins to output so you can control the shift register
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  Serial.begin(9600);

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

void loop() {
    latchAndWrite(0x02, 0x05);
    latchAndWrite(0x03, 0x03);
    latchAndWrite(0x07, 0x00);
    delay(500);
    latchAndWrite(0x02, 0x04);
    latchAndWrite(0x03, 0x06);
    latchAndWrite(0x07, 0x01);
    delay(500);
}
