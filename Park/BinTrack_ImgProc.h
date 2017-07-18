#pragma once

#include "opencvIncludes.h"
#include "ImgProc.h"
#include "BgsSegment.h"
#include "Filter.h"
#include "BgsSegment.h"
#include "BinTracker.h"

using namespace std;
using namespace cv;

class BinTrack_ImgProc : public ImgProc
{

public:
	BinTrack_ImgProc();
	~BinTrack_ImgProc();
	void bgs(Mat& img);

	void segment(Mat& img);
	void filter(Mat& img);
	void classify(Mat& img);
	void tracking(Mat& img);


};

