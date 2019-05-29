#include "pch.h"
#include "queue_test.h"
#include <queue>
#include <list>
#include <iostream>
#include <iterator>

using namespace STL_Test;

QueueTest::QueueTest()
{
}

QueueTest::~QueueTest()
{
}


void QueueTest::Test()
{
	std::deque<int> mydeque(8, 66);
	std::list<int> mylist(5, 77);
	std::cout << "size of mydeque: " << mydeque.size() << std::endl;
	std::cout << "size of mylist : " << mylist.size() << std::endl;


	std::cout << "---std::queue<int> first;---" << std::endl;
	std::queue<int> first;
	std::cout << "size of first : " << first.size() << std::endl;



	std::cout << "---std::queue<int> second(mydeque);---" << std::endl;
	std::queue<int> second(mydeque);
	std::cout << "size of second: " << second.size() << std::endl;



	std::cout << "---first.swap(second);---" << std::endl;
	first.swap(second);
	std::cout << "size of first : " << first.size() << std::endl;
	std::cout << "size of second: " << second.size() << std::endl;
	std::cout << "first : ";
	while (!first.empty())
	{
		std::cout << first.front() << " ";
		first.pop();
	}
	std::cout << std::endl;
	std::cout << "size of first : " << first.size() << std::endl;
	std::cout << "size of second: " << second.size() << std::endl;


	std::cout << "---std::queue<int, std::list<int>> third;---" << std::endl;
	std::queue<int, std::list<int>> third;
	std::cout << "size of third: " << third.size() << std::endl;



	std::cout << "---std::queue<int, std::list<int>> fourth(mylist);---" << std::endl;
	std::queue<int, std::list<int>> fourth(mylist);
	std::cout << "size of fourth: " << fourth.size() << std::endl;


	std::cout << "---fourth.push(333);---" << std::endl;
	fourth.push(333);
	std::cout << "size of fourth: " << fourth.size() << std::endl;


	std::cout << "---fourth.emplace(555);---" << std::endl;
	fourth.emplace(555);
	std::cout << "size of fourth: " << fourth.size() << std::endl;
	std::cout << "fourth.back() = " << fourth.back() << std::endl;
	std::cout << "fourth : ";
	while (!fourth.empty())
	{
		std::cout << fourth.front() << " ";
		fourth.pop();
	}
	std::cout << std::endl;
	std::cout << "size of fourth: " << fourth.size() << std::endl;



}