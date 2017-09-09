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

	cv::Mat in;
	cv::Mat out;
	cv::Mat tmp1;//temporary 1


	detector->imgAquist(in);
	cv::Mat raw = in.clone();

	int x = raw.cols / 2;
	int y = raw.rows / 2;
	int w = raw.cols / 6;
	int h = raw.rows / 6;

	std::vector<cv::Point>* points1 = new std::vector<cv::Point>;
	std::vector<cv::Point>* points2 = new std::vector<cv::Point>;
	std::vector<cv::Point>* points3 = new std::vector<cv::Point>;
	std::vector<cv::Point>* points4 = new std::vector<cv::Point>;
	std::vector<cv::Point>* points5 = new std::vector<cv::Point>;
	std::vector<cv::Point> points6;

	//dummypoints
	points1->push_back(cv::Point(1, 1)); //Just adding one point
	points2->push_back(cv::Point(1, 1));
	points3->push_back(cv::Point(1, 1));
	points4->push_back(cv::Point(1, 1));

	//serious points, this VF will be used by stillTracker 
	points5->push_back(cv::Point(x, y));
	points5->push_back(cv::Point(x + w, y));
	points5->push_back(cv::Point(x + w, y + w));
	points5->push_back(cv::Point(x, y + w));

	
	cv::Rect ROIrect(x, y, w, h);
	
	///test. the Rect can be painted
	///cv::rectangle(raw, ROIrect, cv::Scalar(0, 0, 255), 3);


	///test:: can print the contours added manually
	///std::vector<std::vector<cv::Point>>* a = new std::vector<std::vector<cv::Point>>();
	///a->push_back(*points5);

	///cv::drawContours(raw, *a, -1, cv::Scalar(255, 0, 0), 3);


	detector->segment(in, tmp1);
	///convert to gray
	///detector->filter(tmp1, out);

	///construct image with all element with value 255
	cv::Mat white(in.rows, in.cols, CV_8UC1, 255);

	


	cv::Mat cr = raw(cv::Rect(x, y, w, h)); //this roi is used for every vehicle frame
	cv::Mat br = white(cv::Rect(x, y, w, h));
	


	///calc centroid
	cv::Point p1 = tools::getCentroid(*points1);
	cv::Point p2 = tools::getCentroid(*points2);
	cv::Point p3 = tools::getCentroid(*points3);
	cv::Point p4 = tools::getCentroid(*points4);
	cv::Point p5 = tools::getCentroid(*points5);




	
	//Simulate moving car that stops
	VehicleFrame* vf1 = new VehicleFrame(3.3, points1, p1, cr, br, raw, white);
	VehicleFrame* vf2 = new VehicleFrame(2.2, points2, p2, cr, br, raw, white);
	VehicleFrame* vf3 = new VehicleFrame(1.1, points3, p3, cr, br, raw, white);
	VehicleFrame* vf4 = new VehicleFrame(0.1, points4, p4, cr, br, raw, white);
	VehicleFrame* vf5 = new VehicleFrame(0.0, points5, p5, cr, br, raw, white);


	v->addVF(vf1);
	v->addVF(vf2);
	v->addVF(vf3);
	v->addVF(vf4);
 	v->addVF(vf5);

	return v;

}

