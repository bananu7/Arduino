#include "LiquidC.h"
#include <SPI.h>

#include "maxim.h"
 
//some comments missing here but they will be in the original sketch

// initialize the library with the number of the sspin
//(or the latch pin of the 74HC595)
LiquidC lcd(10);

void setup() {
  delay(100);
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Dobranoc kocie!");
  Serial.begin(9600);

  Maxim::setupMaxim();
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
    lcd.setCursor(0, 1);
  // print the number of seconds since reset:
    lcd.print(millis()/1000);

    delay(10);

    long m = millis();

    Maxim::writeNumber(m/1000, 2);
    Maxim::writeNumber((m/1000) * (m/1000), 1);

    delay(10);
}

