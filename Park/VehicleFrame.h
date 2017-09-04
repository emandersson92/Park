#pragma once
#include "opencvIncludes.h"

#include "VehicleFrame.h"
#include "VehicleList.h"

class VehicleList;

class VehicleFrame
{
public:
	VehicleFrame();
	~VehicleFrame();

	//Functions used by lists to determine if they belong
	double getSpeed();
	void Vehicle::setPosition(int x, int y){
	cv::Point2d getPosition();

	VehicleList* list;

private:
	double speed;
	int xPos;
	int yPos;
	
	vector<Point>* vehicleArea;

};

