#undef _VECTOR_TEST_H_
#ifndef _VECTOR_TEST_H_
#define _VECTOR_TEST_H_

#include <vector>
#include <string>

#pragma once


namespace STL_Test
{
	class VectorTest
	{
	public:
		VectorTest();
		~VectorTest();
		void MemberFunctionsTest();
		void CapacityTest();
		void IteratorTest();
		void ModifiersTest();
		void ElementAccessTest();
		void GetAllocatorTest();
	private:
		void Output(std::vector<int>& myVector, std::string name);
		void Output(std::vector<double>& myVector, std::string name);
		void Output(std::vector<std::string>& myVector, std::string name);
	};
}

#endif