#pragma once
#include "windows.h"
#include "MyTimer.h"

class SimpleTimer : public MyTimer
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
  void isCounting(){

private:

	double time; //program made up time in order to simplify timer object
	bool COUNTING; //true if the timer incrementing "time"

};

