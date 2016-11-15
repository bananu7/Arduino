#include <Arduino.h>

#include <Communication.h>
#include <Maxim.h>
#include <HD44780.h>

int main(void)
{
	init();

  #if defined(USBCON)
  	USB.attach();
  #endif

  // setup
  //LedPanel<10>* panel;
  using Pins = comm::MultiplexLatcherPins<2,3,4>;

  int hour = 1;
  int minute = 00;
  int second = 0;
  auto m = maxim::Maxim(make_sender(comm::HardwareSpi(), comm::MultiplexLatcher<4, Pins::pins>()));

  // loop
  while(true) {
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

    m.writeNumber(hour * 100 + minute, 0);
    m.writeNumber(second, 1);

    delay(1000);
    /*panel->data(false, false, false, false, false, false);
    panel->present();
    delay(500);
    panel->data(false, false, false, false, true, true);
    panel->present();
    delay(500);*/

		if (serialEventRun) serialEventRun();
	}

	return 0;
}
