#pragma once
#include "opencvIncludes.h"
#include "MyTracker.h"

class draw
{
public:
	draw();
	~draw();
	
	//General functions
	void addText();
	void addKeyInfoText();

	//Park application functions
	void addTimeText(cv::Mat& img, MyTracker& t);
	void drawContours(cv::Mat& img, MyTracker& t);


};

