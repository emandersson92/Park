#include "stdafx.h"
#include "Filter.h"


Filter::Filter(){
	init();
}


Filter::~Filter(){
}



void Filter::apply(cv::Mat& in, cv::Mat& out) {
	//implement so constructor defines which function to call
	openFilter(in, out);

}

void Filter::openFilter(cv::Mat& in, cv::Mat& out) {
	erode(in, out, erElem);
	dilate(in, out, diElem);

}
void Filter::closeFilter(cv::Mat& in, cv::Mat& out) {
	dilate(in, out, diElem);
	erode(in, out, erElem); 
}



void Filter::init() {
	int erShape = cv::MORPH_RECT;
	int diShape = cv::MORPH_RECT;

	int erosion_elem = 0;
	int erosion_size = 20;			//shall be adaptive in the future
	int dilation_elem = 0;
	int dilation_size = 5;			//shall be adaptive in the future


	erElem = getStructuringElement(erShape, 
		cv::Size(2 * erosion_size + 1, 2 * erosion_size + 1),
		cv::Point(erosion_size, erosion_size));

	diElem = cv::getStructuringElement(diShape,
		cv::Size(2 * dilation_size + 1, 2 * dilation_size + 1),
		cv::Point(dilation_size, dilation_size));

}