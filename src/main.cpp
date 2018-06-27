#include "wiringpi/wiringPi/wiringPi.h"
#include "Controller.hh"

int main(int argc, char **argv)
{
  wiringPiSetup(); //Init GPIO
  Controller ctrl;

  while (true)
  {
    ctrl.pollEvent();
  }
  return (0);
}
