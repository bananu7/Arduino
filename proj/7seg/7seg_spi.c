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
    const int clockDivider = SPI_CLOCK_DIV2;
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

void setup() {
  //set pins to output so you can control the shift register
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  Serial.begin(9600);
}

const byte digits[10] = { 126, 72, 61, 109, 75, 103, 119, 76, 127, 111 };

void loop() {
  for (int numberToDisplay = 0; numberToDisplay <= 9; numberToDisplay++) {
    // take the latchPin low so 
    // the LEDs don't change while you're sending in bits:
    digitalWrite(latchPin, LOW);
    // shift out the bits:
    
    //shiftOut(dataPin, clockPin, MSBFIRST, digits[numberToDisplay]);  
    shiftOutSPI(digits[numberToDisplay]);
    
    //take the latch pin high so the LEDs will light up:
    digitalWrite(latchPin, HIGH);
    // pause before next value:

    Serial.println(numberToDisplay);
    delay(500);
  }
}
