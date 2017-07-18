// Park.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "opencv2\opencv.hpp"
#include "opencv2\video\tracking.hpp"

#include <sys/types.h>
#include <sys/stat.h>
#include "tools.h"


//tracker
#include <opencv2/core/utility.hpp>

#include <opencv2/tracking.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <cstring>




using namespace cv;
using namespace std;
using namespace tl;


void test(const char *);
void imgDis(Mat& out);
void imgProc(Mat& raw, Mat& drawn);
void imgAqu(string input, Mat& out);
void drawcont(Mat& in, Mat& drawn);


int main()
{

	//Definitions
	Mat raw;
	Mat drawn;
	string input = "img\\bin_dot_1.png";


	//Image aquistion
	imgAqu(input, raw);


	imgProc simpleBinTrack;


	//Image processing
	imgProc(raw, drawn);


	//Image display
	imgDis(drawn);
	
	getchar();


	//Mat canny_output;
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;

	/// Detect edges using canny
	//Canny(src_gray, canny_output, thresh, thresh * 2, 3);
	/// Find contours
	//findContours(canny_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));




	

    return 0;
}

void imgAqu(string input, Mat& raw) {
	
	try {
	  raw = imread(input); 
		//Läs detta imorgon
	//https://stackoverflow.com/questions/23468537/differences-of-using-const-cvmat-cvmat-cvmat-or-const-cvmat

	}
	catch (exception e) {
		cout << "could not load image" << endl;
		cout << "Push any character to exit" << endl;
		getchar();
		exit(-1);
	}
}


void imgProc(Mat& in, Mat& drawn) {
  //----------------------------------------
  //Find and Draw contours
  //
  //........................................

 

  drawcont(in, drawn);


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


void tracker(){

int main( int argc, char** argv ){
  // show help
  if(argc<2){
    cout<<
      " Usage: tracker <video_name>\n"
      " examples:\n"
      " example_tracking_kcf Bolt/img/%04d.jpg\n"
      " example_tracking_kcf faceocc2.webm\n"
      << endl;
    return 0;
  }
  // declares all required variables
  Rect2d roi;
  Mat frame;

  // create a tracker object
  Ptr<Tracker> tracker = Tracker::create( "KCF" );
  // set input video
  string video = argv[1];
  VideoCapture cap(video);
  // get bounding box
  cap >> frame;
  roi=selectROI("tracker",frame);
  //quit if ROI was not selected
  if(roi.width==0 || roi.height==0)
    return 0;
  // initialize the tracker
  tracker->init(frame,roi);
  // perform the tracking process
  printf("Start the tracking process, press ESC to quit.\n");
  for ( ;; ){
    // get frame from the video
    cap >> frame;
    // stop the program if no more images
    if(frame.rows==0 || frame.cols==0)
      break;
    // update the tracking result
    tracker->update(frame,roi);
    // draw the tracked object
    rectangle( frame, roi, Scalar( 255, 0, 0 ), 2, 1 );
    // show image with the tracked object
    imshow("tracker",frame);
    //quit on ESC button
    if(waitKey(1)==27)break;
  }
  return 0;
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

