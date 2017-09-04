#include "stdafx.h"
#include "Vehicle.h"


Vehicle::Vehicle()
{
}


Vehicle::~Vehicle()
{
}

Vehicle::getLastVehicleFrame(){
  return vehicleFrames->back();

}

Vehicle::addVehicleFrame(VehicleFrame* v){
  vehicleFrames->push_back(v); 
}
