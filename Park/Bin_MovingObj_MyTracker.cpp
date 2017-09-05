#include "stdafx.h"
#include "Bin_MovingObj_MyTracker.h"


Bin_MovingObj_MyTracker::Bin_MovingObj_MyTracker(std::vector<std::vector<cv::Point>>* c){
	contours = c;
	detector = new BinDetect(traffic);				//This tracker type uses BinDetect-detector
}


Bin_MovingObj_MyTracker::~Bin_MovingObj_MyTracker(){
	delete(detector);
}


void Bin_MovingObj_MyTracker::track() {
	cv::Mat out;

	//TODO add contours as argument 
	//detector->apply(out);



	//compare and match existing vehicle with the new VehicleFrame

	//bounding box code
	//...
	//...
	//...


}



