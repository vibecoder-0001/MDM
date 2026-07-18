#include <nrfx.h>

volatile bool toggleLED = false;

extern "C" void TIMER1_IRQHandler(void)
{
  if (NRF_TIMER1->EVENTS_COMPARE[0]) {
    NRF_TIMER1->EVENTS_COMPARE[0] = 0;
    toggleLED = true;
  }
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);

  NRF_TIMER1->MODE = TIMER_MODE_MODE_Timer;
  NRF_TIMER1->BITMODE = TIMER_BITMODE_BITMODE_32Bit;
  NRF_TIMER1->PRESCALER = 4;      // 1 MHz
  NRF_TIMER1->CC[0] = 1000000;    // 1 second
  NRF_TIMER1->SHORTS = TIMER_SHORTS_COMPARE0_CLEAR_Msk;
  NRF_TIMER1->INTENSET = TIMER_INTENSET_COMPARE0_Msk;

  NVIC_EnableIRQ(TIMER1_IRQn);
  NRF_TIMER1->TASKS_START = 1;
}

void loop() {
  if (toggleLED) {
    toggleLED = false;
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  }
}