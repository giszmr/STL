#ifndef _SET_TEST_H_
#define _SET_TEST_H_


#include <set>
#include <string>
#include <iostream>


#pragma once

namespace STL_Test
{
	class SetTest
	{
	public:
		SetTest() {};
		~SetTest() {};
		void ConstructorTest();
		void ModifiersTest();
		void SetUnionTest();
		void SetIntersectionTest();
	private:
		void Output(std::set<int> mySet, std::string name);
		void Output(std::set<int, std::greater<int>> mySet, std::string name);
		void Output(std::set<double> mySet, std::string name);
		void Output(std::set<double, std::greater<double>> mySet, std::string name);

	};
}





#endif