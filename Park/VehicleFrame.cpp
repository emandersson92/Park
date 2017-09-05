#include "stdafx.h"
#include "VehicleFrame.h"


VehicleFrame::VehicleFrame()
{
  speed = 0.0;
  xPos = 0;
  yPos = 0;
}

VehicleFrame::VehicleFrame(double spd, int x, int y, std::vector<cv::Point>* contours, Mat c_ROI, Mat b_ROI)
{
  color_ROI = c_ROI;
  bin_ROI = b_ROI;

  speed = spd;
  xPos = x;
  yPos = y;
  vehicleContours = contours;

}

VehicleFrame::~VehicleFrame()
{
}

double VehicleFrame::getSpeed() {
	return 0.0;
}


void VehicleFrame::setPosition(int x, int y){
  xPos = x;
  yPos = y;
  
} 


cv::Point2d VehicleFrame::getPosition() {
	return cv::Point2d(0, 0);
}


std::vector<cv::Point>* VehicleFrame::getContours(){
	return vehicleContours;
}

double VehicleFrame::getArea(){
  return contours.getvehicleArea
}

Mat VehicleFrame::getBinROI(){
  return bin_ROI;
}

Mat VehicleFrame::getColorROI(){
  return color_ROI;
}




