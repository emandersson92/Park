#include "stdafx.h"
#include "VehicleFrame.h"


VehicleFrame::VehicleFrame()
{
  speed = 0.0;
}

VehicleFrame::VehicleFrame(double spd, std::vector<cv::Point>* contours, cv::Mat& c_ROI, cv::Mat& b_ROI, cv::Mat& arg_raw, cv::Mat& arg_bin_raw)
{
  color_ROI = c_ROI;
  bin_ROI = b_ROI;
  raw = arg_raw;
  bin_raw = arg_bin_raw;

  speed = spd;
  vehicleContours = contours;

}

VehicleFrame::~VehicleFrame()
{
}

bool VehicleFrame::intersect(VehicleFrame* vf) {
	///the bin_ROI's must be a ROI (part of a bigger cv::Mat object)
	cv::Mat deb1 = vf->bin_ROI;
	cv::Mat res = deb1 & bin_ROI;

	if(cv::countNonZero(res) == 0){
		return false;
	}
	else{
		return true;
	}
}


void VehicleFrame::locateROI() {
	///get relative ROI location
	cv::Size size; cv::Point ofs;
	bin_ROI.locateROI(size, ofs);
	//return size and ofs?
	
	///get ROI movement spot
	
	//movementArea = out_detect(cv::Rect(ofs.x, ofs.y, cur_vehicleArea.cols, cur_vehicleArea.rows));

}


double VehicleFrame::getSpeed() {
	return 0.0;
}

 

cv::Point2d VehicleFrame::getPosition() {
	return cv::Point2d(0, 0);
}


std::vector<cv::Point>* VehicleFrame::getContours(){
	return vehicleContours;
}

//double VehicleFrame::getArea(){
//  return vehicleContours->getvehicleArea()
//}

cv::Mat VehicleFrame::getBinROI(){
	return bin_ROI;

}
cv::Mat VehicleFrame::cloneBinROI(){
	///get relative ROI location
	cv::Size size; cv::Point ofs;
	bin_ROI.locateROI(size, ofs);
	///get ROI movement spot
	cv::Rect r(ofs.x, ofs.y, bin_ROI.cols, bin_ROI.rows);
	
	cv::Mat clone = bin_raw.clone();
	cv::Mat ROI = clone(r);
  return ROI;
}


cv::Mat VehicleFrame::getColorROI(){
  return color_ROI;
}




