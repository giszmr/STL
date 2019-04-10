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
	for (size_t i = 0; i < str.length(); i++)
	{
		cout << str[i];
	}
	cout << endl;

	//reference of specified character
	for (size_t i = 0; i < str.length(); i++)
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

/*
string (1)
	size_t find (const string& str, size_t pos = 0) const noexcept;

c-string (2)
	size_t find (const char* s, size_t pos = 0) const;

buffer (3)
	size_t find (const char* s, size_t pos, size_type n) const;

character (4)
	size_t find (char c, size_t pos = 0) const noexcept;

*/
void StringTest::StringFind()
{
	string str1 = "I have two boxes, but he has three boxes.";
	string str2("box");
	size_t pos = 0;

	cout << "----------------string find test------------------" << endl;
	cout << "str1: " << str1 << endl;
	cout << "str2: " << str2 << endl;

	pos = str1.find(str2);
	if (pos != string::npos)
		cout << "string " << str2 << " is found at " << pos << endl;

	pos = str1.find(str2, 12);
	if (pos != string::npos)
		cout << "string " << str2 << " is found at " << pos << endl;

	const char *cStr = "boxes";
	pos = str1.find(cStr);
	if (pos != string::npos)
		cout << "CHAR " << cStr << " is found at " << pos << endl;

	pos = str1.find(cStr, 12);
	if (pos != string::npos)
		cout << "CHAR " << cStr << " is found at " << pos << endl;

	pos = str1.find('b', 1);   //find one character
	if (pos != string::npos)
		cout << "CHAR " << cStr << " is found at " << pos << endl;

	pos = str1.find(cStr, 10, 1); //find 'b' of "boxes" at inde 11 (boxes)
	if (pos != string::npos)
		cout << "CHAR " << cStr << " is found at " << pos << endl;

	pos = str1.find(cStr, 12, 1);  //find 'b' of "boxes" at index 18 (but)
	if (pos != string::npos)
		cout << "CHAR " << cStr << " is found at " << pos << endl;

	pos = str1.find(cStr, 12, 2); //find "bo" of "boxes" at index 35 (boxes)
	if (pos != string::npos)
		cout << "CHAR " << cStr << " is found at " << pos << endl;

	cout << "----------------string rfind test------------------" << endl;
	pos = str1.rfind(str2);
	if (pos != string::npos)
		cout << "string " << str2 << " is rfind at index " << pos << endl;

	pos = str1.rfind(str2, 35);
	if (pos != string::npos)
		cout << "string " << str2 << " is rfind at index " << pos << endl;

	pos = str1.rfind(str2, 34);
	if (pos != string::npos)
		cout << "string " << str2 << " is rfind at index " << pos << endl;

	const char* cStrr = "boxes";
	pos = str1.rfind(cStrr);
	if (pos != string::npos)
		cout << "CHAR " << cStrr << " is rfind at index " << pos << endl;

	pos = str1.rfind(cStrr, 35, 1);
	if (pos != string::npos)
		cout << "CHAR 'b' is rfind at index " << pos << endl;

	pos = str1.rfind(cStrr, 34, 1); //match "but"
	if (pos != string::npos)
		cout << "CHAR 'b' is rfind at index " << pos << endl;

	pos = str1.rfind(cStrr, 34, 2); //match "boxes"
	if (pos != string::npos)
		cout << "CHAR 'bo' is rfind at index " << pos << endl;

	pos = str1.rfind('b', 34);
	if (pos != string::npos)
		cout << "CHAR 'b' is rfind at index " << pos << endl;

	cout << "----------------string find_first_of test------------------" << endl;
	pos = str1.find_first_of(str2);
	if (pos != string::npos)
		cout << "char 'o' of " << str2 << " is find_first_of at index " << pos << endl;

	pos = str1.find_first_of('x', 15);
	if (pos != string::npos)
		cout << "char 'x' is find_frist_of at index " << pos << endl;

	cout << "----------------string find_last_of test------------------" << endl;
	pos = str1.find_last_of(str2);
	if (pos != string::npos)
		cout << "char 'o' of " << str2 << " is find_last_of at index " << pos << endl;

	pos = str1.find_last_of('x', 15);
	if (pos != string::npos)
		cout << "char 'x' is find_last_of at index " << pos << endl;

	cout << "----------------string find_first_not_of test------------------" << endl;
	pos = str1.find_first_not_of(str2);
	if (pos != string::npos)
		cout << "string " << str2 << " is find_first_not_of at index " << pos << endl;

	pos = str1.find_first_not_of('x', 15);
	if (pos != string::npos)
		cout << "char 'x' is find_first_not_of at index " << pos << endl;

	cout << "----------------string find_last_not_of test------------------" << endl;
	pos = str1.find_last_not_of(str2);
	if (pos != string::npos)
		cout << "string " << str2 << " is find_last_not_of at index " << pos << endl;

	pos = str1.find_last_not_of('x', 15);
	if (pos != string::npos)
		cout << "char 'x' is find_last_not_of at index " << pos << endl;


	cout << "----------------string substr test------------------" << endl;
	string strTmp = "Happy birthday to you.";
	string subStr = strTmp.substr(1, 10);
	cout << "substr: " << subStr << endl;

	cout << "----------------string copy test------------------" << endl;
	char buffer[50] = { 0 };
	strTmp.copy(buffer, 5, 3);
	cout << "copy: " << buffer << endl;
}

