#include "stdafx.h"
#include "myAdaptiveFilter.h"


myAdaptiveFilter::myAdaptiveFilter()
{
}


myAdaptiveFilter::~myAdaptiveFilter()
{
}

void myAdaptiveFilter::openFilter(Mat& img) {
	Mat tmp;
	erode(img, tmp);
	dilate();
}
void myAdaptiveFilter::closeFilter(Mat& img) {
	dilate();
	erode();
}