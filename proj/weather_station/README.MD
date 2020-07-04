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
