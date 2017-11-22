#include "p41_draw_on_image.h"

#include <iostream>
#include <string>
#include <opencv2\core.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\imgproc.hpp>

p41_draw_on_image::p41_draw_on_image() {
}


p41_draw_on_image::~p41_draw_on_image() {
}

void p41_draw_on_image::run() {
	welcomeMsg();

	std::string filePath;
	std::cout << "[Input] Image file path > ";
	std::cin >> filePath;

	cv::Mat img = cv::imread(filePath);
	cv::circle(img, cv::Point(img.cols / 2, img.rows / 2), 65, cv::Scalar(0, 0, 0), 3);

	cv::namedWindow("p41_draw_on_image");
	cv::imshow("p41_draw_on_image", img);
	cv::waitKey(0);
}

void p41_draw_on_image::welcomeMsg() {
	std::clog << "[Study] OpenCV Practice by Hub : @class p41_draw_in_image\n";
	std::clog << "[Study] This class provides drawing on image.\n";
}
