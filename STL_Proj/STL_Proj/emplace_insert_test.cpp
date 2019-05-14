#include "pch.h"
#include "emplace_insert_test.h"
#include <Windows.h>
#include <iomanip>

using namespace STL_Test;


MyBook::MyBook()
	:m_name(""), m_price(0.0)
{
	std::cout << std::left << std::setw(19) << "Default Constructor" << std::endl;
}

MyBook::MyBook(std::string name, double price)
	:m_name(name), m_price(price)
{
	std::cout << std::left << std::setw(19) << "Constructor: " << "(" << std::setw(18) << (m_name.empty() ? std::string("NULL") : m_name) << "," << m_price << ")" << std::endl;
}

MyBook::MyBook(const MyBook& rhs) //should be const
	:m_name(rhs.m_name), m_price(rhs.m_price)
{
	std::cout << std::left << std::setw(19) << "Copy Constructor: " << "(" << std::setw(18) << (m_name.empty() ? std::string("NULL") : m_name) << "," << m_price << ")" << std::endl;
}

MyBook::~MyBook()
{
	std::cout <<std::left <<std::setw(19) << "Deconstructor: " << "(" << std::setw(18) << (m_name.empty() ? std::string("NULL") : m_name) << "," << m_price << ")" << std::endl;
}






EmaplaceInsertTest::EmaplaceInsertTest()
{
}

EmaplaceInsertTest::~EmaplaceInsertTest()
{
}

void EmaplaceInsertTest::Test()
{
	std::cout << "------begin--------" << std::endl;

	std::vector<MyBook> myVector;
	myVector.reserve(100);

	//MyBook myBook("Sam Will", 9.9);


	std::cout << std::endl << "resize(3):" << std::endl;
	myVector.resize(3); //Default Constructor
	std::cout << "------" << std::endl;




	std::cout << std::endl << "push_back:" << std::endl;
	//myVector.push_back(MyBook("Red Stone", 3.3));
	//myVector.push_back(myBook);  //Copy Constructor
	myVector.push_back({ "Red Stone", 1.0 });
	std::cout << "------" << std::endl;




	std::cout << std::endl << "emplace_back:" << std::endl;
	//myVector.emplace_back(MyBook("Kate Runner", 5.6));  //Constructor & Copy Constructor
	//myVector.emplace_back(myBook);  //Copy Constructor
	myVector.emplace_back("Kite Runner", 2.0);
	std::cout << "------" << std::endl;




	std::cout << std::endl << "insert:" << std::endl;
	//myVector.insert(myVector.cend(), MyBook("Gone With the Wind", 2.1));  //Constructor & Copy Constructor
	//myVector.insert(myVector.cend(), myBook);  //Copy Constructor
	myVector.insert(myVector.cend(), { "Gone With the Wind", 3.0 });
	std::cout << "------" << std::endl;



	std::cout << std::endl << "emplace:" << std::endl;
	//myVector.emplace(myVector.cend(), MyBook("Twilight", 4.2));  //Constructor & Copy Constructor
	//myVector.emplace(myVector.cend(), myBook);  //Copy Constructor
	myVector.emplace(myVector.cend(), "Twilight", 4.0);
	std::cout << "------" << std::endl;



	OutputIndex(myVector);



	std::cout << std::endl << "insert:" << std::endl;
	myVector.insert(++myVector.cbegin(), { "Helo", 5.0 });
	std::cout << "------" << std::endl;




	OutputIndex(myVector);



	std::cout << std::endl << "resize(10):" << std::endl;
	myVector.resize(10); //Default Constructor
	std::cout << "------" << std::endl;



	OutputIndex(myVector);


	std::cout << std::endl << "insert:" << std::endl;
	myVector.insert(myVector.cbegin(), { "Adel", 5.0 });
	std::cout << "------" << std::endl;


	OutputIndex(myVector);




	std::cout << std::endl << "resize(3):" << std::endl;
	myVector.resize(3); //Default Constructor
	std::cout << "------" << std::endl;


	std::cout << std::endl << "Compare(OutputIndex,OutputIter):" << std::endl;
	OutputIndex(myVector);
	std::cout << "------" << std::endl;
	OutputIter(myVector);
	std::cout << "------" << std::endl;





	std::cout << std::endl << "------end--------" << std::endl;

}


