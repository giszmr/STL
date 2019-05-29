#include "pch.h"
#include "compare_test.h"
#include <queue>
#include <list>
#include <iostream>
#include <iterator>
#include <array>
#include <iomanip> //setprecision()

using namespace STL_Test;



void CompareTest::Test()
{
	MyKey key1(10, "Joe");
	MyKey key2(20, "Johe");
	MyKey key3(30, "Sally");
	MyKey Key4(30, "Ross");
	std::map<MyKey, std::string> myMap = { std::pair<MyKey, std::string>(key1, "first"),
											std::pair<MyKey, std::string>(key2, "second"),
											std::pair<MyKey, std::string>(key3, "third"),
											std::pair<MyKey, std::string>(Key4, "fourth") };

	Output(myMap, "myMap");


	std::map<MyKey, std::string, cmpKey> myMap2 = { std::pair<MyKey, std::string>(key1, "first"),
											std::pair<MyKey, std::string>(key2, "second"),
											std::pair<MyKey, std::string>(key3, "third"),
											std::pair<MyKey, std::string>(Key4, "fourth") };
	Output(myMap2, "myMap2");
}


void CompareTest::Output(std::map<MyKey, std::string>& myMap, std::string name)
{
	std::cout << name << "(" << myMap.size() << ",0x" << std::hex << myMap.max_size() << std::dec << ")" << " : ";
	if (myMap.empty())
	{
		std::cout << "empty";
	}
	else
	{
		for (std::map<MyKey, std::string>::iterator it = myMap.begin(); it != myMap.end(); it++)
		{
			std::cout << "{(" << it->first.getAge() << "," << it->first.getName() <<") , " << std::setw(3) << it->second << "} ";
		}
	}
	std::cout << std::endl;
}


void CompareTest::Output(std::map<MyKey, std::string, cmpKey>& myMap, std::string name)
{
	std::cout << name << "(" << myMap.size() << ",0x" << std::hex << myMap.max_size() << std::dec << ")" << " : ";
	if (myMap.empty())
	{
		std::cout << "empty";
	}
	else
	{
		for (std::map<MyKey, std::string>::iterator it = myMap.begin(); it != myMap.end(); it++)
		{
			std::cout << "{(" << it->first.getAge() << "," << it->first.getName() << ") , " << std::setw(3) << it->second << "} ";
		}
	}
	std::cout << std::endl;
}