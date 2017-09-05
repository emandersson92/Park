#pragma once

#include "VehicleFrame.h"
#include <iostream>
#include <vector>

class VehicleFrame;

class Vehicle
{
 public:
	Vehicle();
	~Vehicle();
	VehicleFrame* getLastVehicleFrame();
	void addVehicleFrame(VehicleFrame* v);

 private:
	std::vector<VehicleFrame*> vehicleFrames;
};

