#include "pch.h"
#include "stack_test.h"
#include <stack>
#include <iostream>
#include <iterator>

using namespace STL_Test;

StackTest::StackTest()
{
}

StackTest::~StackTest()
{
}


void StackTest::Test()
{
	std::deque<int> mydeque(5, 99);
	std::vector<int> myvector(3, 100);
	std::cout << "size of mydeque : " << mydeque.size() << std::endl;
	std::cout << "size of myvector: " << myvector.size() << std::endl;


	std::cout << "---std::stack<int> first;---" << std::endl;
	std::stack<int> first;
	std::cout << "size of first : " << first.size() << std::endl;



	std::cout << "---std::stack<int> second(mydeque);---" << std::endl;
	std::stack<int> second(mydeque);
	std::cout << "size of second: " << second.size() << std::endl;



	std::cout << "---first.swap(second);---" << std::endl;
	first.swap(second);
	std::cout << "size of first : " << first.size() << std::endl;
	std::cout << "size of second: " << second.size() << std::endl;
	std::cout << "first : ";
	while (!first.empty())
	{
		std::cout << first.top() << " ";
		first.pop();
	}
	std::cout << std::endl;
	std::cout << "size of first : " << first.size() << std::endl;
	std::cout << "size of second: " << second.size() << std::endl;


	std::cout << "---std::stack<int, std::vector<int>> third;---" << std::endl;
	std::stack<int, std::vector<int>> third;
	std::cout << "size of third: " << third.size() << std::endl;



	std::cout << "---std::stack<int, std::vector<int>> fourth(myvector);---" << std::endl;
	std::stack<int, std::vector<int>> fourth(myvector);
	std::cout << "size of fourth: " << fourth.size() << std::endl;


	std::cout << "---fourth.push(333);---" << std::endl;
	fourth.push(333);
	std::cout << "size of fourth: " << fourth.size() << std::endl;


	std::cout << "---fourth.emplace(555);---" << std::endl;
	fourth.emplace(555);
	std::cout << "size of fourth: " << fourth.size() << std::endl;
	std::cout << "fourth : ";
	while (!fourth.empty())
	{
		std::cout << fourth.top() << " ";
		fourth.pop();
	}
	std::cout << std::endl;
	std::cout << "size of fourth: " << fourth.size() << std::endl;



}


