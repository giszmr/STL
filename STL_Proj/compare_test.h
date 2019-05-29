#undef _COMPARE_TEST_H_
#ifndef _COMPARE_TEST_H_
#define _COMPARE_TEST_H_

#include <map>
#include <vector>
#include <deque>
#include <string>

#pragma once

namespace STL_Test
{
	class MyKey
	{
	public:
		MyKey(int _age, std::string _name) :age(_age), name(_name) {};
		~MyKey() {};
		int getAge() const { return age; };
		std::string getName() const { return name; };
		bool operator<(const MyKey& myKey) const             //overload operator "<"
		{
			if (age != myKey.age)
			{
				return age < myKey.age;
			}
			if (name != myKey.name)
			{
				return name < myKey.name;
			}
			return false;
		}
	private:
		int age;
		std::string name;
	};

	struct cmpKey   //imitate "compare" function. it could be "less" or "greater".
	{
		bool operator()(const MyKey& key1, const MyKey& key2)
		{
			if (key1.getAge() != key2.getAge())
			{
				return key1.getAge() > key2.getAge();
			}
			if (key1.getName() != key2.getName())
			{
				return key1.getName() > key2.getName();
			}
			return false;
		}

	};

	class CompareTest
	{
	public:
		CompareTest() {};
		~CompareTest() {};
		void Test();
	private:
		void Output(std::map<MyKey, std::string>& myMap, std::string name);
		void Output(std::map<MyKey, std::string, cmpKey>& myMap, std::string name);
	};
}

#endif
