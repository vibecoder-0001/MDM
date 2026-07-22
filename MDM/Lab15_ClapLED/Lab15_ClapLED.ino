#include <PDM.h>

#define RED   LEDR
#define GREEN LEDG
#define BLUE  LEDB

short sampleBuffer[256];
volatile int samplesRead = 0;

const int THRESHOLD = 300;   // Adjust this value if needed

// Callback function for PDM microphone
void onPDMdata()
{
  int bytesAvailable = PDM.available();
  PDM.read(sampleBuffer, bytesAvailable);
  samplesRead = bytesAvailable / 2;
}

void setup()
{
  Serial.begin(115200);
  while (!Serial);

  // RGB LED pins
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

  // Default: Red ON, Green OFF, Blue OFF
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, HIGH);

  // Initialize microphone
  PDM.onReceive(onPDMdata);

  if (!PDM.begin(1, 16000)) {
    Serial.println("Failed to start PDM microphone!");
    while (1);
  }

  Serial.println("Sound Threshold LED Control Started");
}

void loop()
{
  if (samplesRead) {

    long sum = 0;

    for (int i = 0; i < samplesRead; i++) {
      sum += abs(sampleBuffer[i]);
    }

    int soundLevel = sum / samplesRead;

    Serial.print("Sound Level: ");
    Serial.println(soundLevel);

    if (soundLevel > THRESHOLD) {
      // Green ON
      digitalWrite(RED, HIGH);
      digitalWrite(GREEN, LOW);
    }
    else {
      // Red ON
      digitalWrite(RED, LOW);
      digitalWrite(GREEN, HIGH);
    }

    samplesRead = 0;
  }
}
