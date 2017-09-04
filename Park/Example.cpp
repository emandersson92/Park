#include "Example.h"


Example::Example(){

}

Example::Example~(){

}

Vehicle* Example::createVehicle(){

	Timer* timer = new SimpleTimer();
	vector<point> contours = circle( drawing, center[i], (int)radius[i], color, 2, 8, 0 );
	
	Vehicle* v = e.createVehicle(0.0, 30, 40, timer, contours);

	cv::rectangle r1();
	cv::rectangle r2();
	cv::rectangle r3();
	cv::rectangle r4();
	cv::rectangle r5();


	//Simulate moving car which stops
	VehicleFrame* vf1 = new VehicleFrame(3.3, 50, 50, r1);
	VehicleFrame* vf2 = new VehicleFrame(2.2, 45, 45, r2);
	VehicleFrame* vf3 = new VehicleFrame(1.1, 45, 45, r3);
	VehicleFrame* vf4 = new VehicleFrame(0.1, 45, 45, r4);
	VehicleFrame* vf5 = new VehilceFrame(0.0, 45, 45, r5);



	v->addVehicleFrame(vf1);
	v->addVehicleFrame(vf2);
	v->addVehicleFrame(vf3);
	v->addVehicleFrame(vf4);
 	v->addVehicleFrame(vf5);

return v;
  
}


