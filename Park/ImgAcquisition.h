#pragma once
#include "opencvIncludes.h"

class ImgAcquisition
{
public:
	ImgAcquisition(int pathNmb);
	~ImgAcquisition();

	void apply(string path, Mat& out);

	static int BIN_DOT_IMG = 1;
	int OTHER_IMG = 2;

private:

	const string bin_dot_img_path = "img\\bin_dot_1.png";
	// ...
	// ...
	// ...


	void getImg(string& path, Mat& out);
	void setPath(int pathNmb, string& path);

	string path;							//Path to be used


};

