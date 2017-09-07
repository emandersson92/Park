#include "stdafx.h"
#include "BgsSegment.h"

BgsSegment::BgsSegment(){
	//Choose BGS function to use when apply() is called. 
	//(*f)();


	///todo move this to a BgsMog2_init() function
	///no shadows bgs
	b = cv::createBackgroundSubtractorMOG2(500, 16.0, false); //MOG2 approach
}

BgsSegment::~BgsSegment() {
	delete(b);	///not needed with smart pointers? todo
}



void BgsSegment::apply(cv::Mat& in, cv::Mat& out) {
	//implement so constructor defines which function to call
	BgsMog2(in, out);
}

void BgsSegment::BgsMog2(cv::Mat& in, cv::Mat& out) {

	//cv::Ptr<cv::BackgroundSubtractor> pMOG2 = cv::createBackgroundSubtractorMOG2();
	//cv::Ptr<cv::BackgroundSubtractor> b; //MOG2 Background subtractor
  
	//pMOG2->apply(in, out);
	b->apply(in, out);

}


