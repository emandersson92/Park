#pragma once

#include <iostream>
#include <fstream>
#include "stdafx.h"

//useful code-snippets
//Emil A 2017-07-08

namespace tl {
	using namespace std;

	class tools {
		public:
			tools();
			~tools();
			
			static bool file_exists(const char *fileName);

		private:

	};
}