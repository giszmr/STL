#ifndef _MISCELLANEOUS_TEST_H_
#define _MISCELLANEOUS_TEST_H_

#include <vector>
#include <numeric>
#include <string>
#include <iomanip>
#include <iostream>

#pragma once


namespace STL_Test
{
	class MiscellaneousTest
	{
	public:
		MiscellaneousTest() {};
		~MiscellaneousTest() {};
		void IotaTest();
		void AccumulateTest();

	private:
		void Output(std::vector<int>& myVector, std::string name);
		void Output(std::vector<double>& myVector, std::string name);
		void Output(std::vector<char>& myVector, std::string name);
		void Output(std::vector<std::string>& myVector, std::string name);

	};

}



#endif