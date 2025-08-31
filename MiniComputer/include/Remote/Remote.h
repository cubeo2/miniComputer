#pragma once
#include <Config.h>
#include <DataTypes/RemoteDataTypes.h>


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