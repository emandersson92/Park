/********************************
Info:
Class to acquisition an image from an image or a video source
Image path's is integrated in the class


Author:
Emil Andersson 2017-08-30
********************************/
#pragma once
#include "ImgAcquisition.h"
#include "ImgAcquisition_vs17.h"

class ImgAcquisition_vs17 : public ImgAcquisition
{
public:
	ImgAcquisition_vs17(int pathNmb);
	ImgAcquisition_vs17();
	~ImgAcquisition_vs17();

	void apply(cv::Mat& out);

	const static int BIN_DOT_IMG = 1;
	const static int PED_CROSS_VID = 2;

private:

	std::string bin_dot_img_path = "img\\bin_dot_1.png";
	std::string pedest_cross_vid_path = "vid\\p0.mp4";
	// ...
	// ...
	// ...

	void getImg(std::string& path, cv::Mat& out);
	void setPath(int pathNmb, std::string& path);

	void error(std::string& path);
	

	cv::VideoCapture cap;

	std::string path;							//Path to be used

	bool vidPath = false;
	bool imgPath = false;

};

