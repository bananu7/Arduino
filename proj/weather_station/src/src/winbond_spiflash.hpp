#pragma once

#define writeEnable       0x06 // Address Write Enable
#define writeDisable      0x04 // Address Write Disable
#define chipErase         0xc7 // Address Chip Erase
#define readStatusReg1    0x05 // Address Read Status
#define readData          0x03 // Address Read Data
#define pageProgramStat   0x02 // Address Status Page Program
#define chipCommandId     0x9f // Address Status Read Id

#define SS 10
 
const int WB_READ_STATUS_REG_1 = 0x05;
 

class WinbondSpiFlash {
    const int LED_PIN = 2;
    /*
    * See the timing diagram in section 9.2.10 of the
    * data sheet located below, "Read Data (03h)".
    */
    void _read_page(word page_number, byte *page_buffer) {
        digitalWrite(SS, HIGH);
        digitalWrite(SS, LOW);
        SPI.transfer(readData);
        
        // Construct the 24-bit address from the 16-bit page
        // number and 0x00, since we will read 256 bytes (one
        // page).
        SPI.transfer((page_number >> 8) & 0xFF);
        SPI.transfer((page_number >> 0) & 0xFF);
        SPI.transfer(0);
        for (int i = 0; i < 256; ++i) {
            page_buffer[i] = SPI.transfer(0);
        }
        digitalWrite(SS, HIGH);
        not_busy();
    }

    /*
    See the timing diagram in section 9.2.26 of the data sheet, "Chip Erase (C7h / 06h)". (Note:
    */
    void _chip_erase(void) {
        digitalWrite(SS, HIGH);
        digitalWrite(SS, LOW);  
        SPI.transfer(writeEnable);
        digitalWrite(SS, HIGH);
        digitalWrite(SS, LOW);  
        SPI.transfer(chipErase);
        digitalWrite(SS, HIGH);
        
        /* See notes on rev 2 
        digitalWrite(SS, LOW);  
        SPI.transfer(writeDisable);
        digitalWrite(SS, HIGH);
        */
        not_busy();
    }

    // Check if the memory is busy
    void not_busy(void) {
        digitalWrite(LED_PIN, HIGH); 
        digitalWrite(SS, HIGH);  
        digitalWrite(SS, LOW);
        SPI.transfer(WB_READ_STATUS_REG_1);       
        while (SPI.transfer(0) & 1) {}; 
        digitalWrite(SS, HIGH);
        digitalWrite(LED_PIN, LOW);  
    }

    void _chipCmdId(byte *b1, byte *b2, byte *b3) {
        digitalWrite(SS, HIGH);
        digitalWrite(SS, LOW);
        SPI.transfer(chipCommandId);
        *b1 = SPI.transfer(0); // manufacturer id
        *b2 = SPI.transfer(0); // memory type
        *b3 = SPI.transfer(0); // capacity
        digitalWrite(SS, HIGH);
        not_busy();
    }  

    /*
    print_page_bytes() is a simple helper function that formats 256 bytes
    */
    void print_page_bytes(uint8_t *page_buffer) {
        char buf[10];
        for (int i = 0; i < 16; ++i) {
            for (int j = 0; j < 16; ++j) {
            sprintf(buf, "%02x", page_buffer[i * 16 + j]);
            Serial.print(buf);
            }
            Serial.println();
        }
    }

    void error(uint32_t d) {
        pinMode(LED_PIN, OUTPUT);
        for(;;) {
            digitalWrite(LED_PIN, HIGH);
            delay(d);
            digitalWrite(LED_PIN, LOW);
            delay(d);
        }
    }

    void resetStatusReg() {
        Serial.println("Reset status reg"); 
        digitalWrite(SS, HIGH);
        digitalWrite(SS, LOW);  
        SPI.transfer(writeEnable);
        digitalWrite(SS, HIGH);
        digitalWrite(SS, LOW);
        SPI.transfer(0x01);
        SPI.transfer(0);
        SPI.transfer(0);
        digitalWrite(SS, HIGH);
        not_busy();
    }  

public:
    void chipCmdId(void) {
        Serial.println("Set Command: chipCmdIda");
        byte b1, b2, b3;
        _chipCmdId(&b1, &b2, &b3);
        char buf[128];
        sprintf(buf, "ID: %02xh\nMemory Type: %02xh\nCapacity: %02xh",
            b1, b2, b3);
        Serial.println(buf);
        Serial.println("Ready");
    } 

    void chip_erase(void) {
        Serial.println("command: chip_erase");
        _chip_erase();
        Serial.println("Ready");
    }    

    void read_page(unsigned int page_number) {
        char buf[80];
        sprintf(buf, "command: read_page(%04xh)", page_number);
        Serial.println(buf);
        byte page_buffer[256];
        _read_page(page_number, page_buffer);
        print_page_bytes(page_buffer);
        Serial.println("Ready");
    }
    
    void read_all_pages(void) {
        Serial.println("command: read_all_pages");
        byte page_buffer[256];
        for (int i = 0; i < 4096; ++i) {
            _read_page(i, page_buffer);
            print_page_bytes(page_buffer);
        }
        Serial.println("Ready");
    }

    void write_byte(word page, byte offset, byte databyte) {
        char buf[80];
        sprintf(buf, "command: write_byte(%04xh, %04xh, %02xh)", page, offset, databyte);
        Serial.println(buf);
        byte page_data[256];
        _read_page(page, page_data);
        page_data[offset] = databyte;
        write_page(page, page_data);
        Serial.println("Ready");
    }

    void write_page(word page_number, byte *page_buffer) {
        /*
        * See the timing diagram in section 9.2.21 of the
        * data sheet, "Page Program (02h)".
        */
        digitalWrite(SS, HIGH);
        digitalWrite(SS, LOW);  
        SPI.transfer(writeEnable);
        digitalWrite(SS, HIGH);
        digitalWrite(SS, LOW);  
        SPI.transfer(pageProgramStat);
        SPI.transfer((page_number >>  8) & 0xFF);
        SPI.transfer((page_number >>  0) & 0xFF);
        SPI.transfer(0);
        for (int i = 0; i < 256; ++i) {
            SPI.transfer(page_buffer[i]);
        }
        digitalWrite(SS, HIGH);
        ///* See notes on rev 2
        digitalWrite(SS, LOW);  
        SPI.transfer(writeDisable);
        digitalWrite(SS, HIGH);
        //*/
        not_busy();
    } 
};
