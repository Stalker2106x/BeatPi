#include "wiringpi/wiringPi/wiringPi.h"
#include "Controller.hh"
#include "pinconfig.hh"
#include <iostream>

Controller::Controller()
{
  _buttons.push_back(Button(ON_OFF, &Controller::toggleOnOff));
  _buttons.push_back(Button(FORWARD, &Controller::prevNext));
  _buttons.push_back(Button(PLAY_PAUSE, &Controller::togglePlayback));
  _buttons.push_back(Button(REWIND, &Controller::prevNext));
  _buttons.push_back(Button(VOLUME_UP, &Controller::changeVolume));
  _buttons.push_back(Button(VOLUME_DN, &Controller::changeVolume));

}

Controller::~Controller()
{
  
}

void Controller::pollEvent()
{
    for (size_t i = 0; i < _buttons.size(); i++)
    {
      if (_buttons[i].isPressed())
      {
        (this->*_buttons[i].callback)(_buttons[i].keyCode);
      }
    }
}

void Controller::toggleOnOff(int keyCode)
{
  std::cout << "ON/OFF\n";
}

void Controller::changeVolume(int keyCode)
{
  std::cout << "VOL" << (keyCode == VOLUME_UP ? "_UP" : "_DN") << "\n";
}

void Controller::prevNext(int keyCode)
{
  std::cout << (keyCode == FORWARD ? "Next" : "Prev") << "\n";
}

void Controller::togglePlayback(int keyCode)
{
  std::cout << "Play/Pause\n";
}


