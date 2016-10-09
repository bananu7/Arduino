#pragma once

class GameConnection {
    unsigned long deadtime, deadtimeOld, controlTime, controlTimeOld;
    unsigned long now;

    boolean connected = false;

    byte caution = 0, warning = 0, id;

    HandShakePacket HPacket;
    VesselData VData;

    SerialComs comm;

    int input() {
        int returnValue = -1;
        now = millis();

        if (comm.KSPBoardReceiveData()) {
            deadtimeOld = now;
            returnValue = id;

            switch(id) {
            case 0: //Handshake packet
                Handshake();
                break;
            case 1:
                Indicators();
                break;
            }

            //We got some data, turn the green led on
            digitalWrite(GLED,HIGH);
            connected = true;
        }
        else { //if no message received for a while, go idle
            deadtime = now - deadtimeOld; 
            if (deadtime > IDLETIMER) {
                deadtimeOld = now;
                connected = false;
                LEDSAllOff();
            }    
        }

        return returnValue;
    }

    void output() {
        now = millis();
        controlTime = now - controlTimeOld; 
        if (controlTime > CONTROLREFRESH){
            controlTimeOld = now;
            controls();
        }
    }

    void controls() {
        ControlPacket controlPacket;

        static const int SASPIN = 8;
        static const int RCSPIN = 9;
        static const int CG1PIN = 10;
        static const int THROTTLEPIN = 0;

        if (connected) {
            if (digitalRead(SASPIN))  //--------- This is how you do main controls
                controlPacket.setMainControl(ControlElement::SAS, true);
            else
                controlPacket.setMainControl(ControlElement::SAS, false);

            if (digitalRead(RCSPIN))
                controlPacket.setMainControl(ControlElement::RCS, true);
            else
                controlPacket.setMainControl(ControlElement::RCS, false);

            if (digitalRead(CG1PIN))   //--------- This is how you do control groups
                controlPacket.setControlGroup(1, true);
            else
                controlPacket.setControlGroup(1, false);

            //This is an example of reading analog inputs to an axis, with deadband and limits
            controlPacket.Throttle = constrain(map(analogRead(THROTTLEPIN),THROTTLEDB,1024-THROTTLEDB,0,1000),0, 1000);

            comm.KSPBoardSendData(reinterpret_cast<uint8_t*>(&controlPacket), sizeof(controlPacket));
        }
    }

    void controlsInit() {
        pinMode(SASPIN, INPUT_PULLUP);
        pinMode(RCSPIN, INPUT_PULLUP);
        pinMode(CG1PIN, INPUT_PULLUP);
    }

    void setup() {
        Serial.begin(38400);

        initLEDS();
        InitTxPackets();
        controlsInit();

        LEDSAllOff();
    }

    void update()
    {
        input();
        output();
    }
};
