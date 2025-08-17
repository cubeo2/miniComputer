#pragma once

#include <SPI.h>
#include <SD.h>

void memoryInit();
void createFile(const char* filename);
void memoryWrite(const char* filename, const char* data);
void memoryRead(const char* filename);