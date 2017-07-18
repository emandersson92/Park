#pragma once

#include "opencvIncludes.h"

/********************************
Info:
Function to classify objects in the image.
The constructor defines which function to use when apply() is called.


Author:
Emil Andersson 2017-07-18
********************************/

class BinClassify
{
public:
	BinClassify();
	~BinClassify();

	void apply(Mat& img);			//run function defined in constructor

	//functions
	void findCont(Mat& img);

};

