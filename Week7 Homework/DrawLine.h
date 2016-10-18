#pragma once

class CDrawLine
{
public:

	struct DrawPoint
	{
		int start_X_, start_Y_;
		int end_X_, end_Y_;
	}drawPoint_;
	
	CDrawLine(const int start_X, const int start_Y, const int end_X, const int end_Y);

	void Initialize(const int start_X, const int start_Y, const int end_X, const int end_Y);

	void DrawDiagonal(float* pixels, const int width, const int height, const float R, const float G, const float B);
	void DrawLine(float* pixels, const int width, const int height, const float R, const float G, const float B);
	void DrawDot(float* pixels, const int width, const int height, const float R, const float G, const float B);
};