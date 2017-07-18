#include "stdafx.h"
#include "Filter.h"


Filter::Filter(){
	init();
}


Filter::~Filter(){
}



void Filter::apply(Mat& in, Mat& out) {
	//implement so constructor defines which function to call
	openFilter(in, out);

}

void Filter::openFilter(Mat& in, Mat& out) {
	erode(in, out, erElem);
	dilate(in, out, diElem);

}
void Filter::closeFilter(Mat& in, Mat& out) {
	dilate(in, out, diElem);
	erode(in, out, erElem);
}



void Filter::init() {
	int erShape = MORPH_RECT;
	int diShape = MORPH_RECT;

	int erosion_elem = 0;
	int erosion_size = 5;			//shall be adaptive in the future
	int dilation_elem = 0;
	int dilation_size = 5;			//shall be adaptive in the future


	erElem = getStructuringElement(erShape,
		Size(2 * erosion_size + 1, 2 * erosion_size + 1),
		Point(erosion_size, erosion_size));

	diElem = getStructuringElement(diShape,
		Size(2 * dilation_size + 1, 2 * dilation_size + 1),
		Point(dilation_size, dilation_size));

}