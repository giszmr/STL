#undef _EMPLACE_INSERT_TEST_H_
#ifndef _EMPLACE_INSERT_TEST_H_
#define _EMPLACE_INSERT_TEST_H_

#include <map>
#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <functional>

#pragma once

namespace STL_Test
{
	class MyBook
	{
	public:
		MyBook();
		MyBook(std::string name, double price);
		~MyBook();
		MyBook(const MyBook& rhs);
		std::string GetName() { return m_name; }
		double GetPrice() { return m_price; }
	private:
		std::string m_name;
		double m_price;
	};


	class EmaplaceInsertTest
	{
	public:
		EmaplaceInsertTest();
		~EmaplaceInsertTest();
		void Test();
	private:
		void OutputIter(std::vector<MyBook>& myVector);
		void OutputIndex(std::vector<MyBook>& myVector);
	};

}


#endif