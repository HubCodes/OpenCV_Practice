#include <iostream>
#include <memory>

#include "forExample.h"
#include "p34_rdwr.h"
#include "p40_mouse_click.h"
#include "p41_draw_on_image.h"
#include "p43_cv_mat_class.h"
#include "p53_region_of_interest.h"
#include "p62_sap_noise.h"
#include "p67_reduce_color.h"
#include "p87_img_sharpen.h"
#include "p93_multifly_img.h"

#ifdef _DEBUG 
#pragma comment (lib, "opencv_calib3d320d.lib") 
#pragma comment (lib, "opencv_core320d.lib") 
#pragma comment (lib, "opencv_features2d320d.lib") 
#pragma comment (lib, "opencv_flann320d.lib") 
#pragma comment (lib, "opencv_highgui320d.lib") 
#pragma comment (lib, "opencv_imgcodecs320d.lib") 
#pragma comment (lib, "opencv_imgproc320d.lib") 
#pragma comment (lib, "opencv_ml320d.lib") 
#pragma comment (lib, "opencv_objdetect320d.lib") 
#pragma comment (lib, "opencv_photo320d.lib") 
#pragma comment (lib, "opencv_shape320d.lib") 
#pragma comment (lib, "opencv_stitching320d.lib") 
#pragma comment (lib, "opencv_superres320d.lib") 
#pragma comment (lib, "opencv_video320d.lib") 
#pragma comment (lib, "opencv_videoio320d.lib") 
#pragma comment (lib, "opencv_videostab320d.lib") 
#else 
#pragma comment (lib, "opencv_calib3d320.lib")
#pragma comment (lib, "opencv_core320.lib")
#pragma comment (lib, "opencv_features2d320.lib")
#pragma comment (lib, "opencv_flann320.lib")
#pragma comment (lib, "opencv_highgui320.lib")
#pragma comment (lib, "opencv_imgcodecs320.lib")
#pragma comment (lib, "opencv_imgproc320.lib")
#pragma comment (lib, "opencv_ml320.lib")
#pragma comment (lib, "opencv_objdetect320.lib")
#pragma comment (lib, "opencv_photo320.lib")
#pragma comment (lib, "opencv_shape320.lib")
#pragma comment (lib, "opencv_stitching320.lib")
#pragma comment (lib, "opencv_superres320.lib")
#pragma comment (lib, "opencv_video320.lib")
#pragma comment (lib, "opencv_videoio320.lib")
#pragma comment (lib, "opencv_videostab320.lib")
#endif

int main() {

	int classSelector;

	std::cout << "확인할 예제 코드와 관련된 책의 페이지를 입력하세요. > ";
	std::cin >> classSelector;

	std::unique_ptr<forExample> example;

	switch (classSelector) {
	case 34:
		example.reset(new p34_rdwr());
		break;
	case 40:
		example.reset(new p40_mouse_click());
		break;
	case 41:
		example.reset(new p41_draw_on_image());
		break;
	case 43:
		example.reset(new p43_cv_mat_class());
		break;
	case 53:
		example.reset(new p53_region_of_interest());
		break;
	case 62:
		example.reset(new p62_sap_noise());
		break;
	case 67:
		example.reset(new p67_reduce_color());
		break;
	case 87:
		example.reset(new p87_img_sharpen());
		break;
	case 93:
		example.reset(new p93_multifly_img());
		break;
	default:
		std::cerr << "페이지와 관련된 코드가 없습니다.\n";
		return -1;
	}
	example->run();

	return 0;
}
