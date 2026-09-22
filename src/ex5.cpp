#include "Arduino.h"

#define BUTTON_PIN 25
#define LIGHT_PIN 33
#define YELLOW_LED_PIN 12

bool lastButtonState = LOW;

void setup(void)
{
    pinMode(BUTTON_PIN, INPUT);
    pinMode(LIGHT_PIN, INPUT);
    pinMode(YELLOW_LED_PIN, OUTPUT);
    digitalWrite(YELLOW_LED_PIN, LOW);
    Serial.begin(115200);
}

void loop(void)
{
    bool buttonState = digitalRead(BUTTON_PIN);

    if (buttonState == HIGH && lastButtonState == LOW)
    {
        int raw = analogRead(LIGHT_PIN);
        Serial.print("snapshot=");
        Serial.println(raw);

        digitalWrite(YELLOW_LED_PIN, HIGH);
        delay(100);
        digitalWrite(YELLOW_LED_PIN, LOW);
    }

    lastButtonState = buttonState;
}
