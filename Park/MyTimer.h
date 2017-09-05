/*
Abstract Timer Class
 */
#pragma once
#include "opencvIncludes.h"

class MyTimer{
 public:

  MyTimer();
  ~MyTimer();

  virtual void start() = 0;
  virtual void stop() = 0;
  virtual double getTime() = 0;
  virtual void increment() = 0;//only for class simpletimer


 private:

};
