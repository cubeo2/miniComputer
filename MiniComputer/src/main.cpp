#include <Config.h>
#include <Debug.h>
#include <test_SCREEN.h>

// GLOBAL TIME VARIABLES
unsigned long currentMillis;
unsigned long lastMillis;

byte state = 0;

FileMeta file = {"image.txt", 0};
Buffer buffer1;

void setup()
{
    startLog();

    Log("Setup started...");
    memoryInit();
    screenSetup();
    Logln("Setup completed.");
    Logln("");

    // Start communicating via SPI and CS pins
    
}

bool first = true;
void loop()
{

    /*
    CONTROLLER TESTS
    */
    // sendInstruction();
    /*
    MEMORY TESTS
    */
    // if (first)
    // {
    //     Log("Next Chunk: ");
    //     Logln(file.chunk);
    //     memoryRead(buffer1, file);
    //     Log("Next Chunk: ");
    //     Logln(file.chunk);
    //     memoryRead(buffer1, file);
    //     Log("Next Chunk: ");
    //     Logln(file.chunk);
    //     first = false;
    // }

    // checkForCommand();

    /*
    SCREEN TESTS
    */
    // Log("Loop started...");
    // printIage64Test();
    // printImage(frames);
    // delay(1000); // Delay to visualize the output
    // size_t frameCount = sizeof(animation) / sizeof(animation[0]);
    // animate(animation, frameCount);
}
