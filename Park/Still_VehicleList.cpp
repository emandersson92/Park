#include "stdafx.h"
#include "Still_VehicleList.h"


Still_VehicleList::Still_VehicleList()
{
}


Still_VehicleList::~Still_VehicleList()
{
}

//send the vehicle to the next list
void Still_VehicleList::forwardVehicle(Vehicle* v) {
	v->vehicleList = v->VehicleList->nextVehicleList();

}			


void Still_VehicleList::checkListConditions() {}
bool Still_VehicleList::belongCheck(Vehicle* v) { 
	if(v->vehicleParked()){
		return true;
	}
	return false; 
}
