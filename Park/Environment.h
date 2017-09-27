/*
Data about the environment the camera is mounted in
*/

#pragma once

namespace Environment{
	const double imagePixelWidth = 640;
	const double horisontalMetersCatched = 20;
	const double metersPerPixel = horisontalMetersCatched/imagePixelWidth;
	const double fps = 30;
	const double parkedVehicleSpeedThreshold = 400; ///under this speed the vehicle is considered as standing still
}


