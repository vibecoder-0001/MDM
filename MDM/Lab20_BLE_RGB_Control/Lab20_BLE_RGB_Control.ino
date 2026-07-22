#include <Arduino.h>
#include <HardwareBLESerial.h>

HardwareBLESerial &bleSerial = HardwareBLESerial::getInstance();

//#define LED_PIN LED_BUILTIN
#define RED LEDR
#define BLUE LEDB

char receivedint;

void setup() {
  Serial.begin(9600);

  pinMode(RED,OUTPUT);
  pinMode(BLUE,OUTPUT);
  digitalWrite(RED,HIGH);
  digitalWrite(BLUE,HIGH);   // LED OFF (may need HIGH for Nano 33 BLE)

  while (!bleSerial.beginAndSetupBLE("Bluetooth"));

  Serial.println("BLE LED Control Ready");
  bleSerial.println("Connected!");
  bleSerial.println("Send 1 -> LED RED ON");
  bleSerial.println("Send 2 -> LED BLUE ON");
  bleSerial.println("Send 3 -> LED OFF");
}

void loop() {

  // Keep BLE connection alive
  bleSerial.poll();

  // Check if data is received over BLE
  if (bleSerial.available()) {

    receivedint = bleSerial.read();

    Serial.print("Received: ");
    Serial.println(receivedint);

    if (receivedint =='1') {

      digitalWrite(RED, LOW);
      digitalWrite(BLUE, HIGH);   // ON
      bleSerial.println("RED LED ON");
      Serial.println("RED LED ON");

    }
    else if (receivedint == '2') {

      digitalWrite(BLUE, LOW);
      digitalWrite(RED, HIGH);     // OFF
      bleSerial.println("BLUE LED ON");
      Serial.println("BLUE LED ON");

    }
    else if (receivedint == '3'){
      digitalWrite(BLUE, LOW);
      digitalWrite(RED, LOW);
      bleSerial.println("LED TURNED OFF");
      Serial.println("LED TURNED OFF");
    }
    else {

      bleSerial.println("Invalid Command");
      Serial.println("Invalid Command");

    }
  }
}