#include "stdafx.h"
#include "SimpleTimer.h"


SimpleTimer::SimpleTimer()
{
  COUNTING = false;
  time = 0;
}


SimpleTimer::~SimpleTimer()
{
}

void SimpleTimer::increment(){
  if(COUNTING == true){
    time++;
  }
}

void SimpleTimer::start() {
  COUNTING = true;
}

void SimpleTimer::pause(){
    COUNTING = false;
}

void SimpleTimer::stop() {
  COUNTING = false;
}

void SimpleTimer::reset(){
  COUNTING = false;
  time = 0;

}

void SimpleTimer::isCounting(){
	return COUNTING;
}

double SimpleTimer::getTime(){
  return time;
}
