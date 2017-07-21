#pragma once
#include "VehicleList.h"
#include "Vehicle.h"
#include "opencvIncludes.h"	

class Moving_VehicleList : public VehicleList
{
public:
	Moving_VehicleList();
	~Moving_VehicleList();

	void forwardVehicle(Vehicle* v);			//send the vehicle to the next list
	void connectTo(VehicleList* l);
	void checkListConditions();
	bool belongCheck(Vehicle& v);
	
	


private:
	
	//Conditions vehicles need to pass in order to belong to the list
	double maxSpeed;
	Rect2d okArea;


};

