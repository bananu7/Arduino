#include "DirectHD.hpp"
#include <Arduino.h>

DirectHD::DirectHD(uint8_t rs, uint8_t rw, uint8_t enable,
                 uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
                 uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7)
{
  init(0, rs, rw, enable, d0, d1, d2, d3, d4, d5, d6, d7);
}

DirectHD::DirectHD(uint8_t rs, uint8_t enable,
                 uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
                 uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7)
{
  init(0, rs, 255, enable, d0, d1, d2, d3, d4, d5, d6, d7);
}

DirectHD::DirectHD(uint8_t rs, uint8_t rw, uint8_t enable,
                 uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3)
{
  init(1, rs, rw, enable, d0, d1, d2, d3, 0, 0, 0, 0);
}

DirectHD::DirectHD(uint8_t rs,  uint8_t enable,
                 uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3)
{
  init(1, rs, 255, enable, d0, d1, d2, d3, 0, 0, 0, 0);
}

void DirectHD::write4bits(uint8_t value) {
    for (int i = 0; i < 4; i++) {
        pinMode(_data_pins[i], OUTPUT);
        digitalWrite(_data_pins[i], (value >> i) & 0x01);
    }
}

void DirectHD::write8bits(uint8_t value) {
  for (int i = 0; i < 8; i++) {
    pinMode(_data_pins[i], OUTPUT);
    digitalWrite(_data_pins[i], (value >> i) & 0x01);
  }
  
  pulseEnable();
}

void DirectHD::pulseEnable(void) {
    digitalWrite(_enable_pin, LOW);
    delayMicroseconds(1);    
    digitalWrite(_enable_pin, HIGH);
    delayMicroseconds(1);    // enable pulse must be >450ns
    digitalWrite(_enable_pin, LOW);
    delayMicroseconds(100);   // commands need > 37us to settle
}

// write either command or data, with automatic 4/8-bit selection
void DirectHD::send(uint8_t value, uint8_t mode) {
    digitalWrite(_rs_pin, mode);

    // if there is a RW pin indicated, set it low to Write
    if (_rw_pin != 255) { 
      digitalWrite(_rw_pin, LOW);
    }
    
    if (_displayfunction & LCD_8BITMODE) {
      write8bits(value); 
    } else {
      write4bits(value>>4);
      write4bits(value);
    }
}