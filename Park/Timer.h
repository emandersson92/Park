/*
Abstract Timer Class
 */

#include "opencvIncludes.h"


class Timer{
 public:

  Timer();
  ~Timer();

  virtual void start() = 0;
  virtual void stop() = 0;
  virtual double getTime() = 0;
  virtual void increment() = 0;//only for class simpletimer


 private:

};
