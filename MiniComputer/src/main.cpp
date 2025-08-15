#include <Arduino.h>
#include "screen/screen.h"

typedef uint8_t byte;

byte state = 0;

void setup() {
  Serial.begin(9600);

}

void updateScreen() {
  // Update the screen with the current state
  // should possibly calculate a couple a couple of frames, maybe a lot?
  // Maybe another chip maintains the visual output until next time the method is called
  test();
  Serial.println("Updating screen...");
} 
void handleInput() {
  // Handle input from the user
  Serial.println("Handling input...");
}
void updateAudio() {
  // maintain last sound state while other methods are called, using some buffer/chip
  // Update audio output
  Serial.println("Updating audio...");
}
void handleGameController() {
  // Handle game controller input
  Serial.println("Handling game controller...");
}

void loop() {

  handleInput();
  delay(1000);
  handleGameController();
    delay(1000);

  updateAudio();
    delay(1000);

  updateScreen();
    delay(1000);

}