void StringTest::StringModifier()
{
	cout << "***************StringModifier******************" << endl;
	/*string (1)
		string& operator+= (const string& str);

	c-string (2)
		string& operator+= (const char* s);

	character (3)
		string& operator+= (char c);

	initializer list (4)
		string& operator+= (initializer_list<char> il);
	*/
	cout << "string& operator+= (const string& str);=>" << endl;
	string str1 = "good";
	string str2("morning");
	str1 += " ";
	str1 += str2;
	cout << "	" << str1 << endl;

	/*string (1)
		string& append (const string& str);

	substring (2)
		string& append (const string& str, size_t subpos, size_t sublen);

	c-string (3)
		string& append (const char* s);

	buffer (4)
		string& append (const char* s, size_t n);

	fill (5)
		string& append (size_t n, char c);

	range (6)
		template <class InputIterator>
			string& append (InputIterator first, InputIterator last);

	initializer list(7)
		string& append (initializer_list<char> il);
	*/
	cout << "string& append (const string& str);=>" << endl;
	string str3 = "good";
	string str4(" afternoon");
	str3.append(str4);
	//str3.append('!');   //character is not allowed
	str3.append("!");
	cout << "	" << str3 << endl;

	cout << "void push_back (char c);=>" << endl;
	string str5 = "haha";
	str5.push_back('G');
	cout << "	" << str5 << endl;

	/*string (1)
		string& assign (const string& str);

	substring (2)
		string& assign (const string& str, size_t subpos, size_t sublen);

	c-string (3)
		string& assign (const char* s);

	buffer (4)
		string& assign (const char* s, size_t n);

	fill (5)
		string& assign (size_t n, char c);

	range (6)
		template <class InputIterator>
			string& assign (InputIterator first, InputIterator last);

	initializer list(7)
		string& assign (initializer_list<char> il);

	move (8)
		string& assign (string&& str) noexcept;
	*/
	cout << "string& assign (const string& str);=>" << endl;
	string str6 = "good";
	string str7 = "bye";
	str6.assign(str7);
	cout << "	" << str6 << endl;
	str6.assign(10, 'a');
	cout << "	" << str6 << endl;

	/*string (1)
		 string& insert (size_t pos, const string& str);

	substring (2)
		 string& insert (size_t pos, const string& str, size_t subpos, size_t sublen);

	c-string (3)
		 string& insert (size_t pos, const char* s);

	buffer (4)
		 string& insert (size_t pos, const char* s, size_t n);

	fill (5)
		 string& insert (size_t pos,   size_t n, char c);
		 iterator insert (const_iterator p, size_t n, char c);

	single character (6)
		iterator insert (const_iterator p, char c);

	range (7)
		template <class InputIterator>
		iterator insert (iterator p, InputIterator first, InputIterator last);

	initializer list (8)
		 string& insert (const_iterator p, initializer_list<char> il);
	*/
	cout << "string& insert (size_t pos, const string& str);=>" << endl;
	string str8 = "How are you";
	string str9 = "bbb";
	str8.insert(3, str9);
	cout << "	" << str8 << endl;

	/*sequence (1)
		 string& erase (size_t pos = 0, size_t len = npos);

	character (2)
		iterator erase (const_iterator p);

	range (3)
		iterator erase (const_iterator first, const_iterator last);
	*/
	cout << "string& erase (size_t pos = 0, size_t len = npos);=>" << endl;
	string str10 = "I want to sleep";
	cout << "	" << str10 << " " << str10.length() << endl;
	str10.erase(2, 4);
	cout << "	" << str10 << " " << str10.length() << endl;


	/*string (1)
		string& replace (size_t pos,        size_t len,        const string& str);
		string& replace (const_iterator i1, const_iterator i2, const string& str);

	substring (2)
		string& replace (size_t pos,        size_t len,        const string& str,
						 size_t subpos, size_t sublen);

	c-string (3)
		string& replace (size_t pos,        size_t len,        const char* s);
		string& replace (const_iterator i1, const_iterator i2, const char* s);

	buffer (4)
		string& replace (size_t pos,        size_t len,        const char* s, size_t n);
		string& replace (const_iterator i1, const_iterator i2, const char* s, size_t n);

	fill (5)
		string& replace (size_t pos,        size_t len,        size_t n, char c);
		string& replace (const_iterator i1, const_iterator i2, size_t n, char c);

	range (6)
		template <class InputIterator>
			string& replace (const_iterator i1, const_iterator i2,
							   InputIterator first, InputIterator last);

	initializer list (7)
		string& replace (const_iterator i1, const_iterator i2, initializer_list<char> il);
	*/
	cout << "string& replace (size_t pos, size_t len, const string& str);=>" << endl;
	string str11 = "I have a red hat";
	cout << "	" << str11 << endl;
	string str12 = "blue";
	size_t pos = str11.find("red");
	str11.replace(pos, 3, str12);
	cout << "	" << str11 << endl;

	cout << "void swap (string& str);=>" << endl;
	string str13 = "autumn";
	string str14 = "summer";
	cout << "	" << str13 << " || " << str14 << endl;
	str13.swap(str14);
	cout << "	" << str13 << " || " << str14 << endl;

	cout << "void pop_back();=>" << endl;
	string str15 = "abcdefg";
	while (str15.length() != 0)
	{
		cout << "	" << str15 << endl;
		str15.pop_back();
	}
	cout << "enddddddddddddd" << endl;

}

void StringTest::StringIterator()
{
	cout << "***************StringIterator******************" << endl;

	string str = "Can you do this?";
	string::iterator strIter;
	for (strIter = str.begin(); strIter != str.end(); strIter++)
	{
		if (*strIter == 'C')
			*strIter = 'K';
		cout << *strIter;
	}
	cout << endl;

	string::reverse_iterator rIter;
	for (rIter = str.rbegin(); rIter != str.rend(); rIter++)
	{
		if (*rIter == 'C')
			*rIter = 'K';
		cout << *rIter;
	}
	cout << endl;

	string::const_iterator cIter;
	for (cIter = str.cbegin(); cIter != str.cend(); cIter++)
	{
		//if (*rIter == 'C')
		//	*rIter = 'K';
		cout << *cIter;
	}
	cout << endl;

	string::const_reverse_iterator crIter;
	for (crIter = str.crbegin(); crIter != str.crend(); crIter++)
	{
		//if (*rIter == 'C')
		//	*rIter = 'K';
		cout << *crIter;
	}
	cout << endl;
}

