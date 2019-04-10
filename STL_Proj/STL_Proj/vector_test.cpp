#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include "vector_test.h"
#include <iostream> //cin
#include <iterator> //istream_iterator
#include <algorithm>

using namespace std;
using namespace STL_Test;

VectorTest::VectorTest()
{}
VectorTest::~VectorTest()
{}


/*
default (1)
explicit vector (const allocator_type& alloc = allocator_type());

fill (2)
explicit vector (size_type n);
		 vector (size_type n, const value_type& val,
				 const allocator_type& alloc = allocator_type());

range (3)
template <class InputIterator>
  vector (InputIterator first, InputIterator last,
		  const allocator_type& alloc = allocator_type());

copy (4)
vector (const vector& x);
vector (const vector& x, const allocator_type& alloc);

move (5)
vector (vector&& x);
vector (vector&& x, const allocator_type& alloc);

initializer list (6)
vector (initializer_list<value_type> il,
	   const allocator_type& alloc = allocator_type());

*/
void VectorTest::MemberFunctionsTest()
{
	cout << "***************MemberFunctionsTest***************" << endl;
	vector<int> first;
	vector<int> first1(10);
	vector<int> second(4, 132);
	vector<int> third(second.begin(), second.end());
	vector<int> fourth(third);

	cout << "        size  " << "max_size      " << "capacity  " << "empty" << endl;
	cout << "first   " << first.size() << "     " << hex << first.max_size() << dec << "      " << first.capacity() << "         " << first.empty() << endl;
	cout << "second  " << second.size() << "     " << hex << second.max_size() << dec << "      " << second.capacity() << "         " << second.empty() << endl;
	cout << "third   " << third.size() << "     " << hex << third.max_size() << dec << "      " << third.capacity() << "         " << third.empty() << endl;
	cout << "fourth  " << fourth.size() << "     " << hex << fourth.max_size() << dec << "      " << fourth.capacity() << "         " << fourth.empty() << endl;

	cout << "----vector<int> first;----" << endl;
	vector<int>::iterator iter;
	cout << "	first: ";
	for (iter = first.begin(); iter != first.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	cout << "----vector<int> first1(10);----" << endl;
	cout << "	first1: ";
	for (iter = first1.begin(); iter != first1.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	cout << "----vector<int> second(4, 100);----" << endl;
	cout << "	second: ";
	for (iter = second.begin(); iter != second.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	cout << "----vector<int> third(second.begin(), second.end());----" << endl;
	cout << "	third : ";
	for (iter = third.begin(); iter != third.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	cout << "----vector<int> fourth(third);----" << endl;
	cout << "	fourth: ";
	for (iter = fourth.begin(); iter != fourth.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	cout << "----vector<int> fifth{begin(fourth), end(fourth)};----" << endl;
	vector<int> tmp{ 123, 124, 125, 126 ,127, 128};
	vector<int> fifth{begin(tmp), end(tmp)};
	//vector<int> fifth1{end(tmp), begin(tmp)};       // will cause programme aborting.
	cout << "	fifth : ";
	for (iter = fifth.begin(); iter != fifth.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	cout << "----vector<int> sixth{ make_move_iterator(begin(fifth)), make_move_iterator(end(fifth)) };----" << endl;
	vector<int> sixth{ make_move_iterator(begin(fifth)), make_move_iterator(end(fifth)) };
	cout << "	fifth: ";
	for (iter = fifth.begin(); iter != fifth.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;
	cout << "	sixth: ";
	for (iter = sixth.begin(); iter != sixth.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;
	cout << "	orignal vector: ";
	for (iter = tmp.begin(); iter != tmp.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	cout << "----vector<int> sixth1{ make_move_iterator(begin(fifth)), make_move_iterator(end(fifth)) };----" << endl;
	vector<int> sixth1(fifth.size()); //must initialize size of sixth1. and size of sixth1 must equal that of fifth.
	copy(make_move_iterator(begin(fifth)), make_move_iterator(end(fifth)), sixth1.begin());
	// bar now contains unspecified values; clear it:  --> this is offical explaination
	fifth.clear();
	cout << "	fifth: ";
	for (iter = fifth.begin(); iter != fifth.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;
	cout << "	sixth1: ";
	for (iter = sixth1.begin(); iter != sixth1.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;
	cout << "	orignal vector: ";
	for (iter = tmp.begin(); iter != tmp.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	cout << "----vector<int> seventh(arrInt, arrInt + sizeof(arrInt) / sizeof(int));----" << endl;
	int arrInt[] = { 10, 20, 30, 40, 50, 60 };
	vector<int> seventh(arrInt, arrInt + sizeof(arrInt) / sizeof(int));
	//vector<int> seventh(arrInt + sizeof(arrInt) / sizeof(int), arrInt);   // will cause programme aborting.
	cout << "	seventh: ";
	for (iter = seventh.begin(); iter != seventh.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	cout << "----vector<int> eighth(seventh.crbegin(), seventh.crend());----" << endl;
	vector<int> eighth(seventh.crbegin(), seventh.crend());
	//vector<int> eighth(seventh.crend(), seventh.crbegin());         // will cause programme aborting.
	cout << "	eighth: ";
	for (iter = eighth.begin(); iter != eighth.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	cout << "----std::vector::operator=----" << endl;
	vector<int> ninth(5, 1);
	vector<int> tenth(8, 3);
	cout << "    before 'tenth = ninth' :" << endl;
	cout << "		size  " << "max_size      " << "capacity  " << "empty" << endl;
	cout << "	ninth   " << hex << ninth.size() << dec << "     " << ninth.max_size() << "    " << ninth.capacity() << "         " << ninth.empty() << endl;
	cout << "	tenth   " << tenth.size() << "     " << tenth.max_size() << "    " << tenth.capacity() << "         " << tenth.empty() << endl;
	cout << "	ninth: ";
	for (iter = ninth.begin(); iter != ninth.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;
	cout << "	tenth: ";
	for (iter = tenth.begin(); iter != tenth.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	tenth = ninth;
	cout << "    after 'tenth = ninth' :" << endl;
	cout << "		size  " << "max_size      " << "capacity  " << "empty" << endl;
	cout << "	ninth   " << hex << ninth.size() << dec << "     " << ninth.max_size() << "    " << ninth.capacity() << "         " << ninth.empty() << endl;
	cout << "	tenth   " << tenth.size() << "     " << tenth.max_size() << "    " << tenth.capacity() << "         " << tenth.empty() << endl;
	cout << "	ninth: ";
	for (iter = ninth.begin(); iter != ninth.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;
	cout << "	tenth: ";
	for (iter = tenth.begin(); iter != tenth.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	cout << "    after 'ninth = vector<int>()' :" << endl;
	ninth = vector<int>();
	cout << "		size  " << "max_size      " << "capacity  " << "empty" << endl;
	cout << "	ninth   " << hex << ninth.size() << dec << "     " << ninth.max_size() << "    " << ninth.capacity() << "         " << ninth.empty() << endl;
	cout << "	ninth: ";
	for (iter = ninth.begin(); iter != ninth.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;
}

void VectorTest::CapacityTest()
{
	cout << "***************CapacityTest***************" << endl;

	vector<int> first;
	vector<int> second(5);

	cout << "        size  " << "    sizeof    " << "max_size      " << "capacity  " << "empty" << endl;
	cout << "first   " <<  first.size() << "	  " << sizeof(first) << "        " << hex << first.max_size() << dec << "      " << first.capacity() << "         " << first.empty() << endl;
	cout << "second  " <<  second.size() << "	  " << sizeof(second) << "        " << hex << second.max_size() << dec << "      " << second.capacity() << "         " << second.empty() << endl;
	for (auto it : second) cout << it << " ";
	cout << endl;

	cout << "----second.resize(10);----" << endl;
	second.resize(10);
	cout << "second  " << second.size() << "	  " << sizeof(second) << "        " << hex << second.max_size() << dec << "      " << second.capacity() << "        " << second.empty() << endl;
	for (auto it : second) cout << it << " ";
	cout << endl;

	cout << "----second.push_back(8);----" << endl;
	second.push_back(8);
	cout << "second  " << second.size() << "	  " << sizeof(second) << "        " << hex << second.max_size() << dec << "      " << second.capacity() << "        " << second.empty() << endl;
	for (auto it : second) cout << it << " ";
	cout << endl;

	cout << "----second.resize(15,5);----" << endl;
	second.resize(15, 5);
	cout << "second  " << second.size() << "	  " << sizeof(second) << "        " << hex << second.max_size() << dec << "      " << second.capacity() << "        " << second.empty() << endl;
	for (auto it : second) cout << it << " ";
	cout << endl;

	cout << "----second.push_back(8);----" << endl;
	second.push_back(8);
	cout << "second  " << second.size() << "	  " << sizeof(second) << "        " << hex << second.max_size() << dec << "      " << second.capacity() << "        " << second.empty() << endl;
	for (auto it : second) cout << it << " ";
	cout << endl;

	cout << "----second.resize(12,8);----" << endl;
	second.resize(12, 8);
	cout << "second  " << second.size() << "	  " << sizeof(second) << "        " << hex << second.max_size() << dec << "      " << second.capacity() << "        " << second.empty() << endl;
	for (auto it : second) cout << it << " ";
	cout << endl;


	cout << "----second.push_back(10);----" << endl;
	second.push_back(10);  
	cout << "second  " << second.size() << "	  " << sizeof(second) << "        " << hex << second.max_size() << dec << "      " << second.capacity() << "        " << second.empty() << endl;
	for (auto it : second) cout << it << " ";
	cout << endl;

	cout << "----second.pop_back();----" << endl;
	second.pop_back();
	cout << "second  " << second.size() << "	  " << sizeof(second) << "        " << hex << second.max_size() << dec << "      " << second.capacity() << "        " << second.empty() << endl;
	for (auto it : second) cout << it << " ";
	cout << endl;

	cout << "----second.reserve(88);----" << endl;
	second.reserve(88);
	cout << "second  " << second.size() << "	  " << sizeof(second) << "        " << hex << second.max_size() << dec << "      " << second.capacity() << "        " << second.empty() << endl;
	for (auto it : second) cout << it << " ";
	cout << endl;

	cout << "----second.reserve(5);----" << endl;
	second.reserve(5);
	cout << "second  " << second.size() << "	  " << sizeof(second) << "        " << hex << second.max_size() << dec << "      " << second.capacity() << "        " << second.empty() << endl;
	for (auto it : second) cout << it << " ";
	cout << endl;

	cout << "----second.shrink_to_fit();----" << endl;
	second.shrink_to_fit();
	cout << "second  " << second.size() << "	  " << sizeof(second) << "        " << hex << second.max_size() << dec << "      " << second.capacity() << "        " << second.empty() << endl;
	for (auto it : second) cout << it << " ";
	cout << endl;

}

void VectorTest::IteratorTest()
{
	cout << "***************IteratorTest***************" << endl;

	vector<int> vec{ 4, 3, 2, 1, 0 };
	for (auto it = vec.cbegin(); it != vec.cend(); it++)
		cout << *it << " ";
	cout << endl;

	cout << "----vector::erase() & vector::iterator----" << endl;
	for (auto it = vec.begin(); it != vec.end();)
	{
		if (*it == 2)
		{
			it = vec.erase(it);
			cout << "  ";
		}
		else
		{
			cout << *it++ << " ";
		}
	}
	cout << endl;

	//vector<double> data{ 10.1,10.2,10.3,10.4,10.5 };
	//cout << "Enter additional data values separated by spaces or Ctrl+Z to end:" << endl;
	//copy(istream_iterator<double>(cin), istream_iterator<double>(), back_inserter(data));
	//copy(begin(data), end(data), ostream_iterator<double>(cout, " "));
	//cout << endl;
}

void VectorTest::ModifiersTest()
{
	cout << "***************ModifiersTest***************" << endl;
	vector<int> first;
	vector<int> second;
	vector<int> third;

/*
range (1)
template <class InputIterator>
  void assign (InputIterator first, InputIterator last);

fill (2)
void assign (size_type n, const value_type& val);

initializer list (3)
void assign (initializer_list<value_type> il);
*/

	cout << "----vector::assign()----" << endl;

	first.assign(7, 99);      // 7 ints with a value of 99
	for (auto it = first.cbegin(); it != first.cend(); it++)
		cout << *it << " ";
	cout << endl;
	
	int myInt[6] = { 0, 1, 2, 3, 4, 5 };
	third.assign(myInt, myInt + sizeof(myInt) / sizeof(int));  // assigning from array.
	for (auto it = third.cbegin(); it != third.cend(); it++)
		cout << *it << " ";
	cout << endl;

	vector<int>::iterator it = third.begin() + 1;
	second.assign(it, third.end() - 1);     // the 4 central values of third
	for (auto it = second.cbegin(); it != second.cend(); it++)
		cout << *it << " ";
	cout << endl;

	cout << "----vector::erase()----" << endl;
	vector<int> vec{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	for (auto it = vec.cbegin(); it != vec.cend(); it++)
		cout << *it << " ";
	cout << endl;
	cout << "----iterator vector::erase (const_iterator first, const_iterator last);----" << endl;
	vec.erase(vec.begin() + 3, vec.end() - 3);
	for (auto it = vec.cbegin(); it != vec.cend(); it++)
		cout << *it << " ";
	cout << endl;
	cout << "    size  "  << "capacity  " << "max_size      " << "empty" << endl;
	cout << "vec " << vec.size() << "     " << vec.capacity() << "         " << hex << vec.max_size() << dec << "        " << vec.empty() << endl;

	cout << "----iterator vector::erase (const_iterator position);----" << endl;
	vec.erase(vec.begin());
	for (auto it = vec.cbegin(); it != vec.cend(); it++)
		cout << *it << " ";
	cout << endl;
	cout << "    size  " << "capacity  " << "max_size      " << "empty" << endl;
	cout << "vec " << vec.size() << "     " << vec.capacity() << "         " << hex << vec.max_size() << dec << "        " << vec.empty() << endl;

	cout << "----void vector::pop_back();----" << endl;
	vec.pop_back();
	for (auto it = vec.cbegin(); it != vec.cend(); it++)
		cout << *it << " ";
	cout << endl;
	cout << "    size  " << "capacity  " << "max_size      " << "empty" << endl;
	cout << "vec " << vec.size() << "     " << vec.capacity() << "         " << hex << vec.max_size() << dec << "        " << vec.empty() << endl;

	cout << "----void vector::shrink_to_fit();----" << endl;
	vec.shrink_to_fit();
	cout << "    size  " << "capacity  " << "max_size      " << "empty" << endl;
	cout << "vec " << vec.size() << "     " << vec.capacity() << "         " << hex << vec.max_size() << dec << "        " << vec.empty() << endl;

	cout << "----void vector::push_back();----" << endl;
	vec.push_back(99);
	for (auto it = vec.cbegin(); it != vec.cend(); it++)
		cout << *it << " ";
	cout << endl;
	cout << "    size  " << "capacity  " << "max_size      " << "empty" << endl;
	cout << "vec " << vec.size() << "     " << vec.capacity() << "         " << hex << vec.max_size() << dec << "        " << vec.empty() << endl;

	cout << "----void vector::swap (vector& x);----" << endl;
	vector<int> vec1(10, 3);
	vec.swap(vec1);
	cout << "vec : ";
	for (auto it = vec.cbegin(); it != vec.cend(); it++)
		cout << *it << " ";
	cout << endl;
	cout << "vec1: ";
	for (auto it = vec1.cbegin(); it != vec1.cend(); it++)
		cout << *it << " ";
	cout << endl;

	cout << "----void vector::push_back();----" << endl;
	vec.push_back(66);
	cout << "vec : ";
	for (auto it = vec.cbegin(); it != vec.cend(); it++)
		cout << *it << " ";
	cout << endl;
	cout << "vec1: ";
	for (auto it = vec1.cbegin(); it != vec1.cend(); it++)
		cout << *it << " ";
	cout << endl;
	cout << "    size  " << "capacity  " << "max_size      " << "empty" << endl;
	cout << "vec " << vec.size() << "     " << vec.capacity() << "         " << hex << vec.max_size() << dec << "        " << vec.empty() << endl;

	cout << "----ForwardIterator remove (ForwardIterator first, ForwardIterator last, const T& val);----" << endl;
	auto ite = remove(vec.begin(), vec.end(), 3);  //remove() just move elements to be removed backwords, they are not deleted
	cout << "vec : ";
	for (auto it = vec.cbegin(); it != vec.cend(); it++)
		cout << *it << " ";
	cout << endl;
	cout << "vec1: ";
	for (auto it = vec1.cbegin(); it != vec1.cend(); it++)
		cout << *it << " ";
	cout << endl;
	cout << "    size  " << "capacity  " << "max_size      " << "empty" << endl;
	cout << "vec " << vec.size() << "     " << vec.capacity() << "         " << hex << vec.max_size() << dec << "        " << vec.empty() << endl;
	vec.erase(ite, vec.end());
	cout << "vec : ";
	for (auto it = vec.cbegin(); it != vec.cend(); it++)
		cout << *it << " ";
	cout << endl;
	cout << "vec1: ";
	for (auto it = vec1.cbegin(); it != vec1.cend(); it++)
		cout << *it << " ";
	cout << endl;
	cout << "    size  " << "capacity  " << "max_size      " << "empty" << endl;
	cout << "vec " << vec.size() << "     " << vec.capacity() << "         " << hex << vec.max_size() << dec << "        " << vec.empty() << endl;


	cout << "----vector::clear()----" << endl;
	vec.clear();
	for (auto it = vec.cbegin(); it != vec.cend(); it++)
		cout << *it << " ";
	cout << endl;
	cout << "    size  " << "capacity  " << "max_size      " << "empty" << endl;
	cout << "vec " << vec.size() << "     " << vec.capacity() << "         " << hex << vec.max_size() << dec << "        " << vec.empty() << endl;

	/*
	template <class... Args>
	iterator emplace (const_iterator position, Args&&... args);
	*/
	cout << "----vector::emplace (const_iterator position, Args&&... args)----" << endl;
	vector<int> vecEmplace = { 1, 2, 3, 4 };
	for (auto it = vecEmplace.cbegin(); it != vecEmplace.cend(); it++)
		cout << *it << " ";
	cout << endl;
	cout << "    size  " << "capacity  " << "max_size      " << "empty" << endl;
	cout << "vec " << vecEmplace.size() << "     " << vecEmplace.capacity() << "         " << hex << vecEmplace.max_size() << dec << "        " << vecEmplace.empty() << endl;
	vecEmplace.emplace(vecEmplace.cbegin() + 1, 99);
	for (auto it = vecEmplace.cbegin(); it != vecEmplace.cend(); it++)
		cout << *it << " ";
	cout << endl;
	cout << "    size  " << "capacity  " << "max_size      " << "empty" << endl;
	cout << "vec " << vecEmplace.size() << "     " << vecEmplace.capacity() << "         " << hex << vecEmplace.max_size() << dec << "        " << vecEmplace.empty() << endl;

	/*
	template <class... Args>
		void emplace_back (Args&&... args);
	*/
	cout << "----vector::emplace_back (Args&&... args)----" << endl;
	vector<int> vecEmplaceBack = { 1, 2, 3, 4 };
	for (auto it = vecEmplaceBack.cbegin(); it != vecEmplaceBack.cend(); it++)
		cout << *it << " ";
	cout << endl;
	cout << "    size  " << "capacity  " << "max_size      " << "empty" << endl;
	cout << "vec " << vecEmplaceBack.size() << "     " << vecEmplaceBack.capacity() << "         " << hex << vecEmplaceBack.max_size() << dec << "        " << vecEmplaceBack.empty() << endl;
	vecEmplaceBack.emplace_back(99);
	for (auto it = vecEmplaceBack.cbegin(); it != vecEmplaceBack.cend(); it++)
		cout << *it << " ";
	cout << endl;
	cout << "    size  " << "capacity  " << "max_size      " << "empty" << endl;
	cout << "vec " << vecEmplaceBack.size() << "     " << vecEmplaceBack.capacity() << "         " << hex << vecEmplaceBack.max_size() << dec << "        " << vecEmplaceBack.empty() << endl;

}

void VectorTest::ElementAccessTest()
{
	cout << "***************ElementAccessTest***************" << endl;

	vector<string> vec{ "Can", "you", "do", "this", "?" };
	cout << vec.front() << " ";
	cout << vec.at(1) << " ";
	cout << vec[2] << " ";
	cout << vec[3] << " ";
	cout << vec.back() << endl;

	string *p = vec.data();
	auto it = vec.begin();
	// Program will abort. 
	//Because when it == vec.end(), 
	//it will first be added 1, 
	//then compare with vec.end()
	//while(it++ != vec.end())   
	while(it != vec.end())
	{
		cout << *p++ << "(" << *it++ << ")" << " ";
	}
	cout << endl;
}

void VectorTest::GetAllocatorTest()
{
	cout << "***************GetAllocatorTest***************" << endl;
	//allocator_type get_allocator() const noexcept;
	vector<int> vec;
	int *p;

	p = vec.get_allocator().allocate(5);
	for (int i = 0; i < 5; i++)
		vec.get_allocator().construct(&p[i], i * 2);

	for (int i = 0; i < 5; i++)
		cout << "p[" << i << "] = " << p[i] << ", ";
	cout << endl;

	for (int i = 0; i < 5; i++)
		vec.get_allocator().destroy(&p[i]);
	vec.get_allocator().deallocate(p, 5);
}