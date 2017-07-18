#include "stdafx.h"
#include "BinTrack_ImgProc.h"


BinTrack_ImgProc::BinTrack_ImgProc()
{
}


BinTrack_ImgProc::~BinTrack_ImgProc()
{
}



void BinTrack_ImgProc::segment(Mat& img) {
	BgsSegment s;
	s.apply();
	Mat tmp;


}

void BinTrack_ImgProc::filter(Mat& img) {
	Filter f;
	Mat tmp;

}

void BinTrack_ImgProc::classify(Mat& img) {
	BinClassify d;
	Mat tmp;

}

void BinTrack_ImgProc::tracking(Mat& img) {
	BinTracker t;
	Mat tmp;

}
	


