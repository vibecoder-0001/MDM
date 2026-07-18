#define LED_RED LEDR
#define LED_GREEN LEDG
#define LED_BLUE LEDB
void setup(){
 pinMode(LED_RED,OUTPUT);
 pinMode(LED_GREEN,OUTPUT);
 pinMode(LED_BLUE,OUTPUT);
}
void loop(){
 digitalWrite(LED_RED,LOW); digitalWrite(LED_GREEN,HIGH); digitalWrite(LED_BLUE,HIGH); delay(1000);
 digitalWrite(LED_RED,HIGH); digitalWrite(LED_GREEN,LOW); digitalWrite(LED_BLUE,HIGH); delay(1000);
 digitalWrite(LED_RED,HIGH); digitalWrite(LED_GREEN,HIGH); digitalWrite(LED_BLUE,LOW); delay(1000);
 digitalWrite(LED_RED,LOW); digitalWrite(LED_GREEN,LOW); digitalWrite(LED_BLUE,LOW); delay(1000);
 digitalWrite(LED_RED,HIGH); digitalWrite(LED_GREEN,HIGH); digitalWrite(LED_BLUE,HIGH); delay(1000);
}