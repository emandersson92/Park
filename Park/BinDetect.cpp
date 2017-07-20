#include "stdafx.h"
#include "BinDetect.h"


BinDetect::BinDetect()
{
}


BinDetect::~BinDetect()
{
}

void BinDetect::apply(Mat& out) {
	
	imgAquist(in, out);
	segment(in, out);
	filter(in, out);
	classify(in, out);

}

void BinDetect::imgAquist(Mat& in, Mat& out) {
	ImgAcquisition a(Path);
	a.apply(out);
}

void BinDetect::segment(Mat& in, Mat& out) {
	BgsSegment s;
	s.apply(in, out);
	Mat tmp;
}

void BinDetect::filter(Mat& in, Mat& out) {
	Filter f;
	f.apply(in, out);
}

void BinDetect::classify(Mat& in, Mat& out) {
	BinClassify d;
	d.apply(in);
}
	


