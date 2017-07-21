/********************************
Info:
This class is a template of a vehile detector
The class can be used in tracker objects

Author:
Emil Andersson 2017-07-DATE
********************************/
#pragma once
#include "opencvIncludes.h"

class VehicleDetector
{
public:
	VehicleDetector();
	~VehicleDetector();
	
	//The parts that must be included in a VehicleDetector-abstraction 

	virtual void apply(cv::Mat& out) = 0;

private:

	virtual void imgAquist(cv::Mat& in, cv::Mat& out) = 0;
	virtual void segment(cv::Mat& in, cv::Mat& out) = 0;
	virtual void filter(cv::Mat& in, cv::Mat& out) = 0;
	virtual void classify(cv::Mat& in, cv::Mat& out) = 0;
	

};

