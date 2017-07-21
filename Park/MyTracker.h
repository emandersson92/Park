#pragma once
#include "VehicleDetector.h"
#include "Vehicle.h"
#include "VehicleList.h"

class MyTracker
{
public:
	MyTracker();
	~MyTracker();

	virtual void track() = 0;			//connect vehicles and detected vehilceFrames

	void getVehicle();

private:

	Vehicle vehicle;
	VehicleDetector vehDetector;		//a detector the tracker uses to assign the vehicle frame to the vehicle
	

};
