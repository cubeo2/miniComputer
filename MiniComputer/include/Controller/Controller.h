#pragma once
#include <Config.h>
#include <DataTypes/ControllerDataTypes.h>
#include <Utils/Compiler.h>

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