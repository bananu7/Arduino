
#include <Arduino.h>
#include <USBSerial.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define Serial SerialUSB

#define COLUMS          20
#define ROWS             4
#define LCD_SPACE_SYMBOL 0x20 
LiquidCrystal_I2C lcd(PCF8574A_ADDR_A21_A11_A01, 4, 5, 6, 16, 11, 12, 13, 14, POSITIVE);

#define LED_PIN       PA6
#define BTN_RED_PIN   PB11

// the setup function runs once when you press reset or power the board
void setup() {
  SerialUSB.begin();
  // initialize digital pin PC13 as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BTN_RED_PIN, INPUT_PULLUP);

  Wire.setSCL(PB8);
  Wire.setSDA(PB9);
  Wire.begin();
  
  lcd.begin(COLUMS, ROWS);
  lcd.print(F("Spotibox"));

  //while (!Serial);
  Serial.println("\nI2C Scanner");
}

int counter = 0;

void loop() {
  analogWrite(LED_PIN, 12);   // turn the LED on (HIGH is the voltage level)
  delay(100);              // wait for a second
  analogWrite(LED_PIN, 0);    // turn the LED off by making the voltage LOW
  delay(100);              // wait for a second

  /*
  Wire.beginTransmission(0x27);
  int error = Wire.endTransmission();

  if (error == 0) {
    Serial.println("found!");
  } else {
    Serial.println("nope!");
  }
  */

  if (digitalRead(BTN_RED_PIN) == LOW) {
    Serial.println("Button press");

    lcd.setCursor(0, 2);
    lcd.print(counter);

    counter += 1;
  }

}
