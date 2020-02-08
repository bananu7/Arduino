/*
  Optimized digital functions for AVR microcontrollers
  by Watterott electronic (www.watterott.com)
  based on http://code.google.com/p/digitalwritefast
 */

#ifndef __digitalWriteFast_h_
#define __digitalWriteFast_h_ 1

#define ERROR_SEQUENCE 0b10101010 //digitalReadFast will return this value if pin number is not constant
// general macros/defines
#ifndef BIT_READ
# define BIT_READ(value, bit)            ((value) &   (1UL << (bit)))
#endif
#ifndef BIT_SET
# define BIT_SET(value, bit)             ((value) |=  (1UL << (bit)))
#endif
#ifndef BIT_CLEAR
# define BIT_CLEAR(value, bit)           ((value) &= ~(1UL << (bit)))
#endif
#ifndef BIT_WRITE
# define BIT_WRITE(value, bit, bitvalue) (bitvalue ? BIT_SET(value, bit) : BIT_CLEAR(value, bit))
#endif

#ifndef SWAP
#define SWAP(x,y) do{ (x)=(x)^(y); (y)=(x)^(y); (x)=(x)^(y); }while(0)
#endif

/* //not needed, rather it produces annoying warnings when compiled
#ifndef DEC
# define DEC (10)
#endif
#ifndef HEX
# define HEX (16)
#endif
#ifndef OCT
# define OCT (8)
#endif
#ifndef BIN
# define BIN (2)
#endif
*/

// workarounds for ARM microcontrollers
#if (!defined(__AVR__) || defined(ARDUINO_ARCH_SAM))
#ifndef PROGMEM
# define PROGMEM
#endif
#ifndef PGM_P
# define PGM_P const char *
#endif
#ifndef PSTR
# define PSTR(str) (str)
#endif

#ifndef memcpy_P
# define memcpy_P(dest, src, num) memcpy((dest), (src), (num))
#endif
#ifndef strcpy_P
# define strcpy_P(dst, src)       strcpy((dst), (src))
#endif
#ifndef strcat_P
# define strcat_P(dst, src)       strcat((dst), (src))
#endif
#ifndef strcmp_P
# define strcmp_P(a, b)           strcmp((a), (b))
#endif
#ifndef strcasecmp_P
# define strcasecmp_P(a, b)       strcasecmp((a), (b))
#endif
#ifndef strncmp_P
# define strncmp_P(a, b, n)       strncmp((a), (b), (n))
#endif
#ifndef strncasecmp_P
# define strncasecmp_P(a, b, n)   strncasecmp((a), (b), (n))
#endif
#ifndef strstr_P
# define strstr_P(a, b)           strstr((a), (b))
#endif
#ifndef strlen_P
# define strlen_P(a)              strlen((a))
#endif
#ifndef sprintf_P
# define sprintf_P(s, f, ...)     sprintf((s), (f), __VA_ARGS__)
#endif

#ifndef pgm_read_byte
# define pgm_read_byte(addr)      (*(const unsigned char *)(addr))
#endif
#ifndef pgm_read_word
# define pgm_read_word(addr)      (*(const unsigned short *)(addr))
#endif
#ifndef pgm_read_dword
# define pgm_read_dword(addr)     (*(const unsigned long *)(addr))
#endif

#endif


// digital functions
//#ifndef digitalPinToPortReg
#define SPI_SW_SS_PIN   (10) //SS on Uno (for software SPI)
#define SPI_SW_MOSI_PIN (11) //MOSI on Uno (for software SPI)
#define SPI_SW_MISO_PIN (12) //MISO on Uno (for software SPI)
#define SPI_SW_SCK_PIN  (13) //SCK on Uno (for software SPI)


// --- Arduino Due ---
#if (defined(ARDUINO_SAM_DUE) || defined(__SAM3X8E__))

#define UART_RX_PIN     (0)
#define UART_TX_PIN     (1)

#define I2C_SDA_PIN     (20)
#define I2C_SCL_PIN     (21)

#define SPI_HW_SS_PIN   (78) //SS0:77, SS1:87, SS2:86, SS3:78
#define SPI_HW_MOSI_PIN (75) //75
#define SPI_HW_MISO_PIN (74) //74
#define SPI_HW_SCK_PIN  (76) //76


// --- Arduino Zero ---
#elif (defined(ARDUINO_SAM_ZERO) || defined(__SAMD21G18A__))

