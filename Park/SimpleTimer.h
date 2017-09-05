#pragma once
#include "windows.h"
#include "Timer.h"

class SimpleTimer : public Timer
{
public:
  SimpleTimer();
  ~SimpleTimer();
  void start();
  void stop();
  void pause();
  void reset();
  double getTime();
  void increment();


private:

	double time; //program made up time in order to simplify timer object
	boolean COUNTING; //true if the timer incrementing "time"

};

