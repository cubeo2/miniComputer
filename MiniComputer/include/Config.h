#pragma once

#include <Arduino.h>
#include <DataTypes.h>

/*
This file contains all configuration settings for the Mini Computer project.
It includes settings for connected devices, pin configurations, debug options,
and controller configurations.
*/

/*
Devices being used ----
*/ 
#define SCREEN_CONNECT 1
#define MEMORY_CONNECT 1
#define AUDIO_CONNECT 0

/*
Pin Configuration ----
*/
// LED Screen
#define SCREEN_SER 3
#define SCREEN_RCLK 5
#define SCREEN_SCLK 6
#define SCREEN_OE 4
// led screen end
// Memory
#define MEMORY_CS 10
// memory end
//pin configuration end -

/*
Controller Configuration Settings ----
*/ 
#if SCREEN_CONNECT
#include <Screen.h>
#endif

#if MEMORY_CONNECT
#include <Memory.h>
#endif

#if AUDIO_CONNECT
#include <Audio.h>
#endif
// controller end -

/* 
Debug Settings ----
*/
// Serial/SD Logging
#define SERIAL_LOG 1
#define LOG_SD 1
// serial/sd logging end
//DEBUG Settings
#define DEBUG_CONTROLLER 0
#define DEBUG_SCREEN 0
#define DEBUG_AUDIO 0
#if MEMORY_CONNECT && LOG_SD
#define DEBUG_MEMORY 1
#endif
//debug settings end

#if SERIAL_LOG
void serialOn();
void serialLog(const char* message);
void serialLogLn(const char* message);
#endif
// SD Card
#if DEBUG_MEMORY
void sdLog(const char* message);
#endif
// debug end -