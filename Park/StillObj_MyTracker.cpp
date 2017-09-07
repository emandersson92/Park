#include "stdafx.h"
#include "StillObj_MyTracker.h"


StillObj_MyTracker::StillObj_MyTracker(Vehicle* v, VehicleDetector* d)
{

  VehicleFrame* vf = v->getLastVehicleFrame();

  init_trackBinROI = cur_trackBinROI = vf->getBinROI();
  stillTrack_VehicleFrame = vf;
  
  detector = d;

  timer = new SimpleTimer();

  ALIVE = true;
  FIRST = true;
}


StillObj_MyTracker::~StillObj_MyTracker()
{
  delete(timer);
}


void StillObj_MyTracker::track() {
  if (FIRST){
	FIRST = false;
	timer->start();
  }
  
  reduceTrackerArea();
  surviveTest();
  timer->increment();
}


void StillObj_MyTracker::reduceTrackerArea() {
	//backgroundsubtraction on area.
	//need a reducer
	/*
	  the reduce tecqnology works is based on BGS. If there is movement on the ROI the tracking area will be reduced.

	  the BinDetect() - class can be used with BGS in order to detect movement on the ROI.
	 */
  
	detector->imgAquist(in_detect);
	detector->segment(in_detect, tmp1);
	detector->filter(tmp1, out_detect);


	//Binary image subtraction
	//expl: when movement is detected on vehicle spot it indicates vehicle movement


	///get relative ROI location
	cv::Size size; cv::Point ofs;
	cur_trackBinROI.locateROI(size, ofs);


	///get ROI movement spot
	cv::Mat movImgROI = out_detect(cv::Rect(ofs.x, ofs.y, cur_trackBinROI.cols, cur_trackBinROI.rows));
	
	cur_trackBinROI -= movImgROI;
	
}

//Private
void StillObj_MyTracker::surviveTest() {
  
  //simplifying code reading
  cv::Mat cr = cur_trackBinROI;
  cv::Mat ir = init_trackBinROI;
  double cr_fg = percentage_foreground(cr);
  double ir_fg = percentage_foreground(ir);


  //test
  if(ir_fg < cr_fg){
	getchar();
  }

  double lifeLeft = (100.0 * cr_fg/ir_fg);
  
  MyAssert::assertPercentage(lifeLeft);

  if (lifeLeft < _minLife)
	{
	  ALIVE = false;
	  //killTracker(); --> use abstract class enwrapper?
	}
}

bool StillObj_MyTracker::isAlive(){
	return ALIVE;
}

double StillObj_MyTracker::getParkTime(){
	return timer->getTime();
}


void StillObj_MyTracker::paint(){
  //Paint trackingarea on raw img.
	out_detect += stillTrack_VehicleFrame->getBinROI();

}


double StillObj_MyTracker::percentage_foreground(cv::Mat m){
  
  double ret = cv::countNonZero(m)/(m.cols * m.rows)*100;
  MyAssert::assertPercentage(ret);
  
  return ret;
}

cv::Mat StillObj_MyTracker::getLastImg(){
  return out_detect;
}
