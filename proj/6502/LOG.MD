# "The Litre" build log

### 2020-11-07

I'm starting the log to hopefully make it a new tradition for those projects. So far, I've ordered a few parts, which I've added to the readme.

I found a number of interesting resources so far for the build. The most notable one is the ["Veronica" PC](https://blondihacks.com/veronica-cpu-board/), done almost exactly like I wanted to, also utilizing a passive backplane with 8-bit ISA slots.

### 2020-11-10

I created a first breadboard prototype with just the chip and an Arduino Mega. I used Ben's code for logging the bus. I had no hardware clock, so I decided to use the mega pin to generate it like so:

    digitalWrite(CLOCK, LOW);
    delayMicroseconds(1);
    digitalWrite(CLOCK, HIGH);
    
The clock needs to be kept high when waiting, but that allows a regular old 6502 (not the 65c02 version) to be single-stepped just fine. I had a few issues when I mixed up the bit order for the buses (`A0` and `D0` are LSB), and offset the data pins by one. Then when it still didn't work, I replaced the CPU with another copy, which improved things a bit. At the end it turned out that I just didn't push it into the breadboard enough. Oh well... Anyway, here's a successful log:

    1111000110110010   11101010   f1b2  r ea
    1111000110110011   11101010   f1b3  r ea
    1111000110110011   11101010   f1b3  r ea
    1111000110110100   11101010   f1b4  r ea
    1111000110110100   11101010   f1b4  r ea
    1111000110110100   11101010   f1b4  r ea
    1111000110110100   11101010   f1b4  r ea
    0000000111110001   11101010   01f1  r ea
    0000000111110000   11101010   01f0  r ea
    0000000111101111   11101010   01ef  r ea
    1111111111111100   11101010   fffc  r ea
    1111111111111101   11101010   fffd  r ea
    1110101011101010   11101010   eaea  r ea
    1110101011101011   11101010   eaeb  r ea
    1110101011101011   11101010   eaeb  r ea
    1110101011101100   11101010   eaec  r ea
    1110101011101100   11101010   eaec  r ea
    1110101011101101   11101010   eaed  r ea
    1110101011101101   11101010   eaed  r ea
