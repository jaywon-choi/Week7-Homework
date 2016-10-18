#include "DrawLine.h"
#include <iostream>

CDrawLine::CDrawLine(const int start_X, const int start_Y, const int end_X, const int end_Y)
{
	Initialize(start_X, start_Y, end_X, end_Y);
}


void CDrawLine::Initialize(const int start_X, const int start_Y, const int end_X, const int end_Y)
{
	drawPoint_.start_X_ = start_X;
	drawPoint_.start_Y_ = start_Y;
	drawPoint_.end_X_ = end_X;
	drawPoint_.end_Y_ = end_Y;
}


//void CDrawLine::DrawDiagonal(float* pixels, const int width, const int height)
//{
//
//	int startX, startY;
//	int dx, dy, p, endX;
//
//	dx = abs(drawPoint_.start_X_ - drawPoint_.end_X_);
//	dy = abs(drawPoint_.start_Y_ - drawPoint_.end_Y_);
//
//	p = 2 * dy - dx;
//
//	if (drawPoint_.start_X_ > drawPoint_.end_X_)
//	{
//		startX = drawPoint_.end_X_;
//		startY = drawPoint_.end_Y_;
//		endX = drawPoint_.start_X_;
//	}
//	else
//	{
//		startX = drawPoint_.start_X_;
//		startY = drawPoint_.start_Y_;
//		endX = drawPoint_.end_X_;
//	}
//	pixels[((startY * width) + startX) * 3 + 0] = 0.0f;
//	pixels[((startY * width) + startX) * 3 + 1] = 0.0f;
//
//
//	while (startX < endX)
//	{
//		startX = startX + 1;
//		if (p < 0)
//		{
//			p = p + 2 * dy;
//		}
//		else
//		{
//			startY = startY + 1;
//			p = p + 2 * (dy - dx);
//		}
//		pixels[((startY * width) + startX) * 3 + 0] = 0.0f;
//		pixels[((startY * width) + startX) * 3 + 1] = 0.0f;
//	}
//	
//}
void CDrawLine::DrawDiagonal(float* pixels, const int width, const int height, const float R, const float G, const float B)
{
	
	if ((drawPoint_.end_X_ - drawPoint_.start_X_) != 0)
	{
		for (int i = drawPoint_.start_Y_; i < drawPoint_.end_Y_; i++)
		{
			const int j = (drawPoint_.end_X_ - drawPoint_.start_X_)*(i - drawPoint_.start_Y_) / (drawPoint_.end_Y_ - drawPoint_.start_Y_) + drawPoint_.start_X_;

			pixels[(i * width + j) * 3 + 0] = R;
			pixels[(i * width + j) * 3 + 1] = G;
			pixels[(i * width + j) * 3 + 2] = B;
		}
	}
	
	
}
void CDrawLine::DrawLine(float* pixels, const int width, const int height, const float R, const float G, const float B)
{
	bool horizon = abs(drawPoint_.end_X_ - drawPoint_.start_X_);
	bool vertical = abs(drawPoint_.end_Y_ - drawPoint_.start_Y_);
	
	if (horizon && vertical)
		return;

	

	if (horizon)
	{
		for (int i = drawPoint_.start_X_; i < drawPoint_.end_X_; i++)
		{
			pixels[(drawPoint_.start_Y_ * width + i) * 3 + 0] = R;
			pixels[(drawPoint_.start_Y_ * width + i) * 3 + 1] = G;
			pixels[(drawPoint_.start_Y_ * width + i) * 3 + 2] = B;
		}
	}
	else if (vertical)
	{
		for (int i = drawPoint_.start_Y_; i < drawPoint_.end_Y_; i++)
		{
			pixels[(i * width + drawPoint_.start_X_) * 3 + 0] = R;
			pixels[(i * width + drawPoint_.start_X_) * 3 + 1] = G;
			pixels[(i * width + drawPoint_.start_X_) * 3 + 2] = B;
		}
	}
}

void CDrawLine::DrawDot(float* pixels, const int width, const int height, const float R, const float G, const float B)
{

}