#include <Arduino.h>

typedef struct Shift_Register {
    byte SER;
    byte RCLK;
    byte SCLK;
    byte OE;
} Shift_Register;

typedef struct Frame {
  byte rows[4];
  int duration;
} Frame;

void shift_register_init(Shift_Register * sr);
void shift_register_write(Shift_Register * const sr, byte data);

void frameDisplay(byte frame[]);
void printImage(byte frame[]);
void animate(Frame frames[], size_t frameCount);

void screenSetup();