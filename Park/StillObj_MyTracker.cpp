#include "stdafx.h"
#include "StillObj_MyTracker.h"


StillObj_MyTracker::StillObj_MyTracker(VehicleFrame* vf, BinDetect* binDetect)
{
	init_trackArea = cu_trackArea = vf->getTrackArea().copy();
	ALIVE = true;
}


StillObj_MyTracker::~StillObj_MyTracker()
{
}


void StillObj_MyTracker::track() {
    surviveTest();
}


//Vehicle has parked to long!
void StillObj_MyTracker::alarm() {

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
//		killTracker();
	}
}

void StillObj_MyTracker::isAlive(){
	return ALIVE;
}
