#pragma once
#include "opencvIncludes.h"
#include "Show.h"

class Filter
{
public:
	Filter();								//define function to run when apply() is called 
	~Filter();

	void apply(cv::Mat& in, cv::Mat& out);			//run function defined in constructor


private:
	void init();

	void openFilter(cv::Mat& in, cv::Mat& out);
	void closeFilter(cv::Mat& in, cv::Mat& out);


	cv::Mat erElem;								//Erode element
	cv::Mat diElem;								//Dilate element

	Show* show;

};

