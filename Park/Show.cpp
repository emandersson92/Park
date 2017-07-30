#include "stdafx.h"
#include "Show.h"


//why do I need this here? TODO
std::vector<myWindow> Show::windows;

Show::Show()
{
}

Show::~Show()
{
	
	/* code gives error
	for each (myWindow w in windows)
	{
		//how to free the windows? todo
	}
	*/
	
}

int Show::winCount = 0;

//Usage: call during image processing in your loop. Use showImg at end of loop to show added images.
void Show::add(cv::Mat& img, const char * name) {

	///window already added?
	for each (myWindow w in windows)
	{
		if (w.name._Equal(name))
			return;
	}

	myWindow w;
	w.image = img;
	w.name = name;

	
	windows.push_back(w);
	cv::namedWindow(name);
	cv::Point p = getNewPos(img.cols);
	cvMoveWindow(name, p.x, p.y);

	winCount++;
}

void Show::showImg() {
	
	for each (myWindow w in windows)
	{
		cv::imshow(w.name, w.image);
		cv::waitKey(10);
	}
	
}

cv::Point Show::getNewPos(const int dx) {
	return cv::Point(winCount * dx, 650);
		
}