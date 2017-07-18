#pragma once
#include "opencvIncludes.h"


class Filter
{
public:
	Filter();								//define function to run when apply() is called 
	~Filter();

	void apply(Mat& in, Mat& out);			//run function defined in constructor


private:
	void init();

	void openFilter(Mat& in, Mat& out);
	void closeFilter(Mat& in, Mat& out);


	Mat erElem;								//Erode element
	Mat diElem;								//Dilate element

};

