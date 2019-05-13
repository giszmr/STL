#include "pch.h"
#include "unordered_map_test.h"
#include <queue>
#include <list>
#include <iostream>
#include <iterator>
#include <array>
#include <iomanip> //setprecision()

using namespace STL_Test;

UnorderedMapTest::UnorderedMapTest()
{
}

UnorderedMapTest::~UnorderedMapTest()
{
}


void UnorderedMapTest::ConstructorTest()
{
	std::cout << std::endl << "********ConstructorTest********" << std::endl;


	std::unordered_map<std::string, int> first;
	Output(first, "first");


	std::unordered_map<std::string, int> second = { 
		{"Hello", 1}, 
		{"everybody", 2}, 
		{"!", 3} 
	};
	std::unordered_map<std::string, int> second2 = { 
		{"So", 1}, 
		{"glad", 2}, 
		{"to", 3}, 
		{"see", 3}, 
		{"you", 3}, 
		{".", 3} 
	};
	Output(second, "second");
	Output(second2, "second2");


	std::unordered_map<std::string, int> third(second);
	std::unordered_map<std::string, int> fourth = { second.cbegin(), second.cend() };
	std::unordered_map<std::string, int> fifth = { second.cbegin(), second.cend(), 11 };
	std::unordered_map<std::string, int> sixth = { second.cbegin(), second.cend(), 22 };
	std::unordered_map<std::string, int> seventh = { second.cbegin(), second.cend(), 33 };
	std::unordered_map<std::string, int> eighth = { second.cbegin(), second.cend(), 44 };
	std::unordered_map<std::string, int> ninth(merge(seventh, eighth));
	std::unordered_map<std::string, int> tenth(merge(second, second2)); //move elements
	Output(third, "third"); // pay attention to the bucket_size of these unordered_map
	Output(fourth, "fourth");
	Output(fifth, "fifth");
	Output(sixth, "sixth");
	Output(seventh, "seventh");
	Output(eighth, "eighth");
	Output(ninth, "ninth");
	Output(tenth, "tenth");


	Name name1("Smith", "John");
	Name name2("Willton", "John");
	Name name3("Hillary", "Clinton");
	std::unordered_map<Name, int, Hash_Name> eleventh{
		{
			{name1, 1},
			{name2, 2},
			{name3, 3}
		},
		10,
		Hash_Name()
	};
	Output(eleventh, "eleventh");

}
std::unordered_map<std::string, int> UnorderedMapTest::merge(std::unordered_map<std::string, int> map1, std::unordered_map<std::string, int> map2)
{
	std::unordered_map<std::string, int> tmp(map1);
	//Each element is inserted only if its key is not equivalent to the key of any other element already in the container 
	//(keys in an unordered_map are unique).
	tmp.insert(map2.cbegin(), map2.cend());
	return tmp;
}


void UnorderedMapTest::ModifiersTest()
{
	std::cout << std::endl << "********ConstructorTest********" << std::endl;

	std::unordered_map<std::string, int> first;
	std::unordered_map<std::string, int> second = { {"Old", 55}, {"Yong", 10} };

	std::cout << "insert:" << std::endl;
	first.insert(std::pair<std::string, int> {"John", 33});
	first.insert({ {"Smith", 22}, {"Rose", 44} });
	std::pair<std::string, int> mypair = { "Joe", 15 };
	first.insert(mypair);
	first.insert(second.cbegin(), second.cend());
	Output(first, "first");


	std::cout << std::endl << "emplace:" << std::endl;

}


void UnorderedMapTest::ObserversTest()
{
	
}


void UnorderedMapTest::OperationsTest()
{
	
}


void UnorderedMapTest::BucketsTest()
{

}


void UnorderedMapTest::HashPolicyTest()
{

}


void UnorderedMapTest::Output(std::unordered_map<std::string, int> mymap, std::string name)
{
	std::cout <<  std::setw(7) << name << "(" << mymap.size() << ",0x" << std::hex << mymap.max_size() << std::dec << "; " << std::setw(2) << mymap.bucket_count() << ",0x" << std::hex << mymap.max_bucket_count() << std::dec << ")" << " : ";
	if (mymap.empty())
	{
		std::cout << "empty";
	}
	else
	{
		for (auto it = mymap.cbegin(); it != mymap.cend(); it++)
		{
			std::cout << "(" << it->first << "," << std::setw(2) << it->second << ") ";
		}
	}
	std::cout << std::endl;
}



void UnorderedMapTest::Output(std::unordered_map<Name, int, Hash_Name> mymap, std::string name)
{
	std::cout << std::setw(7) << name << "(" << mymap.size() << ",0x" << std::hex << mymap.max_size() << std::dec << "; " << std::setw(2) << mymap.bucket_count() << ",0x" << std::hex << mymap.max_bucket_count() << std::dec << ")" << " : ";
	if (mymap.empty())
	{
		std::cout << "empty";
	}
	else
	{
		for (auto it = mymap.cbegin(); it != mymap.cend(); it++)
		{
			std::cout << "(" << std::setw(5) << it->first.GetFristName() << "." << it->first.GetSecondName() << "," << std::setw(2) << it->second << ") ";
		}
	}
	std::cout << std::endl;
}



