#include "stdafx.h"
#include "draw.h"


draw::draw()
{
}


draw::~draw()
{
}


//General functions
void draw::addText(){}
void draw::addKeyInfoText(){}

//Park application functions
void draw::addTimeText(cv::Mat& img, MyTracker& t){}
void draw::drawContours(cv::Mat& img, MyTracker& t){}