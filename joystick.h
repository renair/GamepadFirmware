#ifndef _JOYSTICK_H
#define _JOYSTICK_H

#include <Arduino.h>

const byte CENTER = 0b0000;
const byte RIGHT = 0b0001;
const byte LEFT = 0b0010;
const byte UP = 0b0011;
const byte UP_RIGHT = 0b0100;
const byte UP_LEFT = 0b0101;
const byte DOWN = 0b0110;
const byte DOWN_RIGHT = 0b0111;
const byte DOWN_LEFT = 0b1000;

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
