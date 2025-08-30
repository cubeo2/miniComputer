#pragma once
#include <Config.h>

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
//Data packet to be sent between Arduinos (image is 40B)
struct DataPacket {
    byte packet[PACKET_SIZE];
    // auxilary information about outgoing data
    byte2 meta;
    DataTypes dataType;
    DataPacket(DataTypes type){
        dataType = type;
        meta = 0;
        switch (type) {
            case image:
                packet[40] = 0;
                break;
            // animations have a max size of 200B for now
            case animation:
                packet[200]; 
                break;
            // NEEDS TO BE CHANGED BASED ON AUDIO HARDWARE
            case audio:
                packet[32]; 
                break;
            // NEEDS TO BE CHANGED BASED ON TEXT HARDWARE
            case text:
                packet[32];
                break;
            // NEEDS TO BE CHANGED BASED ON OBJECT HARDWARE
            case object:
                packet[32]; 
                break;
            // NEEDS OPTIMIZATION
            // control data passes 2 bytes, one for each button cluster
            case controls:
                packet[2]; 
                break;
            // DEFAULT SHOULD NEVER RUN
            default:
                packet[0]; 
                break;
        }
        memset(packet, 0, sizeof(packet));
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