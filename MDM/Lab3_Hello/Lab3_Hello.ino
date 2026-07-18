void setup(){
  Serial.begin(9600);
  while(!Serial);
  Serial.println("Hello World!");
  Serial.println("Name : Hasnain");
}
void loop(){
  Serial.println("Arduino Nano 33 BLE Sense");
  delay(1000);
}