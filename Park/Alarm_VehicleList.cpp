#include "stdafx.h"
#include "Alarm_VehicleList.h"


Alarm_VehicleList::Alarm_VehicleList()
{
}


Alarm_VehicleList::~Alarm_VehicleList()
{
}

//send the vehicle to the next list
void Alarm_VehicleList::forwardVehicle(Vehicle* v) {
	v->vehicleList = v->VehicleList->nextVehicleList();

}			


void Alarm_VehicleList::checkListConditions() {}
bool Alarm_VehicleList::belongCheck(Vehicle* v) { 

	//first call will start the timer

	double ptime = v->getParkTime();
	double lifeThresh = v->getLifeThresh();
	double lifeLeft = v->getLifeLeft();
		
	///Printing info in console
	std::cout << "Parktime: " << ptime << " of " << parktimelimit << std::endl;
	std::cout << "Life: " <<  lifeLeft << " of " << lifeThresh << " minimum " << std::endl << std::endl;

	
	if (!v->isAlive()) {
		std::cout << "VEHICLE HAS LEFT PARKING LOT" << std::endl;
		getchar();
		exit(0);
	}

	else if (ptime > parktimelimit) {
		std::cout << "VEHICLE HAS BEEN PARKING TO LONG!" << std::endl;
		getchar();
		exit(0);
	}

 

