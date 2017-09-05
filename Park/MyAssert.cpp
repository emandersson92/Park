#include "stdafx.h"
#include "MyAssert.h"


void MyAssert::assertPercentage(){
	if(ret < 0 || ret > 100){
	  getchar();
	}
}