#define UART_RX_PIN     (0)
#define UART_TX_PIN     (1)

#define I2C_SDA_PIN     (16)
#define I2C_SCL_PIN     (17)

#define SPI_HW_SS_PIN   (14) //14
#define SPI_HW_MOSI_PIN (21) //21
#define SPI_HW_MISO_PIN (18) //18
#define SPI_HW_SCK_PIN  (20) //20


// --- Arduino Mega ---
#elif (defined(ARDUINO_AVR_MEGA) || \
       defined(ARDUINO_AVR_MEGA1280) || \
       defined(ARDUINO_AVR_MEGA2560) || \
       defined(__AVR_ATmega1280__) || \
       defined(__AVR_ATmega1281__) || \
       defined(__AVR_ATmega2560__) || \
       defined(__AVR_ATmega2561__))

#define UART_RX_PIN     (0) //PE0
#define UART_TX_PIN     (1) //PE1

#define I2C_SDA_PIN     (20)
#define I2C_SCL_PIN     (21)

#define SPI_HW_SS_PIN   (53) //PB0
#define SPI_HW_MOSI_PIN (51) //PB2
#define SPI_HW_MISO_PIN (50) //PB3
#define SPI_HW_SCK_PIN  (52) //PB1

#define __digitalPinToPortReg(P) \
(((P) >= 22 && (P) <= 29) ? &PORTA : \
((((P) >= 10 && (P) <= 13) || ((P) >= 50 && (P) <= 53)) ? &PORTB : \
(((P) >= 30 && (P) <= 37) ? &PORTC : \
((((P) >= 18 && (P) <= 21) || (P) == 38) ? &PORTD : \
((((P) >= 0 && (P) <= 3) || (P) == 5) ? &PORTE : \
(((P) >= 54 && (P) <= 61) ? &PORTF : \
((((P) >= 39 && (P) <= 41) || (P) == 4) ? &PORTG : \
((((P) >= 6 && (P) <= 9) || (P) == 16 || (P) == 17) ? &PORTH : \
(((P) == 14 || (P) == 15) ? &PORTJ : \
(((P) >= 62 && (P) <= 69) ? &PORTK : &PORTL))))))))))

#define __digitalPinToDDRReg(P) \
(((P) >= 22 && (P) <= 29) ? &DDRA : \
((((P) >= 10 && (P) <= 13) || ((P) >= 50 && (P) <= 53)) ? &DDRB : \
(((P) >= 30 && (P) <= 37) ? &DDRC : \
((((P) >= 18 && (P) <= 21) || (P) == 38) ? &DDRD : \
((((P) >= 0 && (P) <= 3) || (P) == 5) ? &DDRE : \
(((P) >= 54 && (P) <= 61) ? &DDRF : \
((((P) >= 39 && (P) <= 41) || (P) == 4) ? &DDRG : \
((((P) >= 6 && (P) <= 9) || (P) == 16 || (P) == 17) ? &DDRH : \
(((P) == 14 || (P) == 15) ? &DDRJ : \
(((P) >= 62 && (P) <= 69) ? &DDRK : &DDRL))))))))))

#define __digitalPinToPINReg(P) \
(((P) >= 22 && (P) <= 29) ? &PINA : \
((((P) >= 10 && (P) <= 13) || ((P) >= 50 && (P) <= 53)) ? &PINB : \
(((P) >= 30 && (P) <= 37) ? &PINC : \
((((P) >= 18 && (P) <= 21) || (P) == 38) ? &PIND : \
((((P) >= 0 && (P) <= 3) || (P) == 5) ? &PINE : \
(((P) >= 54 && (P) <= 61) ? &PINF : \
((((P) >= 39 && (P) <= 41) || (P) == 4) ? &PING : \
((((P) >= 6 && (P) <= 9) || (P) == 16 || (P) == 17) ? &PINH : \
(((P) == 14 || (P) == 15) ? &PINJ : \
(((P) >= 62 && (P) <= 69) ? &PINK : &PINL))))))))))

