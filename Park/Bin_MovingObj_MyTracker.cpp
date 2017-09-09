#include "stdafx.h"
#include "Bin_MovingObj_MyTracker.h"


Bin_MovingObj_MyTracker::Bin_MovingObj_MyTracker(VehicleDetector* d, int arg_minObjArea){
	detector = d;
	minObjArea = arg_minObjArea;
}


Bin_MovingObj_MyTracker::~Bin_MovingObj_MyTracker(){
	delete(detector);
}

std::vector<Vehicle*> Bin_MovingObj_MyTracker::getVehicles() {
	return vehicles;
}

void Bin_MovingObj_MyTracker::paint() {
	for(Vehicle* v : vehicles){

		VehicleFrame* vf = v->getLastVehicleFrame();

		///Paint rectangle
		cv::Size size; cv::Point ofs;
		cv::Mat ROI = vf->getBinROI();
		ROI.locateROI(size, ofs);
		cv::Rect r = cv::Rect(ofs.x, ofs.y, ROI.cols, ROI.rows);
		cv::rectangle(raw, r, cv::Scalar(255, 0, 0));

		///Paint centroid
		cv::Point p = vf->getCentroid();
		cv::circle(raw, p, 5, cv::Scalar(0, 255, 0), 3);

		///Paint filtered centroids

		std::vector<VehicleFrame*> vehicleFrames = v->getVehicleFrames();
		///get centroids vector
		todo: learn how to backward iterate vector
		tools::filterCentroids(5)

	}

	cv::namedWindow("win");
	cv::imshow("win", raw);
	cv::waitKey(2);
	
}


void Bin_MovingObj_MyTracker::track() {
	//Tracking by detection
	detector->imgAquist(in_detect);
	raw = in_detect.clone();
	detector->segment(in_detect, tmp1);
	detector->filter(tmp1, out_detect);

	std::vector<std::vector<cv::Point>> contours;
	std::vector<cv::Vec4i> hierarchy;

	/// Find contours
	findContours(out_detect, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, cv::Point(0, 0));



	for (Vehicle* v : vehicles) {
		v->VF_found = false;
	}

	///create vehicleFrames of found contours
	for (std::vector<cv::Point> c : contours) {

		if (cv::contourArea(c) > minObjArea) {
			cv::Rect r = cv::boundingRect(c);

			///construct vehicleFrame
			cv::Mat binROI = out_detect(r);
			cv::Mat colROI = raw(r);

			///convert c to pointer
			std::vector<cv::Point>* c_pnt = new std::vector<cv::Point>;

			while (!c.empty()) {
				c_pnt->push_back(c.back());
				c.pop_back();
			}


			cv::Point p = tools::getCentroid(*c_pnt);

			VehicleFrame* vf = new VehicleFrame(-1, c_pnt, p, colROI, binROI, raw, out_detect);


			bool vehicleFound = false;
			for (Vehicle* v : vehicles) {
				if (!v->VF_found && vf->intersect(v->getLastVehicleFrame())) {
					//calc speed;
					v->addVF(vf);
					v->VF_found = true;
					vehicleFound = true;
					break;
				}

			}

			if (!vehicleFound) {
				///No matching, create New Vehicle
				Vehicle* v = new Vehicle(vf);
				v->VF_found = true;
				vehicles.push_back(v);
			}

		}


		///Kill vehicles which did not fint vehicleFrames
		std::vector<Vehicle*> tmp_vehicles;
		Vehicle* tv;///tmp vehicle

		while (!vehicles.empty()) {
			tv = vehicles.back();
			vehicles.pop_back();

			if (tv->VF_found == true) {
				tmp_vehicles.push_back(tv);
			}
		}

		///move all obj in tmp_vehicles back in vehicles
		for (Vehicle* tvs : tmp_vehicles) {
			vehicles.push_back(tvs);
		}
	}
}

