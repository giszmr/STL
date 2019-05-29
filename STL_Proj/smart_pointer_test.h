#ifndef _SMART_POINTER_TEST_H_
#define _SMART_POINTER_TEST_H_


#include <string>
#include <iostream>
#include <memory>


#pragma once

namespace STL_Test
{
	class SmartPointerTest
	{
	public:
		SmartPointerTest() {};
		~SmartPointerTest() {};
		void AutoPointerTest();
		void SharedPointerTest();
		void WeakPointerTest();
		void UniquePointerTest();
		void NULL_nullptr_Test();
	private:
		void func(int a);
		void func(int* a);


	};
}





#endif