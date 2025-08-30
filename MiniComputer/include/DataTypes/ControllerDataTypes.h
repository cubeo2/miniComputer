#pragma once 
#include <Config.h>

enum ButtonType : byte
{
  NO_PRESS,
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