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

using namespace std;
using namespace cv;

class BinDetect : public VehicleDetector
{

public:
	BinDetect();
	~BinDetect();

	void apply(Mat& out);

	

private:

	
	void imgAquist(Mat& in, Mat& out);
	void segment(Mat& in, Mat& out);
	void filter(Mat& in, Mat& out);
	void classify(Mat& in, Mat& out);
	

	Mat in;


	//Application specific choices:
	const int Path = ImgAcquisition::BIN_DOT_IMG;



};

