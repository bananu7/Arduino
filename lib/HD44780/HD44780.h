#pragma once

#include <inttypes.h>
#include "Print.h"

#define LCD_5x10DOTS 0x04
#define LCD_5x8DOTS 0x00

#define LCD_8BITMODE 0x10
#define LCD_4BITMODE 0x00

class HD44780 : public Print {
public:
    void begin(uint8_t cols, uint8_t rows, uint8_t charsize = LCD_5x8DOTS);

    // user-facing ui
    void clear();
    void home();
    void noDisplay();
    void display();
    void noBlink();
    void blink();
    void noCursor();
    void cursor();
    void scrollDisplayLeft();
    void scrollDisplayRight();
    void leftToRight();
    void rightToLeft();
    void autoscroll();
    void noAutoscroll();
    void createChar(uint8_t location, uint8_t charmap[]);
    void setCursor(uint8_t col, uint8_t row); 

    size_t write(uint8_t) override;
protected:
    void init(uint8_t fourbitmode, uint8_t rs, uint8_t rw, uint8_t enable,
          uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
          uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7);
    
    void command(uint8_t);

    virtual void write4bits(uint8_t) = 0;
    virtual void pulseEnable() = 0;
    virtual void send(uint8_t value, uint8_t mode) = 0;

    uint8_t _rs_pin; // LOW: command.  HIGH: character.
    uint8_t _rw_pin; // LOW: write to LCD.  HIGH: read from LCD.
    uint8_t _enable_pin; // activated by a HIGH pulse.
    uint8_t _data_pins[8];

    uint8_t _displayfunction;
    uint8_t _displaycontrol;
    uint8_t _displaymode;

    uint8_t _initialized;

    uint8_t _numlines,_currline;
};

