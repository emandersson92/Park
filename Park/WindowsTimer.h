#pragma once
#include "windows.h"


class WindowsTimer : Timer
{
public:
	WindowsTimer(Vehicle);
	~WindowsTimer();
	void start(HWND hwnd, UINT_PTR IDT_TIMER1);
	void stop();
p

private:
	long time;


};