#define __digitalPinToBit(P) \
(((P) >=  7 && (P) <=  9) ? (P) - 3 : \
(((P) >= 10 && (P) <= 13) ? (P) - 6 : \
(((P) >= 22 && (P) <= 29) ? (P) - 22 : \
(((P) >= 30 && (P) <= 37) ? 37 - (P) : \
(((P) >= 39 && (P) <= 41) ? 41 - (P) : \
(((P) >= 42 && (P) <= 49) ? 49 - (P) : \
(((P) >= 50 && (P) <= 53) ? 53 - (P) : \
(((P) >= 54 && (P) <= 61) ? (P) - 54 : \
(((P) >= 62 && (P) <= 69) ? (P) - 62 : \
(((P) == 0 || (P) == 15 || (P) == 17 || (P) == 21) ? 0 : \
(((P) == 1 || (P) == 14 || (P) == 16 || (P) == 20) ? 1 : \
(((P) == 19) ? 2 : \
(((P) == 5 || (P) == 6 || (P) == 18) ? 3 : \
(((P) == 2) ? 4 : \
(((P) == 3 || (P) == 4) ? 5 : 7)))))))))))))))


// --- Arduino 644 ---
#elif (defined(__AVR_ATmega644__) || \
       defined(__AVR_ATmega644P__))

#define UART_RX_PIN     (8) //PD0
#define UART_TX_PIN     (9) //PD1

#define I2C_SDA_PIN     (17) //PC1
#define I2C_SCL_PIN     (16) //PC0

#define SPI_HW_SS_PIN   (4) //PB4
#define SPI_HW_MOSI_PIN (5) //PB5
#define SPI_HW_MISO_PIN (6) //PB6
#define SPI_HW_SCK_PIN  (7) //PB7

#define __digitalPinToPortReg(P) \
(((P) >= 0 && (P) <= 7) ? &PORTB : (((P) >= 8 && (P) <= 15) ? &PORTD : (((P) >= 16 && (P) <= 23) ? &PORTC : &PORTA)))
#define __digitalPinToDDRReg(P) \
(((P) >= 0 && (P) <= 7) ? &DDRB : (((P) >= 8 && (P) <= 15) ? &DDRD : (((P) >= 8 && (P) <= 15) ? &DDRC : &DDRA)))
#define __digitalPinToPINReg(P) \
(((P) >= 0 && (P) <= 7) ? &PINB : (((P) >= 8 && (P) <= 15) ? &PIND : (((P) >= 8 && (P) <= 15) ? &PINC : &PINA)))
#define __digitalPinToBit(P) \
(((P) >= 0 && (P) <= 7) ? (P) : (((P) >= 8 && (P) <= 15) ? (P) - 8 : (((P) >= 16 && (P) <= 23) ? (P) - 16 : (P) - 24)))


// --- Arduino Leonardo ---
#elif (defined(ARDUINO_AVR_LEONARDO) || \
       defined(__AVR_ATmega16U4__) || \
       defined(__AVR_ATmega32U4__))

#define UART_RX_PIN     (0) //PD2
#define UART_TX_PIN     (1) //PD3

#define I2C_SDA_PIN     (2) //PD1
#define I2C_SCL_PIN     (3) //PD0

#define SPI_HW_SS_PIN   (17) //PB0
#define SPI_HW_MOSI_PIN (16) //PB2
#define SPI_HW_MISO_PIN (14) //PB3
#define SPI_HW_SCK_PIN  (15) //PB1

#define __digitalPinToPortReg(P) \
((((P) >= 0 && (P) <= 4) || (P) == 6 || (P) == 12 || (P) == 24 || (P) == 25 || (P) == 29) ? &PORTD : (((P) == 5 || (P) == 13) ? &PORTC : (((P) >= 18 && (P) <= 23)) ? &PORTF : (((P) == 7) ? &PORTE : &PORTB)))
#define __digitalPinToDDRReg(P) \
((((P) >= 0 && (P) <= 4) || (P) == 6 || (P) == 12 || (P) == 24 || (P) == 25 || (P) == 29) ? &DDRD : (((P) == 5 || (P) == 13) ? &DDRC : (((P) >= 18 && (P) <= 23)) ? &DDRF : (((P) == 7) ? &DDRE : &DDRB)))
#define __digitalPinToPINReg(P) \
((((P) >= 0 && (P) <= 4) || (P) == 6 || (P) == 12 || (P) == 24 || (P) == 25 || (P) == 29) ? &PIND : (((P) == 5 || (P) == 13) ? &PINC : (((P) >= 18 && (P) <= 23)) ? &PINF : (((P) == 7) ? &PINE : &PINB)))
#define __digitalPinToBit(P) \
(((P) >= 8 && (P) <= 11) ? (P) - 4 : (((P) >= 18 && (P) <= 21) ? 25 - (P) : (((P) == 0) ? 2 : (((P) == 1) ? 3 : (((P) == 2) ? 1 : (((P) == 3) ? 0 : (((P) == 4) ? 4 : (((P) == 6) ? 7 : (((P) == 13) ? 7 : (((P) == 14) ? 3 : (((P) == 15) ? 1 : (((P) == 16) ? 2 : (((P) == 17) ? 0 : (((P) == 22) ? 1 : (((P) == 23) ? 0 : (((P) == 24) ? 4 : (((P) == 25) ? 7 : (((P) == 26) ? 4 : (((P) == 27) ? 5 : 6 )))))))))))))))))))


