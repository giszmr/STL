#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include "vector_test.h"
#include <iostream> //cin
#include <iterator> //istream_iterator
#include <algorithm>
#include <iomanip>

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
	Output(first, "first ");
	Output(first1, "first1");
	Output(second, "second");
	Output(third, "third ");
	Output(fourth, "fourth");


	cout << "fifth{begin(fourth), end(fourth)}:" << endl;
	vector<int> tmp{ 123, 124, 125, 126 ,127, 128};
	vector<int> fifth{begin(tmp), end(tmp)};
	//vector<int> fifth1{end(tmp), begin(tmp)};       // will cause programme aborting.
	Output(fifth, "fifth ");


	cout << "sixth{ make_move_iterator(begin(fifth)), make_move_iterator(end(fifth)) }:" << endl;
	vector<int> sixth{ make_move_iterator(begin(fifth)), make_move_iterator(end(fifth)) };
	Output(tmp, "tmp   ");
	Output(fifth, "fifth ");
	Output(sixth, "sixth ");


	cout << "copy(make_move_iterator(begin(fifth)), make_move_iterator(end(fifth)), sixth1.begin()):" << endl;
	vector<int> sixth1(fifth.size()); //must initialize size of sixth1. and size of sixth1 must equal that of fifth.
	copy(make_move_iterator(begin(fifth)), make_move_iterator(end(fifth)), sixth1.begin());
	// fifth now contains unspecified values; clear it:  --> this is offical explaination
	fifth.clear();
	Output(tmp, "tmp   ");
	Output(fifth, "fifth ");
	Output(sixth1, "sixth1");

	cout << "seventh(arrInt, arrInt + sizeof(arrInt) / sizeof(int)):" << endl;
	int arrInt[] = { 10, 20, 30, 40, 50, 60 };
	vector<int> seventh(arrInt, arrInt + sizeof(arrInt) / sizeof(int));
	//vector<int> seventh(arrInt + sizeof(arrInt) / sizeof(int), arrInt);   // will cause programme aborting.
	Output(seventh, "seventh");

	cout << "eighth(seventh.crbegin(), seventh.crend()):" << endl;
	vector<int> eighth(seventh.crbegin(), seventh.crend());
	//vector<int> eighth(seventh.crend(), seventh.crbegin());         // will cause programme aborting.
	Output(eighth, "eighth");

	cout << "operator=:" << endl;
	vector<int> ninth(5, 1);
	vector<int> tenth(8, 3);
	Output(ninth, "ninth");
	Output(tenth, "tenth");
	tenth = ninth;
	cout << "after 'tenth = ninth' :" << endl;
	Output(ninth, "ninth");
	Output(tenth, "tenth");

	cout << "ninth = vector<int>():" << endl;
	ninth = vector<int>();
	Output(ninth, "ninth");

}

void VectorTest::CapacityTest()
{
	cout << "***************CapacityTest***************" << endl;

	vector<int> first;
	vector<int> second(5);

	Output(first, "first ");
	Output(second, "second");

	cout << "push_back(8):" << endl;
	second.push_back(8);
	Output(second, "second");


	cout << "resize(10):" << endl;
	second.resize(10);
	Output(second, "second");


	cout << "push_back(8):" << endl;
	second.push_back(8);
	Output(second, "second");


	cout << "resize(15,5):" << endl;
	second.resize(15, 5);
	Output(second, "second");


	cout << "push_back(8):" << endl;
	second.push_back(8);
	Output(second, "second");



	cout << "resize(12,8):" << endl;
	second.resize(12, 8);
	Output(second, "second");



	cout << "push_back(10):" << endl;
	second.push_back(10);  
	Output(second, "second");


	cout << "pop_back():" << endl;
	second.pop_back();
	Output(second, "second");


	cout << "reserve(88):" << endl;
	second.reserve(88);
	Output(second, "second");


	cout << "reserve(5):" << endl;
	second.reserve(5);
	Output(second, "second");


	cout << "shrink_to_fit():" << endl;
	second.shrink_to_fit();
	Output(second, "second");


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

	cout << "assign():" << endl;

	first.assign(7, 99);      // 7 ints with a value of 99
	Output(first, "first ");

	
	int myInt[6] = { 0, 1, 2, 3, 4, 5 };
	third.assign(myInt, myInt + sizeof(myInt) / sizeof(int));  // assigning from array.
	Output(third, "third ");


	vector<int>::iterator it = third.begin() + 1;
	second.assign(it, third.end() - 1);     // the 4 central values of third
	Output(second, "second");


	cout << "erase (first, last):" << endl;
	vector<int> vec{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	Output(vec, "vec");
	vec.erase(vec.begin() + 3, vec.end() - 3);
	Output(vec, "vec");



	cout << "erase(position):" << endl;
	vec.erase(vec.begin());
	Output(vec, "vec");



	cout << "pop_back():" << endl;
	vec.pop_back();
	Output(vec, "vec");



	cout << "shrink_to_fit():" << endl;
	vec.shrink_to_fit();
	Output(vec, "vec");



	cout << "push_back():" << endl;
	vec.push_back(99);
	Output(vec, "vec");
	


	cout << "swap():" << endl;
	vector<int> vec1(10, 3);
	Output(vec, "vec ");
	Output(vec1, "vec1");
	vec.swap(vec1);
	Output(vec, "vec ");
	Output(vec1, "vec1");



	cout << "push_back():" << endl;
	vec.push_back(66);
	Output(vec, "vec ");
	Output(vec1, "vec1");



	cout << "remove(first, last, val):" << endl;
	auto ite = remove(vec.begin(), vec.end(), 3);  //remove() just move elements to be removed backwords, they are not deleted
	Output(vec, "vec ");

	
	cout << "erase(first, last):" << endl;
	vec.erase(ite, vec.end());
	Output(vec, "vec ");



	cout << "clear():" << endl;
	vec.clear();
	Output(vec, "vec ");

	/*
	template <class... Args>
	iterator emplace (const_iterator position, Args&&... args);
	*/
	cout << "emplace (position, Args&&... args):" << endl;
	vector<int> vecEmplace = { 1, 2, 3, 4 };
	Output(vecEmplace, "vecEmplace");
	vecEmplace.emplace(vecEmplace.cbegin() + 1, 99);
	Output(vecEmplace, "vecEmplace");

	/*
	template <class... Args>
		void emplace_back (Args&&... args);
	*/
	cout << "emplace_back (Args&&... args):" << endl;
	vector<int> vecEmplaceBack = { 1, 2, 3, 4 };
	Output(vecEmplaceBack, "vecEmplaceBack");
	vecEmplaceBack.emplace_back(99);
	Output(vecEmplaceBack, "vecEmplaceBack");

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


void VectorTest::Output(std::vector<int>& myVector, std::string name)
{
	cout << name << ": ";
	if (!myVector.empty())
	{
		cout << "(" << std::setw(3) << myVector.size() << "," << std::setw(3) << myVector.capacity() << "," << std::setw(3) << hex << myVector.max_size() << dec << ") ";
		for (auto it : myVector) cout << it << " ";
		cout << endl;
	}
	else
	{
		cout << name << " is empty." << endl;
	}
}



void VectorTest::Output(std::vector<double>& myVector, std::string name)
{

}

void VectorTest::Output(std::vector<std::string>& myVector, std::string name)
{

}


