#include "stdafx.h"
#include "Bin_MovingObj_MyTracker.h"


Bin_MovingObj_MyTracker::Bin_MovingObj_MyTracker()
{
}


Bin_MovingObj_MyTracker::~Bin_MovingObj_MyTracker()
{
}

void Bin_MovingObj_MyTracker::track() {
	Mat out;
	detector.apply(out);

	//compare and match existing vehicle with the new VehicleFrame

	//bounding box code
	//...
	//...
	//...


}