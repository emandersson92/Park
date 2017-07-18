#include "stdafx.h"
#include "BgsSegment.h"

BgsSegment::BgsSegment(){
	//Choose BGS function to use when apply() is called. 
	//(*f)();


	///todo move this to a BgsMog2_init() function
	b = createBackgroundSubtractorMOG2(); //MOG2 approach
}

BgsSegment::~BgsSegment() {
	delete(b);
}



void BgsSegment::apply(Mat& in, Mat& out) {
	//implement so constructor defines which function to call
	BgsMog2(in, out);
}

void BgsSegment::BgsMog2(Mat& in, Mat& out) {
	b->apply(in, out);
}


