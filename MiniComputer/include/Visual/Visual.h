#pragma once
#include <Config.h>

/*
This file contains declarations for controlling an LED screen using shift registers in the Mini Computer project.
It includes functions for initializing the shift register, writing data to it, printing images, animating frames, and setting up the screen.
*/

struct Shift_Register {
    byte SER;
    byte RCLK;
    byte SCLK;
    byte OE;
};

struct Frame {
  byte rows[4];
  int duration;
};

#if SCREEN_CONNECT
void shift_register_init(Shift_Register* const sr);
void shift_register_write(Shift_Register *const sr, uint64_t &data);
void printImage(byte frame[]);
void animate(Frame frames[], size_t frameCount);
void screenSetup();

void printIage64Test();
#else
inline void shift_register_init(Shift_Register* const sr){}
inline void shift_register_write(Shift_Register *const sr, uint64_t &data){}
inline void printImage(byte frame[]){}
inline void animate(Frame frames[], size_t frameCount){}
inline void screenSetup(){}

inline void printIage64Test(){}
#endif