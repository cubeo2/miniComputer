#include <Config.h>
#include <Debug.h>
#include <test_SCREEN.h>

byte state = 0;

FileMeta file{"TEST.txt", 0};
Buffer buffer1;

void setup()
{
  serialOn();
  serialLog("Setup started...");
  memoryInit();
  screenSetup();
  serialLogLn("Setup completed.");
  serialLogLn("");
  // memoryWrite("test.txt", "Hello, World!");
}

// void updateScreen() {
//   // Update the screen with the current state
//   // should possibly calculate a couple a couple of frames, maybe a lot?
//   // Maybe another chip maintains the visual output until next time the method is called

//   Serial.println("Updating screen...");
// }
// void handleInput() {
//   // Handle input from the user
//   Serial.println("Handling input...");
// }
// void updateAudio() {
//   // maintain last sound state while other methods are called, using some buffer/chip
//   // Update audio output
//   Serial.println("Updating audio...");
// }
// void handleGameController() {
//   // Handle game controller input
//   Serial.println("Handling game controller...");
// }
bool first = true;
void loop()
{

  if (first)
  {
    memoryRead(buffer1, file);
    serialLogLn(buffer1.toString());
    first = false;
  }

  // serialLog("Loop started...");
  // printIage64Test();
  // printImage(frames);
  // delay(1000); // Delay to visualize the output
  // size_t frameCount = sizeof(animation) / sizeof(animation[0]);
  // animate(animation, frameCount);
}
