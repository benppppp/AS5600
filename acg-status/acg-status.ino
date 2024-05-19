#include <Wire.h>

void setup() {
  Wire.begin();
  Serial.begin(115200);
  Serial.println("ok");
}

void loop() {
  Wire.beginTransmission(0x36);  //Transmission à l'esclave d'adresse 0x36
  Wire.write(0x0B);
  Wire.endTransmission();
  Wire.requestFrom(0x36, 1);
  byte Status = Wire.read() << 2;
  Status = Status >> 5;  // ne conserver que les 3 bits centraux

  Wire.beginTransmission(0x36);
  Wire.write(0x1A);
  Wire.endTransmission();
  Wire.requestFrom(0x36, 1);
  int Acg = Wire.read();

  Serial.print("Status:");    //3 bits:présence d'aimant=1,trop loin=1, trop près=1
  Serial.print(Status, BIN);  //Le bon réglage doit etre 100
  Serial.print(" ACG");       //ACG doit etre entre 1 et 127 pour une distance correcte de l'aimant
  Serial.println(Acg);
}