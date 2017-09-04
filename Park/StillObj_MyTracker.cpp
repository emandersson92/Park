#include "stdafx.h"
#include "StillObj_MyTracker.h"


StillObj_MyTracker::StillObj_MyTracker(Vehicle* v, VehicleDetector* d)
{
  init_trackArea = cur_trackArea = v->getLastVehicleFrame()->getArea().copy();
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
	
	detector->ImgAquist(out_detect);
	detector->segment(in_detect, out_detect);
	detector->filter(in_detect, out_detect);
	
	cur_trackArea =- out_detect;

}

//Private
void StillObj_MyTracker::surviveTest() {

  //validate
  double c = cur_trackArea.size();
  double i = init_trackArea.size();
  
	double lifeLeft = (100.0 * c/i);
	if (lifeLeft < _minLife)
	{
		ALIVE = false;
		//killTracker(); --> use abstract class enwrapper?
	}
}

void StillObj_MyTracker::isAlive(){
	return ALIVE;
}

void StillObj_MyTracker::getParkTime(){
	return time;
}

Mat StillObj_MyTracker::getRaw(){
  return raw;
}

void StillObj_MyTracker::paint(){
  //Paint trackingarea on raw img.
  circle()
}
