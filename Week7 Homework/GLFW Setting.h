#pragma once
#include <GLFW\glfw3.h>


class GLFW_setting 
{
public:
	
	int window_width_, window_height_;
	GLFWwindow* window_;
	float *pixels_;

	GLFW_setting(const int window_width, const int window_height) : window_(nullptr), window_width_(window_width), window_height_(window_height)
	{
		//window_width_ = window_width;
		//window_height_ = window_height;

		pixels_ = new float[window_width_ * window_height_ * 3];
	}

	~GLFW_setting()
	{
		delete[] pixels_;
		glfwTerminate();
	}
	
	void initializeWindow(const int window_width, const int window_height, float *pixels)
	{
		for (int i = 0; i < window_height; i++)
		{
			int column = i * window_width;

			for (int j = 0; j < window_width; j++)
			{
				pixels[(column + j) * 3 + 0] = 1.0f;
				pixels[(column + j) * 3 + 1] = 1.0f;
				pixels[(column + j) * 3 + 2] = 1.0f;
			}
		}
	}

	void GLFW_initialize()
	{
		
		if (!glfwInit())
			exit(1);

		window_ = glfwCreateWindow(window_width_, window_height_, "Week7 Homework", NULL, NULL);

		if (!window_)
		{
			glfwTerminate();
			exit(1);
		}

		glfwMakeContextCurrent(window_);

		glClear(GL_COLOR_BUFFER_BIT);
		
		initializeWindow(window_width_, window_height_, pixels_);
	}

	void GLFW_postProcess()
	{
		glDrawPixels(window_width_, window_height_, GL_RGB, GL_FLOAT, pixels_);
		glfwSwapBuffers(window_);
		glfwPollEvents();
	}
};