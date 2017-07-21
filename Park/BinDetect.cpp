#include "stdafx.h"
#include "BinDetect.h"


BinDetect::BinDetect()
{
}


BinDetect::~BinDetect()
{
}

void BinDetect::apply(cv::Mat& out) {
	
	imgAquist(in, out);
	segment(in, out);
	filter(in, out);
	classify(in, out);

}

void BinDetect::imgAquist(cv::Mat& in, cv::Mat& out) {
	ImgAcquisition a(Path);
	a.apply(out);
}

void BinDetect::segment(cv::Mat& in, cv::Mat& out) {
	BgsSegment s;
	s.apply(in, out);
	cv::Mat tmp;
}

void BinDetect::filter(cv::Mat& in, cv::Mat& out) {
	Filter f;
	f.apply(in, out);
}

void BinDetect::classify(cv::Mat& in, cv::Mat& out) {
	BinClassify d;
	d.apply(in);
}
	


