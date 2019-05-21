#include "pch.h"
#include "multimap_test.h"
#include <queue>
#include <list>
#include <iostream>
#include <iterator>
#include <array>
#include <iomanip> //setprecision()

using namespace STL_Test;

MultimapTest::MultimapTest()
{
}

MultimapTest::~MultimapTest()
{
}

void MultimapTest::ConstructorTest()
{
	std::cout << std::endl << "********ConstructorTest********" << std::endl;


	std::multimap<int, std::string> first;
	//first[0] = "first";    //multimap does not support '[]' operator.
	Output(first, "first ");


	std::multimap<int, std::string> second = { {10, "!"}, {5, "are"}, {8, "you"}, {3, "How"} };
	Output(second, "second");


	std::multimap<int, std::string> third(second);
	Output(third, "third ");


	std::multimap<int, std::string> fourth = third;
	Output(fourth, "fourth");


	std::multimap<int, std::string> fifth(second.cbegin(), second.cend());
	Output(fifth, "fifth ");


}


void MultimapTest::ModifiersTest()
{
	std::cout << std::endl << "********ModifiersTest********" << std::endl;


	std::multimap<int, std::string> first;

	std::cout  << "insert:" << std::endl;
	first.insert({ 1, "Hi" }); //for the second argument("Hi"), function doesn't know if it's char* or std::string.
	//first.insert(2, "little");  // error
	first.insert(std::make_pair(2, ","));
	first.insert(std::make_pair(2, ","));
	first.insert(std::pair<int, std::string>(3, "my")); //std::pair<int, std::string> specifies the arguement types are "int" and "std::string".
	first.insert(std::pair<int, std::string>{int{ 4 }, std::string{ "friend" }});
	Output(first, "first ");


	std::multimap<int, std::string> second = { {5, "laugh"}, {7, "cry"} };
	std::cout << std::endl << "emplace:" << std::endl;
	second.emplace(6, "^_^");
	//second.emplace({ 6, "beautiful" });// error
	Output(second, "second");


	std::cout << std::endl << "emplace_hint:" << std::endl;
	second.emplace_hint(second.find(6), std::pair<int, std::string>(8, "=_="));
	//second.emplace({ 5, "beautiful" });// error
	Output(second, "second");

	
	std::cout << std::endl << "swap:" << std::endl;
	second.swap(first);
	Output(first, "first ");
	Output(second, "second");


	std::cout << std::endl << "erase:" << std::endl;
	second.erase(2);
	second.erase(second.cbegin());
	Output(second, "second");
	first.erase(++first.cbegin(), --first.cend());
	Output(first, "first ");


	std::cout << std::endl << "clear:" << std::endl;
	first.clear();
	second.clear();
	Output(first, "first ");
	Output(second, "second");

}


void MultimapTest::ObserversTest()
{
	std::cout << std::endl << "********ObserversTest********" << std::endl;


	std::multimap<int, std::string> first = { {4, "!"}, {2, "are"}, {3, "you"}, {1, "How"} };
	Output(first, "first ");


	std::cout << std::endl << "key_comp:" << std::endl;
	std::multimap<int, std::string>::iterator it = first.begin();
	int highest = first.rbegin()->first; // the key of the last element of multimap "first".
	std::multimap<int, std::string>::key_compare fMyCompare = first.key_comp();
	do {
		std::cout << (*it).second << " ";
	} while (fMyCompare((*it++).first, highest)); //could not use first.key_comp() directly
	std::cout << std::endl;


	std::cout << std::endl << "value_comp:" << std::endl;
	std::multimap<int, std::string>::iterator iter = first.begin();
	std::pair<int, std::string> last = *first.rbegin(); // the key of the last element of multimap "first".
	do {
		std::cout << (*iter).second << " ";
	} while (first.value_comp()(*iter++, last)); //could not use first.key_comp() directly
	std::cout << std::endl;

}


