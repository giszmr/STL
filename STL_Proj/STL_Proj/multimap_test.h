#undef _MULTIMAP_TEST_H_
#ifndef _MULTIMAP_TEST_H_
#define _MULTIMAP_TEST_H_

#include <map>
#include <vector>
#include <deque>
#include <string>

#pragma once

namespace STL_Test
{
	class MultimapTest
	{
	public:
		MultimapTest();
		~MultimapTest();
		void ConstructorTest();
		void ModifiersTest();
		void ObserversTest();
		void OperationsTest();
	private:
		void Output(std::multimap<int, std::string> myMultimap, std::string name);
		void OutputR(std::multimap<int, std::string> myMultimap, std::string name);
		void Output(std::multimap<int, double> myMultimap, std::string name);
	};
}

#endif