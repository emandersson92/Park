#pragma once

#include "VehicleFrame.h"
#include <iostream>
#include <vector>
#include "Environment.h"
#include "VehicleList.h"
#include "MyTimer.h"

class VehicleFrame;

class Vehicle
{
 public:
	Vehicle(VehicleFrame* vf, VehicleList* list);
	Vehicle();
	~Vehicle();
	VehicleFrame* getLastVehicleFrame();
	std::vector<VehicleFrame*> getVehicleFrames();
	void addVF(VehicleFrame* v);
	void addVF_ifBelong(VehicleFrame* v);
	bool VF_found;
	double getVehicleSpeed();
	cv::Point filterCentroid();
	bool vehicleParked();
	VehicleList* getVehicleList();

	void forwardToNextListIfBelong();




 private:

	MyTimer* timer;///park time timer

	VehicleList* vehicleList;
	std::vector<VehicleFrame*> vehicleFrames;
	const int nVehicleFramesStillWhenParked = 5;

};

