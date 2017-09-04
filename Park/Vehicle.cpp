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
