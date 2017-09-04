/*
Used for instance to tests to create example objects
The vehicle is created here

 */

#pragma once

#include "opencv2\imgproc.hpp"


#include "Vehicle.h"
#include <vector>



class Example{

 public:
  Example();
  ~Example();

  Vehicle* createVehicle();


 private:

};

