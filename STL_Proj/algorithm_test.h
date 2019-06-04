#ifndef _ALGORITHM_TEST_H_
#define _ALGORITHM_TEST_H_


#include <string>
#include <iostream>
#include <vector>


#pragma once

namespace STL_Test
{
	class Price
	{
	public:
		Price() 
		{ 
			std::cout << "Default Constructor" << std::endl; 
		}
		Price(int value, int additionalValue) :m_value(value), m_additionalValue(additionalValue)
		{ 
			std::cout << "Constructor" << std::endl; 
		}
		Price(const Price& price) 
		{
			std::cout << "Copy Constructor" << std::endl;
			m_value = price.m_value;
			m_additionalValue = price.m_additionalValue;
		}
		Price& operator=(const Price& price)
		{
			std::cout << "Assign Constructor" << std::endl;
			m_value = price.m_value;
			return *this;
		}
		bool operator<(const Price& price) const
		{
			std::cout << "overload operator <" << std::endl;
			return m_value < price.m_value;
		}
		~Price() 
		{ 
			std::cout << "~Deconstructor" << std::endl; 
		}
		int GetValue() { return m_value; }
		int GetAdditionalValue() { return m_additionalValue; }


	private:
		int m_value;
		int m_additionalValue;
	};




	class AlgorithmTest
	{
	public:
		AlgorithmTest() {};
		~AlgorithmTest() {};
		void DefaultSortTest();
		void StableSortTest();
		void PartialSortTest();
		void ParticalSortCopyTest();
		void NthElementTest();
		void PartitionTest();
		void PartitionCopyTest();
		void IsSortedUntilTest();
		void FindIfTest();
		void AdjacentFindTest();
		void EqualTest();
		void SetUnionTest(); //std::set_union. Other algorithms: std::set_diffenence; std::set_intersection.
		void HeapTest();

	private:
		void Output(std::vector<int>& myVector, std::string name);
		void Output(std::vector<Price>& myVector, std::string name);
		void Output(std::vector<double>& myVector, std::string name);
		void Output(std::vector<std::string>& myVector, std::string name);


	};
}





#endif