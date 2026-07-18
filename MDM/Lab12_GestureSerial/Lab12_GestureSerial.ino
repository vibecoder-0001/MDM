#include <Arduino_APDS9960.h>

void setup() {
  Serial.begin(9600);
  while (!Serial);
  APDS.begin();
}

void loop() {
  if (APDS.gestureAvailable()) {
    Serial.print("Gesture: ");
    Serial.println(APDS.readGesture());
  }
}