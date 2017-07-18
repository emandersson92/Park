#include "stdafx.h"
#include "BinTracker.h"

#include "draw.h"

BinTracker::BinTracker()
{
}


BinTracker::~BinTracker()
{
}

//Binary tracker
void BinTracker::binTrack() {
	draw d;


	d.drawContours(img, this);
	
}