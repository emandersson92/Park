#pragma once

#include "opencvIncludes.h"

/********************************
Info:
Class that segment the foreground from the background in a videostream.
The constructor shall define what function to use when apply() is called.


Author:
Emil Andersson 2017-07-18
********************************/

class BgsSegment
{
public:
	BgsSegment();
	~BgsSegment();

	void apply(Mat& in, Mat& out);


private: 
	//void(*f)(int);
	void BgsMog2(Mat& in, Mat& out);
	
	Ptr<BackgroundSubtractor> b; //MOG2 Background subtractor


};

