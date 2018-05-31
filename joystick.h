#ifndef _JOYSTICK_H
#define _JOYSTICK_H

#include <Arduino.h>

const byte CENTER = 0;
const byte RIGHT = 1;
const byte LEFT = 2;
const byte UP = 3;
const byte UP_RIGHT = 4;
const byte UP_LEFT = 5;
const byte DOWN = 6;
const byte DOWN_RIGHT = 7;
const byte DOWN_LEFT = 8;

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
