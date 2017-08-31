#include "stdafx.h"
#include "StillObj_MyTracker.h"


StillObj_MyTracker::StillObj_MyTracker()
{
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
