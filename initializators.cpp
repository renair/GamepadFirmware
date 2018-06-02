#include "initializators.h"

void initPins()
{
  for(byte pin = 2; pin <= 11;++pin) // 10 pins in total
  {
    pinMode(pin, INPUT);
#ifdef SOFTWARE_PULLUP
    digitalWrite(pin, HIGH);
#endif //SOFTWARE_PULLUP
  }
}

bool makeHandshake()
{
  //TODO Implement handshake here
  return true;1
}