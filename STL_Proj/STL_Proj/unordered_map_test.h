#undef _UNORDERED_MAP_TEST_H_
#ifndef _UNORDERED_MAP_TEST_H_
#define _UNORDERED_MAP_TEST_H_

#include <unordered_map>
#include <vector>
#include <deque>
#include <string>
#include <functional>

#pragma once

namespace STL_Test
{
	class Name
	{
	public:
		Name(std::string first, std::string second) :m_FirstName(first), m_SecondName(second) {};
		~Name() {};
		std::string GetFristName() const { return m_FirstName; }
		std::string GetSecondName() const { return m_SecondName; }
		size_t hash() const  //hasher function
		{
			return std::hash<std::string>()(m_FirstName + m_SecondName);
		}
		bool operator==(const Name& name) const
		{
			return m_FirstName == name.m_FirstName && m_SecondName == name.m_SecondName;
		}
	private:
		std::string m_FirstName;
		std::string m_SecondName;
	};

	class Hash_Name  //hasher
	{
	public:
		size_t operator() (const Name& name) const
		{
			return name.hash();
		}
	};

	class UnorderedMapTest
	{
	public:
		UnorderedMapTest();
		~UnorderedMapTest();
		void ConstructorTest();
		void ModifiersTest();
		void ObserversTest();
		void ElementAccessTest();
	private:
		std::unordered_map<std::string, int> merge(std::unordered_map<std::string, int>& map1, std::unordered_map<std::string, int>& map2);
		void Output(std::unordered_map<std::string, int>& mymap, std::string name);
		void Output(std::unordered_map<Name, int, Hash_Name>& mymap, std::string name);
	};
}

#endif
