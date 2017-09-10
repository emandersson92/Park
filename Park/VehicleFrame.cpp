#include "stdafx.h"
#include "VehicleFrame.h"


VehicleFrame::VehicleFrame()
{
  speed = -1.0;
}

VehicleFrame::VehicleFrame(double spd, std::vector<cv::Point>* contours, cv::Point arg_centroid, cv::Mat& c_ROI, cv::Mat& b_ROI, cv::Mat& arg_raw, cv::Mat& arg_bin_raw)
{

	///need to copy, Mat's given by argument will be overwritten
  raw = arg_raw.clone();
  bin_raw = arg_bin_raw.clone();

  ///Need to recreate the ROI's. Can be done prettier.
  cv::Size size; cv::Point ofs;
  c_ROI.locateROI(size, ofs);
  color_ROI = raw(cv::Rect(ofs.x, ofs.y, c_ROI.cols, c_ROI.rows));
  ///
  b_ROI.locateROI(size, ofs);
  bin_ROI = bin_raw(cv::Rect(ofs.x, ofs.y, b_ROI.cols, b_ROI.rows));


  centroid = arg_centroid;
  speed = spd;
  vehicleContours = contours;

}

VehicleFrame::~VehicleFrame()
{
	delete(vehicleContours);

}

void VehicleFrame::setFilteredCentroid(cv::Point p) {
	filteredCentroid = p;
}

cv::Point VehicleFrame::getCentroid() {
	return centroid;
}


bool VehicleFrame::intersect(VehicleFrame* vf) {
	///the bin_ROI's must be a ROI (part of a bigger cv::Mat object)
	cv::Mat argROI = vf->bin_ROI;
	cv::Mat thisROI = bin_ROI;

	cv::Mat f_argROI = ROI_toFullsize(argROI);
	cv::Mat f_thisROI = ROI_toFullsize(thisROI);

	cv::Mat res = f_argROI & f_thisROI;

	if(cv::countNonZero(res) == 0){
		return false;
	}
	else{
		return true;
	}
}

cv::Mat VehicleFrame::ROI_toFullsize(cv::Mat& ROI) {
	///get relative ROI location
	cv::Size size; cv::Point ofs;
	ROI.locateROI(size, ofs);
	
	if (size.width <= 0 || size.height <= 0) {
		std::cout << "the ROI has no parent Mat object" << std::endl;
		getchar();
	}

	cv::Mat black(size.height, size.width, CV_8UC1, cv::Scalar(0));

	cv::Mat blackROI = black(cv::Rect(ofs.x, ofs.y, ROI.cols, ROI.rows));

	blackROI += ROI;

	///the ROI object all by itself
	cv::Mat lonelyROI = black;

	return lonelyROI;
}


void VehicleFrame::locateROI() {
	///get relative ROI location
	cv::Size size; cv::Point ofs;
	//ROI.locateROI(size, ofs);
	//return size and ofs?

	///get ROI movement spot
	
	//movementArea = fullsize(cv::Rect(ofs.x, ofs.y, ROI.cols, ROI.rows));

}


double VehicleFrame::getFrameSpeed() {
	return speed;
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




