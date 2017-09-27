#pragma once
#include "VehicleList.h"

class Alarm_VehicleList : public VehicleList
{
public:
	Alarm_VehicleList();
	~Alarm_VehicleList();

	void forwardVehicle(Vehicle* v);			//send the vehicle to the next list
	void checkListConditions();
	bool belongCheck(Vehicle* v);


};

