#include "stdafx.h"
#include "BgsSegment.h"

BgsSegment::BgsSegment(void (*f) (int))
{
	//Choose BGS function to use when apply() is called. 
	(*f)();
	
}

BgsSegment::~BgsSegment()
{
	
}

void BgsSegment::apply() {

}

void BgsSegment::BGS() {

	BackgroundSubtractorMOG2 b();
	b.apply(img, tmp);
	img = tmp;
}


