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


	bool tools::removeListIndex(list<Vehicle*> l, Vehicle* v) {
		list<Vehicle*>::const_iterator it;

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
					break;
				}
			}
		}
	
		*/
	}


}
