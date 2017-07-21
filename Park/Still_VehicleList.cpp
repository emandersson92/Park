#include "stdafx.h"
#include "Still_VehicleList.h"


Still_VehicleList::Still_VehicleList()
{
}


Still_VehicleList::~Still_VehicleList()
{
}

void Still_VehicleList::forwardVehicle(Vehicle* v) {}			//send the vehicle to the next list
void Still_VehicleList::connectTo(VehicleList* l) {}
void Still_VehicleList::checkListConditions() {}
bool Still_VehicleList::belongCheck(Vehicle& v) {}
