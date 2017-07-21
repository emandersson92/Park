// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../Park/tools.h"
#include "../Park/Vehicle.h"

using namespace tl;
using namespace std;

int main()
{
	
	list<Vehicle*> list;

	Vehicle* v1 = new Vehicle();
	Vehicle* v2 = new Vehicle();
	Vehicle* v3 = new Vehicle();
	Vehicle* v4 = new Vehicle();
	Vehicle* v5 = new Vehicle();
	Vehicle* v6 = new Vehicle();
	Vehicle* v7 = new Vehicle();
	Vehicle* v8 = new Vehicle();
	Vehicle* v9 = new Vehicle();

	list.push_back(v1);
	list.push_back(v2);
	list.push_back(v3);
	list.push_back(v4);
	list.push_back(v5);
	list.push_back(v6);
	list.push_back(v7);
	list.push_back(v8);
	list.push_back(v9);


	tools::removeListIndex(list, v3);

	getchar();



	delete(v1);
	delete(v2);
	delete(v3);
	delete(v4);
	delete(v5);
	delete(v6);
	delete(v7);
	delete(v8);
	delete(v9);




    return 0;
}

