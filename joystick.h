#ifndef _JOYSTICK_H
#define _JOYSTICK_H

#include <Arduino.h>

enum JoystickDirection{CENTER = 0, UP, UP_RIGHT, RIGHT, RIGHT_DOWN, DOWN, DOWN_LEFT, LEFT, LEFT_UP};

class Joystick {
private:
  const byte _vertical;
  const byte _horizontal;
  const byte _button;
public:
  //horizontal pin, vertical pin, button pin 
  Joystick(byte, byte, byte = -1);
  JoystickDirection getDirection();
  bool isButtonPressed();
};

#endif  //_JOYSTICK_H
