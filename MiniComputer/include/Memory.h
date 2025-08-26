#pragma once
#include <Config.h>
#include <SPI.h>
#include <SD.h>

/*
This header file contains functions for initializing and managing memory operations
using an SD card. It includes functions for initializing the SD card, creating files,
writing data to files, and reading data from files.
*/

#define BUFFER_SIZE 512

// 512 bytes of data for each buffer, or 1 chunk of data as is the standard
// for SD cards

// This ring buffer contains 512B of raw data from the SD card
struct Buffer
{
    byte buffer[BUFFER_SIZE];
    byte2 head = 0;
    byte2 tail = 0;
    byte2 numBytes = 0;
    Buffer()
    {
        for (int i = 0; i < BUFFER_SIZE; i++)
        {
            buffer[i] = 0;
        }
    }
#if SERIAL_LOG
    String toString()
    {
        String result = "Buffer: ";
        // result += "head=";
        // result += String(head);
        // result += ", tail=";
        // result += String(tail);
        // result += ", numBytes=";
        // result += String(numBytes);
        // result += ", firstBytes=[";

        for (int i = 0; i < numBytes; i++)
        {
            result += String(buffer[i], HEX);
        }
        result += "]";
        return result;
    }
#endif
};

enum DataTypes : byte
{
    image,
    animation,
    audio,
    text,
    object,
    controls
};

struct FileMeta
{
    String filename;
    byte2 chunk;
    void nextChunk()
    {
        chunk += 513;
    }
#if SERIAL_LOG
    String toString()
    {
        String result = "FileMeta: ";
        result += "filename=";
        result += filename;
        result += ", chunk=";
        result += String(chunk);
        return result;
    }
#endif
};

struct dataMeta
{
    byte2 meta;
    DataTypes dataType;
#if SERIAL_LOG

    String toString()
    {
        String result = "dataMeta: ";
        result += "meta=";
        result += String(meta);
        result += ", dataType=";
        result += String((int)dataType); // cast enum to int
        return result;
    }
#endif
};

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