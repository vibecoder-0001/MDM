#include <Arduino_APDS9960.h>
#define RED LEDR
#define GREEN LEDG
#define BLUE LEDB

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  digitalWrite(RED,HIGH);
  digitalWrite(GREEN,HIGH);
  digitalWrite(BLUE,HIGH);
  Serial.begin(9600);
  while(!Serial);
  APDS.begin();
}

void loop() {
  if(APDS.proximityAvailable()){
    int proximity=APDS.readProximity();
    Serial.println(proximity);
    digitalWrite(RED,HIGH);
    digitalWrite(GREEN,HIGH);
    digitalWrite(BLUE,HIGH);
    if(proximity>200) digitalWrite(RED,LOW);
    else if(proximity>100) digitalWrite(GREEN,LOW);
    else digitalWrite(BLUE,LOW);
    delay(100);
  }
}