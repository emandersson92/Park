#pragma once

#include "VehicleFrame.h"
#include <iostream>
#include <vector>
#include "Environment.h"

class VehicleFrame;

class Vehicle
{
 public:
	Vehicle(VehicleFrame* vf);
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


 private:
	 std::vector<VehicleFrame*> vehicleFrames;
	 
	 const int nVehicleFramesStillWhenParked = 5;


};

