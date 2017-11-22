#include "p43_cv_mat_class.h"

#include <iostream>
#include <string>
#include <opencv2\core.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\imgproc.hpp>

p43_cv_mat_class::p43_cv_mat_class() {
}


p43_cv_mat_class::~p43_cv_mat_class() {
}

void p43_cv_mat_class::run() {
	welcomeMsg();
	
	cv::Mat image1(240, 320, CV_8U, 50);
	
	cv::imshow("Image", image1);
	cv::waitKey(0);

	image1.create(200, 200, CV_8U);
	image1 = 200; // cv::Scalar(200);

	cv::imshow("Image", image1);
	cv::waitKey(0);

	cv::Mat image2(240, 320, CV_8UC3, cv::Scalar(0, 0, 255));

	cv::imshow("Image", image2);
	cv::waitKey(0);

	std::string filePath;
	std::cout << "[Input] Image file path > ";
	std::cin >> filePath;

	cv::Mat image3 = cv::imread(filePath);

	cv::Mat image4(image3); // Shallow copy
	image1 = image3;

	image3.copyTo(image2);
	cv::Mat image5 = image3.clone();

	cv::flip(image3, image3, 1);

	cv::imshow("Image 3", image3);
	cv::imshow("Image 1", image1);
	cv::imshow("Image 2", image2);
	cv::imshow("Image 4", image4);
	cv::imshow("Image 5", image5);

	cv::Mat gray = function();

	cv::imshow("Image", gray);
	cv::waitKey(0);

	image1 = cv::imread(filePath, CV_LOAD_IMAGE_GRAYSCALE);
	image1.convertTo(image2, CV_32F, 1 / 255.0, 0.0);

	cv::imshow("Image", image2);
	cv::waitKey(0);
}

void p43_cv_mat_class::welcomeMsg() {
	std::clog << "[Study] OpenCV Practice by Hub : @class p41_draw_in_image\n";
	std::clog << "[Study] This class provides about of cv::Mat class\n";
}

cv::Mat p43_cv_mat_class::function() {

	cv::Mat img(500, 500, CV_8U, 50);

	return img;
}
