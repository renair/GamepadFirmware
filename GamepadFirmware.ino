#include "joystick.h"
#include "communicator.h"

#define SOFTWARE_PULLUP

const int JOYSTICK_X = 0;
const int JOYSTICK_Y = 1;

Joystick j1(JOYSTICK_X, JOYSTICK_Y);
Communicator comm;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  comm.readState(&j1, &j1);
  comm.sendState();
}
