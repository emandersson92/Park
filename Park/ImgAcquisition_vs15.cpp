#include "stdafx.h"
#include "ImgAcquisition_vs15.h"

ImgAcquisition_vs15::ImgAcquisition_vs15(std::string media)
{
  cap = cv::VideoCapture(media);
  if (!cap.isOpened())
	error(media);



  //determine if the media is an image or an video file

  if (hasEnding(media, ".jpg"))
	  imgPath = true;

  else if (hasEnding(media, ".png"))
	  imgPath = true;

  else if (hasEnding(media, ".mp4"))
	  vidPath = true;

  else if (hasEnding(media, ".avi"))
	vidPath = true;

  else{
	std::cout << "Could not determine the media extention" << std::endl;
	getchar();
  }

}

ImgAcquisition_vs15::~ImgAcquisition_vs15()
{
}


void ImgAcquisition_vs15::apply(cv::Mat& out) {

	if (vidPath)
	{
		cap >> out;
		if (out.empty())
		{
			error(path);
		}
	}

	else if (imgPath)
	{
		getImg(path, out);
	}
	
	else{
	  std::cout << "media path undetermined" << std::endl;
	  getchar();
	}
	
}


void ImgAcquisition_vs15::getImg(std::string& path, cv::Mat& out) {
	try {
		out = cv::imread(path);
	}
	catch (std::exception e) {
		error(path);
	}
}

void ImgAcquisition_vs15::error(std::string& path) {
	std::cout << "Could not load file from path:" << std::endl;
	std::cout << path << std::endl;
	std::cout << "" << std::endl;
	std::cout << "Push any character to exit" << std::endl;
	getchar();
	exit(0);
}


bool ImgAcquisition_vs15::hasEnding(std::string const &fullString, std::string const &ending) {
    if (fullString.length() >= ending.length()) {
        return (0 == fullString.compare (fullString.length() - ending.length(), ending.length(), ending));
    } else {
        return false;
    }
}
