#pragma once
#include <Config.h>

// Basic Data Types
typedef unsigned char byte;
typedef unsigned short byte2;
typedef uint32_t byte4;
typedef uint64_t byte8;

// The screen can only show 40 bit images (on or off)
// typedef byte image[5];

// COMMUNICATION TYPES
typedef byte transferPacket[32];
enum CommFlag : byte {
    CHECK_CONNECTION,
    REQUEST_TO_SEND,
    READY,
    RECEIVED,
    SENT,  // may be redundant with request to send
    RESET
};
enum Device : byte {
    CONTROLLER,
    SCREEN,
    MEMORY,
    AUDIO
};
struct DeviceMeta {
    Device type;
    byte csPin;
    bool status;
};

// CONTROLLER TYPES
enum ButtonType : byte
{
  NONE,
  LEFT,
  UP,
  RIGHT,
  DOWN,
  START,
  RED,
  BLUE,
  RED_BLUE,
  INVALID
};
struct Button
{
  int lo;
  int hi;
  ButtonType type;
};

// MEMORY TYPES
struct Buffer
{
    byte buffer[BUFFER_SIZE];
    byte2 head = 0;
    byte2 tail = 0;
    byte2 numBytes = 0;
    Buffer()
    {
        for (byte2 i = 0; i < BUFFER_SIZE; i++)
        {
            buffer[i] = 0;
        }
    }
#if SERIAL_LOG
    void printString(){
        byte2 bytesPrinted = 0;
        for (byte i = 0; i < BUFFER_SIZE / 8; i++) {
            for (byte j = 0; j < 8; j++ ) {
                Log(buffer[bytesPrinted]);
                Log(" ");
                bytesPrinted++;
            }
            Logln("");
            
        }
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
    controls,
    run
};
//Data packet to be sent between Arduinos (image is 38B)
struct DataPacket {
    byte packet[PACKET_SIZE];
    byte2 meta;
    DataTypes dataType;
};

// File meta Data. This struct allows a maximum of MAXIMUM_FILES files to be monitored 
// at a time.
struct FileMeta
{
    String filename;

    byte2 chunk;
    void nextChunk()
    {
        chunk += 512;
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