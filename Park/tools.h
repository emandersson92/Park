#pragma once

#include <iostream>
#include <fstream>
#include "Vehicle.h"


//useful code-snippets
//Emil A 2017-07-08


class tools {
	public:
		tools();
		~tools();
			
		static bool file_exists(const char *fileName);
		static bool removeListIndex(std::list<Vehicle*> l, Vehicle* v);
		static cv::Point tools::getCentroid(std::vector<cv::Point>& contours);
		


	private:

};
