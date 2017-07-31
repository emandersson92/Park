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

#include "opencv2\highgui.hpp"

#include "Show.h"
#include "list"

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

  

struct myTrack {
	Ptr<TrackerKCF> track;
	Ptr<Rect2d> rect;
};


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


	//TEMPORARILY PUT HERE

	const int widMax = 200;
	const int widMin = 50;
	const int heiMax = 200;
	const int heiMin = 50;


	// using CV_TRACKER
	if (CV_TRACKER == true) {
		cout << "CV_TRACKER IS DEFINED" << endl;

		Mat img;
		Mat raw, segmented, filtered, classified;
		bool paused = false;
		bool isTracking = false;

		///Prepare Bindetect
		VehicleDetector* detector = new BinDetect();
		std::vector<std::vector<cv::Point>> contours;
		Rect2d boundingBox;

		///Prepare TrackerKCF
		std::vector<myTrack> trackers;
		std::vector<myTrack> tmpVec;//used when deleting certain elements in trackers (ugly but works)
		//MultiTracker multiTracker;

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

				//new detected objects must not intersect with tracking objects 
				detector->segment(raw, segmented); //wrong background subtraction second time? todo
				detector->filter(segmented, filtered);
				detector->classify(filtered, contours);

				//cv::imshow("filtered", filtered);
				//cv::imshow("segmented", segmented);
				//char ch = waitKey();
					
				///if no object is found, wait for next frame
				if (contours.size() > 0)
				{
					///get one initiating rect to define boundingBox region
					while (!contours.empty()) {
						boundingBox = boundingRect(contours.back());
						contours.pop_back();

						///box big enough?
						if (boundingBox.width <= widMax && boundingBox.width >= widMin && boundingBox.height <= heiMax && boundingBox.height >= heiMin)
						{

							bool intersect = false;

							for each (myTrack t in trackers)
							{
								if (((*t.rect & boundingBox).area() > 0)) {
									intersect = true;
									break;
								}
							}


							if (!intersect) {
								///no intersection. Create new tracker
								Ptr<TrackerKCF> t = TrackerKCF::create();
								
								///initialize the tracker
								if (!t->init(raw, boundingBox))
								{
									std::cout << "***Could not initialize tracker...***\n";
									getchar();
									return -1;
								}

								myTrack nt;///new tracker
								nt.rect = new Rect2d(boundingBox); //need to create new tracker? boundingbox will get destroyed?
								nt.track = t;

								trackers.push_back(nt);
								//multiTracker.add(t, raw, boundingBox);
							}
						}
					}
				}

				///update the tracking result

				

				while (!trackers.empty()) {
					
					Ptr<TrackerKCF> t = trackers.back().track;
					Ptr<Rect2d> r = trackers.back().rect;
					myTrack tmpTrack = trackers.back();
					trackers.pop_back();

					if (!t->update(raw, *r)) {
						///could not update tracker
						///delete tracker
						
						//memory leakage??
						//delete(t);
						//delete(r);
					}
					else {
						tmpVec.push_back(tmpTrack);
					}
				}

				trackers = tmpVec;
				tmpVec.clear();

				/*
				for (int i = 0; i < trackers.size(); i++)
				{
					Ptr<TrackerKCF> t = trackers[i].track;
					Ptr<Rect2d> r = trackers[i].rect;

					if (!t->update(raw, *r)) {
						///could not update tracker
						///delete tracker
						delete(t);
						delete(r);
						trackers.erase(trackers.at(i));

					}
				}
				*/
				
				/*
				for (std::list<myTrack*>::iterator it = trackers.begin(); it != trackers.end(); ++it)
				{
					Ptr<TrackerKCF> t = it->track;
					Ptr<Rect2d> r = it->rect;

					if (!t->update(raw, *r)) {
						///could not update tracker
						///delete tracker
						delete(t);
						delete(r);
						it = trackers->erase(it);

					}

				}
				*/


				
				/*
				for each (myTrack t in trackers)
				{
					if (!t.track->update(raw, *t.rect)) {
						///could not update tracker
						///delete tracker
						delete(t.rect);
						t.track->~TrackerKCF();
						//trackers.erase()
					}
				}

				*/


//				multiTracker.update(raw);
				
				///Todo are the trackers deleted when they are lost?
				

				/// draw the tracked objects
				for (std::vector<myTrack>::iterator it = trackers.begin(); it < trackers.end(); ++it)
				{
					rectangle(raw, *it->rect, Scalar(255, 0, 0), 2, 1);

				}


/*
				/// draw the tracked objects
				for (unsigned i = 0; i<trackers.size(); i++)
					rectangle(raw, trackers.begin()   getObjects()[i], Scalar(255, 0, 0), 2, 1);

	*/
	// show image with the tracked object
		
				imshow("tracking window", raw);
				//quit on ESC button
				if (waitKey(1) == 27)break;
			}

			Show::showImg();

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

