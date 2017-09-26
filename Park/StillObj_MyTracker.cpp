#include "stdafx.h"
#include "StillObj_MyTracker.h"


StillObj_MyTracker::StillObj_MyTracker(Vehicle* v, VehicleDetector* d)
{
	///VehicleFrame
  VehicleFrame* vf = v->getLastVehicleFrame();
  cur_vehicleArea = vf->cloneBinROI();
  init_vehicleArea = vf->cloneBinROI();

  vehicleFrame = vf;

  detector = d;

  ///percentage of ROI is car area (not 0 but 255)
  ir_fg = percentage_foreground(init_vehicleArea);


  timer = new SimpleTimer();

  ALIVE = true;
  FIRST = true;
}


StillObj_MyTracker::~StillObj_MyTracker()
{
  delete(timer);
}

/* TODO
Vehicle* StillObj_MyTracker::getVehicle() {
	return;
}
*/
void StillObj_MyTracker::track() {
  if (FIRST){
	FIRST = false;
	timer->start();
  }
  
  reduceVehicleArea();
  surviveTest();
  restoreVehicleArea();
  


  timer->increment();
}



/*
Explanation:
When movement is detected on vehicle spot it indicates vehicle movement.

Practical:
The vehicleArea's white area will be replaced with black on the parts where movement apperears.
*/
void StillObj_MyTracker::reduceVehicleArea() {

	detector->imgAquist(in_detect);
	raw = in_detect.clone();
	detector->segment(in_detect, tmp1);
	detector->filter(tmp1, out_detect);

	///get relative ROI location
	cv::Size size; cv::Point ofs;
	cur_vehicleArea.locateROI(size, ofs);
	///get ROI movement spot
	movementArea = out_detect(cv::Rect(ofs.x, ofs.y, cur_vehicleArea.cols, cur_vehicleArea.rows));
	
	///tracked area subtracted with area with movement
	cur_vehicleArea -= movementArea;
}

void StillObj_MyTracker::surviveTest() {
  
	//Implement time?

  ///simplifying future code reading
  cv::Mat cr = cur_vehicleArea;
  cv::Mat ir = init_vehicleArea;
  double cr_fg = percentage_foreground(cr);


  //test
  if(ir_fg < cr_fg){
	getchar();
  }

  lifeLeft = (100.0 * cr_fg/ir_fg);
  
  //test
  MyAssert::assertPercentage(lifeLeft);

  if (lifeLeft < _minLife)
	{
	  ALIVE = false;
	  //killTracker(); --> use abstract class enwrapper?
	}
}

void StillObj_MyTracker::restoreVehicleArea(){

	cur_vehicleArea += init_vehicleArea;

}



double StillObj_MyTracker::getLifeThresh(){
  return _minLife;
}

double StillObj_MyTracker::getLifeLeft(){
  return lifeLeft;
}


bool StillObj_MyTracker::isAlive(){
	return ALIVE;
}

double StillObj_MyTracker::getParkTime(){
	return timer->getTime();
}


void StillObj_MyTracker::paint(){

	///get relative ROI location
	cv::Size size; cv::Point ofs;
	cur_vehicleArea.locateROI(size, ofs);

	///get ROI movement spot
	cv::Mat rawROI = raw(cv::Rect(ofs.x, ofs.y, cur_vehicleArea.cols, cur_vehicleArea.rows));

	///convert vehicleArea to 3 type channel in order to add to raw
	cv::Mat trackColROI;///color
	cv::cvtColor(cur_vehicleArea, trackColROI, CV_GRAY2BGR);

	///movement in red
	trackColROI.setTo(cv::Scalar(0, 0, 255), movementArea);

	rawROI = rawROI + trackColROI;

}


double StillObj_MyTracker::percentage_foreground(cv::Mat& m){

	double nonzero = cv::countNonZero(m);

	double ret = nonzero / (double)(m.cols * m.rows) * 100;
	MyAssert::assertPercentage(ret);

	return ret;
}

cv::Mat StillObj_MyTracker::getLastImg(){
  return raw;
}
