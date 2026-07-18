void setup() {
  Serial.begin(9600);
  while (!Serial);
  Serial.println("================================");
  Serial.println("Arduino Nano 33 BLE Sense Ready");
  Serial.println("Configuration Successful!");
  Serial.println("================================");
}
void loop() {}