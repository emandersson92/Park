/********************************
Info:
Moving object abstraction (a MovingObj_MyTracker can be setup in multiple ways)

Author:
Emil Andersson 2017-07-21
********************************/

#pragma once
#include "MyTracker.h"
#include "VehicleDetector.h"

class MovingObj_MyTracker : public MyTracker
{
public:
	MovingObj_MyTracker();
	~MovingObj_MyTracker();

};

