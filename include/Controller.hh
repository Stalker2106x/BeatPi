#ifndef CONTROLLER_HH_
#define CONTROLLER_HH_

#include <vector>
#include <utility>
#include "Button.hh"

class Controller
{
public:
    Controller();
    ~Controller();

    void pollEvent();

    void toggleOnOff(int keyCode);
    void changeVolume(int keyCode);
    void prevNext(int keyCode);
    void togglePlayback(int keyCode);

private:
    std::vector<Button> _buttons;
};

#endif /* !CONTROLLER_HH_ */
