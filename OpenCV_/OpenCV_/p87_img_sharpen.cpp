#include "p87_img_sharpen.h"

#include <iostream>
#include <string>
#include <opencv2\core.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\imgproc.hpp>

p87_img_sharpen::p87_img_sharpen() {
}


p87_img_sharpen::~p87_img_sharpen() {
}

void p87_img_sharpen::run() {
	welcomeMsg();

	std::string filePath;
	std::cout << "[Input] file path > ";
	std::cin >> filePath;

	cv::Mat img = cv::imread(filePath);	
	cv::Mat result(img.size(), img.type());
	int n_chan = img.channels();

	const uchar* prev;
	const uchar* cur;
	const uchar* next;

	uchar* out;

	for (int j = 1; j < img.rows - 1; j++) {
		prev = img.ptr<const uchar>(j - 1);
		cur = img.ptr<const uchar>(j);
		next = img.ptr<const uchar>(j + 1);

		out = result.ptr<uchar>(j);

		for (int i = 0; i < (img.cols - 1) * n_chan; i++) {
			*out++ = cv::saturate_cast<uchar>(5 * cur[i] - cur[i - n_chan] - cur[i + n_chan] - prev[i] - next[i]);
		}

		result.row(0).setTo(cv::Scalar(0));
		result.row(result.rows - 1).setTo(cv::Scalar(0));
		result.col(0).setTo(cv::Scalar(0));
		result.col(result.cols - 1).setTo(cv::Scalar(0));
	}

	cv::namedWindow("p87_img_sharpen");
	cv::imshow("p87_img_sharpen", result);

	cv::waitKey(0);
}

void p87_img_sharpen::welcomeMsg() {
	std::clog << "[Study] OpenCV Practice by Hub : @class p87_img_sharpen\n";
	std::clog << "[Study] This class provides sharpen image.\n";
}
