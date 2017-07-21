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
void drawcont(Mat& in, Mat& drawn);


int main()
{


	MyTracker simpleTracker = new Bin_MovingObj_MyTracker();


	//still tracker
	//...
	//...
	//...

	vector<MyTracker> trackers;

	trackers.push_back(simpleTracker);
	//trackers.push_back(still tracker);
	//...
	//...
	//...





	VehicleList movList = Moving_VehicleList();
	VehicleList stillList = Still_VehicleList();
	VehicleList alarmList = Still_VehicleList();

	//************************************************
	//vehicle lifecycle:
	//
	//   [movlist] --> [stillList] --> [alarmList]
	//
	movList.connectTo(stillList);
	stillList.connectTo(alarmList);
	//
	//................................................
	



	//Forward vehicles to next lists if condition is ok
	for (MyTracker t : trackers) {
		Vehicle v = t.getVehicle();

		if (v.list.nextList->belongCheck(v)) {
			v.list.forwVehicle();
		}
		else if (t.list.belongCheck(v)) {
			toss vehicle and tracker();
		}
	}


	//add new vehicles to the first list.
	//...
	//...
	//...

	}

    return 0;
}

void drawcont(Mat& in, Mat& drawn){

  Mat gray;
  vector<vector<Point> > contours;
  vector<Vec4i> hierarchy;

  cvtColor(in, gray, CV_BGR2GRAY);

  findContours( gray, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );

  /// Draw contours
  //  drawn = Mat::zeros( gray.size(), CV_8UC3 );
  drawn = gray;
  RNG rng;
  for( int i = 0; i< contours.size(); i++ )
     {
       Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
       drawContours( drawn, contours, i, color, 2, 8, hierarchy, 0, Point() );
     }
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

