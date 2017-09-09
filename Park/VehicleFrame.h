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
  VehicleFrame(double spd, std::vector<cv::Point>* contours, cv::Mat& c_ROI, cv::Mat& b_ROI, cv::Mat& arg_raw, cv::Mat& arg_bin_raw);
  ~VehicleFrame();

	//Functions used by lists to determine if they belong
	double getSpeed();
	cv::Point2d getPosition();
	std::vector<cv::Point>* getContours();
	//double getArea();
	cv::Mat cloneBinROI();
	cv::Mat getBinROI();
	cv::Mat getColorROI();
	bool VehicleFrame::intersect(VehicleFrame* vf);
	void VehicleFrame::locateROI();
	cv::Mat VehicleFrame::ROI_toFullsize(cv::Mat& ROI);


	VehicleList* list;

private:
	double speed;
	
	cv::Mat raw;//access to main img
	cv::Mat bin_raw;

	cv::Mat color_ROI;//main object in this class
	cv::Mat bin_ROI;
	

	std::vector<cv::Point>* vehicleContours;

};

