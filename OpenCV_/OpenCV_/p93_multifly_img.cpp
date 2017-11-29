#include "p93_multifly_img.h"

#include <iostream>
#include <string>
#include <opencv2\core.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\imgproc.hpp>

p93_multifly_img::p93_multifly_img() {
}


p93_multifly_img::~p93_multifly_img() {
}

void p93_multifly_img::run() {
	welcomeMsg();

	std::string filePath1;
	std::cout << "[Input] image1 file path > ";
	std::cin >> filePath1;

	std::string filePath2;
	std::cout << "[Input] image2 file path > ";
	std::cin >> filePath2;

	cv::Mat img1 = cv::imread(filePath1);
	cv::Mat img2 = cv::imread(filePath2);
	cv::Mat result;

	cv::addWeighted(img1, 0.7, img2, 0.6, 0.0, result);

	cv::namedWindow("p93_multifly_img");
	cv::imshow("p93_multifly_img", result);

	cv::waitKey(0);
}

void p93_multifly_img::welcomeMsg() {
	std::clog << "[Study] OpenCV Practice by Hub : @class p93_multifly_img\n";
	std::clog << "[Study] This class provides multifly image example.\n";
}
