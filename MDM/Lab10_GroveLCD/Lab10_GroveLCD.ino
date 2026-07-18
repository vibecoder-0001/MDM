#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

void setup() {
  lcd.begin(16,2);
  lcd.setRGB(0,255,0);
  lcd.setCursor(0,0);
  lcd.print("Nano 33 BLE");
  lcd.setCursor(0,1);
  lcd.print("Lab 10");
}
void loop(){}