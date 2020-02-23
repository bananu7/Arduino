#pragma once

#include <EEPROM.h>
#include <Arduino.h>
#include <Time.h>

void printCurrentTime() {
    Serial.printf("%d-%d-%d %d:%d\n", year(), month(), day(), hour(), minute());
}

static const int timeOffsetInEeprom = 0;

void loadTimeFromEEPROM() {
    const uint8_t yearL = EEPROM.read(timeOffsetInEeprom + 0);
    const uint8_t yearH = EEPROM.read(timeOffsetInEeprom + 1);
    const uint8_t mon = EEPROM.read(timeOffsetInEeprom + 2);
    const uint8_t d = EEPROM.read(timeOffsetInEeprom + 3);
    const uint8_t h = EEPROM.read(timeOffsetInEeprom + 4);
    const uint8_t min = EEPROM.read(timeOffsetInEeprom + 5);
    setTime(h, min, 0, d, mon, (yearH << 8) | yearL);
}
void saveCurrentTimeToEEPROM() {
    EEPROM.write(timeOffsetInEeprom + 0, year() & 0xff);
    EEPROM.write(timeOffsetInEeprom + 1, (year() >> 8) & 0xff);
    EEPROM.write(timeOffsetInEeprom + 2, month() & 0xff);
    EEPROM.write(timeOffsetInEeprom + 3, day() & 0xff);
    EEPROM.write(timeOffsetInEeprom + 4, hour() & 0xff);
    EEPROM.write(timeOffsetInEeprom + 5, minute() & 0xff);
}