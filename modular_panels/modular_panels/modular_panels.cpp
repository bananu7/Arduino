//#include <Arduino.h>

#include <Communication.h>
#include <Maxim.h>
#include <SerialHD.hpp>

Maxim* m;
SerialHD* lcd;

int hour = 23;
int minute = 44;
int second = 45;

using Pins = comm::MultiplexLatcherPins<2,3,4>;

void setup() {
	  m = new Maxim(make_sender(comm::HardwareSpi(), comm::MultiplexLatcher<4, Pins::pins>()));

		delay(10);

		lcd = new SerialHD(make_sender(comm::HardwareSpi(), comm::MultiplexLatcher<6, Pins::pins>()));
		lcd->begin(16, 2);
		delay(10);

		//m->writeNumber(0, 0);
		//m->writeNumber(0, 1);
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

	m->writeNumber(second, 0);
	//m->writeNumber(hour * 100 + minute, 1);

	delay(1000);

	lcd->home();
	lcd->print("test");

	//m->writeNumber(second, 1);
}
