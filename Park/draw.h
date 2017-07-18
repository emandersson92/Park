#pragma once

#include "opencvIncludes.h"


class draw
{
public:
	draw();
	~draw();
	
	//General functions
	void addText();
	void addKeyInfoText();

	//Park application functions
	void addTimeText(Mat& img, myTracker& t);
	void drawContours(Mat& img, myTracker& t);


};

