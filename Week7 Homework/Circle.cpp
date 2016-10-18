#include "Circle.h"
#include <math.h>
/*
CCircle::CCircle(const int x, const int y, const int radius, const float R, const float G, const float B)
{
	Initialize(x, y, radius, R, G, B);
}
*/
void CCircle::Initialize(const int x, const int y, const int radius, const float R, const float G, const float B)
{
	cX_ = x;
	cY_ = y;
	radius_ = radius;

	myColor_.R_ = R;
	myColor_.G_ = G;
	myColor_.B_ = B;
}


void CCircle::draw(float* pixels, const int window_width, const int window_height)
{
	float i = 0.0;
	float rDeg = 0.0;
	float degree = 360.0;
	int x2 = 0, y2 = 0;


	for (degree = 0; degree < 360; degree++)
	{
		rDeg = degree*(pi_ / 180);
		
		x2 = cX_ + radius_ * sin(rDeg);
		y2 = cY_ + radius_ * cos(rDeg);
		
		pixels[(y2 * window_width + x2) * 3 + 0] = myColor_.R_;
		pixels[(y2 * window_width + x2) * 3 + 1] = myColor_.G_;
		pixels[(y2 * window_width + x2) * 3 + 2] = myColor_.B_;
	}

	//drawRedCircle(pixels, window_width, window_width, cX_, cY_, radius_ + 20);
}

