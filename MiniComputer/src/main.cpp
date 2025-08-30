#include <Config.h>
#include <Debug.h>
#include <CommunicationController.h>
#include <test_SCREEN.h>

// GLOBAL TIME VARIABLES
unsigned long currentMillis;
unsigned long lastMillis;

byte state = 0;

// volatile byte receivedData = 0;
// byte receivedFlag = 0;
// volatile bool dataReady = false;

DeviceMeta deviceMeta[] = {
    {CONTROLLER, REMOTE_CONT_CS, false},
    {SCREEN, SCREEN_CS, false},
    {MEMORY, MEMORY_CS, false},
    {AUDIO, AUDIO_CS, false}};
    
void setup()
{
    startMaster();
    startLog();

    Log("Setup started...");
    
    Logln("Setup completed.");
    Logln("");

    // Start communicating via SPI and CS pins
    
}

bool first = true;
void loop()
{
   
    sendData(deviceMeta[CONTROLLER], 0x05);
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
