void Indicators() {
  caution = 0;
  warning = 0;

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
    
  digitalWrite(SASLED,ControlStatus(AGSAS));
  digitalWrite(RCSLED,ControlStatus(AGRCS));
  digitalWrite(CG1LED,ControlStatus(AGCustom01));
}

void initLEDS() {
  pinMode(GLED,OUTPUT);
  digitalWrite(GLED,HIGH);

  pinMode(YLED,OUTPUT);
  digitalWrite(YLED,HIGH);

  pinMode(RLED,OUTPUT);
  digitalWrite(RLED,HIGH);
  
  pinMode(SASLED,OUTPUT);
  digitalWrite(SASLED,HIGH);
  
  pinMode(RCSLED,OUTPUT);
  digitalWrite(RCSLED,HIGH);
  
  pinMode(CG1LED,OUTPUT);
  digitalWrite(CG1LED,HIGH);
}

void LEDSAllOff() {
  digitalWrite(GLED,LOW);
  digitalWrite(YLED,LOW);
  digitalWrite(RLED,LOW);
  digitalWrite(SASLED,LOW);
  digitalWrite(RCSLED,LOW);
  digitalWrite(CG1LED,LOW);
}


void InitTxPackets() {
  HPacket.id = 0;  
  CPacket.id = 101;
}







