#pragma once
#include <Config.h>

/*
This file contains data types used for memory management in the Mini Computer project.
*/

// Memory Buffer Structure, used to manage a byte buffer with head and tail pointers for reading and writing data.
struct Buffer
{
    byte *buffer;
    byte2 head;
    byte2 tail;
    byte2 numBytes = 0;
    byte2 size;
    Buffer(byte2 bufferSize) : size(bufferSize)
    {
        buffer = new byte[bufferSize];
        memset(buffer, 0, bufferSize);
        head = 0;
        tail = 0;
    }
    ~Buffer()
    {
        delete[] buffer;
    }

#if SERIAL_LOG
    void printString()
    {
        byte2 bytesPrinted = 0;
        for (byte i = 0; i < size / 16; i++)
        {
            for (byte j = 0; j < 16; j++)
            {
                Log(buffer[bytesPrinted], HEX);
                Log(" ");
                bytesPrinted++;
            }
            Logln("");
        }
#endif
    };
    void clear()
    {
        memset(buffer, 0, size);
        head = 0;
        tail = 0;
    }
    bool isEmpty()
    {
        return head == tail;
    }
    bool isFull()
    {
        return ((head + 1) % size) == tail;
    }
};

// Data Types for memory management and data handling
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

// File Metadata Structure, used to manage file information such as filename and current chunk position. Th chunk position is incremented by BUFFER_SIZE for each subsequent chunk in order to keep track of progress through the file.
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