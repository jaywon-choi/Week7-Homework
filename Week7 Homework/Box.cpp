#include "Box.h"
#include "DrawLine.h"
#include <vector>
/*
CBox::CBox(const int start_X, const int start_Y, const int width, const int height, const float R, const float G, const float B)
{
	Initialize(start_X, start_Y, width, height, R, G, B);
}
*/
void CBox::Initialize(const int start_X, const int start_Y, const int width, const int height, const float R, const float G, const float B)
{
	myBox_.start_X_ = start_X;
	myBox_.start_Y_ = start_Y;
	myBox_.BoxWidth_ = width;
	myBox_.BoxHeight_ = height;

	myColor_.R_ = R;
	myColor_.G_ = G;
	myColor_.B_ = B;
}

void CBox::draw(float *pixels, const int window_width, const int window_height)
{
	std::vector<CDrawLine*> drawBox;

	drawBox.push_back(new CDrawLine(myBox_.start_X_, myBox_.start_Y_, myBox_.start_X_ + myBox_.BoxWidth_, myBox_.start_Y_));
	drawBox.push_back(new CDrawLine(myBox_.start_X_, myBox_.start_Y_, myBox_.start_X_, myBox_.start_Y_ + myBox_.BoxHeight_));
	drawBox.push_back(new CDrawLine(myBox_.start_X_, myBox_.start_Y_ + myBox_.BoxHeight_, myBox_.start_X_ + myBox_.BoxWidth_, myBox_.start_Y_ + myBox_.BoxHeight_));
	drawBox.push_back(new CDrawLine(myBox_.start_X_ + myBox_.BoxWidth_, myBox_.start_Y_, myBox_.start_X_ + myBox_.BoxWidth_, myBox_.start_Y_ + myBox_.BoxHeight_));

	for (auto itr : drawBox)
		(itr)->DrawLine(pixels, window_width, window_height, myColor_.R_, myColor_.G_, myColor_.B_);


	for (auto itr : drawBox)
		delete (itr);

	//drawRedCircle(pixels, window_width, window_width, myBox_.start_X_ + myBox_.BoxHeight_ / 2, myBox_.start_Y_ + myBox_.BoxHeight_ / 2, myBox_.BoxWidth_ / 2 + 20);
}