#pragma once
#include "opencvIncludes.h"
#include "MyTracker.h"
#include "VehicleList.h"


class VehicleList
{
public:
	VehicleList();
	~VehicleList();

	virtual void forwVehicle() = 0;			//send the vehicle to the next list
	virtual void connectTo(VehicleList l) = 0;
	virtual void checkListConditions() = 0;
	virtual void belongCheck(Vehicle& v) = 0;


	vector<MyTracker> trackers;

	VehicleList* nextList;

};

