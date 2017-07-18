#include "stdafx.h"
#include "Filter.h"


Filter::Filter()
{
}


Filter::~Filter()
{
}

void Filter::apply() {
	//implement so constructor defines which function to call

}

void Filter::openFilter(Mat& img) {
	Mat tmp;
	erode(img, tmp);
	dilate();

}
void Filter::closeFilter(Mat& img) {
	dilate();
	erode();
}