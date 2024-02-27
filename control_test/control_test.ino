#include "DDCVCP.h"

DDCVCP ddc;

void setup()
{
    Serial.begin(9600);
    delay(2000); // Waiting for the Serial to ready
    while (!ddc.begin())
    {
        Serial.print(F("-  Unable to find DDC/CI. Trying again in 5 seconds.\n"));
        delay(5000);
    }
    Serial.print(F("-  Found DDC/CI successfully.\n"));
    delay(100);

    // Read current brightness
    Serial.print(F("-  Current brightness: "));
    Serial.println(ddc.getBrightness());
    delay(3000);

    Serial.println(F("-  Setting brightness to 10"));
    ddc.setBrightness(10);
    delay(3000);
    Serial.println(F("-  Setting brightness to 100"));
    ddc.setBrightness(100);
    delay(3000);
    Serial.println(F("-  Setting brightness to 50"));
    ddc.setBrightness(50);
    delay(3000);
}

void loop()
{
}
