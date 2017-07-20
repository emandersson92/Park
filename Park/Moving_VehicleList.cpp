#include "stdafx.h"
#include "Moving_VehicleList.h"


Moving_VehicleList::Moving_VehicleList()
{
}


Moving_VehicleList::~Moving_VehicleList()
{
}

void Moving_VehicleList::forwVehicle() {
	

}

void Moving_VehicleList::checkListConditions() {
	//
	for (Vehicle v : vehicles) {
		v.
	}
}







bool Moving_VehicleList::belongCheck(Vehicle v) {
	
	

	//speed ok?
	if (v.getSpeed > maxSpeed)
		return false;
	

	//postition ok?
	Rect2d a;
	if(!a.contains(okArea.x))
		return false


	return true;

}

void Moving_VehicleList::forwardVehicle(Vehicle& v) {
	
	nextList->trackers.push_back(v);
	
	//delete vehicle from vector
	vehicles.erase(vehicles.get_allocator());



}