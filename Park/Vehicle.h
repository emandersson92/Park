#pragma once
#include "opencvIncludes.h"

#include "VehicleFrame.h"
#include "VehicleList.h"

class VehicleList;

class Vehicle
{
public:
	Vehicle();
	~Vehicle();

	//Functions used by lists to determine if they belong
	double getSpeed();
	cv::Point2d getPosition();
	//...
	//...
	//...

	VehicleList* list;

private:
	std::vector<VehicleFrame*> vehFrames;

};

