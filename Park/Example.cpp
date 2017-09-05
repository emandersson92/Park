#include "stdafx.h"
#include "Example.h"


Example::Example(){

}

Example::~Example(){

}

Vehicle* Example::createVehicle(VehicleDetector* detector){
	
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


	cv::Mat in;
	cv::Mat out;

  	detector->imgAquist(out);
	cv::Mat raw = out.clone();

	detector->segment(in, out);
	detector->filter(in, out);

	int x = 500;
	int y = 500;
	int w = 30;
	int h = 30;


	cv::Mat cr = raw(cv::Rect(x, y, w, h)); //this roi is used for every vehicle frame
	cv::Mat br = out(cv::Rect(x, y, w, h));
	
	
	//Simulate moving car that stops
	VehicleFrame* vf1 = new VehicleFrame(3.3, 50, 50, points1, cr, br);
	VehicleFrame* vf2 = new VehicleFrame(2.2, 45, 45, points2, cr, br);
	VehicleFrame* vf3 = new VehicleFrame(1.1, 45, 45, points3, cr, br);
	VehicleFrame* vf4 = new VehicleFrame(0.1, 45, 45, points4, cr, br);
	VehicleFrame* vf5 = new VehicleFrame(0.0, 600, 600, points5, cr, br);


	v->addVehicleFrame(vf1);
	v->addVehicleFrame(vf2);
	v->addVehicleFrame(vf3);
	v->addVehicleFrame(vf4);
 	v->addVehicleFrame(vf5);

	return v;
  
}

