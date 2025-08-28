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
#define SCREEN_CONNECT 0
#define MEMORY_CONNECT 0
#define AUDIO_CONNECT 0
#define CONTROLLER_CONNECT 1

// devices being used end -
/*
General Settings
*/
#define COMMUNICATION_PROTO 1

// General settings end -

/* 
Debug Settings ----
*/
// Serial/SD Logging
#define SERIAL_LOG 1
#include <Debug.h>
#define LOG_SD 0
// serial/sd logging end
//DEBUG Settings
#define DEBUG_CONTROLLER 0
#define DEBUG_SCREEN 0
#define DEBUG_AUDIO 0
#if MEMORY_CONNECT && LOG_SD && SERIAL_LOG
#define DEBUG_MEMORY 1
#endif
//debug settings end -

/*
Pin Configuration ----
*/
// LED Screen
#define SCREEN_SER 3
#define SCREEN_RCLK 5
#define SCREEN_SCLK 7
#define SCREEN_OE 4
// led screen end
// Memory
#define MEMORY_CS 10
// memory end
// Controller
#define DIRECTION_BUTTONS A1
#define ACTION_BUTTONS A0
// controller end
//pin configuration end -

#include <Screen.h>
#include <Memory.h>
#include <Audio.h>
#include <Communication.h>
#include <Controller.h>