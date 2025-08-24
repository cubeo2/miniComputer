#include <Arduino.h>

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

struct Image{

};

#if SCREEN_CONNECT
void shift_register_init(Shift_Register * sr);
void shift_register_write(Shift_Register * const sr, byte data);

void frameDisplay(byte frame[]);
void printImage(byte frame[]);
void animate(Frame frames[], size_t frameCount);

void screenSetup();

void printIage64Test();
#else
inline void shift_register_init(Shift_Register * sr) {}
inline void shift_register_write(Shift_Register * const sr, byte data) {}
inline void frameDisplay(byte frame[]) {}
inline void printImage(byte frame[]) {}
inline void animate(Frame frames[], size_t frameCount) {}
inline void screenSetup() {}
inline void printIage64Test() {}
#endif