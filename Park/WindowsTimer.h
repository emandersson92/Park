#pragma once
#include "windows.h"


class Timer
{
public:
	Timer(Vehicle);
	~Timer();
	void start(HWND hwnd, UINT_PTR IDT_TIMER1);
	void stop();


private:
	long time;


};

