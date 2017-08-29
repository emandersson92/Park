// Park.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <sys/types.h>
#include <sys/stat.h>
#include "tools.h"

#include <cstring>

#include "VehicleDetector.h"
#include "BinDetect.h"
#include "ImgAcquisition.h"

#include "Moving_VehicleList.h"
#include "Still_VehicleList.h"
#include "VehicleList.h"

#include "Bin_MovingObj_MyTracker.h"
#include "MyTrackerKCF.h"

#include "opencv2\highgui.hpp"

#include "Show.h"
#include "list"


void test(const char *);
void imgDis(cv::Mat& out);
static void help();

bool CV_TRACKER;

static const char* keys =
{ "{@tracker_algorithm | | tracker algorithm }"
"{@video_name        | | video name        }" };



typedef std::vector<cv::Point> vecPoint;
typedef std::vector<vecPoint> vecVecPoint;


int main(int argc, char** argv)
{
	
	cv::CommandLineParser parser(argc, argv, keys);

	cv::String tracker_algorithm = parser.get<cv::String>(0);
	cv::String video_name = parser.get<cv::String>(1);

	if (tracker_algorithm.empty())
	{
		help();
		getchar();
		return -1;
	}

	if (tracker_algorithm == "opencv_tracker")
	{ 
		std::cout << "using opencv_tracker" << std::endl;
		CV_TRACKER = true;

	}
	else { 
		CV_TRACKER = false;
	}


	// using CV_TRACKER
	if (CV_TRACKER == true) {
		std::cout << "CV_TRACKER IS DEFINED" << std::endl;

		cv::Mat raw, segmented, filtered, classified;
		bool paused = false;

		///Prepare Bindetect
		VehicleDetector* detector = new BinDetect();
		vecVecPoint contours;

		MyTrackerKCF myTrackerKcf;

		while (true)
		{
			if (!paused)
			{
				detector->imgAquist(raw);

				//new detected objects must not intersect with tracking objects 
				detector->segment(raw, segmented); //wrong background subtraction second time? todo
				detector->filter(segmented, filtered);
				detector->classify(filtered, contours);

				myTrackerKcf.apply(raw, contours);

				Show::showImg();

				char c = (char)cv::waitKey(2);
				if (c == 'q')exit(-1);///Quit on q
				if (c == 'p')paused = !paused;///Pause on p
				if (c == 27)exit(-1);///Quit on ESC-button
			}
		}
	}

	else {
		MyTracker* simpleTracker = new Bin_MovingObj_MyTracker(new std::vector<std::vector<cv::Point>>);


		//still tracker
		//...
		//...
		//...

		std::vector<MyTracker*> trackers;

		trackers.push_back(simpleTracker);
		//trackers.push_back(still tracker);
		//...
		//...
		//...



		VehicleList* movList = new Moving_VehicleList();
		VehicleList* stillList = new Still_VehicleList();
		VehicleList* alarmList = new Still_VehicleList();

		//************************************************
		//vehicle lifecycle:
		//
		//   [movlist] --> [stillList] --> [alarmList]
		//
		movList->connectTo(stillList);
		stillList->connectTo(alarmList);
		//
		//................................................




		//Forward vehicles to next lists if condition is ok
		for (MyTracker* t : trackers) {
			Vehicle* v = t->getVehicle();

			/*
			v->list->nextList.belongCheck(v);


			if (v->list.nextList.belongCheck(*v)) {

			v->list.forwVehicle();
			}
			else if (t.list.belongCheck(v)) {

			//toss vehicle and tracker();
			}

			*/
		}


		//Alt 1: Add vehicles only to the first list
		//Alt 2: Add vehicles in all lists
		//
		//Using Alt ?:

		for each (MyTracker* t in trackers)
		{
			t->track();
		}

	}


    return 0;
}



static void help()
{
	std::cout << "Invalid number of arguments" << std::endl;

}



//Image Display
void imgDis(cv::Mat& out) {
	cv::namedWindow("win");
	imshow("win", out);
	cvMoveWindow("win", 0, 0);
	cv::waitKey(0);

}

void test(const char* test) {
	printf(test);

	//does not work yet
	if (tl::tools::file_exists(test)) {
		std::cout << " exists" << std::endl;
	}
	else {
		std::cout << " dont exists" << std::endl;
	}

}

