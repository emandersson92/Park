#include "stdafx.h"
#include "BinClassify.h"


BinClassify::BinClassify()
{
}
BinClassify::~BinClassify()
{
}

void BinClassify::apply(Mat& img){
	//implement so constructor defines which function to call
	findCont(img);

}			

void BinClassify::findCont(Mat& img){
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;

	findContours(img, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));

}
