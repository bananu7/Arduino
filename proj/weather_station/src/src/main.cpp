#include <Arduino.h>
#include <SPI.h>

#include <Bme280BoschWrapper.h>

#include "winbond_spiflash.hpp"
#include "ExtractArguments.hpp"

WinbondSpiFlash<10> flash;
Bme280BoschWrapper bme(true);

bool g_command_ready(false);
String g_command;

void setup(void) {
    SPI.begin();
    SPI.setDataMode(0);
    SPI.setBitOrder(MSBFIRST);
    Serial.begin(9600);
    Serial.println("");
    //resetStatusReg();

    Serial.println("Ready"); 

    bme.beginSPI(9);
}

void serialEvent() {
    char c;
    while (Serial.available()) {
        c = (char)Serial.read();
        if (c == ';') {
            g_command_ready = true;
        }
        else {
            g_command += c;
        }    
    }
}

void loop(void) {
    if (g_command_ready) {
        if (g_command == "chipCmdIda") {
            flash.chipCmdId();
        }
        else if (g_command == "chip_erase") {
            flash.chip_erase();
        }
        else if (g_command == "read_all_pages") {
            flash.read_all_pages();
        }
        else if (g_command == "read_temperature") {
            bme.measure();
            Serial.print("temperature: ");
            Serial.println(bme.getTemperature());
        }

        else if (g_command.startsWith("read_page")) {
            auto args = extractArguments<1>(g_command);
            if (args.result == false) {
                Serial.println("Error: Command 'read_page' expects an int operand");
            } else {
                auto const& page = args.data[0];
                flash.read_page(page);
            }
        }
        else if (g_command.startsWith("write_byte")) {
            auto args = extractArguments<3>(g_command);
            if (args.result == true) {
                word pageno = args.data[0];
                byte offset = args.data[1];
                byte data = args.data[2];

                flash.write_byte(pageno, offset, data);
            }
        }
        else {
            Serial.print("Invalid command sent: ");
            Serial.println(g_command);
        }

        g_command = "";
        g_command_ready = false;
    }
}
