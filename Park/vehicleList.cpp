#include "stdafx.h"
#include "vehicleList.h"


using namespace std;

VehicleList::VehicleList()
{
}


VehicleList::~VehicleList()
{
}


void connectTo(VehicleList* l){
	nextList = l;

}

