#ifndef _FRIEND_TEST_H_
#define _FRIEND_TEST_H_
#include <string>
#include <iostream>

#pragma once

namespace STL_Test
{
	class Person
	{
	public:
		Person() {};
		Person(std::string hello, std::string name, int age) :m_hello(hello), m_name(name), m_age(age) {};
		~Person() {};
		friend std::ostream& operator<<(std::ostream& out, const Person& person);
		friend class Host;

	private:
		std::string m_hello;
		std::string m_name;
		int m_age;
	};

	inline std::ostream& operator<<(std::ostream& out, const Person& person)
	{
		return out << "My name is " << person.m_name << ". I'm " << person.m_age << " years old.";
	}


	class Host
	{
	public:
		Host() {};
		Host(int value) :m_value(value) {};
		~Host() {};
		void Introduce(const Person& person);
	private:
		int m_value;
	};

}



#endif