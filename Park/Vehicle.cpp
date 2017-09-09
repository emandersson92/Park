#include "stdafx.h"
#include "Vehicle.h"


Vehicle::Vehicle(VehicleFrame* vf)
{
	vehicleFrames.push_back(vf);
	VF_found = false;
}

Vehicle::Vehicle()
{
	VF_found = false;
}


Vehicle::~Vehicle()
{
}

VehicleFrame* Vehicle::getLastVehicleFrame(){
	return vehicleFrames.back();

}

double Vehicle::getSpeed() {
	return getLastVehicleFrame()->getSpeed();
}

void Vehicle::addVF(VehicleFrame* v){
  vehicleFrames.push_back(v); 
}



void Vehicle::addVF_ifBelong(VehicleFrame* vf){
	
	//NOT USED
	///if first
	if(vehicleFrames.empty()){
		vehicleFrames.push_back(vf);
	}


}

