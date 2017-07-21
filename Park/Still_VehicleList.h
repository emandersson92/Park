#pragma once
#include "VehicleList.h"

class Still_VehicleList : public VehicleList
{
public:
	Still_VehicleList();
	~Still_VehicleList();

	void forwardVehicle(Vehicle* v);			//send the vehicle to the next list
	void connectTo(VehicleList* l);
	void checkListConditions();
	bool belongCheck(Vehicle& v);

};

