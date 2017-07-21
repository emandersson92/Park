#include "stdafx.h"
#include "Bin_MovingObj_MyTracker.h"


Bin_MovingObj_MyTracker::Bin_MovingObj_MyTracker(){

	detector = new BinDetect();				//This tracker type uses BinDetect-detector
}


Bin_MovingObj_MyTracker::~Bin_MovingObj_MyTracker(){
	delete(detector);
}

void Bin_MovingObj_MyTracker::track() {
	cv::Mat out;
	detector->apply(out);

	//compare and match existing vehicle with the new VehicleFrame

	//bounding box code
	//...
	//...
	//...


}