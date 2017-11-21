#pragma once
#include "forExample.h"
class p40_mouse_click : public forExample {
public:
	p40_mouse_click();
	~p40_mouse_click();

	virtual void run() override;
	virtual void welcomeMsg() override;

	static void onMouse(int event, int x, int y, int flags, void* param);
};

