/********************************
Info:
MyTracker object connects vehicles and vehicleFrames

Author:
Emil Andersson 2017-07-19
********************************/

#include "stdafx.h"
#include "MyTracker.h"


MyTracker::MyTracker()
{

}


MyTracker::~MyTracker()
{
}

Vehicle* MyTracker::getVehicle() {
	return vehicle;
}