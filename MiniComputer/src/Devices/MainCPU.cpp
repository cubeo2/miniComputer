#include <Config.h>
#include <Communication/CommController.h>
#include <Memory/SDmem.h>
#include <Memory/Buffer.h>
#include <Remote/Remote.h>
#include <Tests/test_SCREEN.h>

// GLOBAL TIME VARIABLES
unsigned long currentMillis;
unsigned long lastMillis;

byte state = 0;

DeviceMeta deviceMeta[] = 
{
    {CONTROLLER, REMOTE_CONT_CS, false},
    {SCREEN, SCREEN_CS, false},
    {MAIN_MEMORY, MEMORY_CS, false},
    {SPEAKER, AUDIO_CS, false}
};
    
void setup()
{
    
    startLog();
    Log("Setup started...");

    startCommController();
    // connectMemory();

    Logln("Setup completed.");
    Logln("");
}

bool first = true;
void loop()
{
   
    // sendData(deviceMeta[CONTROLLER], 0x05);
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
