#include "Arduino.h"

#define LIGHT_SENSOR_PIN 33
#define YELLOW_LED_PIN   12
#define BUTTON_PIN       25
#define FLASH_MS         100

int lastButtonReading = LOW;
int stableButtonState = LOW;
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50; // ms

void setup(void)
{
    Serial.begin(115200);
    pinMode(YELLOW_LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT);
    digitalWrite(YELLOW_LED_PIN, LOW);
}


void loop(void)
{
    int reading = digitalRead(BUTTON_PIN);

    if (reading != lastButtonReading) {
        lastDebounceTime = millis();
    }

    if ((millis() - lastDebounceTime) > debounceDelay) {
        if (reading != stableButtonState) {
            stableButtonState = reading;

            // take a snapshot only on the press edge (LOW -> HIGH)
            if (stableButtonState == HIGH) {
                int snapshot = analogRead(LIGHT_SENSOR_PIN);
                Serial.print("snapshot=");
                Serial.println(snapshot);

                digitalWrite(YELLOW_LED_PIN, HIGH);
                delay(FLASH_MS);
                digitalWrite(YELLOW_LED_PIN, LOW);
            }
        }
    }

    lastButtonReading = reading;
}
