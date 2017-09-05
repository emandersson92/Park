/*
VehicleFrame (VF) is one sample of a vehicle, while a Vehicle is a set of VF's
 */
#pragma once

//Opencv
#include <opencv2\imgproc.hpp>

//My classes
#include "VehicleList.h"

//std
#include <vector>


class VehicleList;
class VehicleFrame;

class VehicleFrame
{
public:

  VehicleFrame();
  VehicleFrame(double spd, int x, int y, std::vector<cv::Point>* contours, cv::Mat c_ROI, cv::Mat b_ROI);
  ~VehicleFrame();

	//Functions used by lists to determine if they belong
	double getSpeed();
	void setPosition(int x, int y);
	cv::Point2d getPosition();
	std::vector<cv::Point>* getContours();
	//double getArea();
	cv::Mat getBinROI();
	cv::Mat getColorROI();

	VehicleList* list;

private:
	double speed;
	int xPos;
	int yPos;
	
	cv::Mat color_ROI;
	cv::Mat bin_ROI;
	

	std::vector<cv::Point>* vehicleContours;

};

