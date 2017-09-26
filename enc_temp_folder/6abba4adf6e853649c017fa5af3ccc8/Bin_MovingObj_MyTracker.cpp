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

		///paint obj speed
		cv::String text = "speed: " + std::to_string(vf->getFrameSpeed());
		cv::putText(raw, text, cv::Point(p.x + 20, p.y), 0, 0.5, cv::Scalar(255, 255, 255));

		///Paint filtered centroids
		/*
		std::vector<VehicleFrame*> vehicleFrames = v->getVehicleFrames();
		///get centroids vector
		todo: learn how to backward iterate vector
		tools::filterCentroids(5)
		*/

	}

	cv::namedWindow("win");
	cv::imshow("win", raw);
	cv::waitKey(2);
	
}


void Bin_MovingObj_MyTracker::track() {
  VehicleFrame* previousVF;
  
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

			VehicleFrame* vf = new VehicleFrame(c_pnt, p, colROI, binROI, raw, out_detect);

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


		//do this prettier
		//----------------------------------------
		///Kill vehicles which did not fint vehicleFrames
		std::vector<Vehicle*> tmp_vehicles;
		Vehicle* tv;///tmp vehicle

		while (!vehicles.empty()) {
			tv = vehicles.back();
			vehicles.pop_back();

			if (tv->VF_found == true) {
				tmp_vehicles.push_back(tv);
			}
			else{
				delete(tv);
			}
		}

		///move all obj in tmp_vehicles back in vehicles
		for (Vehicle* tvs : tmp_vehicles) {
			vehicles.push_back(tvs);
		}
		//----------------------------------------



	}



	///**************************************************
	///postconstruction (add speed and lastVehicleFrame to vehicleFrame)

	///The speed will be -1 on the first iteration
	double speed = -1;

	for (auto v_it = vehicles.begin(); v_it != vehicles.end(); v_it++) {
		std::vector<VehicleFrame*> vehicleFrames = (*v_it)->getVehicleFrames();

		VehicleFrame* lastVF = NULL;
		for (auto vf_it = vehicleFrames.begin(); vf_it != vehicleFrames.end(); vf_it++) {

			///if speed and linking is not performed
			if (!(*vf_it)->fullyConstructed()) {
				
				///Not first VF iteration
				if (!lastVF == NULL){
					cv::Point lastP = lastVF->getCentroid();

					///distance
					double distance = cv::norm(lastP - (*vf_it)->getCentroid());
					double time = 1/fps;
					speed = distance/time;

				}

				
				///First iteration speed will be "-1" and lastVF will be "NULL"
				(*vf_it)->postConstruct(speed, lastVF);

				///set lastVF for next iteration
				lastVF = (*vf_it);

			}
		}
	}


	/*
	for(Vehicle* v : vehicles){
		//Set breakpoint here
		
		std::vector<VehicleFrame*> vfs = v->getVehicleFrames();
		
		for(VehicleFrame* v : vfs){
			if(v->getFrameSpeed == 0){
				//Set breakpoint here
				__nop;
			}
		}

	}
	*/

}

