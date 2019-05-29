#include "pch.h"
#include "priority_queue_test.h"
#include <queue>
#include <list>
#include <iostream>
#include <iterator>
#include <array>
#include <iomanip> //setprecision()

using namespace STL_Test;

PriorityQueueTest::PriorityQueueTest()
{
}

PriorityQueueTest::~PriorityQueueTest()
{
}


void PriorityQueueTest::Test()
{
	std::cout << "***********PriorityQueueTest::Test**********" << std::endl;
	std::cout << "---constructor---" << std::endl;

	std::cout << "---std::priority_queue<int> first(myints, myints + sizeof(myints) / sizeof(int));---" << std::endl;
	int myints[] = { 3, 6, 1, 0, 9 };
	std::cout << "myints: ";
	for (int i = 0; i < sizeof(myints) / sizeof(int); i++)
	{
		std::cout << myints[i] << " ";
	}
	std::cout << std::endl;
	std::priority_queue<int> first(myints, myints + sizeof(myints) / sizeof(int));
	std::cout << "size of first: " << first.size() << std::endl;
	std::cout << "first : ";
	while (!first.empty())
	{
		std::cout << first.top() << " ";
		first.pop();
	}
	std::cout << std::endl;



	std::cout << "---std::priority_queue<std::string> second(myarray.cbegin(), myarray.cend());--" << std::endl;
	std::array<std::string, 9> myarray = { "Hello", "everyboday", ".", "So", "glad", "to", "see", "you", "!" };
	std::cout << "myarray: ";
	for (auto it : myarray)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;
	std::priority_queue<std::string> second(myarray.cbegin(), myarray.cend());
	std::cout << "size of second: " << second.size() << std::endl;
	std::cout << "second : ";
	while (!second.empty())
	{
		std::cout << second.top() << " ";
		second.pop();
	}
	std::cout << std::endl;


	std::cout << "---std::priority_queue<int, std::vector<int>, std::greater<int>> third(myints, myints + sizeof(myints) / sizeof(int));--" << std::endl;
	std::priority_queue<int, std::vector<int>, std::greater<int>> third(myints, myints + sizeof(myints) / sizeof(int));
	std::cout << "myints: ";
	for (int i = 0; i < sizeof(myints) / sizeof(int); i++)
	{
		std::cout << myints[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "size of third: " << third.size() << std::endl;
	std::cout << "third : ";
	while (!third.empty())
	{
		std::cout << third.top() << " ";
		third.pop();
	}
	std::cout << std::endl;



	std::cout << "---std::priority_queue<int, std::vector<int>, std::less<int>> third(myints, myints + sizeof(myints) / sizeof(int));--" << std::endl;
	std::priority_queue<int, std::vector<int>, std::less<int>> fourth(myints, myints + sizeof(myints) / sizeof(int));
	std::cout << "myints: ";
	for (int i = 0; i < sizeof(myints) / sizeof(int); i++)
	{
		std::cout << myints[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "size of fourth: " << fourth.size() << std::endl;
	std::cout << "fourth: ";
	while (!fourth.empty())
	{
		std::cout << fourth.top() << " ";
		fourth.pop();
	}
	std::cout << std::endl;



	std::cout << "---fifth.push()--" << std::endl;
	std::priority_queue<double> fifth;
	std::priority_queue<double, std::deque<double>, std::greater<double>> sixth;
	std::cout << "size of fifth: " << fifth.size() << std::endl;
	std::cout << "size of sixth: " << sixth.size() << std::endl;
	fifth.push(3.14); 
	sixth.push(3.14);
	fifth.push(3.141);
	sixth.push(3.141);
	fifth.push(3.1415);
	sixth.push(3.1415);
	fifth.push(3.14159);
	sixth.push(3.14159);
	fifth.push(3.141592);
	sixth.push(3.141592);
	fifth.push(3.1415926);
	sixth.push(3.1415926);
	fifth.push(3.1);
	sixth.push(3.1);
	fifth.emplace(3.0);
	sixth.emplace(3.0);
	std::cout << "size of fifth: " << fifth.size() << std::endl;
	std::cout << "size of sixth: " << sixth.size() << std::endl;
	std::cout << "fifth: ";
	while (!fifth.empty())
	{
		std::cout << std::setprecision(8) << fifth.top() << " ";
		fifth.pop();
	}
	std::cout << std::endl;
	std::cout << "sixth: ";
	while (!sixth.empty())
	{
		std::cout << std::setprecision(8) << sixth.top() << " ";
		sixth.pop();
	}
	std::cout << std::endl;

}