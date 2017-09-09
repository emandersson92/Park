#include "stdafx.h" //varf�r beh�vs detta h�r?
#include "tools.h"

tools::tools() {

}

tools::~tools() {

}


bool tools::file_exists(const char *fileName)
{
	std::ifstream infile(fileName);
	return infile.good();

}


cv::Point tools::getCentroid(std::vector<cv::Point>& contours) {

	long xmean = 0;
	long ymean = 0;
	int n = contours.size();

	for (cv::Point p : contours) {
		xmean += p.x;
		ymean += p.y;
	}

	xmean /= n;
	ymean /= n;
	return cv::Point(xmean, ymean);

}


bool tools::removeListIndex(std::list<Vehicle*> l, Vehicle* v) {
	std::list<Vehicle*>::const_iterator it;

	it = l.begin();

	while (it != l.end()) {
		if (*it == v) {			//*it = dereference. Does this mean that the Vehicle is achieved?
			l.erase(it);
			return true;
		}
		it++;
	}
	return false;


	/*
			for (it = l.begin(); it != l.end(); it++)
			{
				for (it2 = l.end() - 1; it2 != it + 1; it2--)
			{	
					if ((*it) == (*it2))
				{	
						it = l.erase(it, it2) - 1;
					brea	k;
				}	
			}	
		}	
		
			*/
}


