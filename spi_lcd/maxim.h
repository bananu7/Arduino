#pragma once
#include <inttypes.h>

class Maxim {
public:
  static void writeNumber(int32_t number, int screen);
  static void setupMaxim();
};

void selectDevice(int n);
