#pragma once
#include <Arduino.h>

/*
This file contains all configuration settings for the Mini Computer project.
It includes settings for connected devices, pin configurations, debug options,
and controller configurations.

The use of pre-processing macros (ex. SCREEN_CONNECT) allows for easy enabling or
disabling of features and devices, making the codebase adaptable to different hardware setups without requiring significant changes to the source code.
*/

/*
Devices being used ----
*/ 
#define SCREEN_CONNECT 1
#define MEMORY_CONNECT 1
#define AUDIO_CONNECT 0
#define REMOTE_CONNECT 1
#define LCD_CONNECT 1

// devices being used end -
/*
General Settings
*/
#define COMMUNICATION_PROTO 1

// General settings end -

/* 
Settings ----
*/
// LOGGING
#define SERIAL_LOG 1
#include <Utils/Debug.h>
#define LOG_SD 0
// logging end -
// DEBUG
#define DEBUG_CONTROLLER 0
#define DEBUG_SCREEN 0
#define DEBUG_AUDIO 0
#if MEMORY_CONNECT && LOG_SD && SERIAL_LOG
#define DEBUG_MEMORY 1
#endif
// debug settings end -
// MEMORY
#define BUFFER_SIZE 512
#define PACKET_SIZE 40
#define MAX_FILES 3
// memory end -
// Settings end -
/*
Pin Configuration ----
*/
// LED Screen
#define SCREEN_SER 3
#define SCREEN_RCLK 5
#define SCREEN_SCLK 7
#define SCREEN_OE 4
// led screen end
// LCD Screen
#define LCD_RS 12
#define LCD_EN 11
#define LCD_D4 5
#define LCD_D5 4
#define LCD_D6 3
#define LCD_D7 2
// lcd screen end
// Remote Controller
#define DIRECTION_BUTTONS A1
#define ACTION_BUTTONS A0
// controller end
// Communication
#define MEMORY_CS 10
#define AUDIO_CS 11
#define SCREEN_CS 12
#define REMOTE_CONT_CS 9
#define PERIPHERAL_CS 10
//communication end
//pin configuration end -

// #include <Screen.h>
// #include <Memory.h>
// #include <Audio.h>

// #include <Controller.h>
#include <DataTypes/DataTypes.h>