void EmaplaceInsertTest::OutputIter(std::vector<MyBook> myVector)
{
	std::cout  << "OOOOOOOOutputIter:" << std::endl;
	for (auto iter : myVector)
	{
		std::cout << std::right << std::setw(20) << "(" << std::left << std::setw(18) << (iter.GetName().empty() ? "NULL" : iter.GetName()) << "," << iter.GetPrice() << ")" << std::endl;
	}
}


void EmaplaceInsertTest::OutputIndex(std::vector<MyBook> myVector)
{
	std::cout  << "OOOOOOOOutputIndex:" << std::endl;
	for (int i = 0; i < myVector.size(); i++)
	{
		std::cout << std::right << std::setw(20) << "(" << std::left << std::setw(18)<< (myVector[i].GetName().empty() ? "NULL" : myVector[i].GetName()) << "," << myVector[i].GetPrice() << ")" << std::endl;
	}
}






/*
======================================
======================================
------begin--------

resize(3):
Default Constructor
Default Constructor
Default Constructor
------

push_back:
Constructor:       (Red Stone         ,1)
Copy Constructor:  (Red Stone         ,1)
Deconstructor:     (Red Stone         ,1)
------

emplace_back:
Constructor:       (Kite Runner       ,2)
------

insert:
Constructor:       (Gone With the Wind,3)
Copy Constructor:  (Gone With the Wind,3)
Deconstructor:     (Gone With the Wind,3)
------

emplace:
Constructor:       (Twilight          ,4)
------
Copy Constructor:  (NULL              ,0)
Copy Constructor:  (NULL              ,0)
Copy Constructor:  (NULL              ,0)
Copy Constructor:  (Red Stone         ,1)
Copy Constructor:  (Kite Runner       ,2)
Copy Constructor:  (Gone With the Wind,3)
Copy Constructor:  (Twilight          ,4)
OOOOOOOOutputIndex:
				   (NULL              ,0)
				   (NULL              ,0)
				   (NULL              ,0)
				   (Red Stone         ,1)
				   (Kite Runner       ,2)
				   (Gone With the Wind,3)
				   (Twilight          ,4)
Deconstructor:     (NULL              ,0)
Deconstructor:     (NULL              ,0)
Deconstructor:     (NULL              ,0)
Deconstructor:     (Red Stone         ,1)
Deconstructor:     (Kite Runner       ,2)
Deconstructor:     (Gone With the Wind,3)
Deconstructor:     (Twilight          ,4)

insert:
Constructor:       (Helo              ,5)
Copy Constructor:  (Helo              ,5)
Copy Constructor:  (Twilight          ,4)               //zmr: Why copy the last element in 'myVector'?
Deconstructor:     (Helo              ,5)
Deconstructor:     (Helo              ,5)               //zmr: Why deconstruct 'Helo' twice?
------
Copy Constructor:  (NULL              ,0)
Copy Constructor:  (Helo              ,5)
Copy Constructor:  (NULL              ,0)
Copy Constructor:  (NULL              ,0)
Copy Constructor:  (Red Stone         ,1)
Copy Constructor:  (Kite Runner       ,2)
Copy Constructor:  (Gone With the Wind,3)
Copy Constructor:  (Twilight          ,4)
OOOOOOOOutputIndex:
				   (NULL              ,0)
				   (Helo              ,5)
				   (NULL              ,0)
				   (NULL              ,0)
				   (Red Stone         ,1)
				   (Kite Runner       ,2)
				   (Gone With the Wind,3)
				   (Twilight          ,4)
Deconstructor:     (NULL              ,0)
Deconstructor:     (Helo              ,5)
Deconstructor:     (NULL              ,0)
Deconstructor:     (NULL              ,0)
Deconstructor:     (Red Stone         ,1)
Deconstructor:     (Kite Runner       ,2)
Deconstructor:     (Gone With the Wind,3)
Deconstructor:     (Twilight          ,4)

resize(10):
Default Constructor
Default Constructor
------
Copy Constructor:  (NULL              ,0)
Copy Constructor:  (Helo              ,5)
Copy Constructor:  (NULL              ,0)
Copy Constructor:  (NULL              ,0)
Copy Constructor:  (Red Stone         ,1)
Copy Constructor:  (Kite Runner       ,2)
Copy Constructor:  (Gone With the Wind,3)
Copy Constructor:  (Twilight          ,4)
Copy Constructor:  (NULL              ,0)
Copy Constructor:  (NULL              ,0)
OOOOOOOOutputIndex:
				   (NULL              ,0)
				   (Helo              ,5)
				   (NULL              ,0)
				   (NULL              ,0)
				   (Red Stone         ,1)
				   (Kite Runner       ,2)
				   (Gone With the Wind,3)
				   (Twilight          ,4)
				   (NULL              ,0)
				   (NULL              ,0)
Deconstructor:     (NULL              ,0)
Deconstructor:     (Helo              ,5)
Deconstructor:     (NULL              ,0)
Deconstructor:     (NULL              ,0)
Deconstructor:     (Red Stone         ,1)
Deconstructor:     (Kite Runner       ,2)
Deconstructor:     (Gone With the Wind,3)
Deconstructor:     (Twilight          ,4)
Deconstructor:     (NULL              ,0)
Deconstructor:     (NULL              ,0)

insert:
Constructor:       (Adel              ,5)
Copy Constructor:  (Adel              ,5)
Copy Constructor:  (NULL              ,0)               //zmr: Why copy the last element in 'myVector'?
Deconstructor:     (Adel              ,5)
Deconstructor:     (Adel              ,5)
------
Copy Constructor:  (Adel              ,5)
Copy Constructor:  (NULL              ,0)
Copy Constructor:  (Helo              ,5)
Copy Constructor:  (NULL              ,0)
Copy Constructor:  (NULL              ,0)
Copy Constructor:  (Red Stone         ,1)
Copy Constructor:  (Kite Runner       ,2)
Copy Constructor:  (Gone With the Wind,3)
Copy Constructor:  (Twilight          ,4)
Copy Constructor:  (NULL              ,0)
Copy Constructor:  (NULL              ,0)
OOOOOOOOutputIndex:
				   (Adel              ,5)
				   (NULL              ,0)
				   (Helo              ,5)
				   (NULL              ,0)
				   (NULL              ,0)
				   (Red Stone         ,1)
				   (Kite Runner       ,2)
				   (Gone With the Wind,3)
				   (Twilight          ,4)
				   (NULL              ,0)
				   (NULL              ,0)
Deconstructor:     (Adel              ,5)
Deconstructor:     (NULL              ,0)
Deconstructor:     (Helo              ,5)
Deconstructor:     (NULL              ,0)
Deconstructor:     (NULL              ,0)
Deconstructor:     (Red Stone         ,1)
Deconstructor:     (Kite Runner       ,2)
Deconstructor:     (Gone With the Wind,3)
Deconstructor:     (Twilight          ,4)
Deconstructor:     (NULL              ,0)
Deconstructor:     (NULL              ,0)

resize(3):
Deconstructor:     (NULL              ,0)
Deconstructor:     (NULL              ,0)
Deconstructor:     (Red Stone         ,1)
Deconstructor:     (Kite Runner       ,2)
Deconstructor:     (Gone With the Wind,3)
Deconstructor:     (Twilight          ,4)
Deconstructor:     (NULL              ,0)
Deconstructor:     (NULL              ,0)
------

Compare(OutputIndex,OutputIter):
Copy Constructor:  (Adel              ,5)
Copy Constructor:  (NULL              ,0)
Copy Constructor:  (Helo              ,5)
OOOOOOOOutputIndex:
				   (Adel              ,5)
				   (NULL              ,0)
				   (Helo              ,5)
Deconstructor:     (Adel              ,5)
Deconstructor:     (NULL              ,0)
Deconstructor:     (Helo              ,5)
------
Copy Constructor:  (Adel              ,5)               //zmr: Copy the element for the first time?
Copy Constructor:  (NULL              ,0)
Copy Constructor:  (Helo              ,5)
OOOOOOOOutputIter:
Copy Constructor:  (Adel              ,5)               //zmr: Why copy the element the second time?
				   (Adel              ,5)
Deconstructor:     (Adel              ,5)
Copy Constructor:  (NULL              ,0)
				   (NULL              ,0)
Deconstructor:     (NULL              ,0)
Copy Constructor:  (Helo              ,5)
				   (Helo              ,5)
Deconstructor:     (Helo              ,5)
Deconstructor:     (Adel              ,5)
Deconstructor:     (NULL              ,0)
Deconstructor:     (Helo              ,5)
------

------end--------
Deconstructor:     (Adel              ,5)
Deconstructor:     (NULL              ,0)
Deconstructor:     (Helo              ,5)

C:\Users\mengriz\source\repos\STL_Proj\Debug\STL_Proj.exe (process 13192) exited
 with code 0.
To automatically close the console when debugging stops, enable Tools->Options->
Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .
*/