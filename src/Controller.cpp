#include <iostream>
#include "wiringpi/wiringPi/wiringPi.h"
#include "Controller.hh"

Controller::Controller()
{
  _buttons.push_back(std::make_pair(FORWARD, &Controller::prevNext));
  _buttons.push_back(std::make_pair(PLAY_PAUSE, &Controller::togglePlayback));
  _buttons.push_back(std::make_pair(REWIND, &Controller::prevNext));
  _buttons.push_back(std::make_pair(VOLUME_UP, &Controller::changeVolume));
  _buttons.push_back(std::make_pair(VOLUME_DN, &Controller::changeVolume));
}

Controller::~Controller()
{

}

void Controller::pollEvent()
{
    for (size_t i; i < _buttons.size(); i++)
    {
        if (digitalRead(_buttons[i].first) == HIGH) continue;
        (this->*_buttons[i].second)(_buttons[i].first);
    }
}

void Controller::changeVolume(int keyCode)
{

}

void Controller::prevNext(int keyCode)
{

}

void Controller::togglePlayback(int keyCode)
{

}


