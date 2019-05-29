#include "pch.h"
#include "map_test.h"
#include <queue>
#include <list>
#include <iostream>
#include <iterator>
#include <array>
#include <iomanip> //setprecision()

using namespace STL_Test;

MapTest::MapTest()
{
}

MapTest::~MapTest()
{
}

void MapTest::ConstructorTest()
{
	std::cout << std::endl << "********ConstructorTest********" << std::endl;
	std::map<char, int> first;
	first['a'] = 97;
	first['d'] = 100;
	first['c'] = 99;
	first['b'] = 98;    //map[]
	Output(first, "first ");  //pay attention to the order
	
	first.at('d') = 88;    //map.at()
	Output(first, "first ");

	std::map<char, int> second(first.cbegin(), first.cend());
	Output(second, "second");

	std::map<char, int> third(second);
	Output(third, "third ");

	//std::map<char, int> fourth( std::make_pair('e', 101), std::make_pair('f', 102), std::make_pair('g', 103) );  //cannot convert from 'std::pair<char,int>' to 'const std::less<_Kty>'
	std::map<char, int> fourth = { std::make_pair('e', 101), std::make_pair('f', 102), std::make_pair('g', 103) };
	//or	std::map<char, int> fourth { std::make_pair('e', 101), std::make_pair('f', 102), std::make_pair('g', 103) };
	Output(fourth, "fourth");
	OutputR(fourth, "fourth");

	std::map<char, int> fifth = { {'h', 104}, {'i', 105}, {'j', 106} };
	//or 	std::map<char, int> fifth { {'h', 104}, {'i', 105}, {'j', 106} };
	Output(fifth, "fifth ");

	std::map<char, int> sixth = fifth;
	Output(sixth, "sixth ");

	std::map<char, int> seventh;
	Output(seventh, "seventh");

	std::map<char, int> eighth = std::map<char, int>();
	Output(eighth, "eighth ");

}


void MapTest::ModifiersTest()
{
	std::cout << std::endl << "********ConstructorTest********" << std::endl;

	
	std::cout << "greater:" << std::endl;
	std::map<std::string, double, std::greater<std::string>> first = { {"John", 150.2}, {"Joe", 200.5}, {"Ross", 180.1} };    //use my "key_compare"
	Output(first, "first");//(Joe,200) (John,150) (Ross,180) //pay attention to the order



	std::cout << std::endl << "insert:" << std::endl;
	first.insert(std::pair<std::string, double>("Richo", 100.9));    // return std::pair<std::map<std::string, double>::iterator, bool>
	Output(first, "first");

	//The function optimizes its insertion time if position points to the element that will follow the inserted element (or to the end, if it would be the last).
	first.insert(first.find("Richo"), std::pair<std::string, double>("Alex", 99.8));   //Could not return std::pair<std::map<std::string, double>::iterator, bool>
	Output(first, "first");

	std::pair<std::map<std::string, double>::iterator, bool> ret;
	ret = first.insert(std::pair<std::string, double>("Alex", 99.8));
	if (ret.second)
		Output(first, "first");
	else
		std::cout << "Failed to insert same element" << "(" << ret.first->first << "," << ret.first->second << ")!" << std::endl;
	


	std::cout << std::endl << "default(less):" << std::endl;
	std::map<std::string, double> second = { {"Cand", 222.8}, {"Holy", 59.3} };   //use default "key_compare"(std::less<>)
	Output(second, "second");

	

	std::cout << std::endl << "swap:" << std::endl;
	std::map<std::string, double, std::greater<std::string>> third = { {"Red", 30.3} };
	Output(third, "third");
	third.swap(first);
	Output(first, "first");
	Output(third, "third");



	std::cout << std::endl << "emplace:" << std::endl;
	first.emplace(std::make_pair("Sally", 30.9));
	first.emplace(std::make_pair("Blue", 30.9));
	Output(first, "first");


	std::cout << std::endl << "emplace_hint:" << std::endl;
	first.emplace_hint(first.find("Red"), std::make_pair("Tully", 30.9));
	Output(first, "first");


	std::cout << std::endl << "erase:" << std::endl;
	third.erase("Joe");
	Output(third, "third");
	third.erase(third.find("John"));
	Output(third, "third");
	third.erase(third.cbegin());
	Output(third, "third");
	first.erase(++first.cbegin(), --first.cend());
	Output(first, "first");



	std::cout << std::endl << "clear:" << std::endl;
	first.clear();
	Output(first, "first");
}


