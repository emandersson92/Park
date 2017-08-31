#include "stdafx.h"
#include "BinDetect.h"


BinDetect::BinDetect(int IMGAC)
{
	
	if (IMGAC == VS_15)
	{
		a = new ImgAcquisition_vs15();
	}

	else if(IMGAC == VS_17)
	{
		a = new ImgAcquisition_vs17();
	}
	//else if(IMGAC == RASPBERRY){
	  //a = new ImgAcquisition_raspberry();
	//}
	

	s = new BgsSegment();
	f = new Filter();
	d = new BinClassify();
}

BinDetect::~BinDetect(){}


void BinDetect::apply(std::vector<std::vector<cv::Point>>& contours) {

	imgAquist(raw);
	segment(raw, segmented);
	filter(segmented, filtered);
	classify(filtered, contours);
}

void BinDetect::imgAquist(cv::Mat& out) {
	a->apply(out);
}

void BinDetect::segment(cv::Mat& in, cv::Mat& out) {
	s->apply(in, out);
}

void BinDetect::filter(cv::Mat& in, cv::Mat& out) {
	f->apply(in, out);
}

void BinDetect::classify(cv::Mat& in, std::vector<std::vector<cv::Point>>& contours) {
	d->apply(in, contours);
}



void BinDetect::getRaw(cv::Mat& m) { m = raw; }

	


