#include <Arduino_APDS9960.h>

volatile unsigned long objectCount = 0;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  if (!APDS.begin()) {
    Serial.println("APDS9960 Error");
    while (1);
  }

  Serial.println("Counter Started");
}

void loop() {
  static bool detected = false;

  if (APDS.proximityAvailable()) {
    int proximity = APDS.readProximity();

    if (proximity > 200 && !detected) {
      objectCount++;
      detected = true;
      Serial.print("Count = ");
      Serial.println(objectCount);
    }

    if (proximity < 150) {
      detected = false;
    }
  }
}