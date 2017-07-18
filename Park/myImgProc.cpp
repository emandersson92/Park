#include "stdafx.h"
#include "myImgProc.h"


myImgProc::myImgProc()
{
}


myImgProc::~myImgProc()
{
}

void myImgProc::bgs(Mat& img) {
	Mat tmp;
	
	BackgroundSubtractorMOG2 b;
	b.apply(img, tmp);
	img = tmp;

}





