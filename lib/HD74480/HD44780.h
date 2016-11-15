#pragma once

#include <inttypes.h>
#include "Print.h"

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

protected:
    void write(uint8_t);
    void command(uint8_t);

    void send(uint8_t, uint8_t);

    virtual void write4bits(uint8_t) = 0;
    virtual void write8bits(uint8_t) = 0;
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

