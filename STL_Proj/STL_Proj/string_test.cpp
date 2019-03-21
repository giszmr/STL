#include "pch.h"
#include <iostream>
#include <string>
#include "string_test.h"


using namespace std;
using namespace STL_Test;

StringTest::StringTest()
{}

StringTest::~StringTest()
{}

void StringTest::ConsructorTest()
{
	cout << "***************ConsructorTest******************" << endl;

	string str_null;
	cout << "0 " << str_null << endl;

	string str_hello("hello_hello");
	cout << "1 " << str_hello << endl;
	
	string str_world("world_world");
	cout << "2 " << str_world << endl;

	string str_copy(str_hello);
	cout << "3 " << str_copy << endl;

	string str_assignment = str_world;
	cout << "4.1 " << str_assignment << endl;

	string str_assignment1 = "hello to cc, so glad to see you.";
	cout << "4.2 " << str_assignment1 << endl;

	string str_start_from(str_hello, 5);
	cout << "5 " << str_start_from << endl;

	string str_start_len(str_world, 3, 5);
	cout << "6 " << str_start_len << endl;

	string str_c_string(str_hello.c_str());
	cout << "7 " << str_c_string << endl;

	string str_c_string_len(str_world.c_str(), 4);
	cout << "8 " << str_c_string_len << endl;

	string str_c_string_start_len(str_hello.c_str(), 5, 3);
	cout << "9 " << str_c_string_start_len << endl;

	string str_char_num(10, 'A');
	cout << "10 " << str_char_num << endl;

	string str_iter(str_world.begin(), str_world.end());
	cout << "11 " << str_iter << endl;



}

void StringTest::CapacityTest()
{
	cout << "***************CapacityTest******************" << endl;

	string str("Hello, everybody. So glad to see you!");
	cout << str << endl;
	if (str.empty())
		cout << "str is empty" << endl;
	else
		cout << "str is not empty" << endl;
	cout << "0.1 " << str.size() << endl;
	cout << "0.2 " << str.length() << endl;
	cout << "0.3 " << str.capacity() << endl;
	cout << "0.4 " << hex << str.max_size() << dec << endl;

	str.resize(50);
	cout << str << endl;
	cout << "1.1 " << str.size() << endl;
	cout << "1.2 " << str.length() << endl;
	cout << "1.3 " << str.capacity() << endl;
	cout << "1.4 " << hex << str.max_size() << dec << endl;

	str.resize(30);
	cout << str << endl;
	cout << "2.1   " << str.size() << endl;
	cout << "2.2   " << str.length() << endl;
	cout << "2.3.0 " << str.capacity() << endl;
	str.shrink_to_fit();
	cout << "2.3.1 " << str.capacity() << endl;
	str.reserve(100);
	cout << "2.3.2 " << str.capacity() << endl;
	str.reserve(10);
	cout << "2.3.3 " << str.capacity() << endl;
	cout << "2.4   " << hex << str.max_size() << dec << endl;

	str.clear();
	cout << str << endl;
	cout << "3.1   " << str.size() << endl;
	cout << "3.2   " << str.length() << endl;
	cout << "3.3.0 " << str.capacity() << endl;
	str.shrink_to_fit();
	cout << "3.3.1 " << str.capacity() << endl;
	str.reserve(100);
	cout << "3.3.2 " << str.capacity() << endl;
	str.reserve(10);
	cout << "3.3.3 " << str.capacity() << endl;
	cout << "3.4   " << hex << str.max_size() << dec << endl;

}

void StringTest::ElementAccessTest()
{
	cout << "***************ElementAccessTest******************" << endl;

	string str("http://c.biancheng.net/view/1446.html");

	//reference of specified character
	for (int i = 0; i < str.length(); i++)
	{
		cout << str[i];
	}
	cout << endl;

	//reference of specified character
	for (int i = 0; i < str.length(); i++)
	{
		cout << str.at(i);
	}
	cout << endl;

	//reference of last character
	str.back() = 'L';
	cout << str << endl;

	//reference of first character
	str.front() = 'H';
	cout << str << endl;
}


void StringTest::StringOperations()
{
	cout << "***************StringOperations******************" << endl;
	StringCompare();
	StringFind();
}

/*
string(1)
	int compare(const string& str) const noexcept;

substrings(2)
	int compare(size_t pos, size_t len, const string& str) const;
	int compare(size_t pos, size_t len, const string& str, size_t subpos, size_t sublen) const;

c - string(3)
	int compare(const char* s) const;
	int compare(size_t pos, size_t len, const char* s) const;

buffer(4)
	int compare(size_t pos, size_t len, const char* s, size_t n) const;
*/
void StringTest::StringCompare()
{

	string str1 = "red apple";
	string str2("green apple");
	cout << "1.1 " << str1 << endl;
	cout << "1.2 " << str2 << endl;

	cout << "----------------string compare test------------------" << endl;
	if (str1.compare(str2) != 0)
		cout << str1 << " is not " << str2 << endl;

	if (str1.compare(4, 5, "apple") == 0)
		cout << str1 << " is an apple" << endl;

	if (str2.compare(str2.size() - 5, 5, "apple") == 0)
		cout << str2 << " is also an apple" << endl;

	if (str1.compare(str1.size() - 5, 5, str2, str2.size() - 5, 5) == 0)
		cout << str1 << " and " << str2 << " are both apples" << endl;

	const char *cStr = "red apple";
	if (str1.compare(cStr) == 0)
		cout << str1 << "s" << endl;

	const char *cStr1 = "apple";
	if (str1.compare(str1.size() - 5, 5, cStr1) == 0)
		cout << str1 << " is an apple" << endl;

	const char *cStr2 = "apple me";
	if (str2.compare(str2.size() - 5, 5, cStr2, 5) == 0)
		cout << str2 << " is an apple" << endl;
}


void StringTest::StringFind()
{

}