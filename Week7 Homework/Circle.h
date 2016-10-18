#pragma once
//#include "GeometricObject.h"

class CCircle// :public CGeometricObject
{
public :

	struct MyColor
	{
		float R_, G_, B_;
	}myColor_;
	
	int cX_, cY_;
	float radius_;
	float pi_ = 3.141592;

	//CCircle(const int x, const int y, const int radius, const float R, const float G, const float B);
	void Initialize(const int x, const int y, const int radius, const float R, const float G, const float B);
	void draw(float* pixel, const int window_width, const int window_height);
};