#include "stdafx.h"
#include "Timer.h"


Timer::Timer()
{
}


Timer::~Timer()
{
}

void Timer::start(HWND hwnd, UINT_PTR IDT_TIMER1) {

	SetTimer(hwnd,             // handle to main window 
		IDT_TIMER1,            // timer identifier 
		10000,                 // 10-second interval 
		(TIMERPROC)NULL);     // no timer callback 

}

void Timer::stop() {

}
ark
