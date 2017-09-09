/*
Used for instance to tests to create example objects
The vehicle is created here

 */

#pragma once

#include "opencv2\imgproc.hpp"
#include <vector>

#include "Vehicle.h"
#include "VehicleFrame.h"
#include "tools.h"

class Example{

 public:
  Example();
  ~Example();

  Vehicle* createVehicle(VehicleDetector* detector);


 private:

};

