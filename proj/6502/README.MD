# Custom 6502 computer project

Workname: The Litre (because it's made of 100x100mm boards that are attached perpendicularly).

## Idea

I want to make a custom computer for educational purposes. It's supposed to be modular, so that parts of it can be developed and tested in isolation. I want to make use of the 6502 which is a CPU that has very straightforward operation, works on the entire address space in an uniform way and naturally works with separate components.

## Parts list

### ICs:


| Purpose | Number | Manufacturer | Notes | Datasheet |
|---------|--------|--------------|-------|-----------|
| CPU     | R6502P | Rockwell | Unfortunately this one requires keeping the clock high for standby, as it doesn't have static registers. |
| VIA (interface adapter) | 6522 | MOS | |
| EEPROM | AT28C256 | ATmel | | [PDF](http://ww1.microchip.com/downloads/en/DeviceDoc/doc0006.pdf) |
| RAM | HM62256ALP-10 | | 32/768-word x 8-bit High Speed CMOS Static | [PDF](http://pdf.datasheetcatalog.com/datasheets/90/176972_DS.pdf) |
| CRT controller | MC6845P | Motorola | | [PDF](http://pdf.datasheetcatalog.com/datasheet_pdf/motorola/MC6845L_and_MC6845P.pdf) |

### Connectors, misc.

* 2x31 "edge card slot", the same as for 8-bit ISA (PC XT) bus.