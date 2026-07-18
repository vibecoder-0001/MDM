#include <Arduino_LSM9DS1.h>
#define RED LEDR
#define GREEN LEDG
#define BLUE LEDB

void setup(){
  pinMode(RED,OUTPUT);
  pinMode(GREEN,OUTPUT);
  pinMode(BLUE,OUTPUT);
  digitalWrite(RED,HIGH);
  digitalWrite(GREEN,HIGH);
  digitalWrite(BLUE,HIGH);
  Serial.begin(9600);
  while(!Serial);
  if(!IMU.begin()){
    Serial.println("IMU Failed");
    while(1);
  }
}

void loop(){
  float x,y,z;
  if(IMU.accelerationAvailable()){
    IMU.readAcceleration(x,y,z);
    digitalWrite(RED,HIGH);
    digitalWrite(GREEN,HIGH);
    digitalWrite(BLUE,HIGH);
    if(x>0.5) digitalWrite(RED,LOW);
    else if(x<-0.5) digitalWrite(BLUE,LOW);
    else digitalWrite(GREEN,LOW);
    delay(200);
  }
}