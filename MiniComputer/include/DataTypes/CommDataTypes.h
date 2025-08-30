#pragma once
#include <Config.h>

typedef byte transferPacket[32];

enum FlagType : byte {
    NONE,
    CHECK_STATUS,
    REQUEST_TO_SEND,
    READY,
    RECEIVED,
    SENT,  // may be redundant with request to send
    RESET,
};

enum CommPriority : byte {
    ONE,
    TWO,
    THREE
};

struct CommFlag {
    byte commFlag;
    CommFlag() {
        commFlag = 0;
    }
    byte checkPriority() {
        byte priority = 0xF0 & commFlag;
        priority >>= 4;
        return priority;
    }
    byte checkFlag() {
        byte flag = 0x0F & commFlag;
        return flag;
    }
    void setFlag(FlagType type, CommPriority priority) {
        commFlag = (priority << 4) | type;
    }
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