# Weather station project

This is a large-ish project as it involves 4 big parts to integrate:

* An MCU, obviously. Started with ATTiny 2313A, moved to ATMega328p. See MCU section for details.
* Bosch BME280 evnironment sensor - doing humidity, temperature and pressure readings, all at the same time. This a new, state-of-the art sensor, but that requires a breakout board, as the package is super small.
* Winbond W25Q80BV flash memory. This is a 1MB flash memory that can be used for datalogging. It only supports clearing entire pages, but individual bytes can be written and added, which makes it very good for appending small amounts of data.
* NRF24L01 wireless module. Still not integrated. Could possibly be used for gathering data.

## MCU choice

I couldn't make the prototype on the Uno, because pretty much all the external components require 3V3. Thus, I made a 2313 breakout board.
This worked well with one thing, however its limited memory meant that i could fit all the drivers. The BME sensor driver was particularly large.

That prompted the move to ATMega. I made another breakout and so far this is as far as I got; with the software able to read the sensor data and store it in the flash memory.

## Development log

* I've managed to either destroy or buy problematic Flash (that didn't hurt) and a mega (that hurt way more).
* As far as programming the Mega, I started doing non-bootloader loading, but quickly realized it's actually much less convenient than with a bootloader. As a reminder, a bootloader runs before your code (slowing down startup a bit), but allows you to load a program via serial. This means i just need 5 wires hooked up to get both programming and serial capabilities, which is really convenient.
* In order to enable booting from bootloader (and in fact putting it on there), a chip needs to be connected to an SPI AVRISP-like programmer to burn the correct fuse values in and transfer the bootloader code. The bootloader binary is in the repo.
