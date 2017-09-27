#pragma once
#include "VehicleDetector.h"
#include "Vehicle.h"
#include "VehicleList.h"

class Vehicle; //Declaration

class MyTracker
{
public:
	MyTracker();
	~MyTracker();

	virtual void track() = 0;			//connect vehicles and detected vehilceFrames
	virtual bool isAlive() = 0;
	virtual double getParkTime() = 0;

	virtual cv::Mat getLastImg() = 0;
	virtual void paint() = 0;	
	//virtual std::vector<Vehicle*> getVehicles() = 0; TODO!

	virtual double getLifeThresh() = 0;
	virtual double getLifeLeft() = 0;
	
	std::vector<Vehicle*> getVehicles();


private:

	std::vector<Vehicle*> vehicles;
	VehicleDetector* vehDetector;		//a detector the tracker uses to assign the vehicle frame to the vehicle
	

};
