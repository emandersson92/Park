#include "stdafx.h"
#include "myTracker.h"

#include "draw.h"

myTracker::myTracker()
{
}


myTracker::~myTracker()
{
}

//Binary tracker
void myImgProc::binTrack() {
	draw d;


	d.drawContours(img, this);
	
}