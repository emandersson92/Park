#pragma once
#include "opencvIncludes.h"

#include "VehicleFrame.h"
#include "VehicleList.h"

class Vehicle
{
public:
	Vehicle();
	~Vehicle();

	//Functions used by lists to determine if they belong
	void getSpeed();
	void getPosition();
	//...
	//...
	//...

	VehicleList* list;

private:
	std::vector<VehicleFrame> vehFrames;

};

