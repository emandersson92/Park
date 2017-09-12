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
  VehicleFrame(std::vector<cv::Point>* contours, cv::Point arg_centroid, cv::Mat& c_ROI, cv::Mat& b_ROI, cv::Mat& arg_raw, cv::Mat& arg_bin_raw);
  void postConstruct(double arg_speed, VehicleFrame* previousVF);///arguments not available at initial construct
  ~VehicleFrame();


	//Functions used by lists to determine if they belong
	double getFrameSpeed();
	cv::Point2d getPosition();
	std::vector<cv::Point>* getContours();
	//double getArea();
	cv::Mat cloneBinROI();
	cv::Mat getBinROI();
	cv::Mat getColorROI();
	cv::Point getCentroid();
	void setFilteredCentroid(cv::Point p);
	bool VehicleFrame::intersect(VehicleFrame* vf);
	void VehicleFrame::locateROI();
	cv::Mat VehicleFrame::ROI_toFullsize(cv::Mat& ROI);
	VehicleFrame* getPreviousVehicleFrame();
	VehicleFrame* getNextVehicleFrame();
	void setNextVehicleFrame(VehicleFrame* vf);
	bool fullyConstructed();

	VehicleList* list;

private:
	double speed;
	
	cv::Mat raw;//access to main img
	cv::Mat bin_raw;

	cv::Mat color_ROI;//main object in this class
	cv::Mat bin_ROI;
	
	VehicleFrame* previousVehicleFrame;
	VehicleFrame* nextVehicleFrame;
	cv::Point centroid;
	cv::Point filteredCentroid = cv::Point(0, 0);
	std::vector<cv::Point>* vehicleContours;

	bool VF_fullyConstructed;
	
};

