#include <config.h>
#include <Audio.h>

int speakerPin = 9;   // drives transistor
int analogPin = A0;   // reads resistor/pot

void setup() {
  pinMode(speakerPin, OUTPUT);
  Serial.begin(9600); // optional for debugging
}

void loop() {
  int sensorValue = analogRead(analogPin); // 0–1023
  Serial.println(sensorValue); // optional: see readings

  // Map analog value to frequency (100 Hz – 2000 Hz)
  int freq = map(sensorValue, 0, 1023, 100, 2000);

  // Map analog value to duration (50 – 500 ms)
  int dur = map(sensorValue, 0, 1023, 50, 500);

  tone(speakerPin, freq, 300); // play tone
  delay(dur + 50);             // wait a bit before next tone
}
