#include "joystick.h"
#include "communicator.h"

const int JOYSTICK_X = 0;
const int JOYSTICK_Y = 1;

Joystick j1(JOYSTICK_X, JOYSTICK_Y);
Communicator comm;

byte direct;

void setup()
{
  Serial.begin(9600);
  direct = j1.getDirection();
}

void loop()
{
  comm.readState(&j1, &j1);
  comm.sendState();
}
