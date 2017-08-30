#include "stdafx.h"
#include "ImgAcquisition_vs17.h"


ImgAcquisition_vs17::ImgAcquisition_vs17() {}

ImgAcquisition_vs17::ImgAcquisition_vs17(int pathNmb)
{
	setPath(pathNmb, path);

	if (vidPath)
	{


		cap = cv::VideoCapture("Park\\vid\\p0.mp4");
		if (!cap.isOpened())
			error(path);


		cap = cv::VideoCapture("img\\bin_dot_1.png");
		if (!cap.isOpened())
			error(path);


		cap = cv::VideoCapture("vid\\p0.mp4");
		if (!cap.isOpened())
			error(path);


		cap = cv::VideoCapture(path);
		if (!cap.isOpened())
			error(path);
	}
}

ImgAcquisition_vs17::~ImgAcquisition_vs17()
{
}

//Called from constructor
void ImgAcquisition_vs17::setPath(int pathNmb, std::string& path) {
	switch (pathNmb) {
	case BIN_DOT_IMG:
		path = bin_dot_img_path;
		imgPath = true;
		break;

	case PED_CROSS_VID:
		path = pedest_cross_vid_path;
		vidPath = true;
		break;


	default:
		std::cout << "could not set image path" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "press any key to quit" << std::endl;
		getchar();
		exit(-1);
	}
}



void ImgAcquisition_vs17::apply(cv::Mat& out) {
	if (vidPath)
	{
		cap >> out;
		if (out.empty())
		{
			error(path);
		}
	}

	if (imgPath)
	{
		getImg(path, out);
	}
}


void ImgAcquisition_vs17::getImg(std::string& path, cv::Mat& out) {
	try {
		out = cv::imread(path);
	}
	catch (std::exception e) {
		error(path);
	}
}

void ImgAcquisition_vs17::error(std::string& path) {
	std::cout << "Could not load file from path:" << std::endl;
	std::cout << path << std::endl;
	std::cout << "" << std::endl;
	std::cout << "Push any character to exit" << std::endl;
	getchar();
	exit(0);
}
