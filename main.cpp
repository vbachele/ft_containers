#if STD_
#define STD std
#define CONTAINER std
#define PRINTCONTAINER() std::cout << "std::vector\n\n" << std::endl;
#include <vector>
#include <stack>
#include <map>
#include <iostream>
#else
#define STD ft
#define CONTAINER ft
#define PRINTCONTAINER() std::cout << "STD::vector\n\n" << std::endl;
#include "inc/Vector.hpp"
#include "Vector_Iterators.hpp"
#include "inc/Utils.hpp"
#endif

void	display_vector(STD::vector<int> &T)
{
	for (size_t i = 0; i < T.size(); ++i)
	{
       std::cout << T.at(i) << "; ";
    }
	std::cout << std::endl;
}

void	vector_test_reverse_iterator()
{
	STD::vector<int> fill_vector(4, 500);
	fill_vector.push_back(42);
	std::cout << "-------------- REVERSE ITERATOR FUNCTION ---------------" << std::endl;
	std::cout << "-------------- RBEGIN ---------------" << std::endl << std::endl;
	STD::vector<int>::reverse_iterator it = fill_vector.rbegin();
	std::cout << *it << std::endl;
	std::cout << "-------------- REND ---------------" << std::endl << std::endl;
	STD::vector<int>::reverse_iterator it2 = fill_vector.rend() - 1;
	std::cout << *it2 << std::endl;
}

void	vector_test_iterator_functions(void)
{
	STD::vector <int> default_vector;
	STD::vector <int> fill_vector(4, 500);
	STD::vector <int> copy_vector(fill_vector);
	default_vector = fill_vector;
	std::cout << "-------------- ITERATOR FUNCTIONS ---------------" << std::endl << std::endl;
	std::cout << "-------------- BEGIN ---------------" << std::endl << std::endl;
	display_vector(default_vector);
	STD::vector<int>::iterator it = default_vector.begin();
	std::cout << *it << std::endl;
	std::cout << "-------------- END ---------------" << std::endl << std::endl;
	display_vector(default_vector);
	STD::vector<int>::iterator it_end = default_vector.end();
	std::cout << *it_end << std::endl;
	std::cout << "myvector contains:";
  	for (STD::vector<int>::iterator it = default_vector.begin(); it != default_vector.end(); ++it)
   		std::cout << ' ' << *it;
  	std::cout << '\n';
}

void	vector_test_element_access_functions(void)
{
	STD::vector <int> default_vector;
	STD::vector <int> fill_vector(4, 500);
	STD::vector <int> copy_vector(fill_vector);
	default_vector = fill_vector;
	fill_vector.push_back(42);
	std::cout << "-------------- ELEMENT ACCESS FUNCTIONS ---------------" << std::endl;
	std::cout << "-------------- OPERATOR[] ---------------" << std::endl << std::endl;
	std::cout << "The member [5] of the array is: ";
	std::cout << fill_vector[4] << std::endl;
	std::cout << "-------------- AT ---------------" << std::endl << std::endl;
	std::cout << "my vector contains:";
  	for (unsigned i = 0; i< fill_vector.size(); i++)
    	std::cout << ' ' << fill_vector.at(i);
  	std::cout << std::endl;
	std::cout << "-------------- FRONT ---------------" << std::endl << std::endl;
	std::cout << "myvector.front() is now " << fill_vector.front() << std::endl;
	std::cout << "-------------- BACK ---------------" << std::endl << std::endl;
	fill_vector.push_back(16);
	std::cout << "myvector.back() is now " << fill_vector.back() << std::endl;
}

