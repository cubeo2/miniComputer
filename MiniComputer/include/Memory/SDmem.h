#pragma once
#include <Config.h>
#include <SD.h>
#include <DataTypes/MemoryDataTypes.h>

/*
This header file contains functions for initializing and managing memory operations
using an SD card. It includes functions for initializing the SD card, creating files,
writing data to files, and reading data from files.
*/

#if MEMORY_CONNECT
// Memory initialization function
void connectSD();
// SD card functions
void createFile(const char *filename);
bool createFolder(const char *folderName);
void memoryWrite(const char *filename, const char *data);
bool memoryRead(Buffer &buff, FileMeta &file);

// Buffer management functions
bool writeBuffer(Buffer &buff, const byte &data);
bool readBuffer(Buffer &buff, byte &data);
bool fillPacket(Buffer &buff, DataPacket &dataPacket);
bool cleanBuffer (Buffer &buff);

#else
// Memory initialization function
inline void connectSD(){}
// SD card functions
inline void createFile(const char *filename){}
inline bool createFolder(const char *folderName){}
inline void memoryWrite(const char *filename, const char *data){}
inline bool memoryRead(Buffer &buff, FileMeta &file){}

// Buffer management functions
inline bool writeBuffer(Buffer &buff, const byte &data){}
inline bool readBuffer(Buffer &buff, byte &data){}
inline bool fillPacket(Buffer &buff, DataPacket &dataPacket){}
inline bool cleanBuffer (Buffer &buff){}
#endif

// Possibly add these if there is a need to figure out the frame/pixelcount
// void frameCount();
// void pixelCount();