#pragma once
#include "MovingObj_MyTracker.h"
#include "BinDetect.h"
#include "MediaPaths.h"

class Bin_MovingObj_MyTracker : public MovingObj_MyTracker
{
public:
	Bin_MovingObj_MyTracker(std::vector<std::vector<cv::Point>>* c);
	~Bin_MovingObj_MyTracker();

	void track();


private:
	VehicleDetector* detector;
	std::vector<cv::Mat> cars;
	
	std::vector<std::vector<cv::Point>>* contours;		//contours is updated from detectVehicles(); 

};

