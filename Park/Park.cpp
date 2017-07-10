// Park.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "opencv2\opencv.hpp"

#include <sys/types.h>
#include <sys/stat.h>
#include "tools.h"

void test(const char *);

using namespace cv;
using namespace std;
using namespace tl;

int main()
{
	//namedWindow("win");
	try {
		Mat img = imread("img\\bin_dot_1.png");
		//imshow("win", img);
	}
	catch(exception e){
		cout << "could not load image" << endl;
	}

	test("img");
	test("doc");
	test("c:\\");
	test("c:\\workspace");
	test("c:\\workspaceasdfasdf");


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

void test(const char* test) {
	printf(test);

	if (tools::file_exists(test)) {
		cout << " exists" << endl;
	}
	else {
		cout << " dont exists" << endl;
	}

}

