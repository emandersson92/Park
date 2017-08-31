#include "stdafx.h"
#include "Timer.h"


SimpleTimer::SimpleTimer()
{
  COUNTING = false;
  timer = 0;
}


SimpleTimer::~SimpleTimer()
{
}

void SimpleTimer::increment(){
  if(COUNTING == true){
    timer++;
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
  timer = 0;

}
