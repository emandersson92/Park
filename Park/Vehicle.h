#pragma once

#include "VehicleFrame.h"
#include <iostream>
#include <vector>

class VehicleFrame;

class Vehicle
{
 public:
	Vehicle(VehicleFrame* vf);
	Vehicle();
	~Vehicle();
	VehicleFrame* getLastVehicleFrame();
	void addVF(VehicleFrame* v);
	void addVF_ifBelong(VehicleFrame* v);
	bool VF_found;
	double getSpeed();

 private:
	std::vector<VehicleFrame*> vehicleFrames;



};