void MapTest::ObserversTest()
{
	std::cout << std::endl << "********ObserversTest********" << std::endl;

	std::map<std::string, double, std::greater<std::string>> first = { {"John", 150.2}, {"Joe", 200.5}, {"Ross", 180.1} };    //use my "key_compare"
	std::map<std::string, double> second = { {"Cand", 222.8}, {"Holy", 59.3} };   //use default "key_compare"(std::less<>)


	std::cout << "key_compare value_compare:" << std::endl;
	std::map<std::string, double, std::greater<std::string>>::key_compare myComp = first.key_comp();   //?????? If I know the key_compare, why should I get it in this way?
	std::map<std::string, double, std::greater<std::string>>::value_compare myValComp = first.value_comp();
	std::map<std::string, double>::key_compare myComp2 = second.key_comp();
	std::map<std::string, double>::value_compare myValComp2 = second.value_comp();
	std::cout << "first : " << &myComp << " " << &myValComp  << std::endl;
	std::cout << "second: " << &myComp2 << " " << &myValComp2  << std::endl;
}


void MapTest::OperationsTest()
{
	std::cout << std::endl << "********OperationsTest********" << std::endl;


	std::cout << "lower/upper_bound:" << std::endl;
	std::map<std::string, double, std::greater<std::string>> first = { {"John", 150.2}, {"Joe", 200.5}, {"Ross", 180.1} };    //use my "key_compare"
	Output(first, "first");
	std::map<std::string, double>::iterator itLower, itUpper;
	itLower = first.lower_bound("John");   //itLower point to {"John", 150.2}
	itUpper = first.upper_bound("John");   //itUpper point
	std::cout << "lower_bound: " << itLower->first << "," << itLower->second << std::endl;
	std::cout << "upper_bound: " << itUpper->first << "," << itUpper->second << std::endl;



	std::cout << std::endl << "equal_range:" << std::endl;
	std::pair<std::map<std::string, double>::iterator, std::map<std::string, double>::iterator> ret;
	ret = first.equal_range("Ross");
	std::cout << "first : " << ret.first->first << "," << ret.first->second << std::endl;
	std::cout << "second: " << ret.second->first << "," << ret.second->second << std::endl;
}



void MapTest::Output(std::map<char, int>& mymap, std::string name)
{
	std::cout << name << "(" << mymap.size() << ",0x" << std::hex << mymap.max_size() << std::dec << ")" << " : ";
	if (mymap.empty())
	{
		std::cout << "empty";
	}
	else
	{
		for (auto it = mymap.cbegin(); it != mymap.cend(); it++)
		{
			std::cout << "(" << it->first << "," << std::setw(3) << it->second << ") ";
		}
	}
	std::cout << std::endl;
}



void MapTest::OutputR(std::map<char, int>& mymap, std::string name)
{
	std::cout << name << "(" << mymap.size() << ",0x" << std::hex << mymap.max_size() << std::dec << ")" << " : ";
	if (mymap.empty())
	{
		std::cout << "empty";
	}
	else
	{
		for (auto it = mymap.crbegin(); it != mymap.crend(); it++)
		{
			std::cout << "(" << it->first << "," << it->second << ") ";
		}
	}
	std::cout << std::endl;
}



void MapTest::Output(std::map<std::string, double>& mymap, std::string name)
{
	std::cout << name << "(" << mymap.size() << ",0x" << std::hex << mymap.max_size() << std::dec << ")" << " : ";
	if (mymap.empty())
	{
		std::cout << "empty";
	}
	else
	{
		for (auto it = mymap.cbegin(); it != mymap.cend(); it++)
		{
			std::cout << "(" << std::setw(5) << it->first << "," << std::setw(5) << it->second << ") ";
		}
	}
	std::cout << std::endl;
}

void MapTest::Output(std::map<std::string, double, std::greater<std::string>>& mymap, std::string name)
{
	std::cout << name << "(" << mymap.size() << ",0x" << std::hex << mymap.max_size() << std::dec << ")" << " : ";
	if (mymap.empty())
	{
		std::cout << "empty";
	}
	else
	{
		for (auto it = mymap.cbegin(); it != mymap.cend(); it++)
		{
			std::cout << "(" << std::setw(5) << it->first << "," << std::setw(5) << it->second << ") ";
		}
	}
	std::cout << std::endl;
}


