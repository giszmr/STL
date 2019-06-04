#include "pch.h"
#include <iomanip>
#include <algorithm>
#include <iterator>
#include "algorithm_test.h"


using namespace STL_Test;


bool IsOdd(int i) {
	return ((i % 2) == 1);
}
bool myfunction(int i, int j) {
	return (i == j);
}


void AlgorithmTest::DefaultSortTest()
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


void AlgorithmTest::StableSortTest()
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

void AlgorithmTest::PartialSortTest()
{
	std::cout << "\n****************PartialSortTest*****************" << std::endl;


	int count = 5;
	std::vector<int> numbers{ 22, 7, 93, 45, 19, 56, 88, 12, 8, 7, 15, 10 };
	Output(numbers, "numbers");

	std::cout << "\npartial_sort:" << std::endl;
	std::partial_sort(numbers.begin(), numbers.begin() + count, numbers.end());
	Output(numbers, "numbers");


	std::cout << "\npartial_sort + compare:" << std::endl;
	std::partial_sort(numbers.begin(), numbers.begin() + count, numbers.end(), std::greater<int>());
	Output(numbers, "numbers");
}

void AlgorithmTest::ParticalSortCopyTest()
{
	std::cout << "\n****************ParticalSortCopyTest*****************" << std::endl;


	int count = 5;
	std::vector<int> ret(5);
	std::vector<int> numbers{ 22, 7, 93, 45, 19, 56, 88, 12, 8, 7, 15, 10 };
	Output(numbers, "numbers");
	Output(ret, "ret");


	std::cout << "\npartial_sort_copy:" << std::endl;
	std::partial_sort_copy(numbers.begin(), numbers.end(), ret.begin(), ret.end());
	Output(numbers, "numbers");
	Output(ret, "ret");


	std::cout << "\npartial_sort_copy + compare:" << std::endl;
	std::partial_sort_copy(numbers.begin(), numbers.end(), ret.begin(), ret.end(), std::greater<int>());
	Output(numbers, "numbers");
	Output(ret, "ret");

}

