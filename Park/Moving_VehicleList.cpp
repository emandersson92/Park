#include "stdafx.h"
#include "Moving_VehicleList.h"


Moving_VehicleList::Moving_VehicleList()
{
}


Moving_VehicleList::~Moving_VehicleList()
{
}


void Moving_VehicleList::forwardVehicle(Vehicle* v) {

	nextList->vehicles.push_back(v);

	//delete vehicle from vector
	

	/*
	
	 i = vehicles(v);


	list<Vehicle*>::iterator i = vehicles_Make_iter(v);

	vehicles.erase(vehicles.get_allocator(v));
	vehicles.c


	vehicles.erase();
	vehicles.erase(vehicles.get_allocator());
	*/



void Moving_VehicleList::connectTo(VehicleList* l) {

}


void Moving_VehicleList::checkListConditions() {
	//
	for (Vehicle* v : vehicles) {
		
	}
}

bool Moving_VehicleList::belongCheck(Vehicle& v) {
	
	

	//speed ok?
	if (v.getSpeed > maxSpeed)
		return false;
	

	return true;
	/*
	//postition ok?
	Rect2d a;
	if(!a.contains(okArea.x))
		return false
	return true;
	*/
}

