#pragma once

#include "VehicleFrame.h"
#include <iostream>
#include <vector>
#include "Environment.h"
#include "VehicleList.h"
#include "MyTimer.h"

class VehicleFrame;

class Vehicle
{
 public:
	Vehicle(VehicleFrame* vf, VehicleList* list);
	Vehicle();
	~Vehicle();
	VehicleFrame* getLastVehicleFrame();
	std::vector<VehicleFrame*> getVehicleFrames();
	void addVF(VehicleFrame* v);
	void addVF_ifBelong(VehicleFrame* v);
	bool VF_found;
	double getVehicleSpeed();
	cv::Point filterCentroid();
	bool vehicleParked();
	VehicleList* getVehicleList();

	void forwardToNextListIfBelong();




 private:



	VehicleList* vehicleList;
	std::vector<VehicleFrame*> vehicleFrames;
	const int nVehicleFramesStillWhenParked = 5;




	//****************************************
	//stillobj tracker:

	MyTimer* timer;///park time timer
	
	///percentage foreground (255) of init_vehicleArea
	double ir_fg;


	///Initially and Current vehicle area in white (255)  and background in black (0), one channel. 
	cv::Mat init_vehicleArea; 
	cv::Mat cur_vehicleArea;

	cv::Mat movementArea;//Binary image with white (255) on area where movement appeared since last frame and black (0) where movement did not appear

	///min life before tracker dies in % (cur_trackArea/init_trackArea). 
	double lifeLeft;
	const double _minLife = 30.0;
	bool ALIVE; // lists with trackers can check i trackers are dead. If they are, they can be removed and later freed.



};

