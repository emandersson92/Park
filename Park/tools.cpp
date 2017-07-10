#include "stdafx.h" //varför behövs detta här?
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
