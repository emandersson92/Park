#include "stdafx.h"
#include "VehicleFrame.h"


VehicleFrame::VehicleFrame()
{
  speed = 0.0;
  xPos = 0;
  yPos = 0;
}

VehicleFrame::VehicleFrame(double spd, int x, int y, std::vector<cv::Point>* track_area)
{
  speed = spd;
  xPos = x;
  yPos = y;
  vehicleArea = track_area;

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
	return vehicleArea;
}






