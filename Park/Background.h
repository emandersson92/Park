#pragma once

#include "stdafx.h"
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"


class Background
{
public:
	Background();
	~Background();

	int calcHist(char* img);


};
