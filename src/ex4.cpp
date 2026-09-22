#include "Arduino.h"

#define LIGHT_SENSOR_PIN 33
#define BLUE_LED_PIN   14
#define GREEN_LED_PIN  27
#define YELLOW_LED_PIN 12
#define RED_LED_PIN    26

unsigned long lastRead = 0;
const unsigned long interval = 500; // ms

void allLedsOff(void)
{
    digitalWrite(BLUE_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, LOW);
    digitalWrite(RED_LED_PIN, LOW);
}

/****************************************************/
void setup(void)
{
    Serial.begin(115200);
    pinMode(BLUE_LED_PIN, OUTPUT);
    pinMode(GREEN_LED_PIN, OUTPUT);
    pinMode(YELLOW_LED_PIN, OUTPUT);
    pinMode(RED_LED_PIN, OUTPUT);
    allLedsOff();
}


/****************************************************/
void loop(void)
{
    if (millis() - lastRead >= interval) {
        lastRead = millis();
        int raw = analogRead(LIGHT_SENSOR_PIN);

        allLedsOff();

        if (raw <= 1023) {
            digitalWrite(BLUE_LED_PIN, HIGH);
            Serial.println("band=BLUE");
        } else if (raw <= 2047) {
            digitalWrite(GREEN_LED_PIN, HIGH);
            Serial.println("band=GREEN");
        } else if (raw <= 3071) {
            digitalWrite(YELLOW_LED_PIN, HIGH);
            Serial.println("band=YELLOW");
        } else {
            digitalWrite(RED_LED_PIN, HIGH);
            Serial.println("band=RED");
        }
    }
}
