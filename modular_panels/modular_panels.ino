#include "Panel.hpp"

LedPanel<10>* panel;

void setup() {
    panel = new LedPanel<10>();
}

void loop() {
    panel->data(false, false, false, false, false, false);
    panel->present();
    delay(500);
    panel->data(false, false, false, false, true, true);
    panel->present();
    delay(500);
}
