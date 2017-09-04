#pragma once

#include "VehicleFrame"
#include "Vehicle"
#include <iostream>


class Vehicle
{
public:
	Vehicle();
	~Vehicle();
	getLastVehicleFrame();
	addVehicleFrame(VehicleFrame* v);

 private:
	std::vector<VehicleFrame> vehicleFrames;
};

