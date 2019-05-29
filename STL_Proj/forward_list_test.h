#undef _FORWARD_LIST_TEST_H_
#ifndef _FORWARD_LIST_TEST_H_
#define _FORWARD_LIST_TEST_H_

#include <forward_list>
#include <string>

#pragma once

namespace STL_Test
{
	class ForwardListTest
	{
	public:
		ForwardListTest();
		~ForwardListTest();
		void ModifiersTest();
		void OperationsTest();
	private:
		void OutputList(std::forward_list<int>& myForwardList, std::string name);
	};
}

#endif
