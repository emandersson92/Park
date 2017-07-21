#pragma once

#include <iostream>
#include <fstream>
#include "stdafx.h"
#include "Vehicle.h"


//useful code-snippets
//Emil A 2017-07-08

namespace tl {
	using namespace std;

	class tools {
		public:
			tools();
			~tools();
			
			static bool file_exists(const char *fileName);
			static bool tools::removeListIndex(list<Vehicle*> l, Vehicle* v);

		private:

	};
}