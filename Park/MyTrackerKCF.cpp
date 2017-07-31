#include "stdafx.h"
#include "MyTrackerKCF.h"

//this declaration must be here in some way...
/*
struct myTrack {
	cv::Ptr<cv::TrackerKCF> track;
	cv::Ptr<cv::Rect2d> rect;
};
*/



MyTrackerKCF::MyTrackerKCF()
{
	//create new KCF tracker from built in opencv

}


MyTrackerKCF::~MyTrackerKCF()
{
}


void MyTrackerKCF::apply(cv::Mat& raw, vecVecPoint& contours) {
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
					cv::Ptr<cv::TrackerKCF> t = cv::TrackerKCF::create();

					///initialize the tracker
					if (!t->init(raw, boundingBox))
					{
						std::cout << "***Could not initialize tracker...***\n";
						getchar();
						exit(-1);
					}

					myTrack nt;///new tracker
					nt.rect = new cv::Rect2d(boundingBox); //need to create new tracker? boundingbox will get destroyed?
					nt.track = t;

					trackers.push_back(nt);
					//multiTracker.add(t, raw, boundingBox);
				}
			}
		}
	}

	///update the tracking result
	while (!trackers.empty()) {

		cv::Ptr<cv::TrackerKCF> t = trackers.back().track;
		cv::Ptr<cv::Rect2d> r = trackers.back().rect;
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

	/// draw the tracked objects
	for (std::vector<myTrack>::iterator it = trackers.begin(); it < trackers.end(); ++it)
	{
		rectangle(raw, *it->rect, cv::Scalar(255, 0, 0), 2, 1);
	}

	Show::add(raw, "tracking window");

}