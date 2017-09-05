#include "stdafx.h"
#include "Vehicle.h"


Vehicle::Vehicle()
{
}


Vehicle::~Vehicle()
{
}

VehicleFrame* Vehicle::getLastVehicleFrame(){
	return vehicleFrames.back();

}

void Vehicle::addVehicleFrame(VehicleFrame* v){
  vehicleFrames.push_back(v); 
}
