/*
VehicleFrame (VF) is one sample of a vehicle, while a Vehicle is a set of VF's
 */


#pragma once
#include "opencvIncludes.h"

#include "VehicleFrame.h"
#include "VehicleList.h"
#include <vector>

class VehicleList;

class VehicleFrame
{
public:

  VehicleFrame();
  VehicleFrame(double speed, int x, int y, std::vector<cv::Point>* track_area);
  ~VehicleFrame();

	//Functions used by lists to determine if they belong
	double getSpeed();
	void setPosition(int x, int y);
	cv::Point2d getPosition();
	std::vector<cv::Point>* getContours();
	double getArea();
	Mat getBinROI();
	Mat getColorROI();

	VehicleList* list;

private:
	double speed;
	int xPos;
	int yPos;
	
	Mat color_ROI;
	Mat bin_ROI;
	

	std::vector<cv::Point>* vehicleContours;

};

