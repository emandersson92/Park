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
	void addTimeText(Mat& img, MyTracker& t);
	void drawContours(Mat& img, MyTracker& t);


};

