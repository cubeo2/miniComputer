#include <Config.h>
#include <Debug.h>
#include <test_SCREEN.h>

byte state = 0;

FileMeta file = {"image.txt", 0};
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

bool first = true;
void loop()
{

  if (first)
  {
    serialLog("Next Chunk: ");
    serialLogLn(file.chunk);
    memoryRead(buffer1, file);
    serialLog("Next Chunk: ");
    serialLogLn(file.chunk);
    memoryRead(buffer1, file);
    serialLog("Next Chunk: ");
    serialLogLn(file.chunk);
    first = false;
  }

  // serialLog("Loop started...");
  // printIage64Test();
  // printImage(frames);
  // delay(1000); // Delay to visualize the output
  // size_t frameCount = sizeof(animation) / sizeof(animation[0]);
  // animate(animation, frameCount);
}
