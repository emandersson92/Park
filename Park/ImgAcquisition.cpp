#include "stdafx.h"
#include "ImgAcquisition.h"


ImgAcquisition::ImgAcquisition(int pathNmb)
{
	setPath(pathNmb, path);
}

ImgAcquisition::~ImgAcquisition()
{
}

//Called from constructor
void ImgAcquisition::setPath(int pathNmb, std::string& path) {
	switch (pathNmb) {
	case BIN_DOT_IMG:
		path = "img\\bin_dot_1.png";
		break;

	default:
		std::cout << "could not set image path" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "press any key to quit" << std::endl;
		getchar();
		exit(-1);
	}
}




void ImgAcquisition::apply(Mat& out) {
	getBinDot(path, out);
}


void ImgAcquisition::getBinDot(string& path, Mat& out) {
	try {
		out = imread(path);
	}
	catch (exception e) {
		cout << "Could not load image from path:" << endl;
		cout << path << endl;
		cout << "" << endl;
		cout << "Push any character to exit" << endl;
		getchar();
		exit(-1);
	}
}

