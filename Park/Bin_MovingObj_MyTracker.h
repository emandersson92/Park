/*
Tracking by detection  
Author: Emil Andersson 
 */

#pragma once
#include "MovingObj_MyTracker.h"
#include "VehicleDetector.h"
#include "BinDetect.h"
#include "MediaPaths.h"
#include "tools.h"
/*


 */

#include "environment.h"
#include "MyAssert.h"
#include "VehicleList.h"
#include "MyTracker.h"

class Bin_MovingObj_MyTracker : MyTracker{

public:
	
	Bin_MovingObj_MyTracker(VehicleDetector* d, int arg_minObjArea, VehicleList* list);
	~Bin_MovingObj_MyTracker();
	std::vector<Vehicle*> Bin_MovingObj_MyTracker::getVehicles();
	void Bin_MovingObj_MyTracker::paint();
	void track();


private:

	cv::Mat in_detect;
	cv::Mat raw;
	cv::Mat tmp1;
	cv::Mat out_detect;

	VehicleDetector* detector;
	VehicleList* vehicleList;///Access to the list the vehicle is connected to for now
	
	std::vector<std::vector<cv::Point>>* contours;		//contours is updated from detectVehicles(); 

	int minObjArea;

};

