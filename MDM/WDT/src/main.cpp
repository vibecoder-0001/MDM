#include <Arduino.h>

// Feed the watchdog
void feedWatchdog()
{
    NRF_WDT->RR[0] = WDT_RR_RR_Reload;
}

void setup()
{
    Serial.begin(115200);

    while (!Serial);

    Serial.println("\n==========");
    Serial.println("System Started");
    Serial.println("==========");

    // Configure watchdog timeout (~4 seconds)
    NRF_WDT->CRV = 4 * 32768;

    // Enable Reload Register 0
    NRF_WDT->RREN = WDT_RREN_RR0_Msk;

    // Start Watchdog
    NRF_WDT->TASKS_START = 1;
}

void loop()
{
    static unsigned long startTime = millis();

    if (millis() - startTime < 10000)
    {
        Serial.println("Feeding Watchdog...");
        feedWatchdog();
        delay(1000);
    }
    else
    {
        Serial.println();
        Serial.println("Simulating Software Hang...");
        Serial.println("Watchdog will reset the board in about 4 seconds.");

        while (true)
        {
            // Do NOT feed watchdog
        }
    }
} 