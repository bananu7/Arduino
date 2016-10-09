#pragma once

class GameConnection {
    unsigned long deadtime, deadtimeOld, controlTime, controlTimeOld;
    unsigned long now;

    boolean Connected = false;

    byte caution = 0, warning = 0, id;

    HandShakePacket HPacket;
    VesselData VData;
    ControlPacket CPacket;

    void setup() {
      Serial.begin(38400);

      initLEDS();
      InitTxPackets();
      controlsInit();

      LEDSAllOff();
    }

    void loop()
    {
      input();
      output();
    }
};