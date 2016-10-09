#pragma once

class GameConnection {
    unsigned long deadtime, deadtimeOld, controlTime, controlTimeOld;
    unsigned long now;

    boolean Connected = false;

    byte caution = 0, warning = 0, id;

    HandShakePacket HPacket;
    VesselData VData;
    ControlPacket CPacket;

    SerialComs comm;

    int input() {
        int returnValue = -1;
        now = millis();

        if (KSPBoardReceiveData()) {
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
            Connected = true;
        }
        else { //if no message received for a while, go idle
            deadtime = now - deadtimeOld; 
            if (deadtime > IDLETIMER) {
                deadtimeOld = now;
                Connected = false;
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
        if (connected) {
            if (digitalRead(SASPIN))  //--------- This is how you do main controls
                MainControls(SAS, HIGH);
            else
                MainControls(SAS, LOW);

            if (digitalRead(RCSPIN))
                MainControls(RCS, HIGH);
            else
                MainControls(RCS, LOW);

            if (digitalRead(CG1PIN))   //--------- This is how you do control groups
                ControlGroups(1, HIGH);
            else
                ControlGroups(1, LOW);      

            //This is an example of reading analog inputs to an axis, with deadband and limits
            CPacket.Throttle = constrain(map(analogRead(THROTTLEPIN),THROTTLEDB,1024-THROTTLEDB,0,1000),0, 1000);

            KSPBoardSendData(details(CPacket));
        }
    }

    void controlsInit() {
        pinMode(SASPIN, INPUT_PULLUP);
        pinMode(RCSPIN, INPUT_PULLUP);
        pinMode(CG1PIN, INPUT_PULLUP);
    }

    void mainControls(byte n, boolean s) {
        if (s)
            CPacket.MainControls |= (1 << n);       // forces nth bit of x to be 1.  all other bits left alone.
        else
            CPacket.MainControls &= ~(1 << n);      // forces nth bit of x to be 0.  all other bits left alone.
    }

    void controlGroups(byte n, boolean s) {
        if (s)
            CPacket.ControlGroup |= (1 << n);       // forces nth bit of x to be 1.  all other bits left alone.
        else
            CPacket.ControlGroup &= ~(1 << n);      // forces nth bit of x to be 0.  all other bits left alone.
    }

    byte getControlStatus(byte n) {
        return ((VData.ActionGroups >> n) & 1) == 1;
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
