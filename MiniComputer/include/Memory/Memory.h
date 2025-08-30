#pragma once
#include <Config.h>
#include <SD.h>
#include <DataTypes/MemoryDataTypes.h>

/*
This header file contains functions for initializing and managing memory operations
using an SD card. It includes functions for initializing the SD card, creating files,
writing data to files, and reading data from files.
*/



FileMeta file = {"image.txt", 0};
Buffer buffer1;

// 512 bytes of data for each buffer, or 1 chunk of data as is the standard
// for SD cards

// This ring buffer contains 512B of raw data from the SD card


// struct ImageBuffer {
//     byte images[IMAGE_COUNT][IMAGE_SIZE];
//     byte imageSize = IMAGE_SIZE;
//     byte2 duration;
//     // The meta data contains information
//     byte meta;
// };

// //NOT STARTED
// struct AudioBuffer {
//     byte audioData[512];
//     byte2 audioSize = 512;
// };

#if MEMORY_CONNECT
// Memory initialization function
void memoryInit();
// SD card functions
void createFile(const char *filename);
void memoryWrite(const char *filename, const char *data);
bool memoryRead(Buffer &buff, FileMeta &file);

// Buffer management functions
bool writeBuffer(Buffer &buff, const byte &data);
bool readBuffer(Buffer &buff, byte &data);
void clearBuffer();
void clearTransferBuffer();
DataTypes interpretMemory(Buffer &buff);
DataTypes interpretMemory(DataPacket &dataPacket);


#else
inline void memoryInit() {}

inline void createFile(const char *filename) {}
inline void memoryWrite(const char *filename, const char *data) {}
inline void memoryRead(const char *filename) {}

inline void transferData(const byte *data) {}
inline void writeBuffer() {}
#endif

// Possibly add these if there is a need to figure out the frame/pixelcount
// void frameCount();
// void pixelCount();