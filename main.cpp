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
#endif

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
}

int main(void)
{
	vector_test();

	return (0);
}