// Cowtrack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "opencv2/opencv.hpp"
#include <sstream>
#include ""
#include "Background.h"

//KEY CODES
int KEY_ESC = 27;
int KEY_SPACE = 32;
int KEY_MINUS = 45;
int KEY_PLUS = 43;
int KEY_G = 103;		//Generate new video with brunst parts
int KEY_S = 115;
int KEY_NOKEY = 255;

using namespace cv;
using namespace std;

int main(int, char**)
{


#define ONLINE


#ifdef PARK
	string vid1 = "A:\\Company\\Working\\PROJECTS\\Park\\workspace\\C++\\Videos\\parkinglot.mp4";
#endif

#ifdef COW
	string vid1 = "C:\\Users\\E\\Desktop\\Kodata\\Videor\\cow.mp4";
	string snap_path = "C:\\Users\\E\\Desktop\\Kodata\\Sparade_bilder\\";
#endif

#ifdef ONLINE
	string vid1 = "http://94.72.19.56/mjpg/video.mjpg?COUNTER";

#endif

	

	Background bg;
	bg.calcHist("A:\\Company\\Working\\PROJECTS\\Park\\workspace\\C++\\Videos\\parkinglot.mp4");




	waitKey(0);

	VideoCapture cap(vid1);

	VideoWriter outputVideo;
	
	//const string source = "output.avi";           // the source file name
	//const string NAME = source.substr(0, pAt) + argv[2][0] + ".avi";   // Form the new name with container
	
	/*
	Size S = Size((int)cap.get(CV_CAP_PROP_FRAME_WIDTH),    // Acquire input size
		(int)cap.get(CV_CAP_PROP_FRAME_HEIGHT));
	const string NAME = "C:\\Users\\E\\Desktop\\output.mp4";
	
	int ex = static_cast<int>(cap.get(CV_CAP_PROP_FOURCC));     // Get Codec Type- Int form
	outputVideo.open(NAME, ex=-1, cap.get(CV_CAP_PROP_FPS), S, true);

	*/
	

	/*
	if (!outputVideo.isOpened())
	{
		cout << "Could not open the output video for write: " << endl;
		getchar();
		return -1;
	}
	*/


	Ptr<BackgroundSubtractor> bcksub;
	bcksub = createBackgroundSubtractorMOG2();


	Mat in;	//Raw
	Mat tmp;
	Mat bs; //Backgroundsubtractor'
	Mat er;	//Erode
	Mat di;	//Dilate

	//FULLSCREN WINDOW
	//cvNamedWindow("window", CV_WINDOW_NORMAL);
	//cvSetWindowProperty("window", CV_WND_PROP_FULLSCREEN, CV_WINDOW_FULLSCREEN);

	namedWindow("in");
	namedWindow("bs");
	namedWindow("er");
	namedWindow("di");
	//namedWindow("four");

	int lstkey = 255;



	//ERODE, DILATE, FINDCOUNTOURS - parameters
	int erosion_size = 2;
	int dilate_size = 15;


	Mat erelem = getStructuringElement(MORPH_RECT,
		Size(2 * erosion_size + 1, 2 * erosion_size + 1),
		Point(erosion_size, erosion_size));

	Mat dielem = getStructuringElement(MORPH_RECT,
		Size(2 * dilate_size + 1, 2 * dilate_size + 1),
		Point(dilate_size, dilate_size));

	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;






	while (true) {

		// Grab the frame and display it.
		cap.grab();
		cap.grab();
		cap.grab();
		cap >> in;

		if (in.empty())
		{
			break;	// reach to the end of the video file
		}

		
		bcksub->apply(in, bs);
		erode(bs, er, erelem);
		dilate(er, di, dielem);


		/// Find contours
		findContours(di, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));

		cout << contours.size() << endl;



		for (int i = 0; i < contours.size(); i++) {
			vector<Point> a = contours.at(i);
			Rect r = boundingRect(a);
			long area = r.width*r.height;
			if (area < 5500) 
				break;

			rectangle(in, r, Scalar(0,255,0));
		}



		imshow("in", in);
		imshow("bs", bs);
		imshow("er", er);
		imshow("di", di);


		//outputVideo << in;


		lstkey = waitKey(10);

		//EXIT
		if (lstkey == KEY_ESC) {
			cout << lstkey + " - ENDING" << endl;
			break;
		}


		//Check keys
		else if (lstkey != KEY_NOKEY) {
			cout << lstkey << endl;
		}

		//video_time += time_jump;										// Decrease video time by number of msec in one frame and seek to the new time.

																		//if (waitKey(30) == 0) break;
	}
	// the camera will be deinitialized automatically in VideoCapture destructor
	return 0;
}

