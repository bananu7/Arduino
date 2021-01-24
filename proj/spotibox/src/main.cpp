
#include <Arduino.h>
#include <USBSerial.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#include <algorithm>
#include <array>

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

//---------------------------------------------------

int counter = 0;
std::array<char, 64> buffer;

void handleSerial() {
  std::size_t incomingDataSize = Serial.available();
  while (incomingDataSize > 0) {
    Serial.print("Data incoming, size = ");
    Serial.println(incomingDataSize);

    analogWrite(LED_PIN, 255);

    std::fill(buffer.begin(), buffer.end(), '\0');

    Serial.setTimeout(3000);
    std::size_t commandSize = Serial.readBytesUntil('\n', buffer.data(), buffer.size());
    if (commandSize == 0)  {
      break;
    }

    switch (buffer[0]) {
      case 'p': {
        const int posDigit1 = buffer[1] - '0';
        const int posDigit2 = buffer[2] - '0';

        const int row = posDigit1 <= 3 ? posDigit1 : posDigit1 - 4;
        const int col = posDigit1 <= 3 ? posDigit2 : posDigit2 + 10;

        lcd.setCursor(col,row);
        lcd.print(&buffer[3]);

        break;
      }
      case 'h': {
        const int state = buffer[1] - '0';
        if (state == 0) {
          lcd.noBacklight();
        } else {
          lcd.backlight();
        }
        break;
      }
      case 'c': {
        lcd.clear();
        break;
      }
    }

    incomingDataSize = Serial.available();
  }

  analogWrite(LED_PIN, 0);
}

void handleButton() {
  if (digitalRead(BTN_RED_PIN) == LOW) {
    Serial.println("Button press");

    lcd.setCursor(0, 2);
    lcd.print(counter);

    counter += 1;
  }
}

void loop() {
  handleSerial();
  handleButton();

  delay(100);
}
