#pragma once

#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace std;
using namespace cv;

class myImgProc
{

public:
	myImgProc();
	~myImgProc();
	void bgs(Mat& img);

};

