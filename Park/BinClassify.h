/********************************
Info:
Function to classify objects in the image.
The constructor defines which function to use when apply() is called.


Author:
Emil Andersson 2017-07-18
********************************/
#pragma once

#include "opencv2\core.hpp"
#include "opencv2\imgproc.hpp"

class BinClassify
{
public:
	BinClassify();
	~BinClassify();

	void apply(cv::Mat& img, std::vector<std::vector<cv::Point>>& contours);			//run function defined in constructor


private:
	void findCont(cv::Mat& img, std::vector<std::vector<cv::Point>>& contours);		//functions

	void checkArea(std::vector<std::vector<cv::Point>>& contours);

	int widMax = 200;
	int widMin = 5;
	int heiMax = 200;
	int heiMin = 5;

};

