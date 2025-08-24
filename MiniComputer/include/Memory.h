#pragma once
#include <SPI.h>
#include <SD.h>
#include <DataTypes.h>

/*
This header file contains functions for initializing and managing memory operations
using an SD card. It includes functions for initializing the SD card, creating files,
writing data to files, and reading data from files.
*/

#define SCREEN_LENGTH 4
#define SCREEN_HEIGHT 4
#define PIXEL_COUNT (SCREEN_LENGTH * SCREEN_HEIGHT)
// The image size only works if it is divisible by 8, needs to be changed for more flexibilitiy
#define IMAGE_SIZE (PIXEL_COUNT / 8)  // in bytes
#define IMAGE_COUNT (4072 / PIXEL_COUNT)

// 512 bytes of data for each buffer, or 1 chunk of data as is the standard
// for SD cards
struct ImageBuffer {
    byte images[IMAGE_COUNT][IMAGE_SIZE];
    byte imageSize = IMAGE_SIZE;
    byte2 duration;
    // The meta data contains information 
    byte meta;

};

//NOT STARTED
struct AudioBuffer {
    byte audioData[512];
    byte2 audioSize = 512;
};

void memoryInit();
void createFile(const char* filename);
void memoryWrite(const char* filename, const char* data);
void memoryRead(const char* filename);

// Possibly add these if there is a need to figure out the frame/pixelcount
// void frameCount();
// void pixelCount();