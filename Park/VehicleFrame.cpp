#include "stdafx.h"
#include "VehicleFrame.h"


VehicleFrame::VehicleFrame()
{
  speed = 0.0;
  xPos = 0;
  yPos = 0;
}

VehicleFrame::Vehicle::Vehicle(double speed, int x, int y, vector<Point>* track_area)
{
  speed = speed;
  xPos = x;
  yPos = y;
  vehicleArea = track_area;

}

//Vehicle::~Vehicle()
//{
//}

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


vector<Point>* VehicleFrame::getVehicle(){
	return vehicleArea;
}






