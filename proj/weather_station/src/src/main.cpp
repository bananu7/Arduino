#include <Arduino.h>
#include <SPI.h>
//#include <EEPROM.h>

#include <Bme280BoschWrapper.h>
#include <Time.h>

#include <avr/wdt.h>
#include <avr/sleep.h>

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

    Serial.println("Ready"); 

    bme.beginSPI(9);

    // Go to sleep otherwise
    // disable ADC
    WDTCSR = bit (WDCE) | bit (WDE);
    // set interrupt mode and an interval 
    WDTCSR = bit (WDIE) | bit (WDP2) | bit (WDP1);    // set WDIE, and 1 second delay
    //WDTCSR = bit (WDIE) | bit (WDP3) | bit (WDP0);    // set WDIE, and 8 second delay
    wdt_reset();
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

void printCurrentTime() {
    Serial.printf("%d-%d-%d %d:%d\n", year(), month(), day(), hour(), minute());
}

// watchdog interrupt
ISR (WDT_vect) 
{
   //wdt_disable();  // disable watchdog
    printCurrentTime();

    WDTCSR = bit (WDCE) | bit (WDE);
    // set interrupt mode and an interval 
    //WDTCSR = bit (WDIE) | bit (WDP2) | bit (WDP1);    // set WDIE, and 1 second delay
    WDTCSR = bit (WDIE) | bit (WDP3) | bit (WDP0);    // set WDIE, and 8 second delay
    wdt_reset();
}  // end of WDT_vect


void goToSleep() {
    ADCSRA = 0;

    WDTCSR = bit (WDCE) | bit (WDE);
    // set interrupt mode and an interval 
    //WDTCSR = bit (WDIE) | bit (WDP2) | bit (WDP1);    // set WDIE, and 1 second delay
    WDTCSR = bit (WDIE) | bit (WDP3) | bit (WDP0);    // set WDIE, and 8 second delay
    wdt_reset();  // pat the dog

    set_sleep_mode (SLEEP_MODE_PWR_DOWN);
    noInterrupts ();           // timed sequence follows
    sleep_enable();
    interrupts();             // guarantees next instruction executed
    sleep_cpu();
    sleep_disable();
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
        else if (g_command == "help") {
            Serial.println("List of commands:");
            Serial.println("- chip_erase");
            Serial.println("- read_page <page>");
            Serial.println("- write_byte <page> <offset> <byte>");
            Serial.println("- read_temperature");
            Serial.println("- help");
            Serial.println("- set_time <y> <m> <d> <h> <m>");
            Serial.println("- get_time");
        }

        else if (g_command == "get_time") {
            Serial.print("\nCurrent time: ");
            printCurrentTime();
        }

        else if (g_command.startsWith("set_time")) {
            auto args = extractArguments<5>(g_command);
            if (args.result == true) {
                setTime(args.data[3], args.data[4], 0, args.data[2], args.data[1], args.data[0]);
            }

            //EEPROM.write(0, val);

            Serial.print("\nTime set to:");
            printCurrentTime();
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
