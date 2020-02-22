# Bootstrapping projects

## Standalone chips

### ATmega328P
It has an internal 8Mhz clock, its use depends on the fuses.

Two main ways of operation:

#### Direct (no bootloader)
Only SPI can be used. Needs either UsbAsp or e.g. Uno as programmer.
This method resets the chip using the CS pin.

#### Bootloader

##### Compatibility tables

|Oscillator|Bootloader|Fuses (L-H-E)|
|Internal 8Mhz|`optiboot_atmega328_pro_8MHz.hex`|E2-DE-FF|

##### Preparing the bootloader

The bootloader must be uploaded via SPI first.
After the bootloader is loaded, connect an LED to pin 19 (PB5 or MOSI-SCK). After pulling 
the reset pin to the ground and back, three quick flashes should appear (less than 1s total).

If the flashes are very slow, incorrect fuses might be set (e.g. clock div by 8).

##### Burning with bootloader
After the bootloader is ready, Serial connection can be used.
At minimum, only 4 cables are necessary - Vcc, GND, Rx and Tx.

When using **CP2102** serial adapter, choose `-carduino` programmer.

Reset the board manually by holding the reset to ground, and release just
before starting `avrdude`.

### ATtiny2313A
Use SPI method. Use ATtinyCore board template for Arduino IDE.