/********************************
Info:
This is a simple homebrewed vehicle detection application
The class uses simple biary image classification
BinDetect is a collection of imgAquist, segment, filter and classify.
If the application program will only use parts of these, they have to be called individually
All Mat objects are created in this class. There shall be getters and setters for these. TODO
The contours given as argument to apply() will be altered in this object.


Author:
Emil Andersson 2017-07-19
********************************/
#pragma once
#include "opencv2\core.hpp"

#include "VehicleDetector.h"
#include "ImgAcquisition.h"
#include "ImgAcquisition_vs15.h"
#include "ImgAcquisition_vs17.h"
#include "BgsSegment.h"
#include "Filter.h"
#include "BinClassify.h"



class BinDetect : public VehicleDetector
{

public:
	BinDetect(int IMGAC);
	~BinDetect();

	void apply(std::vector<std::vector<cv::Point>>& contours);

	void imgAquist(cv::Mat& out);
	void segment(cv::Mat& in, cv::Mat& out);
	void filter(cv::Mat& in, cv::Mat& out);
	void classify(cv::Mat& in, std::vector<std::vector<cv::Point>>& contours);


	static const int VS_15 = 1;
	static const int VS_17 = 2;
	static const int RASPBERRY = 3;


private:
	
	
	void getRaw(cv::Mat& m);


	cv::Mat raw;
	cv::Mat segmented;
	cv::Mat filtered;
	cv::Mat classified;

	ImgAcquisition* a;
	BgsSegment* s;
	Filter* f;
	BinClassify* d;


	//Application specific choices:
	//const int Path = ImgAcquisition::PED_CROSS_VID;
	//const int Path = ImgAcquisition::BIN_DOT_IMG;

		
};

