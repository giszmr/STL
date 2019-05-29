#undef _STRING_TEST_H_
#ifndef _STRING_TEST_H_
#define _STRING_TEST_H_

#pragma once

namespace STL_Test
{

	class StringTest
	{
	public:
		StringTest();
		~StringTest();
		void ConsructorTest();
		void CapacityTest();
		void ElementAccessTest();
		void StringOperations();
		void StringModifier();
		void StringIterator();
	private:
		void StringCompare();
		void StringFind();

	};

}
#endif