#pragma once

#include "vector"
#include "opencv2\core.hpp"
#include "opencv2\imgproc.hpp"
#include "opencv2\tracking.hpp"
#include "Show.h"

struct myTrack {
	cv::Ptr<cv::TrackerKCF> track;
	cv::Ptr<cv::Rect2d> rect;
};

class MyTrackerKCF
{

	typedef std::vector<cv::Point> vecPoint;
	typedef std::vector<vecPoint> vecVecPoint;

public:

	MyTrackerKCF();
	~MyTrackerKCF();
	void apply(cv::Mat& raw, vecVecPoint& contours);



private:
	///Prepare TrackerKCF
	std::vector<myTrack> trackers;
	std::vector<myTrack> tmpVec;//used when deleting certain elements in trackers (ugly but works)

	cv::Rect2d boundingBox;

	const int widMax = 200;
	const int widMin = 50;
	const int heiMax = 200;
	const int heiMin = 50;

};

