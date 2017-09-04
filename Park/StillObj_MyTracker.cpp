#include "stdafx.h"
#include "StillObj_MyTracker.h"


StillObj_MyTracker::StillObj_MyTracker(Vehicle* v, VehicleDetector* d)
{
  init_trackArea = cu_trackArea = v->getLastVehicleFrame()->getArea().copy();
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

	Mat out; //shall not be here
	Mat in;
	
	binDetect->ImgAquist(out);
	binDetect->segment(in, out);
	binDetect->filter(in, out);
	
	cur_trackArea =- out;
	

}

//Private
void StillObj_MyTracker::surviveTest() {
	double lifeLeft = (100.0*(double)cur_trackArea.size() / (double)init_trackArea.size());
	if (lifeLeft < minLife)
	{
		ALIVE = false;
		//killTracker();
	}
}

void StillObj_MyTracker::isAlive(){
	return ALIVE;
}

void StillObj_MyTracker::getParkTime(){
	return time;
}


