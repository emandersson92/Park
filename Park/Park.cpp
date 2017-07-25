// Park.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "opencvIncludes.h"

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

using namespace cv;
using namespace std;
using namespace tl;
 

void test(const char *);
void imgDis(Mat& out);
static void help();



static const char* keys =
{ "{@tracker_algorithm | | tracker algorithm }"
"{@video_name        | | video name        }" };

  
int main(int argc, char** argv)
{
	
	CommandLineParser parser(argc, argv, keys);

	String tracker_algorithm = parser.get<String>(0);
	String video_name = parser.get<String>(1);

	if (tracker_algorithm.empty() || video_name.empty())
	{
		help();
		getchar();
		return -1;
	}





	MyTracker* simpleTracker = new Bin_MovingObj_MyTracker(new std::vector<std::vector<cv::Point>>);
	

	//still tracker
	//...
	//...
	//...

	vector<MyTracker*> trackers;

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

    return 0;
}


static void help()
{
	cout << "blablabla" << endl;

}



//Image Display
void imgDis(Mat& out) {
	namedWindow("win");
	imshow("win", out);
	cvMoveWindow("win", 0, 0);
	waitKey(0);

}

void test(const char* test) {
	printf(test);

	//does not work yet
	if (tools::file_exists(test)) {
		cout << " exists" << endl;
	}
	else {
		cout << " dont exists" << endl;
	}

}

