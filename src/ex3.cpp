#include "Arduino.h"

#define LIGHT_SENSOR_PIN 33

unsigned long lastRead = 0;
const unsigned long interval = 500; // ms

void setup(void)
{
    Serial.begin(115200);
}


void loop(void)
{
    if (millis() - lastRead >= interval) {
        lastRead = millis();
        int raw = analogRead(LIGHT_SENSOR_PIN);
        Serial.print("raw=");
        Serial.println(raw);
    }
}
