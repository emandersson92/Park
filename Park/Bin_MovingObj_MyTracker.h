#pragma once
#include "MovingObj_MyTracker.h"
#include "BinDetect.h"

class Bin_MovingObj_MyTracker : public MovingObj_MyTracker
{
public:
	Bin_MovingObj_MyTracker();
	~Bin_MovingObj_MyTracker();

	void track();


private:
	VehicleDetector* detector;
	std::vector<cv::Mat> cars;


};

