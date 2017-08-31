#pragma once
#include "windows.h"


class SimpleTimer
{
public:
  SimpleTimer(Vehicle);
  ~SimpleTimer();
  void start();
  void stop();
  void pause();

private:

	long time; //program made up time in order to simplify timer object
	boolean COUNTING; //true if the timer incrementing "time"

};

