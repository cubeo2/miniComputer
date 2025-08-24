#include <Config.h>
#include <Debug.h>
#include <test_SCREEN.h>

byte frames[] = {
    0b11001000,
    0b10010100,
    0b00010010,
    0b11110001
};

// 0b00001000, 0b00000100, 0b00000010, 0b00000001
int frameTime = 500;
Frame animation[] = {
    {{0b11111000, 0b10010100, 0b10010010, 0b11110001}, frameTime},
    {{0b11111000, 0b11110100, 0b11110010, 0b11110001}, frameTime},
    {{0b00001000, 0b01100100, 0b01100010, 0b00000001}, frameTime},
    {{0b00001000, 0b00000100, 0b00000010, 0b00000001}, frameTime}
};


byte state = 0;

void setup() {
  serialOn();
  serialLog("Setup started...");  
  memoryInit();
  screenSetup();
  serialLog("Setup completed.");

  // memoryWrite("test.txt", "Hello, World!");
}

void updateScreen() {
  // Update the screen with the current state
  // should possibly calculate a couple a couple of frames, maybe a lot?
  // Maybe another chip maintains the visual output until next time the method is called

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

  serialLog("Loop started...");
  printIage64Test();
  // printImage(frames);
  // delay(1000); // Delay to visualize the output
  // size_t frameCount = sizeof(animation) / sizeof(animation[0]);
  // animate(animation, frameCount);

}



