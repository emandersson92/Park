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


 private:
	std::vector<VehicleFrame> vehicleFrames;
};

