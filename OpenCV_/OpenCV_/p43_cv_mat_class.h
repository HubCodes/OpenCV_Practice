#pragma once
#include "forExample.h"

#include <opencv2\core.hpp>

class p43_cv_mat_class : public forExample {
public:
	p43_cv_mat_class();
	~p43_cv_mat_class();

	virtual void run() override;
	virtual void welcomeMsg() override;

	static cv::Mat function();
};

