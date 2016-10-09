#include <SPI.h>
#include "HardwareSpi.h"

const int clockDivider = SPI_CLOCK_DIV4;
const int dataMode = SPI_MODE0;
const int bitOrder = MSBFIRST; 

void HardwareSpi::start() {
    SPI.begin();
    //set clockDivider to SPI_CLOCK_DIV2 by default which is 8MHz
    
    SPI.setClockDivider(clockDivider);
    
    //set data mode to SPI_MODE0 by default
    SPI.setDataMode(dataMode);
    
    //set bitOrder to MSBFIRST by default
    SPI.setBitOrder(bitOrder);
}

void HardwareSpi::end() {
    SPI.end();
}

void HardwareSpi::transmit(byte b) {
    SPI.transfer(b);
}
