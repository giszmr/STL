#include "pch.h"
#include "miscellaneous_test.h"
#include <functional>




using namespace STL_Test;

void MiscellaneousTest::IotaTest()
{
	std::cout << "\n***********IotaTest***********" << std::endl;


	int val = -1;
	std::vector<int> first(10);
	std::iota(first.begin(), first.end(), val);
	Output(first, "first ");


	double dval = -3.1;
	std::vector<double> second(10);
	std::iota(second.begin(), second.end(), dval);
	Output(second, "second");


	char cval = 'A';
	std::vector<char> third(10);
	std::iota(third.begin(), third.end(), cval);
	Output(third, "third ");


	const char *sval = "Hello,everybody!";
	std::vector<std::string> fourth(10);
	std::iota(fourth.begin(), fourth.end(), sval);
	Output(fourth, "fourth");

}


int myfunc(int x, int y)
{
	return x + 2 * y;
}
struct myobject
{
	int operator()(int x, int y)
	{
		return x + 3 * y;
	}
}myobj;
void MiscellaneousTest::AccumulateTest()
{
	std::cout << "\n***********AccumulateTest***********" << std::endl;


	int ival = 200;
	int numbers[] = { 10, 20, 30 };

	std::cout << "using default accumulate: ";
	std::cout << std::accumulate(numbers, numbers + sizeof(numbers) / sizeof(int), ival);
	std::cout << "\n";

	std::cout << "using functional's minus: ";
	std::cout << std::accumulate(numbers, numbers + sizeof(numbers) / sizeof(int), ival, std::minus<int>());
	std::cout << "\n";

	std::cout << "using custom function: ";
	std::cout << std::accumulate(numbers, numbers + sizeof(numbers) / sizeof(int), ival, myfunc);
	std::cout << "\n";

	std::cout << "using default object: ";
	std::cout << std::accumulate(numbers, numbers + sizeof(numbers) / sizeof(int), ival, myobj);
	std::cout << "\n";



	std::string myinit = "mystring: ";
	std::vector<std::string> mystring = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten" };
	//lambda expression: the fourth parameter.
	auto sss = std::accumulate(mystring.begin(), mystring.end(), myinit, [](std::string str, std::string& element)
	{
		if (element[0] == 't')
			return str + "," + element;
		return str;
	});
	std::cout << sss << std::endl;
}

int myfunc1(int x, int y) { return x - y; }
int myfunc2(int x, int y) { return x + y; }
void MiscellaneousTest::InnerProductTest()
{
	std::cout << "\n***********InnerProductTest***********" << std::endl;



	std::vector<int> first(5);
	std::vector<int> second(5);
	Output(first, "first ");
	Output(second, "second");


	std::iota(first.begin(), first.end(), 2);
	std::iota(second.begin(), second.end(), 3);
	Output(first, "first ");
	Output(second, "second");

	std::cout << "default(init=0): ";
	std::cout << std::inner_product(first.begin(), first.end(), second.begin(), 0);
	std::cout << "\n";
	std::cout << "default(init=1): ";
	std::cout << std::inner_product(first.begin(), first.end(), second.begin(), 1);
	std::cout << "\n";


	std::cout << "default(init=0): ";
	std::cout << std::inner_product(first.begin(), first.end(), second.begin(), 0, myfunc1, myfunc2);
	std::cout << "\n";
	std::cout << "default(init=1): ";
	std::cout << std::inner_product(first.begin(), first.end(), second.begin(), 1, myfunc1, myfunc2);
	std::cout << "\n";

/*
***********InnerProductTest***********
first : (  5,  5,3fffffff) 0 0 0 0 0
second: (  5,  5,3fffffff) 0 0 0 0 0
first : (  5,  5,3fffffff) 2 3 4 5 6
second: (  5,  5,3fffffff) 3 4 5 6 7
default(init=0): 110
default(init=1): 111
default(init=0): -45   // = ( (2-3), (3-4), (4-5), (5-6), (6-7) ) x ( (2+3), (3+4), (4+5), (5+6), (6+7) )
default(init=1): -44
*/
}



void MiscellaneousTest::Output(std::vector<int>& myVector, std::string name)
{
	std::cout << name << ": ";
	if (!myVector.empty())
	{
		std::cout << "(" << std::setw(3) << myVector.size() << "," << std::setw(3) << myVector.capacity() << "," << std::setw(3) << std::hex << myVector.max_size() << std::dec << ") ";
		for (size_t i = 0; i < myVector.size(); i++) std::cout << myVector[i] << " ";
		std::cout << std::endl;
	}
	else
	{
		std::cout << name << " is empty." << std::endl;
	}
}

void MiscellaneousTest::Output(std::vector<double>& myVector, std::string name)
{
	std::cout << name << ": ";
	if (!myVector.empty())
	{
		std::cout << "(" << std::setw(3) << myVector.size() << "," << std::setw(3) << myVector.capacity() << "," << std::setw(3) << std::hex << myVector.max_size() << std::dec << ") ";
		for (size_t i = 0; i < myVector.size(); i++) std::cout << myVector[i] << " ";
		std::cout << std::endl;
	}
	else
	{
		std::cout << name << " is empty." << std::endl;
	}
}

void MiscellaneousTest::Output(std::vector<char>& myVector, std::string name)
{
	std::cout << name << ": ";
	if (!myVector.empty())
	{
		std::cout << "(" << std::setw(3) << myVector.size() << "," << std::setw(3) << myVector.capacity() << "," << std::setw(3) << std::hex << myVector.max_size() << std::dec << ") ";
		for (size_t i = 0; i < myVector.size(); i++) std::cout << myVector[i] << " ";
		std::cout << std::endl;
	}
	else
	{
		std::cout << name << " is empty." << std::endl;
	}
}

void MiscellaneousTest::Output(std::vector<std::string>& myVector, std::string name)
{
	std::cout << name << ": ";
	if (!myVector.empty())
	{
		std::cout << "(" << std::setw(3) << myVector.size() << "," << std::setw(3) << myVector.capacity() << "," << std::setw(3) << std::hex << myVector.max_size() << std::dec << ") ";
		for (size_t i = 0; i < myVector.size(); i++) std::cout << myVector[i] << " ";
		std::cout << std::endl;
	}
	else
	{
		std::cout << name << " is empty." << std::endl;
	}
}