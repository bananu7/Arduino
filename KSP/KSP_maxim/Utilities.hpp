#pragma once

#include "Structure.h"

inline void Indicators(VesselData const& VData) {
    int caution = 0;
    int warning = 0;

    caution += VData.G > GCAUTION;
    warning += VData.G > GWARN;
    caution += VData.LiquidFuelS/VData.LiquidFuelTotS*100 < FUELCAUTION;
    warning += VData.LiquidFuelS/VData.LiquidFuelTotS*100 < FUELWARN;

    if (caution != 0)
        digitalWrite(YLED,HIGH);
    else
        digitalWrite(YLED,LOW);

    if (warning != 0)
        digitalWrite(RLED,HIGH);
    else
        digitalWrite(RLED,LOW);

    //digitalWrite(SASLED, VData.getControlStatus(AGSAS));
    digitalWrite(RCSLED, VData.getControlStatus(AGRCS));
    //digitalWrite(CG1LED, VData.getControlStatus(AGCustom01));
}

inline void initLEDS() {
    pinMode(GLED,OUTPUT);
    digitalWrite(GLED,HIGH);

    pinMode(YLED,OUTPUT);
    digitalWrite(YLED,HIGH);

    pinMode(RLED,OUTPUT);
    digitalWrite(RLED,HIGH);

    //pinMode(SASLED,OUTPUT);
    //digitalWrite(SASLED,HIGH);

    pinMode(RCSLED,OUTPUT);
    digitalWrite(RCSLED,HIGH);

    //pinMode(CG1LED,OUTPUT);
    //digitalWrite(CG1LED,HIGH);
}

inline void LEDSAllOff() {
    digitalWrite(GLED,LOW);
    digitalWrite(YLED,LOW);
    digitalWrite(RLED,LOW);
    //digitalWrite(SASLED,LOW);
    digitalWrite(RCSLED,LOW);
    //digitalWrite(CG1LED,LOW);
}
