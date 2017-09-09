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

class Bin_MovingObj_MyTracker{

public:
	
	Bin_MovingObj_MyTracker(VehicleDetector* d, int arg_minObjArea);
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
	std::vector<Vehicle*> vehicles;
	
	std::vector<std::vector<cv::Point>>* contours;		//contours is updated from detectVehicles(); 

	int minObjArea;

};

