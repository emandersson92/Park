/********************************
Info:
A vehicles area is tracked.
Movement on the vehicleArea will be "rubbered" (the vehicle is moving)
When the vehcileArea is to small the vehicle has left the parkinglot

Author:
Emil Andersson 2017-09-07
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
#include "VehicleList.h"

//Test
#include "MyAssert.h"


typedef std::vector<cv::Point> vecCont;
typedef std::vector<vecCont> vecVecCont;


class StillObj_MyTracker : public MyTracker
{
 public:
	StillObj_MyTracker(Vehicle* v, VehicleDetector* d, VehicleList* list);
  ~StillObj_MyTracker();

	void track();
	bool isAlive();
	double getParkTime();
	cv::Mat getLastImg();
	void paint();
	
	double getLifeThresh();
	double getLifeLeft();

	

private:

	double percentage_foreground(cv::Mat& m);
	void reduceVehicleArea();
	void surviveTest();
	void restoreVehicleArea();

	VehicleDetector* detector;
	VehicleList* vehicleList;
	
	cv::Mat raw;
	cv::Mat in_detect;
	cv::Mat tmp1;
	cv::Mat tmp2;
	cv::Mat out_detect;//Mat after detection


	
	bool FIRST;
};

