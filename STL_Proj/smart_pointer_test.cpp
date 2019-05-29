#include "pch.h"
#include <iomanip>
#include <algorithm>
#include <iterator>
#include "smart_pointer_test.h"


using namespace STL_Test;


void SmartPointerTest::AutoPointerTest()
{
	std::cout << std::endl << "************AutoPointerTest****************" << std::endl;

	std::cout << "get:" << std::endl;
	std::auto_ptr<int> first(new int);
	*first.get() = 9;
	std::cout << *first << std::endl;

	*first = 8;
	std::cout << *first.get() << std::endl;


	std::cout << "copy constructor:" << std::endl;
	std::auto_ptr<int> second(first);
	std::cout << "fisrt : ptr=0x" << first.get() << ", " << (first.get() == nullptr ? 0 : *first.get()) << std::endl;
	std::cout << "second: ptr=0x" << second.get() << ", "<< (second.get() == nullptr ? 0 : *second.get()) << std::endl;


	std::cout << std::endl << "assign constructor:" << std::endl;
	std::auto_ptr<int> third = second;
	std::cout << "fisrt : ptr=0x" << first.get() << ", " << (first.get() == nullptr ? 0 : *first.get()) << std::endl;
	std::cout << "second: ptr=0x" << second.get() << ", " << (second.get() == nullptr ? 0 : *second.get()) << std::endl;
	std::cout << "third : ptr=0x" << third.get() << ", " << (third.get() == nullptr ? 0 : *third.get()) << std::endl;

	//Sets the auto_ptr internal pointer to null pointer (which indicates it points to no object) without destructing the object currently pointed by the auto_ptr.
	std::cout << std::endl << "release:" << std::endl;
	int* manual_ptr = nullptr;
	manual_ptr = third.release();
	std::cout << "fisrt : ptr=0x" << first.get() << ", " << (first.get() == nullptr ? 0 : *first.get()) << std::endl;
	std::cout << "second: ptr=0x" << second.get() << ", " << (second.get() == nullptr ? 0 : *second.get()) << std::endl;
	std::cout << "third : ptr=0x" << third.get() << ", " << (third.get() == nullptr ? 0 : *third.get()) << std::endl;
	std::cout << "manual: ptr=0x" << manual_ptr << ", " << (manual_ptr == nullptr ? 0 : *manual_ptr) << std::endl;
	delete manual_ptr;
	std::cout << "manual: ptr=0x" << manual_ptr << " (deleted, but pointer is not equal to nullptr)" << std::endl;
	manual_ptr = nullptr;  //assign pointer to nullptr after it is deleted. otherwise the pointer is not null. it'll be reused incorrectly.
	std::cout << "manual: ptr=0x" << manual_ptr << ", " << (manual_ptr == nullptr ? 0 : *manual_ptr) << std::endl;

	//Deallocate object pointed and set new value
	std::cout << std::endl << "reset:" << std::endl;
	std::auto_ptr<int> fourth(new int);
	std::cout << "fourth: ptr=0x" << fourth.get() << ", 0x" << std::hex << (fourth.get() == nullptr ? 0 : *fourth.get()) << std::dec << std::endl;
	fourth.reset(nullptr);
	std::cout << "fourth: ptr=0x" << fourth.get() << ", 0x" << std::hex << (fourth.get() == nullptr ? 0 : *fourth.get()) << std::dec << std::endl;
	int* p = NULL;
	fourth.reset(p);
	std::cout << "fourth: ptr=0x" << fourth.get() << ", 0x" << std::hex << (fourth.get() == nullptr ? 0 : *fourth.get()) << std::dec << std::endl;
	fourth.reset(new int);
	std::cout << "fourth: ptr=0x" << fourth.get() << ", 0x" << std::hex << (fourth.get() == nullptr ? 0 : *fourth.get()) << std::dec << std::endl;

}

void SmartPointerTest::NULL_nullptr_Test()
{
	std::cout << std::endl << "************NULL_nullptr_Test****************" << std::endl;

	func(NULL);    //func(int a)
	func(nullptr); //func(int* a)

}

void SmartPointerTest::func(int a)
{
	std::cout << "func(int)" << std::endl;
}

void SmartPointerTest::func(int* a)
{
	std::cout << "func(int*a)" << std::endl;
}


