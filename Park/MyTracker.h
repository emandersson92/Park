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

	VehicleList list;					//the list the tracker is connected to

private:

	Vehicle vehicle;
	VehicleDetector vehDetector;		//


};
