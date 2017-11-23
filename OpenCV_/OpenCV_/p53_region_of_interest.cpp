#include "p53_region_of_interest.h"

#include <iostream>
#include <string>
#include <opencv2\core.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\imgproc.hpp>

p53_region_of_interest::p53_region_of_interest() {
}


p53_region_of_interest::~p53_region_of_interest() {
}

void p53_region_of_interest::run() {
	welcomeMsg();

	std::string filePath, logoPath;
	std::cout << "[Input] File path > ";
	std::cin >> filePath;

	std::cout << "[Input] Logo file path > ";
	std::cin >> logoPath;

	cv::Mat image = cv::imread(filePath);
	cv::Mat logo = cv::imread(logoPath);

	if (image.empty() || logo.empty()) {
		std::cerr << "Image open failed!\n";
		std::exit(EXIT_FAILURE);
	}

	cv::Mat imageROI(image, cv::Rect(0, 0/*image.cols - logo.cols, image.rows - logo.rows*/, logo.cols, logo.rows));

	logo.copyTo(imageROI);

	cv::namedWindow("with_logo");
	cv::imshow("with_logo", image);
	cv::waitKey(0);
}

void p53_region_of_interest::welcomeMsg() {
	std::clog << "[Study] OpenCV Practice by Hub : @class p53_region_of_interest\n";
	std::clog << "[Study] This class provides how to define ROI with OpenCV.\n";
}
