#include "DHT.h"

#define PIN_LED_RED 32
#define PIN_LED_WHITE 33
#define PIN_SENSORS 26
#define PIN_BUTTON 27

#define DHTTYPE DHT11
int buttonState = 0;

DHT dht(PIN_SENSORS, DHTTYPE);

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(PIN_LED_RED, OUTPUT);
  pinMode(PIN_LED_WHITE, OUTPUT);
  pinMode(PIN_SENSORS, INPUT);
  pinMode(PIN_BUTTON, INPUT);

  Serial.begin(9600);

  dht.begin();
}

// the loop function runs over and over again forever
void loop() {
  buttonState = digitalRead(PIN_BUTTON);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(PIN_LED_WHITE, HIGH);
    digitalWrite(PIN_LED_RED, HIGH);
  } else {
    // turn LED off:
    digitalWrite(PIN_LED_WHITE, LOW);
    digitalWrite(PIN_LED_RED, LOW);
  }

  Serial.println("Temperature = " + String(dht.readTemperature())+" °C");
  Serial.println("Humidite = " + String(dht.readHumidity())+" %");

}
