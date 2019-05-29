#include "pch.h"
#include "deque_test.h"
#include <deque>
#include <iostream>
#include <string>


using namespace STL_Test;

DequeTest::DequeTest()
{}

DequeTest::~DequeTest()
{}

void DequeTest::MemberFunctionsTest()
{
	std::cout << "---std::deque<int> first;---" << std::endl;
	std::deque<int> first;
	for (auto it = first.cbegin(); it != first.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "       empty  " << "size  " << "max_size" << std::endl;
	std::cout << "first  " << first.empty() << "      " << first.size() << "     " << std::hex << first.max_size() << std::dec << std::endl;

	std::cout << "---std::deque<int> second(5);---" << std::endl;
	std::deque<int> second(5);
	for (auto it = second.cbegin(); it != second.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "       empty  " << "size  " << "max_size" << std::endl;
	std::cout << "second " << second.empty() << "      " << second.size() << "     " << std::hex << second.max_size() << std::dec << std::endl;

	std::cout << "---std::deque<int> third(5, 99);---" << std::endl;
	std::deque<int> third(5, 99);
	for (auto it = third.cbegin(); it != third.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "       empty  " << "size  " << "max_size" << std::endl;
	std::cout << "third  " << third.empty() << "      " << third.size() << "     " << std::hex << third.max_size() << std::dec << std::endl;

	std::cout << "---std::deque<int> fourth(third.cbegin(), third.cend());---" << std::endl;
	std::deque<int> fourth(third.cbegin(), third.cend());
	for (auto it = fourth.cbegin(); it != fourth.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "       empty  " << "size  " << "max_size" << std::endl;
	std::cout << "fourth " << fourth.empty() << "      " << fourth.size() << "     " << std::hex << fourth.max_size() << std::dec << std::endl;

	std::cout << "---std::deque<int> fifth(fourth);---" << std::endl;
	std::deque<int> fifth(fourth);
	for (auto it = fifth.cbegin(); it != fifth.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "       empty  " << "size  " << "max_size" << std::endl;
	std::cout << "fifth  " << fifth.empty() << "      " << fifth.size() << "     " << std::hex << fifth.max_size() << std::dec << std::endl;

	std::cout << "---std::deque<int> sixth(myInts, myInts + sizeof(myInts) / sizeof(int));---" << std::endl;
	int myInts[] = { 1, 2, 3, 4, 5 };
	std::deque<int> sixth(myInts, myInts + sizeof(myInts) / sizeof(int));
	for (auto it = sixth.cbegin(); it != sixth.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "       empty  " << "size  " << "max_size" << std::endl;
	std::cout << "sixth  " << sixth.empty() << "      " << sixth.size() << "     " << std::hex << sixth.max_size() << std::dec << std::endl;

}

void DequeTest::CapacityTest()
{
	std::cout << "**********CapacityTest*********" << std::endl;
	std::deque<std::string> mydeque{ "first", "second", "third", "fourth","fifth" };
	for (auto it = mydeque.cbegin(); it != mydeque.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "         empty  " << "size  " << "max_size" << std::endl;
	std::cout << "mydeque  " << mydeque.empty() << "      " << mydeque.size() << "     " << std::hex << mydeque.max_size() << std::dec << std::endl;

	std::cout << "---mydeque.resize(7, \"none\");---" << std::endl;
	mydeque.resize(7, "none");
	for (auto it = mydeque.cbegin(); it != mydeque.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "         empty  " << "size  " << "max_size" << std::endl;
	std::cout << "mydeque  " << mydeque.empty() << "      " << mydeque.size() << "     " << std::hex << mydeque.max_size() << std::dec << std::endl;

	std::cout << "---mydeque.resize(9);---" << std::endl;
	mydeque.resize(9);
	for (auto it = mydeque.cbegin(); it != mydeque.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "         empty  " << "size  " << "max_size" << std::endl;
	std::cout << "mydeque  " << mydeque.empty() << "      " << mydeque.size() << "     " << std::hex << mydeque.max_size() << std::dec << std::endl;

	std::cout << "---mydeque.shrink_to_fit();---" << std::endl;
	mydeque.shrink_to_fit();
	for (auto it = mydeque.cbegin(); it != mydeque.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "         empty  " << "size  " << "max_size" << std::endl;
	std::cout << "mydeque  " << mydeque.empty() << "      " << mydeque.size() << "     " << std::hex << mydeque.max_size() << std::dec << std::endl;

}

void DequeTest::ElementAccessTest()
{
	std::cout << "**********ElementAccessTest*********" << std::endl;
	std::cout << "---mydeque[i]---" << std::endl;
	std::deque<std::string> mydeque{ "first", "second", "third", "fourth","fifth" };
	std::cout << "         empty  " << "size  " << "max_size" << std::endl;
	std::cout << "mydeque  " << mydeque.empty() << "      " << mydeque.size() << "     " << std::hex << mydeque.max_size() << std::dec << std::endl;
	for (unsigned int i = 0; i < mydeque.size(); i++)
		std::cout << mydeque[i] << " ";
	std::cout << std::endl;

	std::cout << "---mydeque.at(i)---" << std::endl;
	for (unsigned int i = 0; i < mydeque.size(); i++)
		std::cout << mydeque.at(i) << " ";
	std::cout << std::endl;

	std::cout << "---mydeque.front()---" << std::endl;
	std::cout << mydeque.front() << std::endl;

	std::cout << "---mydeque.back()---" << std::endl;
	std::cout << mydeque.back() << std::endl;
}

void DequeTest::ModifiersTest()
{
	std::cout << "**********ElementAccessTest*********" << std::endl;
	std::deque<double> mydeque(6, 3.14);
	for (auto it = mydeque.cbegin(); it != mydeque.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "         empty  " << "size  " << "max_size" << std::endl;
	std::cout << "mydeque  " << mydeque.empty() << "      " << mydeque.size() << "     " << std::hex << mydeque.max_size() << std::dec << std::endl;

	std::cout << "---mydeque.insert(mydeque.cbegin() + 3, 5.55);---" << std::endl;
	mydeque.insert(mydeque.cbegin() + 3, 5.55);
	for (auto it = mydeque.cbegin(); it != mydeque.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "         empty  " << "size  " << "max_size" << std::endl;
	std::cout << "mydeque  " << mydeque.empty() << "      " << mydeque.size() << "     " << std::hex << mydeque.max_size() << std::dec << std::endl;

	std::cout << "---mydeque.insert(mydeque.cbegin() + 4, 2, 6.66);---" << std::endl;
	mydeque.insert(mydeque.cbegin() + 4, 2, 6.66);
	for (auto it = mydeque.cbegin(); it != mydeque.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "         empty  " << "size  " << "max_size" << std::endl;
	std::cout << "mydeque  " << mydeque.empty() << "      " << mydeque.size() << "     " << std::hex << mydeque.max_size() << std::dec << std::endl;

	std::cout << "---mydeque.insert(mydeque.cbegin() + 6, anotherDeque.cbegin(), anotherDeque.cend() - 1);---" << std::endl;
	std::deque<double> anotherDeque{ 2.22, 2.22, 2.22, 2.22 };
	mydeque.insert(mydeque.cbegin() + 6, anotherDeque.cbegin(), anotherDeque.cend() - 1);
	for (auto it = mydeque.cbegin(); it != mydeque.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "         empty  " << "size  " << "max_size" << std::endl;
	std::cout << "mydeque  " << mydeque.empty() << "      " << mydeque.size() << "     " << std::hex << mydeque.max_size() << std::dec << std::endl;

	std::cout << "---mydeque.insert(mydeque.cbegin(), dArr, dArr + sizeof(dArr) / sizeof(double));---" << std::endl;
	double dArr[] = { 1.11, 1.11, 1.11, 1.11 };
	mydeque.insert(mydeque.cbegin(), dArr, dArr + sizeof(dArr) / sizeof(double) - 3);
	for (auto it = mydeque.cbegin(); it != mydeque.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "         empty  " << "size  " << "max_size" << std::endl;
	std::cout << "mydeque  " << mydeque.empty() << "      " << mydeque.size() << "     " << std::hex << mydeque.max_size() << std::dec << std::endl;

	std::cout << "---assignDeque.assign(5, 9.1);---" << std::endl;
	std::deque<double> assignDeque;
	assignDeque.assign(5, 9.1);
	for (auto it = assignDeque.cbegin(); it != assignDeque.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "             empty  " << "size  " << "max_size" << std::endl;
	std::cout << "assignDeque  " << assignDeque.empty() << "      " << assignDeque.size() << "     " << std::hex << assignDeque.max_size() << std::dec << std::endl;

	std::cout << "---assignDeque2.assign(assignDeque.cbegin(), assignDeque.cend() - 2);---" << std::endl;
	std::deque<double> assignDeque2;
	assignDeque2.assign(assignDeque.cbegin(), assignDeque.cend() - 2);
	for (auto it = assignDeque2.cbegin(); it != assignDeque2.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "              empty  " << "size  " << "max_size" << std::endl;
	std::cout << "assignDeque2  " << assignDeque2.empty() << "      " << assignDeque2.size() << "     " << std::hex << assignDeque2.max_size() << std::dec << std::endl;

	std::cout << "---assignDeque3.assign(assignDeque.cbegin(), assignDeque.cend() - 2);---" << std::endl;
	std::deque<double> assignDeque3;
	assignDeque3.assign(dArr, dArr + sizeof(dArr) / sizeof(double));
	for (auto it = assignDeque3.cbegin(); it != assignDeque3.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "              empty  " << "size  " << "max_size" << std::endl;
	std::cout << "assignDeque3  " << assignDeque3.empty() << "      " << assignDeque3.size() << "     " << std::hex << assignDeque3.max_size() << std::dec << std::endl;

	std::cout << "---assignDeque3.push_back(2.11);---" << std::endl;
	assignDeque3.push_back(2.11);
	for (auto it = assignDeque3.cbegin(); it != assignDeque3.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "              empty  " << "size  " << "max_size" << std::endl;
	std::cout << "assignDeque3  " << assignDeque3.empty() << "      " << assignDeque3.size() << "     " << std::hex << assignDeque3.max_size() << std::dec << std::endl;

	std::cout << "---assignDeque3.push_front(0.22);---" << std::endl;
	assignDeque3.push_front(0.22);
	for (auto it = assignDeque3.cbegin(); it != assignDeque3.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "              empty  " << "size  " << "max_size" << std::endl;
	std::cout << "assignDeque3  " << assignDeque3.empty() << "      " << assignDeque3.size() << "     " << std::hex << assignDeque3.max_size() << std::dec << std::endl;

	std::cout << "---assignDeque3.pop_back();---" << std::endl;
	assignDeque3.pop_back();
	for (auto it = assignDeque3.cbegin(); it != assignDeque3.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "              empty  " << "size  " << "max_size" << std::endl;
	std::cout << "assignDeque3  " << assignDeque3.empty() << "      " << assignDeque3.size() << "     " << std::hex << assignDeque3.max_size() << std::dec << std::endl;

	std::cout << "---assignDeque3.pop_front();---" << std::endl;
	assignDeque3.pop_front();
	for (auto it = assignDeque3.cbegin(); it != assignDeque3.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "              empty  " << "size  " << "max_size" << std::endl;
	std::cout << "assignDeque3  " << assignDeque3.empty() << "      " << assignDeque3.size() << "     " << std::hex << assignDeque3.max_size() << std::dec << std::endl;

	std::cout << "---assignDeque3.swap(assignDeque2);---" << std::endl;
	assignDeque3.swap(assignDeque2);
	for (auto it = assignDeque2.cbegin(); it != assignDeque2.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "              empty  " << "size  " << "max_size" << std::endl;
	std::cout << "assignDeque2  " << assignDeque2.empty() << "      " << assignDeque2.size() << "     " << std::hex << assignDeque2.max_size() << std::dec << std::endl;
	for (auto it = assignDeque3.cbegin(); it != assignDeque3.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "              empty  " << "size  " << "max_size" << std::endl;
	std::cout << "assignDeque3  " << assignDeque3.empty() << "      " << assignDeque3.size() << "     " << std::hex << assignDeque3.max_size() << std::dec << std::endl;

	std::cout << "---assignDeque3.assignDeque3.erase(assignDeque3.cbegin());---" << std::endl;
	assignDeque3.erase(assignDeque3.cbegin());
	for (auto it = assignDeque3.cbegin(); it != assignDeque3.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "              empty  " << "size  " << "max_size" << std::endl;
	std::cout << "assignDeque3  " << assignDeque3.empty() << "      " << assignDeque3.size() << "     " << std::hex << assignDeque3.max_size() << std::dec << std::endl;

	std::cout << "---assignDeque3.assignDeque3.erase(assignDeque3.cbegin());---" << std::endl;
	assignDeque3.erase(assignDeque3.cbegin(), assignDeque3.cend());
	for (auto it = assignDeque3.cbegin(); it != assignDeque3.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "              empty  " << "size  " << "max_size" << std::endl;
	std::cout << "assignDeque3  " << assignDeque3.empty() << "      " << assignDeque3.size() << "     " << std::hex << assignDeque3.max_size() << std::dec << std::endl;

	std::cout << "---assignDeque.clear();---" << std::endl;
	assignDeque.clear();
	for (auto it = assignDeque.cbegin(); it != assignDeque.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "             empty  " << "size  " << "max_size" << std::endl;
	std::cout << "assignDeque  " << assignDeque.empty() << "      " << assignDeque.size() << "     " << std::hex << assignDeque.max_size() << std::dec << std::endl;

	std::cout << "---assignDeque.emplace_front(1.1);---" << std::endl;
	assignDeque.emplace_front(1.1);
	for (auto it = assignDeque.cbegin(); it != assignDeque.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "             empty  " << "size  " << "max_size" << std::endl;
	std::cout << "assignDeque  " << assignDeque.empty() << "      " << assignDeque.size() << "     " << std::hex << assignDeque.max_size() << std::dec << std::endl;

	std::cout << "---assignDeque.emplace_back(9.9);---" << std::endl;
	assignDeque.emplace_back(9.9);
	for (auto it = assignDeque.cbegin(); it != assignDeque.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "             empty  " << "size  " << "max_size" << std::endl;
	std::cout << "assignDeque  " << assignDeque.empty() << "      " << assignDeque.size() << "     " << std::hex << assignDeque.max_size() << std::dec << std::endl;

	std::cout << "---assignDeque.emplace_back(9.9);---" << std::endl;
	assignDeque.emplace(assignDeque.cbegin() + 1, 8.8);
	for (auto it = assignDeque.cbegin(); it != assignDeque.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "             empty  " << "size  " << "max_size" << std::endl;
	std::cout << "assignDeque  " << assignDeque.empty() << "      " << assignDeque.size() << "     " << std::hex << assignDeque.max_size() << std::dec << std::endl;

}
