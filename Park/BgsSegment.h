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

	void apply(cv::Mat& in, cv::Mat& out);


private: 
	//void(*f)(int);
	void BgsMog2(cv::Mat& in, cv::Mat& out);
	
	cv::Ptr<cv::BackgroundSubtractor> b; //MOG2 Background subtractor


};

