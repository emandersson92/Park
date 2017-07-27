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



using namespace cv;
using namespace std;
using namespace tl;
 

void test(const char *);
void imgDis(Mat& out);
static void help();

bool CV_TRACKER;

static const char* keys =
{ "{@tracker_algorithm | | tracker algorithm }"
"{@video_name        | | video name        }" };

  
int main(int argc, char** argv)
{
	
	CommandLineParser parser(argc, argv, keys);

	String tracker_algorithm = parser.get<String>(0);
	String video_name = parser.get<String>(1);

	if (tracker_algorithm.empty())
	{
		help();
		getchar();
		return -1;
	}

	if (tracker_algorithm == "opencv_tracker")
	{ 
		cout << "using opencv_tracker" << endl;
		CV_TRACKER = true;

	}
	else { 
		CV_TRACKER = false;
	}


	/*
	int thresh = 100;

	Mat out;
	Mat img = imread("img\\bin_dot_1.png");
	namedWindow("Contours", CV_WINDOW_AUTOSIZE);

	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;
	RNG rng(12345);

	Canny(img, out, thresh, thresh * 2, 3);

	imshow("Contours", out);
	waitKey();
	findContours(out, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE);

	/// Draw contours
	Mat drawing = Mat::zeros(out.size(), CV_8UC3);
	for (int i = 0; i< contours.size(); i++)
	{
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		drawContours(drawing, contours, i, color, 2, 8, hierarchy, 0, Point());
	}

	/// Show in a window
	
	imshow("Contours", drawing);


	waitKey();
	*/

	// using CV_TRACKER
	if (CV_TRACKER == true) {
		cout << "CV_TRACKER IS DEFINED" << endl;

		Mat img;
		Mat raw, segmented, filtered, classified;
		bool paused = true;
		bool isTracking = false;

		///Prepare Bindetect
		VehicleDetector* detector = new BinDetect();
		std::vector<std::vector<cv::Point>> contours;
		Rect2d boundingBox;

		///Prepare TrackerKCF
		Ptr<TrackerKCF> tracker = TrackerKCF::create();
		bool initialized = false;

		namedWindow("tracking window");


		//*****************************************
		// PARTS IN while(true)
		//
		// 1/2 --> detect object from movement
		// 2/2 --> track object detected by movement
		//*****************************************
		while (true)
		{
			if (!paused)
			{
				detector->imgAquist(raw);

				//*****************************************
				// 1/2 --> detect object from movement
				//*****************************************
				if (!isTracking)
				{
					detector->segment(raw, segmented); //wrong background subtraction second time? todo
					detector->filter(segmented, filtered);
					detector->classify(filtered, contours);

					///if no object is found, wait for next frame
					if (contours.size() > 0)
					{
						///get one initiating rect to define boundingBox region
						boundingBox = boundingRect(contours.back());

						if (!initialized)
						{
							//initializes the tracker
							if (!tracker->init(raw, boundingBox))
							{
								std::cout << "***Could not initialize tracker...***\n";
								getchar();
								return -1;
							}
							initialized = true;
							isTracking = true;
						}
						///tracker is initialized
						else {
							isTracking = true;
						}
					}
				}
				///the tracker is tracking
				if (isTracking)
				{
					//*****************************************
					// 2/2 --> track object detected by movement
					//*****************************************

					if (tracker->update(raw, boundingBox))
					{
						rectangle(raw, boundingBox, Scalar(255, 0, 0), 2, 1);
					}
					else {
						//tracker lost?? todo check if you come here when tracker is lost
						initialized = false;
						isTracking = false;
						//tracker->clear(); nessesarry?? todo
					}
				}

				imshow("tracking window", raw);
			}

			char c = (char)waitKey(2);
			if (c == 'q')	//quit
				break;
			if (c == 'p')
				paused = !paused;

		}

	}

	else {
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