/*
std::nth_element
default (1)
template <class RandomAccessIterator>
  void nth_element (RandomAccessIterator first, RandomAccessIterator nth,
					RandomAccessIterator last);

custom (2)
template <class RandomAccessIterator, class Compare>
  void nth_element (RandomAccessIterator first, RandomAccessIterator nth,
					RandomAccessIterator last, Compare comp);

Sort element in range
Rearranges the elements in the range [first,last), in such a way that the element at the nth position is the element that would be in that position in a sorted sequence.
The other elements are left without any specific order, except that none of the elements preceding nth are greater than it, and none of the elements following it are less.
The elements are compared using operator< for the first version, and comp for the second.
*/
void AlgorithmTest::NthElementTest()
{
	std::cout << "\n****************NthElementTest*****************" << std::endl;


	int count = 9;
	std::vector<int> numbers{ 22, 7, 93, 45, 19, 56, 88, 12, 8, 7, 15, 10, 4, 89, 64, 55, 24, 66, 29 };
	Output(numbers, "numbers");

	std::cout << "\nnth_element:" << std::endl;
	std::nth_element(numbers.begin(), numbers.begin() + count, numbers.end());
	Output(numbers, "numbers");


	std::cout << "\nnth_element + compare:" << std::endl;
	std::nth_element(numbers.begin(), numbers.begin() + count, numbers.end(), std::greater<int>());
	Output(numbers, "numbers");
}
/*
std::partition
template <class ForwardIterator, class UnaryPredicate>
  ForwardIterator partition (ForwardIterator first,
							 ForwardIterator last, UnaryPredicate pred);

Partition range in two
Rearranges the elements from the range [first,last), in such a way that all the elements for which pred returns true precede all those for which it returns false. The iterator returned points to the first element of the second group.
The relative ordering within each group is not necessarily the same as before the call. See stable_partition for a function with a similar behavior but with stable ordering within each group.
*/
void AlgorithmTest::PartitionTest()
{
	std::cout << "\n****************PartitionTest*****************" << std::endl;


	std::vector<int> myvector;

	// set some values:
	for (int i = 1; i < 10; ++i) myvector.push_back(i); // 1 2 3 4 5 6 7 8 9

	std::vector<int>::iterator bound;
	bound = std::partition(myvector.begin(), myvector.end(), IsOdd);

	// print out content:
	std::cout << "odd elements:";
	for (std::vector<int>::iterator it = myvector.begin(); it != bound; ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "even elements:";
	for (std::vector<int>::iterator it = bound; it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}
void AlgorithmTest::PartitionCopyTest()
{
	std::cout << "\n****************PartitionCopyTest*****************" << std::endl;



	std::vector<int> foo{ 1,2,3,4,5,6,7,8,9 };
	std::vector<int> odd, even;

	// resize vectors to proper size:
	unsigned n = std::count_if(foo.begin(), foo.end(), IsOdd);
	odd.resize(n); even.resize(foo.size() - n);

	// partition:
	std::partition_copy(foo.begin(), foo.end(), odd.begin(), even.begin(), IsOdd);

	// print contents:
	std::cout << "odd: ";  for (int& x : odd)  std::cout << ' ' << x; std::cout << '\n';
	std::cout << "even: "; for (int& x : even) std::cout << ' ' << x; std::cout << '\n';
}


void AlgorithmTest::IsSortedUntilTest()
{
	std::cout << "\n****************IsSortedUntilTest*****************" << std::endl;


	std::vector<int> numbers{ 22, 7, 93, 45, 19, 56, 88, 12, 8, 7, 15, 10, 4, 89, 64, 55, 24, 66, 29 };
	Output(numbers, "numbers");
	std::sort(numbers.begin(), numbers.begin() + 5);   //sort [numbers.begin(), numbers.begin() + 5)
	Output(numbers, "numbers");
	std::vector<int>::iterator iter = std::is_sorted_until(numbers.begin(), numbers.end());
	std::cout << "iter: " << *iter << std::endl;
}


/*
template <class InputIterator, class UnaryPredicate>
   InputIterator find_if (InputIterator first, InputIterator last, UnaryPredicate pred);
*/
void AlgorithmTest::FindIfTest() //UnaryPredicate pred
{
	std::cout << "\n****************FindIfTest*****************" << std::endl;


	std::vector<int> myvector;

	myvector.push_back(10);
	myvector.push_back(25);
	myvector.push_back(40);
	myvector.push_back(55);
	Output(myvector, "myvector");

	std::vector<int>::iterator it = std::find_if(myvector.begin(), myvector.end(), IsOdd);
	std::cout << "The first odd value is " << *it << '\n';
}
/*
equality (1)
template <class ForwardIterator>
   ForwardIterator adjacent_find (ForwardIterator first, ForwardIterator last);

predicate (2)
template <class ForwardIterator, class BinaryPredicate>
   ForwardIterator adjacent_find (ForwardIterator first, ForwardIterator last,
								  BinaryPredicate pred);
*/
void AlgorithmTest::AdjacentFindTest()  //BinaryPredicate pred
{
	std::cout << "\n****************FindIfTest*****************" << std::endl;


	int myints[] = { 5, 20, 5, 30, 30, 20, 10, 10, 20 };
	std::vector<int> myvector(myints, myints + sizeof(myints)/sizeof(int));
	Output(myvector, "myvector");

	std::vector<int>::iterator it;
	// using default comparison:
	it = std::adjacent_find(myvector.begin(), myvector.end());

	if (it != myvector.end())
		std::cout << "the first pair of repeated elements are: " << *it << '\n';

	//using predicate comparison:
	it = std::adjacent_find(++it, myvector.end(), myfunction);

	if (it != myvector.end())
		std::cout << "the second pair of repeated elements are: " << *it << '\n';
}


void AlgorithmTest::EqualTest()
{
	std::cout << "\n****************EqualTest*****************" << std::endl;


	int myints[] = { 1, 3, 9, 8, 5, 9, 10 };
	std::vector<int> myvector(myints, myints + sizeof(myints) / sizeof(int));
	Output(myvector, "myvector");

	bool ret = std::equal(myvector.begin(), myvector.end(), myints);
	if (ret)
		std::cout << "equal\n";
	else
		std::cout << "not equal\n";

	std::vector<int> myvector2(myvector);
	myvector2.push_back(3);
	std::sort(myvector2.begin(), myvector2.end());
	ret = std::equal(myvector.begin(), myvector.end(), myvector2.begin());
	if (ret)
		std::cout << "equal2\n";
	else
		std::cout << "not equal2\n";
}


void AlgorithmTest::SetUnionTest()
{
	std::cout << "\n****************SetUnionTest*****************" << std::endl;


	int first[] = { 5, 9, 10, 10, 8, 7, 300 };
	int second[] = { 1, 3, 8, 6, 70, 20, 7, 9, 9, 7 };
	std::sort(first, first + sizeof(first) / sizeof(int));
	std::sort(second, second + sizeof(second) / sizeof(int));
	std::vector<int> myvector((sizeof(first) + sizeof(second)) / sizeof(int));   //size of vector should not be 0 before "std::set_union".

	//all elements of "first" and "second" will be reserved in "myvector".
	std::set_union(first, first + sizeof(first) / sizeof(int), second, second + sizeof(second) / sizeof(int), myvector.begin());
	Output(myvector, "myvector");
}


void AlgorithmTest::HeapTest()
{
	std::cout << "\n****************HeapTest*****************" << std::endl;


	std::vector<int> myvector = { 3, 9, 8, 20, 1, 60, 300, 90 };
	std::make_heap(myvector.begin(), myvector.end());
	Output(myvector, "myvector");
	std::cout << "front(): " << myvector.front() << std::endl;

	std::pop_heap(myvector.begin(), myvector.end());  // only move the biggest number to the end of vector.
	Output(myvector, "myvector");
	myvector.pop_back();                              // remove the last element of this vector.
	Output(myvector, "myvector");

	myvector.push_back(200);
	Output(myvector, "myvector");
	std::push_heap(myvector.begin(), myvector.end());    //push the newly added element to the proper position in the heap using std::push_heap
	Output(myvector, "myvector");

	std::sort_heap(myvector.begin(), myvector.end());
	Output(myvector, "myvector");
}



void AlgorithmTest::Output(std::vector<int>& myVector, std::string name)
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

void AlgorithmTest::Output(std::vector<Price>& myVector, std::string name)
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


void AlgorithmTest::Output(std::vector<double>& myVector, std::string name)
{

}

void AlgorithmTest::Output(std::vector<std::string>& myVector, std::string name)
{

}

