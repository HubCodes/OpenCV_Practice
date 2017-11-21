#include "p34_rdwr.h"

#include <iostream>
#include <string>
#include <opencv2\core.hpp>
#include <opencv2\highgui.hpp>

p34_rdwr::p34_rdwr() {
}


p34_rdwr::~p34_rdwr() {
}

void p34_rdwr::run() {

	welcomeMsg();
	
	cv::Mat image;
	std::string imagePath;
	std::string resultPath;

	std::cout << "[Input] Image file path with file name > ";
	std::cin >> imagePath;

	std::cout << "[Input] Result image path > ";
	std::cin >> resultPath;

	image = cv::imread(imagePath);
	
	if (image.empty()) {
		std::cerr << "An error ocurred.\n";
		std::exit(EXIT_FAILURE);
	}
	cv::namedWindow("p34_rdwr");
	cv::imshow("p34_rdwr", image);

	cv::Mat flipped;
	cv::flip(image, flipped, 1);

	cv::namedWindow("p34_rdwr : flipped");
	cv::imshow("p34_rdwr : flipped", flipped);

	cv::imwrite(resultPath.append("\\result.png"), flipped);

	cv::waitKey(0);
}

void p34_rdwr::welcomeMsg() {
	std::clog << "[Study] OpenCV Practice by Hub : @class p34_rdwr\n";
	std::clog << "[Study] This class provides load and store image.\n";
}
