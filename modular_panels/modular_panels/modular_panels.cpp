#include <Arduino.h>

#include <Communication.h>
#include <Maxim.h>

//LedPanel<10>* panel;
using Pins = comm::MultiplexLatcherPins<2,3,4>;
Maxim<comm::Sender<comm::HardwareSpi, comm::MultiplexLatcher<4, Pins::pins>>>* maxim;

int hour = 1;
int minute = 00;
int second = 0;

void setup() {
    maxim = new Maxim<comm::Sender<comm::HardwareSpi, comm::MultiplexLatcher<4, Pins::pins>>>(make_sender(comm::HardwareSpi(), comm::MultiplexLatcher<4, Pins::pins>()));
}

void loop() {
    second += 1;
    if (second >= 60) {
        second = 0;
        minute += 1;
    }

    if (minute >= 60) {
        minute = 0;
        hour += 1;
    }

    if (hour >= 24) {
        hour = 0;
    }

    maxim->writeNumber(hour * 100 + minute, 0);
    maxim->writeNumber(second, 1);

    delay(1000);
    /*panel->data(false, false, false, false, false, false);
    panel->present();
    delay(500);
    panel->data(false, false, false, false, true, true);
    panel->present();
    delay(500);*/
}
