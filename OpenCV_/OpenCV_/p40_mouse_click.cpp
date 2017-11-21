#include "p40_mouse_click.h"

#include <iostream>
#include <string>
#include <functional>
#include <opencv2\core.hpp>
#include <opencv2\highgui.hpp>

p40_mouse_click::p40_mouse_click() {
}


p40_mouse_click::~p40_mouse_click() {
}

void p40_mouse_click::run() {
	welcomeMsg();

	std::string filePath;

	std::cout << "[Input] Image file path > ";
	std::cin >> filePath;

	/* Read image with grayscale. */
	cv::Mat img = cv::imread(filePath);

	if (img.empty()) {
		std::cerr << "An error ocurred.\n";
		std::exit(EXIT_FAILURE);
	}

	cv::namedWindow("p40_mouse_click");
	cv::imshow("p40_mouse_click", img);

	cv::setMouseCallback("p40_mouse_click", onMouse, reinterpret_cast<void*>(&img));

	cv::waitKey(0);
}

void p40_mouse_click::welcomeMsg() {
	std::clog << "[Study] OpenCV Practice by Hub : @class p40_mouse_click\n";
	std::clog << "[Study] This class provides clicking mouse on the image.\n";
}

void p40_mouse_click::onMouse(int event, int x, int y, int flags, void * param) {

	cv::Mat* img = reinterpret_cast<cv::Mat*> (param);

	switch (event) {
	case CV_EVENT_LBUTTONDOWN:
		std::cout << "at (" << x << ", " << y << ") value is : \n" 
			<< static_cast<int>(img->at<cv::Vec3b>(cv::Point(x, y))[0]) << " ," <<
			static_cast<int>(img->at<cv::Vec3b>(cv::Point(x, y))[1]) << " ," << 
			static_cast<int>(img->at<cv::Vec3b>(cv::Point(x, y))[2]) << " \n";
		break;
	}
}
