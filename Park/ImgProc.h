#pragma once
//
//Model of a Image Processing stage
//

class ImgProc
{
public:
	ImgProc();
	~ImgProc();
	
	//The parts that must be included in a ImgProc-abstraction 
	virtual void filter(Mat& img) = 0;
	virtual void detection(Mat& img) = 0;
	virtual void tracking(Mat& img) = 0;

};

