#ifndef CONTROLLER_HH_
#define CONTROLLER_HH_

#include <vector>
#include <utility>
#include "pinconfig.hh"

class Controller
{
public:
    Controller();
    ~Controller();
    
    void pollEvent();

    void changeVolume(int keyCode);
    void prevNext(int keyCode);
    void togglePlayback(int keyCode);

  //Generic controller callback
  typedef void (Controller::*callback_t)(int);

private:
    std::vector<std::pair<int, callback_t>> _buttons;
};

#endif /* !CONTROLLER_HH_ */
