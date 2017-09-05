/********************************
Info:
Class to acquisition an image from an image or a video source
Image path's is integrated in the class


Author:
Emil Andersson 2017-07-18
********************************/
#pragma once
#include "ImgAcquisition.h"
#include "ImgAcquisition_vs15.h"
#include "MediaPaths.h"

class ImgAcquisition_vs15 : public ImgAcquisition
{
public:
	ImgAcquisition_vs15(std::string media);
	~ImgAcquisition_vs15();

	void apply(cv::Mat& out);



private:


	void getImg(std::string& path, cv::Mat& out);
	bool hasEnding (std::string const &fullString, std::string const &ending);
	void error(std::string& path);
	

	cv::VideoCapture cap;

	std::string path;							//Path to be used

	bool vidPath = false;
	bool imgPath = false;

};

