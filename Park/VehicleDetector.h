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

	virtual void apply(std::vector<std::vector<cv::Point>>& c) = 0;
	virtual void getRaw(cv::Mat& m) = 0;

	virtual void imgAquist(cv::Mat& raw) = 0;
	virtual void segment(cv::Mat& in, cv::Mat& out) = 0;
	virtual void filter(cv::Mat& in, cv::Mat& out) = 0;
	virtual void classify(cv::Mat& classified, std::vector<std::vector<cv::Point>>& c) = 0;

private:
	

};

