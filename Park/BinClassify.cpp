#include "stdafx.h"
#include "BinClassify.h"


BinClassify::BinClassify()
{
}
BinClassify::~BinClassify()
{
}

void BinClassify::apply(cv::Mat& img, std::vector<std::vector<cv::Point>>& contours){
	//implement so constructor defines which function to call
	findCont(img, contours);
	checkArea(contours);

}			

void BinClassify::findCont(cv::Mat& img, std::vector<std::vector<cv::Point>>& contours){
	std::vector<cv::Vec4i> hierarchy;

	cv::findContours(img, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, cv::Point(0, 0));
	//cv::findContours()
}

void BinClassify::checkArea(std::vector<std::vector<cv::Point>>& contours) {
	
	std::vector<std::vector<cv::Point>>::const_iterator i;

	//TODO Using vectors is reducing the speed of the program????
	for (i = contours.begin(); i!= contours.end(); ++i)
	{
		cv::Rect2d r = cv::boundingRect(*i);

		///if not right area
		if(r.width > widMax || r.width < widMin || r.height > heiMax || r.height < heiMin)
		{
			//I think this code will increment all elements by one after the removed object. 
			contours.erase(i);
		}

}