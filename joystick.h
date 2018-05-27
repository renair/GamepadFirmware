#ifndef _JOYSTICK_H
#define _JOYSTICK_H

#include <Arduino.h>

const byte CENTER = 0;
const byte UP = 1;
const byte UP_RIGHT = 2;
const byte RIGHT = 3;
const byte RIGHT_DOWN = 4;
const byte DOWN = 5;
const byte DOWN_LEFT = 6;
const byte LEFT = 7;
const byte LEFT_UP = 8;

class Joystick {
  private:
    const byte _vertical;
    const byte _horizontal;
    const byte _button;
  public:
    //horizontal pin, vertical pin, button pin
    Joystick(byte, byte, byte = -1);
    byte getDirection();
    bool isButtonPressed();
};

#endif  //_JOYSTICK_H
