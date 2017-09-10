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
	while(!vehicleFrames.empty()){
		VehicleFrame* vf = vehicleFrames.back();
		vehicleFrames.pop_back();
		delete(vf);
	}
}

VehicleFrame* Vehicle::getLastVehicleFrame(){
	return vehicleFrames.back();

}

double Vehicle::getVehicleSpeed() {
	return -1;
}


cv::Point Vehicle::filterCentroid() {
	///average filter n back

	const int n = 5;
	int cnt = 0;
	int avex = 0;///average speed
	int avey = 0;
	auto middleVF = vehicleFrames.end();///vehicleframe in middle of filter

	for (auto it = vehicleFrames.end(); it != vehicleFrames.begin();) {
		--it;
		cv::Point p = (*it)->getCentroid();
		
		///if speed not undefined
		avex += p.x;
		avey += p.y;

		if (cnt == n / 2) {
			middleVF = it;
		}

		if (cnt++ >= n) {
			break;
		}
	}

	cv::Point p = cv::Point(avex, avey);

	///set filtered Centroid
	(*middleVF)->setFilteredCentroid(p);

	if (cnt == 0) {
		return -1;
	}
	else {
		avex /= cnt;
		avey /= cnt;
		return p;
	}
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


std::vector<VehicleFrame*> Vehicle::getVehicleFrames() {
	return vehicleFrames;
}
