/********************************
Info:
This class is a template of a vehile detector
The class can be used in tracker objects

Author:
Emil Andersson 2017-07-DATE
********************************/
#pragma once
#include "opencvIncludes.h"

using namespace cv;

class VehicleDetector
{
public:
	VehicleDetector();
	~VehicleDetector();
	
	//The parts that must be included in a VehicleDetector-abstraction 

	virtual void apply(Mat& out) = 0;

private:

	virtual void imgAquist(Mat& in, Mat& out) = 0;
	virtual void segment(Mat& in, Mat& out) = 0;
	virtual void filter(Mat& in, Mat& out) = 0;
	virtual void classify(Mat& in, Mat& out) = 0;
	

};

