#include "pch.h"
#include "set_test.h"
#include <iomanip>
#include <algorithm>
#include <iterator>


using namespace STL_Test;


void SetTest::ConstructorTest()
{
	std::cout << std::endl << "********ConstructorTest********" << std::endl;



	std::set<int> first;
	Output(first, "first");

	
	std::set<int> second = { 4,5,6 };
	Output(second, "second");
	for (auto iter= second.begin(); iter!= second.end();iter++)
	{
		//*iter = 10;    //compling error. iter is const.
	}


	double mydoubles[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	std::set<double> third(mydoubles, mydoubles + sizeof(mydoubles) / sizeof(double));
	Output(third, "third");


	std::set<int> fourth(second);
	Output(fourth, "fourth");


	std::set<int> fifth(second.begin(), second.end());
	Output(fifth, "fifth");


	std::set<double, std::greater<double>> sixth{ 1.1, 3.3, 0.2, 4.5 };
	Output(sixth, "sixth");


	

	//汽车对引擎用强引用，引擎对汽车用弱引用。delete引擎并不会析构引擎，只有析构汽车时才会析构引擎
	//实现一下
}


void SetTest::ModifiersTest()
{
	std::cout << std::endl << "********ModifiersTest********" << std::endl;


	std::set<double> second = { 4.0, 5.0, 6.0 };
	Output(second, "second");
	for (auto iter = second.begin(); iter != second.end(); iter++)
	{
		//*iter = 10;    //compling error. iter is const.
	}


	double mydoubles[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	std::set<double> third(mydoubles, mydoubles + sizeof(mydoubles) / sizeof(double));
	Output(third, "third");


	std::cout << std::endl << "swap:" << std::endl;
	second.swap(third);
	Output(second, "second");
	Output(third, "third");


	std::cout << std::endl << "erase:" << std::endl;
	second.erase(3.3);
	second.erase(++second.begin());
	second.erase(second.find(4.4));
	third.erase(third.begin(), third.end());
	Output(second, "second");
	Output(third, "third");


}


void SetTest::SetUnionTest()
{
	std::cout << std::endl << "********SetUnionTest********" << std::endl;

	std::set<int> first = { 1, 2, 4, 3, 5 };
	std::set<int> second = { 9, 20, 7, 6, 8, 4, 5 };
	std::set<int> third;
	int myints[20] = {0};


	std::set_union(first.begin(), first.end(), second.begin(), second.end(), std::ostream_iterator<int> {std::cout, " "}); // ostream
	std::cout << std::endl;

	std::set_union(first.begin(), first.end(), second.begin(), second.end(), std::inserter(third, third.begin()));  // std::inserter()
	Output(third, "third");

	std::set_union(first.begin(), first.end(), second.begin(), second.end(), myints);   // array
	for (int i = 0; i < 20; i++)
	{
		std::cout << myints[i] << " ";
	}
	std::cout << std::endl;



	//////////////////////////
	std::set<int, std::greater<int>> fourth = { 1, 2, 4, 3, 5 };
	std::set<int, std::greater<int>> fifth = { 9, 20, 7, 6, 8, 4, 5 };
	std::set<int, std::greater<int>> sixth;

	std::set_union(fourth.begin(), fourth.end(), fifth.begin(), fifth.end(), std::inserter(sixth, sixth.begin()), std::greater<int>());  // std::inserter()
	Output(sixth, "sixth");

}

void SetTest::SetIntersectionTest()
{
	std::cout << std::endl << "********SetIntersectionTest********" << std::endl;


	std::set<int, std::greater<int>> fourth = { 1, 2, 4, 3, 5 };
	std::set<int, std::greater<int>> fifth = { 9, 20, 7, 6, 8, 4, 5, 3 };
	std::set<int, std::greater<int>> sixth;
	std::set<int, std::greater<int>> seventh;
	std::set<int, std::greater<int>> eighth;


	std::cout << "set_intersection:" << std::endl;
	std::set_intersection(fourth.begin(), fourth.end(), fifth.begin(), fifth.end(), std::inserter(sixth, sixth.begin()), std::greater<int>());  // intersection
	Output(fourth, "fourth");
	Output(fifth, "fifth");
	Output(sixth, "sixth");


	std::cout << "set_difference:" << std::endl;
	std::set_difference(fourth.begin(), fourth.end(), fifth.begin(), fifth.end(), std::inserter(seventh, seventh.begin()), std::greater<int>());  // elements in "forth", which are different with "fifth"
	Output(fourth, "fourth");
	Output(fifth, "fifth");
	Output(seventh, "seventh");


	std::cout << "set_symmetric_difference:" << std::endl;
	std::set_symmetric_difference(fourth.begin(), fourth.end(), fifth.begin(), fifth.end(), std::inserter(eighth, eighth.begin()), std::greater<int>());  // elements in "fifth", which are different with "fourth"
	Output(fourth, "fourth");
	Output(fifth, "fifth");
	Output(eighth, "eighth");
}



void SetTest::Output(std::set<int> mySet, std::string name)
{
	std::cout << std::setw(7)  << name << "(" << mySet.size() << ",0x" << std::hex << mySet.max_size() << std::dec << ")" << " : ";
	if (mySet.empty())
	{
		std::cout << "empty";
	}
	else
	{
		for (auto it = mySet.cbegin(); it != mySet.cend(); it++)
		{
			std::cout << *it  << " ";
		}
	}
	std::cout << std::endl;
}



void SetTest::Output(std::set<int, std::greater<int>> mySet, std::string name)
{
	std::cout << std::setw(7) << name << "(" << mySet.size() << ",0x" << std::hex << mySet.max_size() << std::dec << ")" << " : ";
	if (mySet.empty())
	{
		std::cout << "empty";
	}
	else
	{
		for (auto it = mySet.cbegin(); it != mySet.cend(); it++)
		{
			std::cout << *it << " ";
		}
	}
	std::cout << std::endl;
}




void SetTest::Output(std::set<double> mySet, std::string name)
{
	std::cout << std::setw(7) << name << "(" << mySet.size() << ",0x" << std::hex << mySet.max_size() << std::dec << ")" << " : ";
	if (mySet.empty())
	{
		std::cout << "empty";
	}
	else
	{
		for (auto it = mySet.cbegin(); it != mySet.cend(); it++)
		{
			std::cout << *it << " ";
		}
	}
	std::cout << std::endl;
}




void SetTest::Output(std::set<double, std::greater<double>> mySet, std::string name)
{
	std::cout << std::setw(7) << name << "(" << mySet.size() << ",0x" << std::hex << mySet.max_size() << std::dec << ")" << " : ";
	if (mySet.empty())
	{
		std::cout << "empty";
	}
	else
	{
		for (auto it = mySet.cbegin(); it != mySet.cend(); it++)
		{
			std::cout << *it << " ";
		}
	}
	std::cout << std::endl;
}