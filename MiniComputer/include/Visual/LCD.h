#pragma once
#include <Config.h>
#include <LiquidCrystal.h>

/*
This file contains function declarations for controlling a 16x2 LCD display in the Mini Computer project.
*/

#if LCD_CONNECT
void lcdSetup();
void lcdPrint(const char* message);
void lcdPrint(String message);
void lcdPrintln(String newLine);
void moveCursor(ButtonType direction);
void showCursor();
#else
inline void lcdSetup(){}
inline void lcdPrint(const char* message){}
inline void lcdPrint(String message){}
inline void lcdPrintln(String newLine){}
inline void moveCursor(ButtonType direction){}
inline void showCursor(){}
#endif