// --- Arduino Uno ---
#elif (defined(ARDUINO_AVR_UNO) || \
       defined(ARDUINO_AVR_DUEMILANOVE) || \
       defined(ARDUINO_ARCH_AVR) || \
       defined(__AVR_ATmega328__) || \
       defined(__AVR_ATmega328P__) || \
       defined(__AVR__))

#define UART_RX_PIN     (0) //PD0
#define UART_TX_PIN     (1) //PD1

#define I2C_SDA_PIN     (18) //A4
#define I2C_SCL_PIN     (19) //A5

#define SPI_HW_SS_PIN   (10) //PB0
#define SPI_HW_MOSI_PIN (11) //PB2
#define SPI_HW_MISO_PIN (12) //PB3
#define SPI_HW_SCK_PIN  (13) //PB1

#define __digitalPinToPortReg(P) \
(((P) >= 0 && (P) <= 7) ? &PORTD : (((P) >= 8 && (P) <= 13) ? &PORTB : &PORTC))
#define __digitalPinToDDRReg(P) \
(((P) >= 0 && (P) <= 7) ? &DDRD : (((P) >= 8 && (P) <= 13) ? &DDRB : &DDRC))
#define __digitalPinToPINReg(P) \
(((P) >= 0 && (P) <= 7) ? &PIND : (((P) >= 8 && (P) <= 13) ? &PINB : &PINC))
#define __digitalPinToBit(P) \
(((P) >= 0 && (P) <= 7) ? (P) : (((P) >= 8 && (P) <= 13) ? (P) - 8 : (P) - 14))


// --- Other ---
#else

#define SPI_HW_SS_PIN   SS
#define SPI_HW_MOSI_PIN MOSI
#define SPI_HW_MISO_PIN MISO
#define SPI_HW_SCK_PIN  SCK


#endif
//#endif  //#ifndef digitalPinToPortReg


//ref: http://forum.arduino.cc/index.php?topic=140409.msg1054868#msg1054868
//void OutputsErrorIfCalled( void ) __attribute__ (( error( "Line: "__line__ "Variable used for digitalWriteFast") ));
void NonConstantUsed( void )  __attribute__ (( error("") )); 


#ifndef digitalWriteFast
#if (defined(__AVR__) || defined(ARDUINO_ARCH_AVR))
#define digitalWriteFast(P, V) \
if (__builtin_constant_p(P) && __builtin_constant_p(V)) { \
  BIT_WRITE(*__digitalPinToPortReg(P), __digitalPinToBit(P), (V)); \
} else { \
  NonConstantUsed(); \
}
#else
//#define digitalWriteFast digitalWrite
#error Non-AVR device, unsupported.
#endif
#endif


#ifndef pinModeFast
#if (defined(__AVR__) || defined(ARDUINO_ARCH_AVR))
#define pinModeFast(P, V) \
if (__builtin_constant_p(P) && __builtin_constant_p(V)) { \
  BIT_WRITE(*__digitalPinToDDRReg(P), __digitalPinToBit(P), (V)); \
} else { \
  NonConstantUsed(); \
}
#else
//#define pinModeFast pinMode
#error Non-AVR device, unsupported.
#endif
#endif


#ifndef digitalReadFast
#if (defined(__AVR__) || defined(ARDUINO_ARCH_AVR))
#define digitalReadFast(P) ( (byte) __digitalReadFast((P)) )
#define __digitalReadFast(P ) \
  (__builtin_constant_p(P) ) ? ( \
  ( BIT_READ(*__digitalPinToPINReg(P), __digitalPinToBit(P))) ) : \
  ERROR_SEQUENCE
#else
//#define digitalReadFast digitalRead
#error Non-AVR device, unsupported.
#endif
#endif

