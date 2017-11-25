#include "p62_sap_noise.h"

#include <iostream>
#include <string>
#include <random>
#include <opencv2\core.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\imgproc.hpp>

p62_sap_noise::p62_sap_noise() {
}


p62_sap_noise::~p62_sap_noise() {
}

void p62_sap_noise::run() {
	welcomeMsg();

	std::string filePath;
	std::cout << "[Input] file path > ";
	std::cin >> filePath;

	int n;
	std::cout << "[Input] n factor > ";
	std::cin >> n;

	cv::Mat img = cv::imread(filePath);

	std::default_random_engine generator;
	std::uniform_int_distribution<int> randomRow(0, img.rows - 1);
	std::uniform_int_distribution<int> randomCol(0, img.cols - 1);

	int k, l;

	for (auto i = 0; i < n; i++) {
		k = randomCol(generator);
		l = randomRow(generator);
		if (img.type() == CV_8UC1) {
			img.at<uchar>(l, k) = 255;
		} else if (img.type() == CV_8UC3) {
			img.at<cv::Vec3b>(l, k)[0] = 255;
			img.at<cv::Vec3b>(l, k)[1] = 255;
			img.at<cv::Vec3b>(l, k)[2] = 255;
		}
 	}

	cv::namedWindow("Salt-And-Pepper");
	cv::imshow("Salt-And-Pepper", img);

	cv::waitKey(0);
}
void p62_sap_noise::welcomeMsg() {
	std::clog << "[Study] OpenCV Practice by Hub : @class p62_sap_noise\n";
	std::clog << "[Study] This class provides Salt-and-pepper noise.\n";
}
