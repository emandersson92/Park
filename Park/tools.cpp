#include "stdafx.h" //varf�r beh�vs detta h�r?
#include "tools.h"


namespace tl {

	tools::tools() {

	}

	tools::~tools() {

	}

	bool tools::file_exists(const char *fileName)
	{
		ifstream infile(fileName);
		return infile.good();

	}

}
