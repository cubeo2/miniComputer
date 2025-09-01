#pragma once
#include <Config.h>

/*
This file contains data types used for communication between devices in the Mini Computer project.
*/
typedef byte transferPacket[32];

// Communication Flag Types
enum FlagType : byte
{
    NONE,
    CHECK_STATUS,
    READY,
    NOT_READY,
    REQUEST_TO_SEND,
    SENDING,
    SENT,
    RECEIVING,
    RECEIVED,
    RESET,
};

// Communication Priorities
enum CommPriority : byte
{
    ONE,
    TWO,
    THREE
};

// Communication Flag Structure, used to encapsulate flag and priority information in a single byte.
struct CommFlag
{
    byte commFlag;

    CommFlag()
    {
        commFlag = 0;
    }
    byte checkPriority()
    {
        byte priority = 0xF0 & commFlag;
        priority >>= 4;
        return priority;
    }
    byte checkFlag()
    {
        byte flag = 0x0F & commFlag;
        return flag;
    }
    void setFlag(FlagType type, CommPriority priority)
    {
        commFlag = (priority << 4) | type;
    }
};

// Device Types
enum Device : byte
{
    CONTROLLER,
    SCREEN,
    MAIN_MEMORY,
    SPEAKER
};

// Device Metadata Structure, used to store information about each device. Specifically, its type, chip select pin, and status (connected or not).
struct DeviceMeta
{
    Device type;
    byte csPin;
    bool status;
};