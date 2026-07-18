#include <PDM.h>

short sampleBuffer[256];
volatile int samplesRead=0;

void onPDMdata(){
  int bytesAvailable=PDM.available();
  PDM.read(sampleBuffer,bytesAvailable);
  samplesRead=bytesAvailable/2;
}

void setup(){
  Serial.begin(115200);
  while(!Serial);
  PDM.onReceive(onPDMdata);
  PDM.begin(1,16000);
}

void loop(){
  if(samplesRead){
    long sum=0;
    for(int i=0;i<samplesRead;i++) sum+=abs(sampleBuffer[i]);
    Serial.println(sum/samplesRead);
    samplesRead=0;
  }
}