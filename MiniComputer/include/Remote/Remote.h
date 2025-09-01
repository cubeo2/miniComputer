#pragma once
#include <Config.h>
#include <DataTypes/RemoteDataTypes.h>

/*
This file contains function declarations and definitions related to the handheld controller used in the Mini Computer project.
Its main purpose is to interpret button presses and send the appropriate data to the master microcontroller.
*/

#if REMOTE_CONNECT
ButtonType decodeADC(const int &adc, const Button *buttons, const byte &pin);
int stableRead(int pin);
void sendInstruction();
void logButtonsPressed(ButtonType *types);
int checkForCommand();

#else
inline ButtonType decodeADC(const int &adc, const Button *buttons, const byte &pin){}
inline int stableRead(int pin){}
inline void sendInstruction(){}
inline void logButtonsPressed(ButtonType *types){}
inline int checkForCommand(){}
#endif