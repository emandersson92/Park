#pragma once

#include "VehicleFrame.h"
#include "Vehicle.h"
#include <iostream>


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

