#include <SPI.h>

////Pin connected to DS of 74HC595
const int dataPin = 12;
const int clockPin = 13;
const int latchPin = 10;

byte stat;
byte stat2;

byte shiftInSPI() {
    SPI.begin();
    //set clockDivider to SPI_CLOCK_DIV2 by default which is 8MHz
    const int clockDivider = SPI_CLOCK_DIV8;
    SPI.setClockDivider(clockDivider);
    
    //set data mode to SPI_MODE0 by default
    const int dataMode = SPI_MODE0;
    SPI.setDataMode(dataMode);
    
    //set bitOrder to MSBFIRST by default
    const int bitOrder = MSBFIRST; 
    SPI.setBitOrder(bitOrder);

    byte input = SPI.transfer(0x00);

    SPI.end();

    return input;
}

byte shiftIn() {
  digitalWrite(latchPin, LOW);    // Switch to parallel mode: digital inputs are read into shift register
  delayMicroseconds(10);
  digitalWrite(latchPin, HIGH);   // Switch to serial mode: one data bit is output on each clock falling edge

  byte result;

  for(int i = 0; i < 8; ++i) {           // Iteration over both 8 bit registers
    digitalWrite(clockPin, LOW);         // Generate clock falling edge
    delayMicroseconds(10);

    int r = digitalRead(dataPin);
    if (r) result |= (1 << i);
    digitalWrite(clockPin, HIGH);        // Generate clock rising edge
    delayMicroseconds(10);
  }

  for(int i = 0; i < 8; ++i) {           // Iteration over both 8 bit registers
    digitalWrite(clockPin, LOW);         // Generate clock falling edge
    delayMicroseconds(10);

    int r = digitalRead(dataPin);
    if (r) result |= (1 << i);
    digitalWrite(clockPin, HIGH);        // Generate clock rising edge
    delayMicroseconds(10);
  }
  return result;
}

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, INPUT);

  stat = 0;
  stat2 = 0;
  
  Serial.begin(9600);
}

void loop() {
  digitalWrite(latchPin, LOW);
  delayMicroseconds(10);
  digitalWrite(latchPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(latchPin, LOW);    // Switch to parallel mode: digital inputs are read into shift register
  delayMicroseconds(10);
  digitalWrite(latchPin, HIGH);
  stat = shiftInSPI();
  stat |= shiftInSPI();

  //stat = shiftIn();
  //stat2 = shiftIn();

  if (stat != 0) {
    Serial.println(stat);
  }
  /*(if (stat2 != 0) {
    Serial.println(stat2);
  }*/
  
  delay(100);
  //Serial.print('x');
}
