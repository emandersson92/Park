#include "stdafx.h"
#include "Example.h"


Example::Example(){

}

Example::~Example(){

}

Vehicle* Example::createVehicle(){
	
	Vehicle* v = new Vehicle();

//--------------------------------------------------
//
//  Create some vehicle frames
//
//--------------------------------------------------

	std::vector<cv::Point>* points1 = new std::vector<cv::Point>;
	std::vector<cv::Point>* points2 = new std::vector<cv::Point>;
	std::vector<cv::Point>* points3 = new std::vector<cv::Point>;
	std::vector<cv::Point>* points4 = new std::vector<cv::Point>;
	std::vector<cv::Point>* points5 = new std::vector<cv::Point>;

	//dummypoints
	points1->push_back(cv::Point(1, 1)); //Just adding one point
	points2->push_back(cv::Point(1, 1));
	points3->push_back(cv::Point(1, 1));
	points4->push_back(cv::Point(1, 1));

	//serious points, this VF will be used by stillTracker 
	points5->push_back(cv::Point(500, 500));
	points5->push_back(cv::Point(700, 500));
	points5->push_back(cv::Point(500, 700));
	points5->push_back(cv::Point(700, 700));
	


	//Simulate moving car that stops
	VehicleFrame* vf1 = new VehicleFrame(3.3, 50, 50, points1);
	VehicleFrame* vf2 = new VehicleFrame(2.2, 45, 45, points2);
	VehicleFrame* vf3 = new VehicleFrame(1.1, 45, 45, points3);
	VehicleFrame* vf4 = new VehicleFrame(0.1, 45, 45, points4);
	VehicleFrame* vf5 = new VehicleFrame(0.0, 600, 600, points5);


	v->addVehicleFrame(vf1);
	v->addVehicleFrame(vf2);
	v->addVehicleFrame(vf3);
	v->addVehicleFrame(vf4);
 	v->addVehicleFrame(vf5);

	return v;
  
}

