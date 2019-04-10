#undef _VECTOR_TEST_H_
#ifndef _VECTOR_TEST_H_
#define _VECTOR_TEST_H_

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
	};
}

#endif