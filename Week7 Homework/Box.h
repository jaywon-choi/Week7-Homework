#pragma once
//#include "GeometricObject.h"

class CBox// : public CGeometricObject
{
public:

	struct MyBox
	{
		int start_X_, start_Y_;
		int BoxWidth_, BoxHeight_;
	}myBox_;

	struct MyColor
	{
		float R_, G_, B_;
	}myColor_;

	//CBox(const int start_X, const int start_Y, const int width, const int height , const float R, const float G, const float B);
	void Initialize(const int start_X, const int start_Y, const int width, const int height, const float R, const float G, const float B);
	void draw(float* pixel, const int window_width, const int window_height);

};

