#pragma once
#include <Config.h>

struct Buffer
{
    byte *buffer;
    byte2 head;
    byte2 tail;
    Buffer(byte2 bufferSize)
    {
        buffer = new byte[bufferSize];
        memset(buffer, 0, sizeof(buffer));
        head = 0;
        tail = 0;
    }
    ~Buffer()
    {
        delete[] buffer;
    }
};
#if SERIAL_LOG
void
printString()
{
    for (byte i = 0; i < sizeof(buffer); i++)
    {
        Log(buffer[i]);
        Log(" ");
        bytesPrinted++;

        Logln("");
    }
};
#endif

enum DataTypes : byte
{
    INVALID,
    IMAGE,
    ANIMATION,
    AUDIO,
    TEXT,
    OBJECT,
    CONTROL,
    RUN
};

// Data packet to be sent between Arduinos (image is 40B)
struct DataPacket
{
    DataTypes dataType;
    byte2 meta;
    byte *packet;
    // auxilary information about outgoing data, ex. num of frames, duration etc.
    DataPacket(byte2 packetSize, DataTypes type)
    {
        packet = new byte[packetSize];
        memset(packet, 0, sizeof(packet));
        dataType = type;
        meta = 0;
    }
    ~DataPacket()
    {
        delete[] packet;
    }
};

// File meta Data. This struct allows a maximum of MAXIMUM_FILES files to be monitored
// at a time.
struct FileMeta
{
    String filename;
    byte2 chunk;

    void nextChunk()
    {
        chunk += BUFFER_SIZE;
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