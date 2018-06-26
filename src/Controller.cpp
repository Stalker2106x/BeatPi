#include "Controller.hh"

Controller::Controller()
{
    _buttons.push_back(std::make_pair(FORWARD, dummy()));
    _buttons.push_back(std::make_pair(PLAY_PAUSE, dummy()));
    _buttons.push_back(std::make_pair(REWIND, dummy()));
    _buttons.push_back(std::make_pair(VOLUME_UP, dummy()));
    _buttons.push_back(std::make_pair(VOLUME_DN, dummy()));
}

Controller::~Controller()
{

}

void Controller::pollEvent()
{
    for (size_t i; i < _buttons.size(); i++)
    {
        if (digitalRead(_button[i]) == HIGH) continue;
        _button[i]();
    }
}

void Controller::dummy()
{

}