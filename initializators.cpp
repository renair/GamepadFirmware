#include "initializators.h"
#include "preferences.h"

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

bool makeHandshake(String greet_in)
{
  if(greet_in != "joi?")
  return false;
  Serial.write("yes)");
  return true;
}
