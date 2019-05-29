#undef _LIST_TEST_H_
#ifndef _LIST_TEST_H_
#define _LIST_TEST_H_

#include <list>
#include <string>

#pragma once

namespace STL_Test
{
	class ListTest
	{
	public:
		ListTest();
		~ListTest();
		void MemberFunctionsTest();
		void CapacityTest();
		void ElementAccessTest();
		void ModifiersTest();
		void OperationsTest();
		void MergeTest();
	private:
		void OutputList(std::list<int> myList, std::string name);
		void OutputList(std::list<double> myList, std::string name);
		void OutputList(std::list<std::string> myList, std::string name);
	};
}

#endif