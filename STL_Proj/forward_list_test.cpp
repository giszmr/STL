#include "pch.h"
#include "forward_list_test.h"
#include <forward_list>
#include <iostream>
#include <string>
#include <iterator>

using namespace STL_Test;

ForwardListTest::ForwardListTest()
{}

ForwardListTest::~ForwardListTest()
{}



void ForwardListTest::ModifiersTest()
{
	std::cout << "**********ForwardListTest::ModifiersTest***********" << std::endl;

	std::forward_list<int> myForwardList = { 1, 6, 3, 2, 9, 7, 6, 5, 8 };
	OutputList(myForwardList, "myForwardList");

	std::cout << "---myForwardList.emplace_front(11);---" << std::endl;
	myForwardList.emplace_front(11);
	OutputList(myForwardList, "myForwardList");


	std::cout << "---myForwardList.push_front(99);---" << std::endl;
	myForwardList.push_front(99);
	OutputList(myForwardList, "myForwardList");

	
	std::cout << "---myForwardList.emplace_after(myForwardList.cbegin(), 88);---" << std::endl;
	myForwardList.emplace_after(myForwardList.cbegin(), 88);
	OutputList(myForwardList, "myForwardList");
	
	std::cout << "---myForwardList.emplace_after(myForwardList.cbefore_begin(), 111);---" << std::endl;
	myForwardList.emplace_after(myForwardList.cbefore_begin(), 111);
	OutputList(myForwardList, "myForwardList");
	

	std::cout << "---myForwardList.pop_front();---" << std::endl;
	myForwardList.pop_front();
	OutputList(myForwardList, "myForwardList");


	std::forward_list<int>::iterator it;
	std::cout << "---it = myForwardList.insert_after(myForwardList.cbegin(), 303);---" << std::endl;
	it = myForwardList.insert_after(myForwardList.cbegin(), 303);
	OutputList(myForwardList, "myForwardList");


	std::cout << "---it = myForwardList.insert_after(it, { 3,1,3 });---" << std::endl;
	it = myForwardList.insert_after(it, { 3,1,3 });
	OutputList(myForwardList, "myForwardList");


	std::cout << "---it = myForwardList.insert_after(it, 202);---" << std::endl;
	it = myForwardList.insert_after(it, 202);
	OutputList(myForwardList, "myForwardList");


	std::cout << "---it = myForwardList.erase_after(it);---" << std::endl;
	it = myForwardList.erase_after(it);
	OutputList(myForwardList, "myForwardList");


	std::cout << "---it = myForwardList.erase_after(it, myForwardList.cend());---" << std::endl;
	it = myForwardList.erase_after(it, myForwardList.cend());  //keep "it", erase "it + 1" to "end".
	OutputList(myForwardList, "myForwardList");


	std::cout << "---myForwardList.resize(10);---" << std::endl;
	myForwardList.resize(10);
	OutputList(myForwardList, "myForwardList");

	std::cout << "---myForwardList.resize(5);---" << std::endl;
	myForwardList.resize(5);
	OutputList(myForwardList, "myForwardList");


	std::cout << "---myForwardList.resize(10);---" << std::endl;
	myForwardList.resize(10, 999);
	OutputList(myForwardList, "myForwardList");


	std::cout << "---myForwardList.clear();---" << std::endl;
	myForwardList.clear();
	OutputList(myForwardList, "myForwardList");

}


void ForwardListTest::OperationsTest()
{

}


void ForwardListTest::OutputList(std::forward_list<int>& myForwardList, std::string name)
{
	std::cout << name << " : ";
	for (auto it = myForwardList.cbegin(); it != myForwardList.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "empty  " << "max_size" << std::endl;
	std::cout << myForwardList.empty() << "      " << std::hex << myForwardList.max_size() << std::dec << std::endl;

}