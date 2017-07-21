#include "stdafx.h"
#include "BinClassify.h"


BinClassify::BinClassify()
{
}
BinClassify::~BinClassify()
{
}

void BinClassify::apply(cv::Mat& img){
	//implement so constructor defines which function to call
	findCont(img);

}			

void BinClassify::findCont(cv::Mat& img){
	std::vector<std::vector<cv::Point> > contours;
	std::vector<cv::Vec4i> hierarchy;

	findContours(img, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, cv::Point(0, 0));

}
