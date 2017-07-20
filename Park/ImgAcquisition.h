/********************************
Info:
Class to acquisition an image from an image or a video source
Image path's is integrated in the class


Author:
Emil Andersson 2017-07-18
********************************/

#pragma once
#include "opencvIncludes.h"

class ImgAcquisition
{
public:
	ImgAcquisition(int pathNmb);
	~ImgAcquisition();

	void apply(Mat& out);

	const static int BIN_DOT_IMG = 1;
	int OTHER_IMG = 2;

private:

	const string bin_dot_img_path = "img\\bin_dot_1.png";
	// ...
	// ...
	// ...


	void getBinDot(string& path, Mat& out);
	void setPath(int pathNmb, string& path);

	string path;							//Path to be used


};
