#include "wiringpi/wiringPi/wiringPi.h"
#include "Controller.hh"
#include "Httpd.hh"

int main(int argc, char **argv)
{
  Controller ctrl;
  std::thread http(Httpd::runDaemon);

  while (true)
  {
    ctrl.pollEvent();
  }
  return (0);
}
