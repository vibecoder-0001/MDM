#include <Arduino_LSM9DS1.h>

void setup() {
  Serial.begin(9600);
  while (!Serial);
  if (!IMU.begin()) {
    Serial.println("IMU Error");
    while (1);
  }
}

void loop() {
  float x,y,z;
  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(x,y,z);
    if(x>0.5) Serial.println("Tilt Right");
    else if(x<-0.5) Serial.println("Tilt Left");
    else if(y>0.5) Serial.println("Tilt Forward");
    else if(y<-0.5) Serial.println("Tilt Backward");
    else Serial.println("Flat");
    delay(300);
  }
}