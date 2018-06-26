#ifndef PINCONFIG_HH_
#define PINCONFIG_HH_

#include <vector>
#include <pair>
#include "pinconfig.hh"

class Controller
{
public:
    Controller();
    ~Controller();
    
    void pollEvent();

    typedef void (*callback_t)();

private:
    std::vector<std::pair<int, callback_t>> _buttons;
};

#endif /* !PINCONFIG_HH_ */