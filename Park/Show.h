/********************************
Info:
Class to simplify image handling in opencv

Author:
Emil Andersson 2017-07-30
********************************/
#pragma once
#include "vector"
#include "string"
#include "opencv2\core.hpp"
#include "opencv2\highgui.hpp"
#include "opencv2\imgproc.hpp"


struct myWindow{
	cv::Mat image;
	std::string name;
};


class Show
{
public:
	Show();
	~Show();

	static void add(cv::Mat& img, const char * name);
	static void addText();
	static void showImg();

private:
	
	
	static std::vector<myWindow> windows;
	static std::vector<cv::Mat> images;
	static cv::Point Show::getNewPos(const int dx);

	static int winCount;


	//static int winCount;
};