#endif //__digitalWriteFast_h_
/**
 * Arduino interfacing with the Line 6 Floorboard
 *
 * Thanks to Mark Lavelle for deciphering how this floorboard works and publishing on his website.
 * Go here for the document: http://harmonicappliances.com/floorboard/floorboard.html
 *
 * The following is a description of how to make the connection to the floorboard 
 * (which I copied from the website linked above, because I am lazy as hell.)
 * 
 * ==============================================================
 * The POD & Floor Board use standard "Category 5" network cables for connection. 
 * The connectors on these cables (and the receptacles in the POD and Floor Board) are known as RJ-45s. 
 * They're just like standard phone jacks, but with 8 pins. 
 *
 * The pin numbering I'll use for RJ-type jacks starts at 1 and goes from left to right 
 * looking into the receptacle (the female socket on the POD or Floor Board) 
 * with the locking tab slot on the bottom, like the diagram below. 
 * "Standard" or not, that's the numbering I'll be using here.
 * ==============================================================
 *
 * And here is a very lame ASCII interpretation of the connection drawing. 
 * (Again, for details visit that website linked above.)
 *                                        
 *                                              1: Ground
 *                _________________             2: Wah
 *               | = = = = = = = = |            3: Ground
 *               | 1 2 3 4 5 6 7 8 |            4: Volume
 *               |_____       _____|            5: LEDs
 *                     |_____|                  6: Switches
 *                                              7: +5V
 *                                              8: +5V
 * 
 * So, what we'll be doing is connectiong those lines directly to our arduino.
 * And, basically, besides the power lines, we'll only be using 3 analog and 1 digital 
 * pins which is Awesome!
 * 
 * Analog pins will be 3, 4 and 5 for switches, wah and volume respectively.
 * The LED output will go to digital pin 8 (but it can be any from 8 to 13 since I'm using a method I stole
 * from the internet -don't remember where, sorry- for writing faster than digitalWrite in which all digital
 * output is written to all those pins.)
 *
 * A quick tip:
 * Take a Cat5 cable and cut one end, just to lose the connector, then strip like 1/4" from each wire.
 * You can easily use this wires with a protoboard to connect with your arduino, and use the connector in
 * the other end and plug your floorboard.
 */

// This are the analog pins, used for the switches and expression pedals.
const int pinSw  = 3; // to pin 6 in the RJ45 connector
const int pinWah = 4; // to pin 2 in the RJ45 ...
const int pinVol = 5; // to 4 in ...
const int pinLED = 8;

// This constants are the bit positions for each of the LEDs.
const int DIST  = (8*0)+7;
const int DOWN  = (8*1)+7; 
const int POINT = (8*2)+7;
const int TAP   = (8*3)+7;
const int WAH   = (8*3)+6;
const int SEL   = (8*3)+5;
const int DRV   = (8*3)+4;
const int CHD   = (8*3)+3;
const int CHC   = (8*3)+2;
const int CHB   = (8*3)+1;
const int CHA   = (8*3)+0;

// I made a fancy presentation and use this variable to run it only the first time I engage the thing.
bool presentation;

// We use these to remember what input we had in the previous read.
byte swValue  = 0;
byte volValue = 0;
byte wahValue = 0;

// We have to move all the foot to calibrate the wah 
int readBounds[2][2] = {{420,780},{380,780}};

// Smoothing the expression pedals
const int numReadings = 6;

