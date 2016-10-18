#include <iostream>
#include <GLFW/glfw3.h>

/*
int main()
{
	std::cout << "Hello world" << std::endl;

	int a; // <- garbage value
	a = 123;
	std::cout << a << std::endl;

	int *ptr_a = nullptr;
	// in old style , ptr_a = 0 or ptr_a = NULL;
	
	

	//const int num_int = 1000;
	int num_int = 1000;
	
	ptr_a = new int[num_int]; //dynamic allocation
	
	//int a_arr[num_int];

	
	
	delete[] ptr_a;

	*/











	/*
	std::cout << ptr_a << std::endl;
	
	ptr_a = &a; // & a is the starting address of the a  

	if(ptr_a != nullptr)
	//if(!ptr_a) // do not recommend this style 
		std::cout << *ptr_a << std::endl;
	else
	{
		//do something
		std::cout << "ptr_a was not initialized" << std::endl;
	}


	//pointer basic c
	//function pointer and polymorphism

	}*/


class GeometricObject
{
public:
	
	int a_;
	
	void(GeometricObject::*callBack_)(void) = nullptr;

	//virtual void draw(void) = 0;
	
	static void exe()
	{
		//(this->*callBack_)();
		//Do something 
	}

	void drawCircle()
	{
		std::cout << "draw circle  "<< a_ << std::endl;
	}
	void drawBox()
	{
		std::cout << "draw box  "<< a_ << std::endl;
	}
};



int main()
{
	//drawCircle();
	//drawBox();

	//int *ptr_a = nullptr;

	//void(*func_ptr/*this is a variable*/)(void) = nullptr;

	//func_ptr = &drawCircle;

	//std::cout << func_ptr /*address of function*/ << std::endl;

	//func_ptr();
	//(*func_ptr)();

	//func_ptr = &drawBox;
	//std::cout << func_ptr /*address of function*/ << std::endl;
	//func_ptr();
	//(*func_ptr)();



	//2th class test
	GeometricObject my_box, my_circle;

	my_box.callBack_ = &GeometricObject::drawBox;
	my_circle.callBack_ = &GeometricObject::drawCircle;

	my_box.a_ = 123;
	my_circle.a_ = 456;

	//(my_box.*my_box.callBack_)();
	//(my_circle.*my_circle.callBack_)();
	//my_circle.callBack_();

	GeometricObject::exe();
	GeometricObject::exe();

	return 0;

	/*

	첫번째
	geometric go;
	go.getpointer(...);

	두번째
	이때는 함수앞에 static 이 있어야함

	geometric::member_function(...) ;
	*/
}
