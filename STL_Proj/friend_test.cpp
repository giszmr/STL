#include "pch.h"
#include "friend_test.h"

using namespace STL_Test;




void Host::Introduce(const Person& person)
{
	std::cout << person.m_hello << person << std::endl;
}