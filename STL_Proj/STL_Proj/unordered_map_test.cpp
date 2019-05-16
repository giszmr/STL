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
	std::unordered_map<std::string, int> third2 = second;
	std::unordered_map<std::string, int> fourth = { second.cbegin(), second.cend() };
	std::unordered_map<std::string, int> fifth = { second.cbegin(), second.cend(), 11 };
	std::unordered_map<std::string, int> sixth = { second.cbegin(), second.cend(), 22 };
	std::unordered_map<std::string, int> seventh = { second.cbegin(), second.cend(), 33 };
	std::unordered_map<std::string, int> eighth = { second.cbegin(), second.cend(), 44 };
	std::unordered_map<std::string, int> ninth(merge(seventh, eighth));
	std::unordered_map<std::string, int> tenth(merge(second, second2)); //move elements
	Output(third, "third"); // pay attention to the bucket_size of these unordered_map
	Output(third2, "third2");
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
	std::cout << std::endl << "********ModifiersTest********" << std::endl;

	std::unordered_map<std::string, int> first;
	std::unordered_map<std::string, int> second = { {"Old", 11}, {"Yong", 22} };
	std::unordered_map<std::string, int> third = { {"Male", 10}, {"Female", 20} };

	std::pair<std::unordered_map<std::string, int>::iterator, bool> ret;
	

	//Inserts new "elements" in the unordered_map.
	//Each element is inserted only if its key is not equivalent to the key of any other element already in the container (keys in an unordered_map are "unique").
	std::cout << "insert:" << std::endl;
	ret = first.insert(std::pair<std::string, int>("John", 33));
	first.insert({ {"Smith", 44}, {"Rose", 55} });
	first.insert(first.cbegin(), { "Cat", 56 });   //(pos hint, value)
	std::pair<std::string, int> mypair = { "Joe", 66 };
	ret = first.insert(mypair);
	first.insert(second.cbegin(), second.cend());
	Output(first, "first");


	//Inserts "a" new element in the unordered_map if its key is "unique". 
	std::cout << std::endl << "emplace:" << std::endl;
	ret = first.emplace(std::pair<std::string, int>("Trump", 77));
	ret = first.emplace("Xi Jinping", 88);
	//first.emplace({ "Xi Jinping", 88 });    //this kind of parameter is not allowed
	std::pair<std::string, int> pair1 = { "Jiang Zemin", 99 };
	ret = first.emplace(pair1);
	//first.emplace(third.cbegin(), third.cend());      //illegal
	//first.emplace(third.cbegin());                    //illegal
	Output(first, "first");



	//Inserts "a" new element in the unordered_map if its key is "unique". 
	std::cout << std::endl << "emplace_hint:" << std::endl;
	auto iter = first.emplace_hint(first.cbegin(), "Bush", 10);
	//first.emplace_hint(first.cbegin(), { "Old Bush", 20 });   //illegal
	std::cout << iter->first << "," << iter->second << std::endl;
	Output(first, "first");




	std::cout << std::endl << "********BucketsTest********" << std::endl;

	std::cout << std::endl << "bucket_size:" << first.bucket_count() << std::endl;
	for (size_t i = 0; i < first.bucket_count(); i++)
	{
		std::cout << "Buckets #" << i << " has " << first.bucket_size(i) << " elements." << std::endl;
	}



	std::cout << std::endl << "bucket:" << std::endl;
	size_t pos = first.bucket("Bush");
	std::cout << "Bush is in bucket #" << pos << "." << std::endl;



	std::cout << std::endl << "********HashPolicyTest********" << std::endl;

	std::cout << std::endl << "load_factor:" << std::endl;
	std::cout << "Load factor of this map is " << first.load_factor() << "." << std::endl;
	std::cout << "Max load factor of this map is " << first.max_load_factor() << "." << std::endl;



	std::cout << std::endl << "max_load_factor:" << std::endl;
	first.max_load_factor(0.75f);
	std::cout << "Max load factor of this map is " << first.max_load_factor() << "." << std::endl;

	
	std::cout << std::endl << "rehash:" << std::endl;
	Output(first, "first");
	std::cout << "Load factor of this map is " << first.load_factor() << "." << std::endl;
	std::cout << "Max load factor of this map is " << first.max_load_factor() << "." << std::endl;
	first.rehash(6);   //There are 11 elements in the map. Though rehash(6), the max_load_factor will still be 16.
	Output(first, "first");  
	std::cout << "Load factor of this map is " << first.load_factor() << "." << std::endl;
	std::cout << "Max load factor of this map is " << first.max_load_factor() << "." << std::endl;



	std::cout << std::endl << "bucket_size:" << first.bucket_count() << std::endl;
	for (size_t i = 0; i < first.bucket_count(); i++)
	{
		std::cout << "Buckets #" << i << " has " << first.bucket_size(i) << " elements." << std::endl;
	}



	std::cout << std::endl << "reserve:" << first.bucket_count() << std::endl;
	first.reserve(30);   //reserve impact bucket_size
	Output(first, "first");
	first.reserve(8);
	Output(first, "first");
}


void UnorderedMapTest::ObserversTest()
{
	std::cout << std::endl << "********ObserversTest********" << std::endl;


	std::unordered_map<std::string, int> first = { {"Old", 11}, {"Yong", 22} };
	std::unordered_map<std::string, int>::hasher hashFunc = first.hash_function();
	std::unordered_map<std::string, int>::key_equal keyEqual = first.key_eq();
	std::unordered_map<std::string, int>::allocator_type alloc = first.get_allocator();
	std::cout << "hasher: " << hashFunc("ObserversTest") << std::endl;
	std::cout << "keyEqual: " << keyEqual("keyEqual", "ObserversTest") << std::endl;
	std::cout << "keyEqual: " << keyEqual("ObserversTest", "ObserversTest") << std::endl;

}


void UnorderedMapTest::ElementAccessTest()
{
	std::cout << std::endl << "********ElementAccessTest********" << std::endl;


	std::unordered_map<std::string, int> first = { {"Old", 11}, {"Yong", 22}, {"Beautful", 22}, {"ugly", 22}, {"fat", 22}, {"thin", 22}, {"tall", 22}, {"short", 22} };
	Output(first, "first");

	for (size_t i = 0; i < first.bucket_count(); i++)
	{
		std::cout << "Bucket #" << i << " has " << first.bucket_size(i) << " elements." << std::endl;
	}



	std::cout << std::endl << "begin(i),end(i):" << std::endl;
	for (size_t i = 0; i < first.bucket_count(); i++)
	{
		for (auto iter = first.begin(i); iter != first.end(i); iter++)
		{
			std::cout << "Bucket #" << i << " (" << iter->first << "," << iter->second << ")" << std::endl;
		}
	}




}


void UnorderedMapTest::Output(std::unordered_map<std::string, int> mymap, std::string name)
{
	//bucket_size of a bucket will be 8/16/32/64...
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