void MultimapTest::OperationsTest()
{
	std::cout << std::endl << "********OperationsTest********" << std::endl;


	std::multimap<int, std::string> first = { {9, "!"}, {4, "are"}, {7, "you"}, {1, "How"} };
	first.insert(std::pair<int, std::string>(4, "are"));
	Output(first, "first ");


	std::cout << std::endl << "count:" << std::endl;
	int k1 = 4;
	std::cout << "There are " << first.count(k1) << " element(s) with key " << k1 << std::endl;


	std::cout << std::endl << "lower_bound:" << std::endl;
	int k2 = 3;
	std::multimap<int, std::string>::iterator it = first.lower_bound(k2);
	std::cout << "lower_bound of key " << k2 << " is (" << (*it).first << "," << (*it).second << ")" << std::endl;


	std::cout << std::endl << "upper_bound:" << std::endl;
	std::multimap<int, std::string>::iterator iter = first.upper_bound(k2);
	std::cout << "upper_bound of key " << k2 << " is (" << (*iter).first << "," << (*iter).second << ")" << std::endl;


	std::cout << std::endl << "equal_range:" << std::endl;
	int k3 = 4;
	std::pair<std::multimap<int, std::string>::iterator, std::multimap<int, std::string>::iterator> ret;
	ret = first.equal_range(k3); //k1 should be in the range of the keys.
	if (ret.first != std::end(first)) // this is a smart condition to test if "ret" is empty.
	{
		std::cout << "ret.first(" << (*ret.first).first << "," << (*ret.first).second << ")" << " ";
		std::cout << "ret.second(" << (*ret.second).first << "," << (*ret.second).second << ")" << std::endl;
		while ((*ret.first++).first != (*ret.second).first)
		{
			std::cout << (*ret.first).first << "," << (*ret.first).second << " ";
		}
		std::cout << std::endl;
	}
	else
	{
		std::cout << "key " << k3 << " is not in this multimap." << std::endl;
	}
}



void MultimapTest::Output(std::multimap<int, std::string>& myMultimap, std::string name)
{
	std::cout << name << "(" << myMultimap.size() << ",0x" << std::hex << myMultimap.max_size() << std::dec << ")" << " : ";
	if (myMultimap.empty())
	{
		std::cout << "empty";
	}
	else
	{
		for (auto it = myMultimap.cbegin(); it != myMultimap.cend(); it++)
		{
			std::cout << "(" << it->first << "," << std::setw(3) << it->second << ") ";
		}
	}
	std::cout << std::endl;
}



void MultimapTest::OutputR(std::multimap<int, std::string>& myMultimap, std::string name)
{
	std::cout << name << "(" << myMultimap.size() << ",0x" << std::hex << myMultimap.max_size() << std::dec << ")" << " : ";
	if (myMultimap.empty())
	{
		std::cout << "empty";
	}
	else
	{
		for (auto it = myMultimap.crbegin(); it != myMultimap.crend(); it++)
		{
			std::cout << "(" << it->first << "," << it->second << ") ";
		}
	}
	std::cout << std::endl;
}



void MultimapTest::Output(std::multimap<int, double>& myMultimap, std::string name)
{
	std::cout << name << "(" << myMultimap.size() << ",0x" << std::hex << myMultimap.max_size() << std::dec << ")" << " : ";
	if (myMultimap.empty())
	{
		std::cout << "empty";
	}
	else
	{
		for (auto it = myMultimap.cbegin(); it != myMultimap.cend(); it++)
		{
			std::cout << "(" << std::setw(5) << it->first << "," << std::setw(5) << it->second << ") ";
		}
	}
	std::cout << std::endl;
}

//void MultimapTest::Output(std::map<std::string, double, std::greater<std::string>> myMultimap, std::string name)
//{
//	std::cout << name << "(" << myMultimap.size() << ",0x" << std::hex << myMultimap.max_size() << std::dec << ")" << " : ";
//	if (myMultimap.empty())
//	{
//		std::cout << "empty";
//	}
//	else
//	{
//		for (auto it = myMultimap.cbegin(); it != myMultimap.cend(); it++)
//		{
//			std::cout << "(" << std::setw(5) << it->first << "," << std::setw(5) << it->second << ") ";
//		}
//	}
//	std::cout << std::endl;
//}


