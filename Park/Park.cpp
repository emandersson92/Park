// Park.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "opencv2\opencv.hpp"

#include <sys/types.h>
#include <sys/stat.h>
#include "tools.h"


using namespace cv;
using namespace std;
using namespace tl;


void test(const char *);
void imgDis(Mat out);
void imgAqu(Mat raw, string input);

int main()
{

	//Definitions
	Mat raw;
	string input = "img\\bin_dot_1.png";




	//Image aquistion
	imgAqu(raw&, input);



	//Image display
	imgDis(raw);
	
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

void imgAqu(Mat* raw, string input) {
	
	try {
	  raw* = imread(input); 
		//Läs detta imorgon
	https://stackoverflow.com/questions/23468537/differences-of-using-const-cvmat-cvmat-cvmat-or-const-cvmat

	}
	catch (exception e) {
		cout << "could not load image" << endl;
		cout << "Push any character to exit" << endl;
		getchar();
		exit(-1);
	}
}


//Image Display
void imgDis(Mat out) {
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

