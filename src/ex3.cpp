#include "Arduino.h"

#define LIGHT_PIN 33

unsigned long lastRead = 0;

void setup(void)
{
    pinMode(LIGHT_PIN, INPUT);
    Serial.begin(115200);
}

void loop(void)
{
    unsigned long now = millis();

    if (now - lastRead >= 500)
    {
        lastRead = now;
        int raw = analogRead(LIGHT_PIN);
        Serial.print("raw=");
        Serial.println(raw);
    }
}
