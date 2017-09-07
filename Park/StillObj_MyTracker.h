/********************************
Info:
Area is tracked
Movement on area will "eat" the trackers area
When area is to small the tracker will get destroyed

Author:
Emil Andersson 2017-07-DATE
********************************/

#pragma once

//Opencv
#include "vector"
#include "opencv2\core.hpp"
#include "opencv2\imgproc.hpp"

//My classes
#include "VehicleDetector.h"
#include "VehicleFrame.h"
#include "Vehicle.h"
#include "MyTimer.h"
#include "SimpleTimer.h"
#include "MyTracker.h"

//Test
#include "MyAssert.h"


typedef std::vector<cv::Point> vecCont;
typedef std::vector<vecCont> vecVecCont;


class StillObj_MyTracker : public MyTracker
{
 public:
  StillObj_MyTracker(Vehicle* v, VehicleDetector* d);
  ~StillObj_MyTracker();

	void track();
	bool isAlive();
	double getParkTime();
	cv::Mat getLastImg();
	void paint();
	


private:

	double percentage_foreground(cv::Mat m);
	void reduceTrackerArea();
	void surviveTest();

	VehicleFrame* stillTrack_VehicleFrame;
	VehicleDetector* detector;
	
	cv::Mat in_detect;
	cv::Mat tmp1;
	cv::Mat tmp2;
	cv::Mat out_detect;

	MyTimer* timer;
	
	bool FIRST;


	cv::Mat init_trackBinROI; //Initially binary image with tracked vehicle in foreground 
	cv::Mat cur_trackBinROI;//Current binary image.......

	
	///min life before tracker dies in % (cur_trackArea/init_trackArea). 
	const double _minLife = 30.0;
	bool ALIVE; // lists with trackers can check i trackers are dead. If they are, they can be removed and later freed.
};

