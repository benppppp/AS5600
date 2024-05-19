#include <Wire.h>

void setup() {
  Wire.begin();
  Serial.begin(115200);
  Serial.println("ok");
}

void loop() {
  Wire.beginTransmission(0x36);
  Wire.write(0x0C);//registre RAW angle
  Wire.endTransmission();
  Wire.requestFrom(0x36, 2);
  unsigned int angle = Wire.read()<<8 | Wire.read();//mise des 2 octets d'adresse 0x0C et 0x0D dans l'entier angle
  Serial.print("angle: ");
  Serial.println(angle);
}