// We use arrays of 2 because that's the number of variable resistors we have
int readings[2][numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int readTotal[2];                  // the running total
int readAverage[2];                // the average


// We use these to eliminate bouncing (stolen from here: https://www.arduino.cc/en/Tutorial/Debounce)
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin
// the following variables are unsigned long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

// The values of each LED are stored here.
byte leds[] = {0,0,0,0};

// This is the character map for the LCD display
// Source: http://harmonicappliances.com/floorboard/floorboard.html
byte digit[255];
void initChars() {
  digit['A'] = B11101110;
  digit['B'] = B00111110;
  digit['C'] = B10011100;
  digit['D'] = B01111010;
  digit['E'] = B10011110;
  digit['F'] = B10001110;
  digit['G'] = B11110110;
  digit['H'] = B01101110;
  digit['I'] = B00001100;
  digit['J'] = B01111000;
  digit['k'] = B01001110;
  digit['L'] = B00011100;
  digit['M'] = B10101000;
  digit['N'] = B00101010;
  digit['O'] = B00111010;
  digit['P'] = B11001110;
  digit['Q'] = B11100110;
  digit['R'] = B00001010;
  digit['S'] = B10110110;
  digit['T'] = B00011110;
  digit['U'] = B01111100;
  digit['V'] = B00111000;
  digit['W'] = B01010100;
  digit['X'] = B01011110;
  digit['Y'] = B01110110;
  digit['Z'] = B10011010;
  digit['-'] = B00000010;
  digit['_'] = B00010000;
  digit['0'] = B11111100;
  digit['1'] = B01100000;
  digit['2'] = B11011010;
  digit['3'] = B11110010;
  digit['4'] = B01100110;
  digit['5'] = B10110110;
  digit['6'] = B10111110;
  digit['7'] = B11100000;
  digit['8'] = B11111110;
  digit['9'] = B11110110;
}

void sendPulses() {
  for (int i = 0; i< 32; i++) {
      // We always send one on and one off for each led or display segment.
    // The duration of each pulse tells the floorboard if the led is on or off.
    byte time1 = ((leds[i/8]>>(i%8))&1) ? 2 : 5;
    byte time2 = 6 - time1;

    digitalWriteFast(pinLED, HIGH);
    //digitalWrite(pinLED, HIGH);
    delayMicroseconds(time1);
    digitalWriteFast(pinLED, LOW);
    //digitalWrite(pinLED, LOW);
    delayMicroseconds(time2);
  }
}


void debugPulses() {
  Serial.println("DEBUG PULSES START");
  
  for (int i = 0; i< 32; i++) {
      // We always send one on and one off for each led or display segment.
    // The duration of each pulse tells the floorboard if the led is on or off.
    byte time1 = ((leds[i/8]>>(i%8))&1) ? 1 : 5;
    byte time2 = 6 - time1;

    //Serial.print("time1: ");
    //Serial.println(time1);

    //Serial.print("time2: ");
    //Serial.println(time2);
    Serial.print(time1 == 5 ? "0" : "1");
  }
      Serial.println();

  Serial.println("DEBUG PULSES END");
}

// Sets the char chr in the pos position of the 3 char display
void setChar(char chr, int pos) {
  leds[pos] = (leds[pos] & 1) | digit[chr];
}

// Update a LED
void writeLed(int pos, bool val) {
  int byt = floor(pos / 8);
  int shft  = pos % 8;
  byte msk = ~(1<<(7-shft));
  leds[byt] = (leds[byt] & msk) | (val<<(7-shft));
  sendPulses();
}

// Puts the first 3 chars of the string on the 3-digit display
void writeScreen(String text) {
  for(int i = 0; i<3; i++) {
    if (i+1>text.length()) {
      setChar(0,i);   
    } else {
      setChar(text.charAt(2-i),i);
    }
  }
 sendPulses();
}

// My fancy 3-digit-7-segment-only-numbers-and-some-letters-marquee function
void typeText (String str, int repeat, byte spd) {
  String  newText = "   " + str + "   ";
  newText.toUpperCase();
  int ms = map(spd, 0, 255, 1000, 50);
  for (int i = 0; i < repeat; i++) {
    for (int chr = 0; chr < str.length()+3; chr++) {
      String segment = newText.substring(chr, chr+3);
      writeScreen(segment);
      Serial.println(segment);
      delay(ms);
    }
  }
  writeScreen("   ");
}

void setup() {
  // Initialize fast digital write, needed for sending the LED pulses.
  DDRB = 255;
  pinModeFast(pinLED, OUTPUT);
  //pinMode(pinLED, OUTPUT);
  pinMode(pinSw, INPUT);
  initChars();
  presentation = 1;
  Serial.begin(9600);
  // initialize all the readings to 0:
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[0][thisReading] = 0;
    readings[1][thisReading] = 0;
  }
}

// All switches use the same analog input but with different resistance values, 
// so we have a different voltage for each switch
byte buttonValue2(int value) {
  if (value < 50) 
    return 8;    // TAP BUTTON
  if (value < 130) 
    return 7; // CHANNEL SELECT
  if (value < 250) 
    return 9; // WAH
  if (value < 350) 
    return 3; // CHANNEL A
  if (value < 430)
    return 4; // CHANNEL B
  if (value < 500)
    return 5; // CHANNEL C
  if (value < 600)
    return 6; // CHANNEL D
  if (value < 780)
    return 10; // PRESET ( UP + DOWN)
  if (value < 830)
    return 2; // UP
  if (value < 880)
    return 1; // DOWN
   return 0; // NO BUTTON PRESSED
}

