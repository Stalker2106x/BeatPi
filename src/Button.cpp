#include "wiringpi/wiringPi/wiringPi.h"
#include "Button.hh"
#include <iostream>

Button::Button(int pkeyCode, callback_t pcallback)
{
  std::cout << "Setting up PIN " << keyCode << "\n";
  keyCode = pkeyCode;
  callback = pcallback;
  prevState = false;
  pinMode(keyCode, OUTPUT);
  digitalWrite(keyCode, 1);
}

Button::~Button()
{

}

bool Button::getState()
{
  return (static_cast<bool>(!digitalRead(keyCode)));
}

bool Button::isPressed()
{
  bool pressed = false;
  bool state = getState();

  if (state == true && prevState == false) pressed = true;
  prevState = state;
  return (pressed);
}
