#include <Arduino.h>

#include "GameConnection.hpp"

GameConnection gc;

void setup() {
    gc.setup();
}

void loop() {
    gc.update();
}
