#pragma once
#include "MyTracker.h"
#include "VehicleDetector.h"

class MovingObj_MyTracker : public MyTracker
{
public:
	MovingObj_MyTracker(VehicleDetector& d);
	~MovingObj_MyTracker();

	virtual void track() = 0;

};

