/********************************
Info:
Area is tracked
Movement on area will "eat" the trackers area
When area is to small the tracker will get destroyed


Author:
Emil Andersson 2017-07-DATE
********************************/

#pragma once
#include "vector"
#include "opencv2\core.hpp"
#include "opencv2\imgproc.hpp"
#include "Timer.h"


typedef std::vector<std::vector<cv::Point>> vecVecCont;

class StillObj_MyTracker
{
public:
	StillObj_MyTracker();
	~StillObj_MyTracker();

	void track();

private:


	void alarm();


	Timer t;
	vecVecCont trackarea;



};

