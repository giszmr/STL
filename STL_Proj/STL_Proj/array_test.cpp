#include "pch.h"
#include <iostream>
#include <array>
#include "array_test.h"

using namespace std;
using namespace STL_Test;


ArrayTest::ArrayTest()
{}
ArrayTest::~ArrayTest()
{}


void ArrayTest::CapacityTest()
{
	cout << "------------array::size/max_size/empty--------------------" << endl;

	array<int, 5> arr1;
	cout << "arr1 size:     " << arr1.size() << endl;
	cout << "arr1 max_size: " << arr1.max_size() << endl;
	cout << "arr1 empty:    " << arr1.empty() << endl;


	array<int, 0> arr2;
	cout << "arr2 size:     " << arr2.size() << endl;
	cout << "arr2 max_size: " << arr2.max_size() << endl;
	cout << "arr2 empty:    " << arr2.empty() << endl;
}


void ArrayTest::ModifiersTest()
{
	cout << "-------------array::fill-------------------" << endl;

	array<int, 6> arr;

/*void fill(const value_type& val);
	Fill array with value
		Sets val as the value for all the elements in the array object.
*/
	arr.fill(0xFFFFFFFF);

	for (int &i : arr)
	{
		cout << i << " ";
	}
	cout << endl;

	cout << "-------------array::swap-------------------" << endl;

/*
void swap (array& x) noexcept(noexcept(swap(declval<value_type&>(),declval<value_type&>())));
	Swap content
	Exchanges the content of the array by the content of x, which is another array object of the same type (including the same size).
*/
	array<int, 6> arr1 = { 0, 1, 2, 3, 4, 5 };
	array<int, 7> arr2 = { 0 };
	array<string, 6> arr3 = { "" };

	cout << "before swap:" << endl;
	cout << "arr:  ";
	for (int &i : arr)
		cout << i << " ";
	cout << endl;

	cout << "arr1: ";
	for (int &i : arr1)
		cout << " " << i << " ";
	cout << endl;
	///////////////////////////////////////
	arr.swap(arr1);
	// error C2664: 'void std::array<int,6>::swap(std::array<int,6> &) noexcept': cannot convert argument 1 from 'std::array<int,7>' to 'std::array<int,6> &
	//arr.swap(arr2);
	// error C2664: 'void std::array<int,6>::swap(std::array<int,6> &) noexcept': cannot convert argument 1 from 'std::array<std::string,6>' to 'std::array<int,6> &'
	//arr.swap(arr3);

	cout << "after swap:" << endl;
	cout << "arr:  ";
	for (int &i : arr)
		cout << " " << i << " ";
	cout << endl;

	cout << "arr1: ";
	for (int &i : arr1)
		cout << i << " ";
	cout << endl;
	//////////////////////////////////////
	arr = arr1;

	cout << "after =:" << endl;
	cout << "arr:  ";
	for (int &i : arr)
		cout << i << " ";
	cout << endl;

	cout << "arr1: ";
	for (int &i : arr1)
		cout << i << " ";
	cout << endl;
}

void ArrayTest::IteratorTest()
{
	cout << "-------------array::iterator-------------------" << endl;
	array<int, 10> arr = { 0 };
	int cnt = 0;	

	cout << "before     after" << endl;
	for (auto it = arr.begin(); it != arr.end(); it++)
	{
		cout << *it;
		*it = cnt++;
		cout << "           " << *it << endl;
	}

	cout << "-------------" << endl;
	for (auto it = arr.rbegin(); it != arr.rend(); it++)
	{
		cout << *it << endl;
	}
}


void ArrayTest::ElementAccessTest()
{
	cout << "-------------Array Element Access-------------------" << endl;

	array<int, 9> arr;
	
	for (auto it = arr.begin(); it != arr.end(); it++)
		cout << *it << " ";
	cout << endl;

	arr.fill(0xFFFFFFFF);
	for (auto it = arr.begin(); it != arr.end(); it++)
		cout << *it << " ";
	cout << endl;
	
	int cnt = 0;
	for (auto it = arr.begin(); it != arr.end(); it++)
	{
		*it = cnt++;
		cout << " " << *it << " ";
	}
	cout << endl;

	cout << "-------------Array::operator[]-------------------" << endl;
	cout << "arr[5]      = " << arr[5] << endl;
	cout << "-------------Array::at-------------------" << endl;
	cout << "arr.at(6)   = " << arr.at(6) << endl;
	cout << "std::get<7>arr = " << get<7>(arr) << endl;
	cout << "-------------Array::front-------------------" << endl;
	cout << "arr.front() = " << arr.front() << endl;
	cout << "-------------Array::back-------------------" << endl;
	cout << "arr.back()  = " << arr.back() << endl;
	cout << "-------------Array::data-------------------" << endl;
/*
	  value_type* data() noexcept;
const value_type* data() const noexcept;

Get pointer to data
Returns a pointer to the first element in the array object.*/
	cout << "arr.data()  = " << arr.data() << endl;
	cout << "&arr[0]     = " << &arr[0] << endl;


}