void	vector_test_modifiers_functions(void)
{
	STD::vector <int> default_vector;
	STD::vector <int> fill_vector(4, 500);
	STD::vector <int> copy_vector(fill_vector);
	default_vector = fill_vector;
	std::cout << "-------------- MODIFIERS FUNCTIONS ---------------" << std::endl << std::endl;
	std::cout << "--------------	 PUSH_BACK ---------------" << std::endl << std::endl;
	default_vector.push_back(10);
	default_vector.push_back(25);
	for (size_t i = 0; i < default_vector.size(); ++i)
	{
        std::cout << default_vector.at(i) << "; ";
    }
    std::cout << std::endl;
	display_vector(default_vector);
	std::cout << "--------------	 POP_BACK ---------------" << std::endl << std::endl;
	std::cout << "I'm removing the last element" << std::endl;
	default_vector.pop_back();
	display_vector(default_vector);
	std::cout << "--------------	 SWAP ---------------" << std::endl << std::endl;
	std::cout << "I'm swapping 2 vector" << std::endl;
	default_vector.swap(fill_vector);
	display_vector(default_vector);
	display_vector(fill_vector);
	std::cout << "--------------	 CLEAR ---------------" << std::endl << std::endl;
	std::cout << "BEFORE CLEARING" << std::endl;
	display_vector(fill_vector);
	fill_vector.clear();
	std::cout << "AFTER CLEARING" << std::endl;
	display_vector(fill_vector);
	fill_vector.push_back(25);
	std::cout << "BEFORE CLEARING NUMBER 2" << std::endl;
	display_vector(fill_vector);
	fill_vector.clear();
	std::cout << "AFTER CLEARING NUMBER 2" << std::endl;
	display_vector(fill_vector);
	fill_vector.push_back(600);
	display_vector(fill_vector);
	std::cout << "--------------	 ASSIGN ---------------" << std::endl << std::endl;
	std::cout << "I'm assigning all the vector" << std::endl;
	fill_vector.assign(10, 10);
	display_vector(fill_vector);
	std::cout << "I'm assigning with iterators the vector" << std::endl;
	STD::vector<int>::iterator it;
  	it = fill_vector.begin() + 1;
	fill_vector.assign(it,fill_vector.end() - 1);
	display_vector(fill_vector);
	std::cout << "--------------	 INSERT ---------------" << std::endl << std::endl;
	std::cout << "I'm filling with 3 new elements the vector" << std::endl;
	it = fill_vector.begin();
	fill_vector.insert(it, 3, 34);
	display_vector(fill_vector);
	std::cout << "I'm filling with a single element at pos 2 the vector" << std::endl;
	it = fill_vector.begin() + 1;
	fill_vector.insert(it, 20);
	it = fill_vector.begin();
	display_vector(fill_vector);
	std::cout << "I'm filling with a first and last iterator the vector" << std::endl;
	STD::vector<int> anothervector(2, 400);
	fill_vector.insert(it, anothervector.begin(), anothervector.end());
	display_vector(fill_vector);
	std::cout << "--------------	 ERASE ---------------" << std::endl << std::endl;
	std::cout << "I'm erasing the 5th element the vector" << std::endl;
	fill_vector.erase(fill_vector.begin() + 5);
	display_vector(fill_vector);
	std::cout << "I'm erasing the 5th to the 10th element the vector" << std::endl;
	fill_vector.erase(fill_vector.begin() + 5, fill_vector.begin() + 10 );
	display_vector(fill_vector);
}

void	vector_test_capacity_functions(void)
{
	STD::vector <int> default_vector;
	STD::vector <int> fill_vector(4, 500);
	STD::vector <int> copy_vector(fill_vector);
	default_vector = fill_vector;
	std::cout << std::endl;
	std::cout << "-------------- MEMBER FUNCTIONS ---------------" << std::endl << std::endl;
	std::cout << "-------------- 	SIZE ---------------" << std::endl << std::endl;
	std::cout << "Size = " << default_vector.size() << std::endl;
	std::cout << "-------------- 	CAPACITY ---------------" << std::endl << std::endl;
	std::cout << "Capacity = " << default_vector.capacity() << std::endl;
	std::cout << "-------------- 	MAX SIZE ---------------" << std::endl << std::endl;
	std::cout << "Max_Size = " << default_vector.max_size() << std::endl;
	std::cout << "--------------	 EMPTY ---------------" << std::endl << std::endl;
	std::cout << "is_empty = " << default_vector.empty() << std::endl;
	std::cout << "--------------	 RESERVE ---------------" << std::endl << std::endl;
	default_vector.reserve(10);
	std::cout << "is_empty = " << default_vector.empty() << std::endl;
	std::cout << "Size = " << default_vector.size() << std::endl;
	std::cout << "Capacity = " << default_vector.capacity() << std::endl;
	std::cout << "--------------	 RESIZE ---------------" << std::endl << std::endl;
	std::cout << "Initial size " << default_vector.size() << std::endl;
	default_vector.resize(2, 6);
	std::cout << "size -2 --> size should be 2 : new size = " << default_vector.size() << std::endl;
	default_vector.resize(6, 6);
	std::cout << "size + 2 --> size should be 6 : new size = " << default_vector.size() << std::endl;
}

void	vector_constructor_test(void)
{
	std::cout << "------------------------ VECTOR TEST --------------------------" << std::endl << std::endl;
	std::cout << "------------------------ CONSTRUCTOR TESTS -------------------------" << std::endl << std::endl;
	STD::vector <int> default_vector;
	STD::vector <int> fill_vector(4, 500);
	STD::vector <int> copy_vector(fill_vector);
	default_vector = fill_vector;
	std::cout << std::endl;
}

void	vector_test(void)
{
	vector_constructor_test();
	vector_test_capacity_functions();
	vector_test_modifiers_functions();
	vector_test_element_access_functions();
	vector_test_iterator_functions();
	vector_test_reverse_iterator();
}

int main(void)
{
	vector_test();
	return (0);
}