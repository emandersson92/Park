#pragma once
#include "windows.h"


class Timer
{
public:
	Timer();
	~Timer();
	void startTimer(HWND hwnd, UINT_PTR IDT_TIMER1);
	void stopTimer();


private:
	long time;


};

