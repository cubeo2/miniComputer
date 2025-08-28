#pragma once
#include <Config.h>
#include <Compiler.h>

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

#if CONTROLLER_CONNECT

// void controllerInit();
void sendInstruction();

ButtonType decodeADC(const int &adc, const Button *buttons, const byte &pin);
int stableRead(int pin);
void sendInstruction();
void logButtonsPressed(ButtonType *types);
bool checkForCommand();

#else
inline void controllerInit(){}
inline void sendInstruction(){}
#endif