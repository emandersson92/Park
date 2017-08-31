/*
Abstract Timer Class
 */

#include "opencvIncludes.h"


class WindowsTimer(){
 public:

  WindowsTimer::WindowsTimer();
  WindowsTimer::WindowsTimer~();

  virtual void start() = 0;
  virtual void stop() = 0;

 private:

}

