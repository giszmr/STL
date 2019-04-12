#include "pch.h"
#include "list_test.h"
#include <list>
#include <iostream>
#include <string>
#include <iterator>

using namespace STL_Test;

ListTest::ListTest()
{}

ListTest::~ListTest()
{}

void ListTest::MemberFunctionsTest()
{
	std::cout << "---std::list<int> first;---" << std::endl;
	std::list<int> first;
	for (auto it = first.cbegin(); it != first.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "       empty  " << "size  " << "max_size" << std::endl;
	std::cout << "first  " << first.empty() << "      " << first.size() << "     " << std::hex << first.max_size() << std::dec << std::endl;


	std::cout << "---std::list<int> second(5);---" << std::endl;
	std::list<int> second(7);
	for (auto it = second.cbegin(); it != second.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "        empty  " << "size  " << "max_size" << std::endl;
	std::cout << "second  " << second.empty() << "      " << second.size() << "     " << std::hex << second.max_size() << std::dec << std::endl;


	std::cout << "---std::list<int> third(5, 3);---" << std::endl;
	std::list<int> third(5, 3);
	for (auto it = third.cbegin(); it != third.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "       empty  " << "size  " << "max_size" << std::endl;
	std::cout << "third  " << third.empty() << "      " << third.size() << "     " << std::hex << third.max_size() << std::dec << std::endl;


	std::cout << "---std::list<int> fourth(third.cbegin(), third.cend());---" << std::endl;
	std::list<int> fourth(third.cbegin(), third.cend());
	for (auto it = fourth.cbegin(); it != fourth.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "        empty  " << "size  " << "max_size" << std::endl;
	std::cout << "fourth  " << fourth.empty() << "      " << fourth.size() << "     " << std::hex << fourth.max_size() << std::dec << std::endl;


	std::cout << "---std::list<int> fifth(second);---" << std::endl;
	std::list<int> fifth(second);
	for (auto it = fifth.cbegin(); it != fifth.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "       empty  " << "size  " << "max_size" << std::endl;
	std::cout << "fifth  " << fifth.empty() << "      " << fifth.size() << "     " << std::hex << fifth.max_size() << std::dec << std::endl;


	std::cout << "---std::list<int> sixth = fifth;---" << std::endl;
	std::list<int> sixth = fifth;
	for (auto it = sixth.cbegin(); it != sixth.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "       empty  " << "size  " << "max_size" << std::endl;
	std::cout << "sixth  " << sixth.empty() << "      " << sixth.size() << "     " << std::hex << sixth.max_size() << std::dec << std::endl;

}

void ListTest::CapacityTest()
{
	//empty();size();max_size();
}

void ListTest::ElementAccessTest()
{
	std::cout << "**********ElementAccessTest***********" << std::endl;


	std::list<std::string> myList = { "first", "second", "third", "fourth", "fifth" };
	for (auto it = myList.cbegin(); it != myList.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "        empty  " << "size  " << "max_size" << std::endl;
	std::cout << "myList  " << myList.empty() << "      " << myList.size() << "     " << std::hex << myList.max_size() << std::dec << std::endl;


	std::cout << "---myList.front()---" << std::endl;
	std::cout << myList.front() << std::endl;


	std::cout << "---myList.back()---" << std::endl;
	std::cout << myList.back() << std::endl;
}

void ListTest::ModifiersTest()
{
	std::cout << "**********ModifiersTest***********" << std::endl;


	std::list<int> first = { 1, 2, 3, 4, 5, 6, 7, 8 };
	for (auto it = first.cbegin(); it != first.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "       empty  " << "size  " << "max_size" << std::endl;
	std::cout << "first  " << first.empty() << "      " << first.size() << "     " << std::hex << first.max_size() << std::dec << std::endl;


	std::cout << "---first.resize(10);---" << std::endl;
	first.resize(10);
	for (auto it = first.cbegin(); it != first.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "       empty  " << "size  " << "max_size" << std::endl;
	std::cout << "first  " << first.empty() << "      " << first.size() << "     " << std::hex << first.max_size() << std::dec << std::endl;


	std::cout << "---first.resize(13, 9);---" << std::endl;
	first.resize(13, 9);
	for (auto it = first.cbegin(); it != first.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "       empty  " << "size  " << "max_size" << std::endl;
	std::cout << "first  " << first.empty() << "      " << first.size() << "     " << std::hex << first.max_size() << std::dec << std::endl;


	std::cout << "---first.resize(5);---" << std::endl;
	first.resize(5);
	for (auto it = first.cbegin(); it != first.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "       empty  " << "size  " << "max_size" << std::endl;
	std::cout << "first  " << first.empty() << "      " << first.size() << "     " << std::hex << first.max_size() << std::dec << std::endl;


	std::cout << "---first.push_back(6);---" << std::endl;
	first.push_back(6);
	for (auto it = first.cbegin(); it != first.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "       empty  " << "size  " << "max_size" << std::endl;
	std::cout << "first  " << first.empty() << "      " << first.size() << "     " << std::hex << first.max_size() << std::dec << std::endl;


	std::cout << "---first.push_front(0);---" << std::endl;
	first.push_front(0);
	for (auto it = first.cbegin(); it != first.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "       empty  " << "size  " << "max_size" << std::endl;
	std::cout << "first  " << first.empty() << "      " << first.size() << "     " << std::hex << first.max_size() << std::dec << std::endl;


	std::cout << "---first.emplace_back(7);---" << std::endl;
	first.emplace_back(7);
	for (auto it = first.cbegin(); it != first.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "       empty  " << "size  " << "max_size" << std::endl;
	std::cout << "first  " << first.empty() << "      " << first.size() << "     " << std::hex << first.max_size() << std::dec << std::endl;


	std::cout << "---first.emplace_front(-1);---" << std::endl;
	first.emplace_front(-1);
	for (auto it = first.cbegin(); it != first.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "       empty  " << "size  " << "max_size" << std::endl;
	std::cout << "first  " << first.empty() << "      " << first.size() << "     " << std::hex << first.max_size() << std::dec << std::endl;


	std::cout << "---first.pop_back();---" << std::endl;
	first.pop_back();
	for (auto it = first.cbegin(); it != first.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "       empty  " << "size  " << "max_size" << std::endl;
	std::cout << "first  " << first.empty() << "      " << first.size() << "     " << std::hex << first.max_size() << std::dec << std::endl;


	std::cout << "---first.pop_front();---" << std::endl;
	first.pop_front();
	for (auto it = first.cbegin(); it != first.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "       empty  " << "size  " << "max_size" << std::endl;
	std::cout << "first  " << first.empty() << "      " << first.size() << "     " << std::hex << first.max_size() << std::dec << std::endl;


	std::cout << "---first.emplace(++(++first.cbegin()), 11);---" << std::endl;
	first.emplace(++(++first.cbegin()), 11);   //does not support (first.begin() + 2)
	for (auto it = first.cbegin(); it != first.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "       empty  " << "size  " << "max_size" << std::endl;
	std::cout << "first  " << first.empty() << "      " << first.size() << "     " << std::hex << first.max_size() << std::dec << std::endl;


	std::cout << "---first.emplace(first.cend(), 66);---" << std::endl;
	first.emplace(first.cend(), 66);
	for (auto it = first.cbegin(); it != first.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "       empty  " << "size  " << "max_size" << std::endl;
	std::cout << "first  " << first.empty() << "      " << first.size() << "     " << std::hex << first.max_size() << std::dec << std::endl;


	std::cout << "---first.insert(++++first.cbegin(), 111);---" << std::endl;
	first.insert(++++first.cbegin(), 111);
	for (auto it = first.cbegin(); it != first.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "       empty  " << "size  " << "max_size" << std::endl;
	std::cout << "first  " << first.empty() << "      " << first.size() << "     " << std::hex << first.max_size() << std::dec << std::endl;


	std::cout << "---first.insert(first.cbegin(), 3, -1);---" << std::endl;
	first.insert(first.cbegin(), 3, -1);
	for (auto it = first.cbegin(); it != first.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "       empty  " << "size  " << "max_size" << std::endl;
	std::cout << "first  " << first.empty() << "      " << first.size() << "     " << std::hex << first.max_size() << std::dec << std::endl;


	std::cout << "---first.insert(++first.cbegin(), second.cbegin(), second.cend());---" << std::endl;
	std::list<int> second = { 333,444,555 };
	first.insert(++first.cbegin(), second.cbegin(), second.cend());
	std::cout << "second: ";
	for (auto it = second.cbegin(); it != second.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "first : ";
	for (auto it = first.cbegin(); it != first.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "        empty  " << "size  " << "max_size" << std::endl;
	std::cout << "second  " << second.empty() << "      " << second.size() << "     " << std::hex << second.max_size() << std::dec << std::endl;
	std::cout << "first   " << first.empty() << "      " << first.size() << "    " << std::hex << first.max_size() << std::dec << std::endl;


	std::cout << "---first.swap(second);---" << std::endl;
	first.swap(second);
	std::cout << "second: ";
	for (auto it = second.cbegin(); it != second.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "first : ";
	for (auto it = first.cbegin(); it != first.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "        empty  " << "size  " << "max_size" << std::endl;
	std::cout << "second  " << second.empty() << "      " << second.size() << "    " << std::hex << second.max_size() << std::dec << std::endl;
	std::cout << "first   " << first.empty() << "      " << first.size() << "     " << std::hex << first.max_size() << std::dec << std::endl;


	std::cout << "---second.erase(second.cbegin());---" << std::endl;
	second.erase(second.cbegin());
	for (auto it = second.cbegin(); it != second.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "        empty  " << "size  " << "max_size" << std::endl;
	std::cout << "second  " << second.empty() << "      " << second.size() << "    " << std::hex << second.max_size() << std::dec << std::endl;


	std::cout << "---second.erase(second.cbegin(), ++second.cbegin());---" << std::endl;
	second.erase(second.cbegin(), ++second.cbegin());
	for (auto it = second.cbegin(); it != second.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "        empty  " << "size  " << "max_size" << std::endl;
	std::cout << "second  " << second.empty() << "      " << second.size() << "    " << std::hex << second.max_size() << std::dec << std::endl;


	std::cout << "---second.clear();---" << std::endl;
	second.clear();
	for (auto it = second.cbegin(); it != second.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "        empty  " << "size  " << "max_size" << std::endl;
	std::cout << "second  " << second.empty() << "      " << second.size() << "     " << std::hex << second.max_size() << std::dec << std::endl;


	std::cout << "---first.assign(5, 10);---" << std::endl;
	first.assign(5, 10);
	for (auto it = first.cbegin(); it != first.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "       empty  " << "size  " << "max_size" << std::endl;
	std::cout << "first  " << first.empty() << "      " << first.size() << "     " << std::hex << first.max_size() << std::dec << std::endl;


	std::cout << "---first.assign(third.cbegin(), --third.cend());---" << std::endl;
	std::list<int> third = { 13,14,15,16 };
	first.assign(third.cbegin(), --third.cend());
	std::cout << "third: ";
	for (auto it = third.cbegin(); it != third.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "first: ";
	for (auto it = first.cbegin(); it != first.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "       empty  " << "size  " << "max_size" << std::endl;
	std::cout << "third  " << third.empty() << "      " << third.size() << "     " << std::hex << third.max_size() << std::dec << std::endl;
	std::cout << "first  " << first.empty() << "      " << first.size() << "     " << std::hex << first.max_size() << std::dec << std::endl;

}




// a predicate implemented as a function:
bool single_digit(const int& value) 
{
	return value < 10; 
}
bool gap_no_less_than(const double& first, const double& second)
{
	return fabs(first - second) < 2.0;
}
bool compare_double(const double& first, const double& second)
{
	return first < second; //why only this pattern?????
}
bool compare_nocase(const std::string& first, const std::string& second)
{
	unsigned int i = 0;
	while ((i < first.length()) && (i < second.length()))
	{
		if (tolower(first[i]) < tolower(second[i]))
			return true;
		else if (tolower(first[i]) > tolower(second[i]))
			return false;
		++i;
	}
	return (first.length() < second.length());
}
// a predicate implemented as a class:
struct is_odd
{
	bool operator() (const int& value) 
	{
		return (value % 2) == 1; 
	}
};
struct is_near
{
	bool operator() (const int& first, const int& second)
	{
		return fabs(first - second) < 2;
	}
};
//A predicate is a C++ function returning a boolean or an object having a bool operator() member.
//A unary predicate takes one argument, a binary takes two, and so on.


void ListTest::OperationsTest()
{
	/*
std::list::splice
Transfers elements from x into the container, inserting them at position.

entire list (1)
void splice (const_iterator position, list& x);
void splice (const_iterator position, list&& x);

single element (2)
void splice (const_iterator position, list& x, const_iterator i);
void splice (const_iterator position, list&& x, const_iterator i);

element range (3)
void splice (const_iterator position, list& x,
			 const_iterator first, const_iterator last);
void splice (const_iterator position, list&& x,
			 const_iterator first, const_iterator last);
	*/

	std::cout << "**********OperationsTest***********" << std::endl;
	std::list<int> first = { 1, 2, 3, 4, 5, 6, 7, 8 };
	std::list<int> second = { 20, 30, 40, 50 };
	std::cout << "first : ";
	for (auto it = first.cbegin(); it != first.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "second: ";
	for (auto it = second.cbegin(); it != second.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "        empty  " << "size  " << "max_size" << std::endl;
	std::cout << "first   " << first.empty() << "      " << first.size() << "     " << std::hex << first.max_size() << std::dec << std::endl;
	std::cout << "second  " << second.empty() << "      " << second.size() << "     " << std::hex << second.max_size() << std::dec << std::endl;


	std::cout << "---first.splice(++first.cbegin(), second);---" << std::endl;
	std::list<int>::iterator it = first.begin();
	std::advance(it, 1);   //#include <iterator>
	first.splice(it, second);
	std::cout << "it    : " << *it << std::endl;
	std::cout << "first : ";
	for (auto it = first.cbegin(); it != first.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "second: ";
	for (auto it = second.cbegin(); it != second.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "        empty  " << "size  " << "max_size" << std::endl;
	std::cout << "first   " << first.empty() << "      " << first.size() << "     " << std::hex << first.max_size() << std::dec << std::endl;
	std::cout << "second  " << second.empty() << "      " << second.size() << "     " << std::hex << second.max_size() << std::dec << std::endl;


	std::cout << "---second.splice(second.cbegin(), first, first.cbegin())---" << std::endl;
	second.splice(second.cbegin(), first, first.cbegin());
	std::cout << "first : ";
	for (auto it = first.cbegin(); it != first.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "second: ";
	for (auto it = second.cbegin(); it != second.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "        empty  " << "size  " << "max_size" << std::endl;
	std::cout << "first   " << first.empty() << "      " << first.size() << "     " << std::hex << first.max_size() << std::dec << std::endl;
	std::cout << "second  " << second.empty() << "      " << second.size() << "     " << std::hex << second.max_size() << std::dec << std::endl;


	std::cout << "---second.splice(++second.cbegin(), first, it, first.cend());---" << std::endl;
	second.splice(++second.cbegin(), first, it, first.cend());
	std::cout << "it    : " << *it << std::endl;
	std::cout << "first : ";
	for (auto it = first.cbegin(); it != first.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "second: ";
	for (auto it = second.cbegin(); it != second.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "        empty  " << "size  " << "max_size" << std::endl;
	std::cout << "first   " << first.empty() << "      " << first.size() << "     " << std::hex << first.max_size() << std::dec << std::endl;
	std::cout << "second  " << second.empty() << "      " << second.size() << "     " << std::hex << second.max_size() << std::dec << std::endl;


	std::cout << "---second.splice(second.cbegin(), second, it, second.cend());---" << std::endl;
	second.splice(second.cbegin(), second, it, second.cend());
	std::cout << "it    : " << *it << std::endl;
	std::cout << "second: ";
	for (auto it = second.cbegin(); it != second.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "        empty  " << "size  " << "max_size" << std::endl;
	std::cout << "second  " << second.empty() << "      " << second.size() << "     " << std::hex << second.max_size() << std::dec << std::endl;


	std::cout << "---second.remove(6);---" << std::endl;
	second.remove(6);
	std::cout << "it    : " << *it << std::endl;
	std::cout << "second: ";
	for (auto it = second.cbegin(); it != second.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "        empty  " << "size  " << "max_size" << std::endl;
	std::cout << "second  " << second.empty() << "      " << second.size() << "     " << std::hex << second.max_size() << std::dec << std::endl;



	std::cout << "---second.remove_if();---" << std::endl;
	std::list<int> third = { 1,2,3, 40, 50,60, 777,888,999 };
	std::cout << "third: ";
	for (auto it = third.cbegin(); it != third.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "       empty  " << "size  " << "max_size" << std::endl;
	std::cout << "third  " << third.empty() << "      " << third.size() << "     " << std::hex << third.max_size() << std::dec << std::endl;
	
/*
template <class Predicate>
	void remove_if (Predicate pred);
*/
	std::cout << "---second.remove_if(single_digit);---" << std::endl;
	third.remove_if(single_digit);
	std::cout << "third: ";
	for (auto it = third.cbegin(); it != third.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "       empty  " << "size  " << "max_size" << std::endl;
	std::cout << "third  " << third.empty() << "      " << third.size() << "     " << std::hex << third.max_size() << std::dec << std::endl;

	std::cout << "---second.remove_if(is_odd());---" << std::endl;
	third.remove_if(is_odd());
	std::cout << "third: ";
	for (auto it = third.cbegin(); it != third.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "       empty  " << "size  " << "max_size" << std::endl;
	std::cout << "third  " << third.empty() << "      " << third.size() << "     " << std::hex << third.max_size() << std::dec << std::endl;


/*
(1)	
void unique();

(2)	
template <class BinaryPredicate>
	void unique (BinaryPredicate binary_pred);
*/
	std::cout << "---std::list.unique();---" << std::endl;
	std::list<int> fourth = { 1,1,2,2,3,3,4,4,7,6,8,13,13,11,12 };
	std::list<double> fifth = { 1.1,2.2,2.2,3.3,3.3,4.4,5.5,7.7 };
	std::list<std::string> sixth = { "one","one","two","three","four","four" };
	std::cout << "-before:" << std::endl;
	std::cout << "fourth: ";
	for (auto it = fourth.cbegin(); it != fourth.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "fifth : ";
	for (auto it = fifth.cbegin(); it != fifth.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "sixth : ";
	for (auto it = sixth.cbegin(); it != sixth.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "        empty  " << "size  " << "max_size" << std::endl;
	std::cout << "fourth  " << fourth.empty() << "      " << fourth.size() << "    " << std::hex << fourth.max_size() << std::dec << std::endl;
	std::cout << "fifth   " << fifth.empty() << "      " << fifth.size() << "     " << std::hex << fifth.max_size() << std::dec << std::endl;
	std::cout << "sixth   " << sixth.empty() << "      " << sixth.size() << "     " << std::hex << sixth.max_size() << std::dec << std::endl;

	std::cout << "-after:" << std::endl;
	fourth.unique();
	fifth.unique();
	sixth.unique();
	std::cout << "fourth: ";
	for (auto it = fourth.cbegin(); it != fourth.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "fifth : ";
	for (auto it = fifth.cbegin(); it != fifth.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "sixth : ";
	for (auto it = sixth.cbegin(); it != sixth.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "        empty  " << "size  " << "max_size" << std::endl;
	std::cout << "fourth  " << fourth.empty() << "      " << fourth.size() << "    " << std::hex << fourth.max_size() << std::dec << std::endl;
	std::cout << "fifth   " << fifth.empty() << "      " << fifth.size() << "     " << std::hex << fifth.max_size() << std::dec << std::endl;
	std::cout << "sixth   " << sixth.empty() << "      " << sixth.size() << "     " << std::hex << sixth.max_size() << std::dec << std::endl;

	std::cout << "---std::list.unique(binary_pred);---" << std::endl;
	fourth.unique(is_near());
	fifth.unique(gap_no_less_than);
	std::cout << "fourth: ";
	for (auto it = fourth.cbegin(); it != fourth.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "fifth : ";
	for (auto it = fifth.cbegin(); it != fifth.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "        empty  " << "size  " << "max_size" << std::endl;
	std::cout << "fourth  " << fourth.empty() << "      " << fourth.size() << "     " << std::hex << fourth.max_size() << std::dec << std::endl;
	std::cout << "fifth   " << fifth.empty() << "      " << fifth.size() << "     " << std::hex << fifth.max_size() << std::dec << std::endl;



/*
(1)	
  void merge (list& x);
  void merge (list&& x);

(2)	
template <class Compare>
  void merge (list& x, Compare comp);
template <class Compare>
  void merge (list&& x, Compare comp);

  Merges x into the list by transferring all of its elements
  at their respective ordered positions
  into the container (both containers shall already be ordered).
 */
	std::cout << "---std::list.merge();---" << std::endl;
	std::list<double> seventh = { 3.9, 8.7, 2.1 };
	std::list<double> eighth = { 4.2, 5.9, 3.4, 6.7 };
	std::cout << "-raw data:" << std::endl;
	std::cout << "seventh: ";
	for (auto it = seventh.cbegin(); it != seventh.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "eighth : ";
	for (auto it = eighth.cbegin(); it != eighth.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "        empty  " << "size  " << "max_size" << std::endl;
	std::cout << "seventh  " << seventh.empty() << "      " << seventh.size() << "     " << std::hex << seventh.max_size() << std::dec << std::endl;
	std::cout << "eighth   " << eighth.empty() << "      " << eighth.size() << "     " << std::hex << eighth.max_size() << std::dec << std::endl;

	std::cout << "---std::list.sort();---" << std::endl;
	seventh.sort();
	eighth.sort();
	std::cout << "seventh: ";
	for (auto it = seventh.cbegin(); it != seventh.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "eighth : ";
	for (auto it = eighth.cbegin(); it != eighth.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "        empty  " << "size  " << "max_size" << std::endl;
	std::cout << "seventh  " << seventh.empty() << "      " << seventh.size() << "     " << std::hex << seventh.max_size() << std::dec << std::endl;
	std::cout << "eighth   " << eighth.empty() << "      " << eighth.size() << "     " << std::hex << eighth.max_size() << std::dec << std::endl;

	std::cout << "---std::list.merge(list& x);---" << std::endl;
	seventh.merge(eighth); //If both lists are not sorted, program will crash.
	std::cout << "seventh: ";
	for (auto it = seventh.cbegin(); it != seventh.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "eighth : ";
	for (auto it = eighth.cbegin(); it != eighth.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "        empty  " << "size  " << "max_size" << std::endl;
	std::cout << "seventh  " << seventh.empty() << "      " << seventh.size() << "     " << std::hex << seventh.max_size() << std::dec << std::endl;
	std::cout << "eighth   " << eighth.empty() << "      " << eighth.size() << "     " << std::hex << eighth.max_size() << std::dec << std::endl;

	/*
	Compare comp: Binary predicate
	*/
	std::cout << "---std::list.merge(list& x, Compare comp);---" << std::endl;
	eighth.merge(seventh, compare_double); //If both lists are not sorted, program will crash.
	std::cout << "seventh: ";
	for (auto it = seventh.cbegin(); it != seventh.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "eighth : ";
	for (auto it = eighth.cbegin(); it != eighth.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "        empty  " << "size  " << "max_size" << std::endl;
	std::cout << "seventh  " << seventh.empty() << "      " << seventh.size() << "     " << std::hex << seventh.max_size() << std::dec << std::endl;
	std::cout << "eighth   " << eighth.empty() << "      " << eighth.size() << "     " << std::hex << eighth.max_size() << std::dec << std::endl;


	std::cout << "---std::list.reverse();---" << std::endl;
	eighth.reverse();
	std::cout << "eighth : ";
	for (auto it = eighth.cbegin(); it != eighth.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "        empty  " << "size  " << "max_size" << std::endl;
	std::cout << "eighth   " << eighth.empty() << "      " << eighth.size() << "     " << std::hex << eighth.max_size() << std::dec << std::endl;
	std::cout << "---std::list.reverse();---" << std::endl;
	eighth.reverse();
	std::cout << "eighth : ";
	for (auto it = eighth.cbegin(); it != eighth.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "        empty  " << "size  " << "max_size" << std::endl;
	std::cout << "eighth   " << eighth.empty() << "      " << eighth.size() << "     " << std::hex << eighth.max_size() << std::dec << std::endl;



	std::cout << "---std::list.sort(); raw data---" << std::endl;
	std::list<std::string> mylist = { "one", "two", "three", "four" };
	std::cout << "mylist: ";
	for (auto it = mylist.cbegin(); it != mylist.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "        empty  " << "size  " << "max_size" << std::endl;
	std::cout << "mylist  " << mylist.empty() << "      " << mylist.size() << "     " << std::hex << mylist.max_size() << std::dec << std::endl;

	std::cout << "---std::list.sort();---" << std::endl;
	mylist.sort();
	std::cout << "mylist: ";
	for (auto it = mylist.cbegin(); it != mylist.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "        empty  " << "size  " << "max_size" << std::endl;
	std::cout << "mylist  " << mylist.empty() << "      " << mylist.size() << "     " << std::hex << mylist.max_size() << std::dec << std::endl;

	/*
comp
	Binary predicate that, taking two values of the same type of those contained in the list, returns true if the first argument goes before the second argument in the strict weak ordering it defines, and false otherwise.
	This shall be a function pointer or a function object.
	*/
	std::cout << "---std::list.sort(Compare comp);---" << std::endl;
	mylist.sort(compare_nocase);
	std::cout << "mylist: ";
	for (auto it = mylist.cbegin(); it != mylist.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "        empty  " << "size  " << "max_size" << std::endl;
	std::cout << "mylist  " << mylist.empty() << "      " << mylist.size() << "     " << std::hex << mylist.max_size() << std::dec << std::endl;

}
