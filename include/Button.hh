#ifndef BUTTON_HH_
#define BUTTON_HH_

//Generic controller callback
class Controller;
typedef void (Controller::*callback_t)(int);

class Button
{
public:
  Button(int keyCode, callback_t callback);
  ~Button();

  bool getState();
  bool isPressed();
  
  int keyCode; 
  bool prevState;
  callback_t callback;
};

#endif /* !BUTTON_HH_ */
