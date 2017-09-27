/*
Vehicle List contains at least one tracker of some kind. It can for instance be a movingObj_MyTracker or a StillObj_MyTracker.

 */
#pragma once
#include "opencvIncludes.h"

#include "MyTracker.h"
#include "Vehicle.h"

class Vehicle;			//Declaration needed because of nested includes
class MyTracker;

class VehicleList
{
public:
	VehicleList();
	~VehicleList();

	virtual void forwardVehicle(Vehicle* v) = 0;			//send the vehicle to the next list

	virtual void checkListConditions() = 0;
	virtual bool belongCheck(Vehicle* v) = 0;

	void connectTo(VehicleList* l);

	std::vector<MyTracker*> trackers;

	//Can be multiple lists in future
	VehicleList* nextList;

};

