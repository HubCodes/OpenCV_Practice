#include "p67_reduce_color.h"

#include <iostream>
#include <string>
#include <opencv2\core.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\imgproc.hpp>

p67_reduce_color::p67_reduce_color() {
}


p67_reduce_color::~p67_reduce_color() {
}

void p67_reduce_color::run() {
	welcomeMsg();

	std::string filePath;
	std::cout << "[Input] file path > ";
	std::cin >> filePath;

	int n;
	std::cout << "[Input] n factor > ";
	std::cin >> n;

	cv::Mat img = cv::imread(filePath);

	uchar* data;

	int nc = img.cols * img.channels();
	
	for (auto j = 0; j < img.rows; j++) {
		data = img.ptr<uchar>(j);

		for (auto i = 0; i < nc; i++) {
			data[i] = data[i] / n*n + n / 2;
		}
	}

	cv::namedWindow("p67_reduce_color");
	cv::imshow("p67_reduce_color", img);

	cv::waitKey(0);
}

void p67_reduce_color::welcomeMsg() {
	std::clog << "[Study] OpenCV Practice by Hub : @class p67_reduce_color\n";
	std::clog << "[Study] This class provides reduce color.\n";
}


