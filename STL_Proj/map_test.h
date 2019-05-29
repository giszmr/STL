#undef _MAP_TEST_H_
#ifndef _MAP_TEST_H_
#define _MAP_TEST_H_

#include <map>
#include <vector>
#include <deque>
#include <string>

#pragma once

namespace STL_Test
{
	class MapTest
	{
	public:
		MapTest();
		~MapTest();
		void ConstructorTest();
		void ModifiersTest();
		void ObserversTest();
		void OperationsTest();
	private:
		void Output(std::map<char, int>& mymap, std::string name);
		void OutputR(std::map<char, int>& mymap, std::string name);
		void Output(std::map<std::string, double>& mymap, std::string name);
		void Output(std::map<std::string, double, std::greater<std::string>>& mymap, std::string name);
	};
}

#endif
