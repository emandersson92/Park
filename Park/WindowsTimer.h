#pragma once
#include "windows.h"
#include "Vehicle.h"
#include "MyTimer.h"

class WindowsTimer : public MyTimer
{
public:
	WindowsTimer(Vehicle v);
	~WindowsTimer();
	void start(HWND hwnd, UINT_PTR IDT_TIMER1);
	void stop();


private:
	double time;


};

