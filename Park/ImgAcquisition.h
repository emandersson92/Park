/********************************
Info:
Abstract class which shall be included by Imgage acquisition classes

Author:
Emil Andersson 2017-08-30
********************************/
#pragma once
#include "opencvIncludes.h"

class ImgAcquisition
{
public:
	ImgAcquisition();
	~ImgAcquisition();

	virtual void apply(cv::Mat& out) = 0;

};

