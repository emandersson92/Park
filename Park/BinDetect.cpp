#include "stdafx.h"
#include "BinDetect.h"


BinDetect::BinDetect()
{
}


BinDetect::~BinDetect()
{
}

void BinDetect::apply(std::vector<std::vector<cv::Point>>& contours) {

	imgAquist(raw);
	segment(raw, segmented);
	filter(segmented, filtered);
	classify(filtered, contours);

}

void BinDetect::imgAquist(cv::Mat& out) {
	ImgAcquisition a(Path);
	a.apply(out);
}

void BinDetect::segment(cv::Mat& in, cv::Mat& out) {
	BgsSegment s;
	s.apply(in, out);
}

void BinDetect::filter(cv::Mat& in, cv::Mat& out) {
	Filter f;
	f.apply(in, out);
}

void BinDetect::classify(cv::Mat& in, std::vector<std::vector<cv::Point>>& contours) {
	BinClassify d;
	d.apply(in, contours);
}
	


