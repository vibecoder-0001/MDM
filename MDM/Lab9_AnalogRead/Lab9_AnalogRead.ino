void setup(){
  Serial.begin(9600);
}
void loop(){
  int sensorValue=analogRead(A6);
  Serial.print("Analog Value = ");
  Serial.println(sensorValue);
  delay(200);
}