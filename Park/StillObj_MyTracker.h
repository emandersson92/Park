/********************************
Info:
Area is tracked
Movement on area will "eat" the trackers area
When area is to small the tracker will get destroyed

Author:
Emil Andersson 2017-07-DATE
********************************/

#pragma once
#include "vector"
#include "opencv2\core.hpp"
#include "opencv2\imgproc.hpp"

#include "Timer.h"
#include "VehicleDetector.h"
#include "Vehicle.h"

typedef std::vector<cv::Point> vecCont;
typedef std::vector<vecCont> vecVecCont;


class StillObj_MyTracker
{
public:
	StillObj_MyTracker();
	~StillObj_MyTracker();

	void track();

private:

	VehicleDetector* detector;

	Timer* timer;

	Boolean FIRST;

	cv::Mat ROI;

	std::vector<Point>* init_trackArea;
	std::vector<Point>* cur_trackArea;


	//Tracker survival data
	void surviveTest();
	///min life before tracker dies in % (cur_trackArea/init_trackArea). 
	const double minLife = 30.0;
	boolean ALIVE; // lists with trackers can check i trackers are dead. If they are, they can be removed and later freed.
};