byte buttonValue(int value) {
  #define CHECK(V) (abs(value - V) < 3)
  
  if (CHECK(85)) return DOWN;
  if (CHECK(37)) return DIST;
  if (CHECK(99)) return DRV;
  
  return 0; // NO BUTTON PRESSED
  #undef CHECK
}

// I made this function at the begining for testing the LEDS, but I liked so much that 
// I left it here and use it as part fancy presentation.
void test(bool val) {
  int dl=80;
  writeLed(DIST, val);
  delay(dl);
  writeLed(DOWN, val);
  delay(dl);
  writeLed(POINT, val);
  delay(dl);
  writeLed(TAP, val);
  delay(dl);
  writeLed(WAH, val);
  delay(dl);
  writeLed(SEL, val);
  delay(dl);
  writeLed(DRV, val);
  delay(dl);
  writeLed(CHD, val);
  delay(dl);
  writeLed(CHC, val);
  delay(dl);
  writeLed(CHB, val);
  delay(dl);
  writeLed(CHA,val);
}

byte parseFromMax(byte data) {
  // Digits in max are represented with their ASCII value, the floorboard uses a lcd segment
  // map described in the document linked in the description at the top of this file.
  return digit[data & ~(128)] | data>>7;
}

void badassPresentation() {
    test(1);
    test(0);
    typeText("IMBIREk JEST NAJLEPSZY", 1, 220);
    test(1);
    test(0);
}

int smooth(int pos, int value) {
  value = constrain(map(value, readBounds[pos][0], readBounds[pos][1], 0, 255), 0, 255);
  readTotal[pos] = readTotal[pos] - readings[pos][readIndex];
  readTotal[pos] += value;
  readings[pos][readIndex] = value;
  readAverage[pos] = readTotal[pos] / numReadings;
  return readAverage[pos];
}

int lastReadSw;

void loop() {
  //Serial.println("loop");
  if (presentation) {
    presentation = false;
    Serial.println("presentation");
    //test(true);
  }
  
  writeLed(POINT, false);  
  writeScreen("CAT");


  byte readSw = analogRead(pinSw);  
  //Serial.println(readSw);
  if (abs(lastReadSw - readSw) < 3) {
    // successful press

    int bv = buttonValue(readSw);
    if (bv) {
      writeLed(bv, true);  
    }
  }
  lastReadSw = readSw;

  delay(10);
}


void loop2() {
  // My badass presentation!!!
  if (presentation) {
    presentation = 0;
    badassPresentation();
  }
  
  // Start reading the analog inputs.
  byte readSw = buttonValue(analogRead(pinSw));  
  
  byte byteWah = 0;//smooth(0,analogRead(pinWah));
  byte byteVol = 0;//smooth(1,analogRead(pinVol));
  readIndex = readIndex + 1 == numReadings ? 0 : readIndex + 1;
  
  // And again, All of this debouncing stuff was taken from here:
  //   https://www.arduino.cc/en/Tutorial/Debounce
  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH),  and you've waited
  // long enough since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (readSw != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay){
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:

    // if the button state has changed
    if (readSw != buttonState) {
      // only toggle the LED if the new button state is HIGH
      buttonState = readSw;
    }
  }

  // save the reading.  Next time through the loop,
  // it'll be the lastButtonState:
  lastButtonState = readSw;

  // Now if somenthing changed since the last time we proceed to process the input data.
  if ((byteVol != volValue) || (byteWah != wahValue) || (buttonState != swValue)) {
    // update the globals, to remember the nex time.
    wahValue = byteWah;
    volValue = byteVol;
    swValue  = buttonState;
    
    // With this I can send the three input bytes to the serial port, which i happen to read back  there on Max7
    Serial.print(swValue);
    Serial.print(" ");
    Serial.print(wahValue);
    Serial.print(" ");
    Serial.println(volValue);
    delay(20);
    
  }

  // Check if we have input in the serial port
  if (Serial.available()) {
    // Led info is represented in 4 bytes
    char buf[4];
    Serial.readBytes(buf, 4);
    leds[0] = parseFromMax(buf[0]);
    leds[1] = parseFromMax(buf[1]);
    leds[2] = parseFromMax(buf[2]);
    leds[3] = buf[3];
    // Finally send all these bits as a pulse train to the floorboard.
    sendPulses();
  }
}
