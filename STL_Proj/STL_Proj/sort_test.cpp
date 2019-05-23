#include "pch.h"
#include <iomanip>
#include <algorithm>
#include <iterator>
#include "sort_test.h"


using namespace STL_Test;



void SortTest::DefaultSortTest()
{
	std::cout << "****************DefaultSortTest*****************" << std::endl;

	std::vector<int> first{ 3, 1, 100, 60, 70, 88, 21, 23, 4, 90, 86 };
	Output(first, "first");
	std::sort(first.begin(), first.end());
	Output(first, "first");
	std::sort(first.begin(), first.end(), std::greater<int>());
	Output(first, "first");

	std::cout << "\n--begin vector<Price> test:" << std::endl;
	std::cout << "\nConstruct Price objects:" << std::endl;
	Price p1(1, 100);
	Price p2(2, 200);
	Price p3(3, 300);
	Price p4(3, 400);
	Price p5(5, 500);
	Price p6(6, 600);
	std::cout << "\nDefine vector<Price>:" << std::endl;
	std::vector<Price> second;
	std::cout << "\nreserve vector<Price>:" << std::endl;
	second.reserve(10);
	std::cout << "\ninsert vector<Price>:" << std::endl;
	second.insert(second.end(), p6);
	std::cout << "\nemplace vector<Price>:" << std::endl;
	second.emplace(second.end(), p5);
	std::cout << "\npush_back vector<Price>:" << std::endl;
	second.push_back(p4);
	std::cout << "\nmove vector<Price>:" << std::endl;
	second.push_back(std::move(p3));
	second.push_back(p2);
	second.push_back(p1);
	std::cout << "\noutput vector<Price>:" << std::endl;
	Output(second, "second");
	std::cout << "\nsort vector<Price>:" << std::endl;
	std::sort(second.begin(), second.end());
	std::cout << "\noutput vector<Price>:" << std::endl;
	Output(second, "second");
	std::cout << "\n--end vector<Price> test:" << std::endl;

}


void SortTest::StableSortTest()
{
	std::cout << "****************StableSortTest*****************" << std::endl;


	std::cout << "\n--begin vector<Price> test:" << std::endl;
	Price p1(1, 100);
	Price p2(2, 200);
	Price p3(3, 300);
	Price p4(3, 400);
	Price p5(5, 500);
	Price p6(6, 600);
	std::vector<Price> second;
	second.reserve(10);
	second.push_back(p6);
	second.push_back(p5);
	second.push_back(p4);
	second.push_back(p3);
	second.push_back(p2);
	second.push_back(p1);
	std::cout << "\noutput vector<Price>:" << std::endl;
	Output(second, "second");
	std::cout << "\nsort vector<Price>:" << std::endl;
	std::stable_sort(second.begin(), second.end());
	std::cout << "\noutput vector<Price>:" << std::endl;
	Output(second, "second");
	std::cout << "\n--end vector<Price> test:" << std::endl;
}

void SortTest::PartialSortTest()
{

}

void SortTest::ParticalSortCopyTest()
{

}





void SortTest::Output(std::vector<int>& myVector, std::string name)
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

void SortTest::Output(std::vector<Price>& myVector, std::string name)
{
	std::cout << name << ": ";
	if (!myVector.empty())
	{
		std::cout << "(" << std::setw(3) << myVector.size() << "," << std::setw(3) << myVector.capacity() << "," << std::setw(3) << std::hex << myVector.max_size() << std::dec << ") ";
		for (size_t i = 0; i < myVector.size(); i++) 
			std::cout << "(" << myVector[i].GetValue() << "," << myVector[i].GetAdditionalValue() << ") ";
		std::cout << std::endl;
	}
	else
	{
		std::cout << name << " is empty." << std::endl;
	}
}


void SortTest::Output(std::vector<double>& myVector, std::string name)
{

}

void SortTest::Output(std::vector<std::string>& myVector, std::string name)
{

}