void SmartPointerTest::SharedPointerTest()
{
	std::cout << std::endl << "************SharedPointerTest****************" << std::endl;

	int* p = new int(9);
	//int v = 10;
	//int* pp = &v;
	//std::shared_ptr<int> mysharedptr(pp); // if constructing a shared pointer this way, an exception will be thrown when output it like "std::cout << *mysharedptr << std::endl"
	
	std::shared_ptr<int> first;
	std::cout << "first.use_count: " << first.use_count() << " unique(" << (first.unique() ? "yes" : "no") << ")" << std::endl;

	std::shared_ptr<int> second(nullptr);
	std::cout << "second.use_count: " << second.use_count() << " unique(" << (second.unique() ? "yes" : "no") << ")" << std::endl;

	std::shared_ptr<int> third(p);
	std::cout << std::endl << "share pointer:" << std::endl;
	std::cout << "third.use_count: " << third.use_count() << " unique(" << (third.unique() ? "yes" : "no") << ")" << std::endl;


	std::shared_ptr<int> fourth(third);
	std::cout << std::endl << "copy constructor:" << std::endl;
	std::cout << "third.use_count: " << third.use_count() << std::endl;
	std::cout << "fourth.use_count: " << fourth.use_count() << std::endl;

	std::shared_ptr<int> fifth(std::move(fourth)); //move fourth to fifth
	std::cout << std::endl << "move:" << std::endl;
	std::cout << "third.use_count: " << third.use_count() << std::endl;
	std::cout << "fourth.use_count: " << fourth.use_count() << std::endl;
	std::cout << "fifth.use_count: " << fifth.use_count() << std::endl;


	std::shared_ptr<int> sixth = fifth;
	std::cout << std::endl << "assign:" << std::endl;
	std::cout << "third.use_count: " << third.use_count() << std::endl;
	std::cout << "fourth.use_count: " << fourth.use_count() << std::endl;
	std::cout << "fifth.use_count: " << fifth.use_count() << std::endl;
	std::cout << "sixth.use_count: " << sixth.use_count() << " unique(" << (sixth.unique() ? "yes" : "no") << ")" << std::endl;

	std::cout << (third == nullptr ? 0 : *third)
		<< (fourth == nullptr ? 0 : *fourth) 
		<< (fifth == nullptr ? 0 : *fifth.get())
		<< (sixth == nullptr ? 0 : *sixth) << std::endl;


	std::cout << std::endl << "swap:" << std::endl;
	std::shared_ptr<int> seventh(new int(100));
	std::shared_ptr<int> eighth(new int(200));
	eighth.swap(seventh);
	std::cout << "third(" << *seventh << ").use_count: " << seventh.use_count() << std::endl;
	std::cout << "fourth(" << *eighth << ").use_count: " << eighth.use_count() << std::endl;

	std::cout << std::endl << "operator bool():" << std::endl;
	if (fourth)
		std::cout << "fourth is not empty" << std::endl;
	else
		std::cout << "fourth is empty" << std::endl;

}



void SmartPointerTest::WeakPointerTest()
{
	std::cout << std::endl << "************WeakPointerTest****************" << std::endl;

	std::cout << "lock:" << std::endl;
	std::shared_ptr<int> sp1, sp2;
	std::weak_ptr<int> wp;
											// sharing group:
											// --------------
	sp1 = std::make_shared<int>(20);		// sp1
	wp = sp1;								// sp1, wp

	sp2 = wp.lock();						// sp1, wp, sp2
	sp1.reset();							//      wp, sp2

	sp1 = wp.lock();						// sp1, wp, sp2

	std::cout << "*sp1: " << *sp1 << '\n';
	std::cout << "*sp2: " << *sp2 << '\n';


	std::cout << std::endl << "expired:" << std::endl;
	std::shared_ptr<int> shared(new int(10));
	std::weak_ptr<int> weak(shared);
	std::cout << "1. weak " << (weak.expired() ? "is" : "is not") << " expired\n";
	shared.reset();
	std::cout << "2. weak " << (weak.expired() ? "is" : "is not") << " expired\n";

}



void SmartPointerTest::UniquePointerTest()
{
	std::cout << std::endl << "************UniquePointerTest****************" << std::endl;


	std::default_delete<int> d;
	std::unique_ptr<int> u1;
	std::unique_ptr<int> u2(nullptr);
	std::unique_ptr<int> u3(new int);
	std::unique_ptr<int> u4(new int, d);
	std::unique_ptr<int> u5(new int, std::default_delete<int>());
	std::unique_ptr<int> u6(std::move(u5));
	std::unique_ptr<int> u7(std::move(u6));
	std::unique_ptr<int> u8(std::auto_ptr<int>(new int));

	std::cout << "u1: " << (u1 ? "not null" : "null") << '\n';
	std::cout << "u2: " << (u2 ? "not null" : "null") << '\n';
	std::cout << "u3: " << (u3 ? "not null" : "null") << '\n';
	std::cout << "u4: " << (u4 ? "not null" : "null") << '\n';
	std::cout << "u5: " << (u5 ? "not null" : "null") << '\n';
	std::cout << "u6: " << (u6 ? "not null" : "null") << '\n';
	std::cout << "u7: " << (u7 ? "not null" : "null") << '\n';
	std::cout << "u8: " << (u8 ? "not null" : "null") << '\n';
}