#pragma once
#include "opencvIncludes.h"
#include "MyTracker.h"
#include "VehicleList.h"
#include "Vehicle.h"


class VehicleList
{
public:
	VehicleList();
	~VehicleList();

	virtual void forwardVehicle(Vehicle* v) = 0;			//send the vehicle to the next list
	virtual void connectTo(VehicleList* l) = 0;
	virtual void checkListConditions() = 0;
	virtual bool belongCheck(Vehicle& v) = 0;


	vector<MyTracker*> trackers;
	list<Vehicle*> vehicles;

	VehicleList* nextList;

};

