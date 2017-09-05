#include "stdafx.h"
#include "MyAssert.h"


MyAssert::MyAssert() {}

MyAssert::~MyAssert() {}

void MyAssert::assertPercentage(double t){
	if(t < 0 || t > 100){
	  getchar();
	}
}
