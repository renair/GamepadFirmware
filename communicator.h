#ifndef _COMMUNICATOR_H
#define _COMMUNICATOR_H

#include <Arduino.h>
#include <Console.h>
#include <stdint.h>
#include "joystick.h"

// Protocol Description
//  Bit   |   Value
//   1    |   Button 1
//   2    |   Button 2
//   3    |   Button 3
//   4    |   Button 4
//   5    |   Button 5
//   6    |   Button 6
//   7    |   Button 7
//   8    |   Button 8
//   9    |   Button 9
//   10   |   Button 10
// 11-14  |   Joystick Left
// 15-18  |   Joystick Right
// Protocol have 16 bit so int16_i is used for data transmission.

class Communicator
{
  private:
    int32_t _state;
    int32_t _previousState;
  public:
    Communicator(int = 9600);
    void readState(Joystick*, Joystick*);
    void sendState();
};

#endif //_COMMUNICATOR_H
