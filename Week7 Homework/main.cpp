#include <iostream>
#include <GLFW\glfw3.h>
#include "GLFW Setting.h"
#include "DrawLine.h"
#include "Box.h"
#include "Circle.h"
#include <list>

class GeometricObject
{
public:

	void(GeometricObject::*callBack_)(float *pixels, const int window_width, const int window_height) = nullptr;

	void drawObject(float *pixels, const int window_width, const int window_height)
	{
		(this->*callBack_)(pixels, window_width, window_height);
	}


	static GeometricObject* getPointer(const std::string type_name)
	{
		auto new_ob = new GeometricObject;

		if (type_name == "Box")
		{
			new_ob->callBack_ = &GeometricObject::drawBox;
		}
		else if (type_name == "Circle")
		{
			new_ob->callBack_ = &GeometricObject::drawCircle;
		}
		return new_ob;
	}


	void drawBox(float *pixels, const int window_width, const int window_height)
	{
		std::cout << "draw Box" << std::endl;
		
		CBox myBox;
		myBox.Initialize(285, 310, 70, 70, 0.6f, 0.5f, 0.8f);
		myBox.draw(pixels, window_width, window_height);

		CBox mySurroundingBox;
		mySurroundingBox.Initialize(265, 290, 110, 110, 0.f, 0.f, 0.8f);
		mySurroundingBox.draw(pixels, window_width, window_height);
	}

	void drawCircle(float *pixels, const int window_width, const int window_height)
	{
		std::cout << "draw Circle" << std::endl;

		CBox myBox;
		myBox.Initialize(285, 60, 70, 70, 0.75f, 0.3f, 0.3f);
		myBox.draw(pixels, window_width, window_height);

		CCircle mySurroundingCircle;
		mySurroundingCircle.Initialize(320, 95, 65, 1.0f, 0.3f, 0.3f);
		mySurroundingCircle.draw(pixels, window_width, window_height);
	}
};



int main()
{
	int window_width = 600;
	int window_height = 480;
	
	GLFW_setting glfw_setting(window_width, window_height);
	glfw_setting.GLFW_initialize();

	std::list <GeometricObject*> myGo_list;

	myGo_list.push_back(GeometricObject::getPointer("Box"));
	myGo_list.push_back(GeometricObject::getPointer("Circle"));

	for (auto itr : myGo_list)
		itr->drawObject(glfw_setting.pixels_, window_width, window_height);


	while (!glfwWindowShouldClose(glfw_setting.window_))
	{
	
		/* To do */
		
		glfw_setting.GLFW_postProcess();
		
	}

	for (auto itr : myGo_list)
		delete itr;

	return 0;
}