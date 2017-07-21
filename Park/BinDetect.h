/********************************
Info:
This is a simple homebrewed vehicle detection application
The class uses simple biary image classification


Author:
Emil Andersson 2017-07-19
********************************/
#pragma once

#include "opencvIncludes.h"
#include "VehicleDetector.h"

#include "ImgAcquisition.h"
#include "BgsSegment.h"
#include "Filter.h"
#include "BinClassify.h"


class BinDetect : public VehicleDetector
{

public:
	BinDetect();
	~BinDetect();

	void apply(cv::Mat& out);

	

private:

	
	void imgAquist(cv::Mat& in, cv::Mat& out);
	void segment(cv::Mat& in, cv::Mat& out);
	void filter(cv::Mat& in, cv::Mat& out);
	void classify(cv::Mat& in, cv::Mat& out);
	

	cv::Mat in;


	//Application specific choices:
	const int Path = ImgAcquisition::BIN_DOT_IMG;



};

