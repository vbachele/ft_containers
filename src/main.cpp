/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:26:04 by vbachele          #+#    #+#             */
/*   Updated: 2022/06/06 00:11:17 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"
#include "randomit.hpp"

// void	vector_test_relational_operator_functions()
// {
// 	Vector <int> default_vector;
// 	Vector <int> fill_vector(4, 500);
// 	Vector <int> copy_vector(fill_vector);
// 	default_vector = fill_vector;
// 	if (copy_vector > fill_vector)
// 		std::cout << "copy_vector is lesser than fill_vector" << std::endl;
// }

void	vector_test_element_access_functions(void)
{
	Vector <int> default_vector;
	Vector <int> fill_vector(4, 500);
	Vector <int> copy_vector(fill_vector);
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

void	vector_test_iterator_functions(void)
{
	Vector <int> default_vector;
	Vector <int> fill_vector(4, 500);
	Vector <int> copy_vector(fill_vector);
	default_vector = fill_vector;
	std::cout << "-------------- ITERATOR FUNCTIONS ---------------" << std::endl << std::endl;
	std::cout << "-------------- BEGIN ---------------" << std::endl << std::endl;
	Vector<int>::iterator it = default_vector.begin();
	std::cout << it << std::endl;
	std::cout << "-------------- END ---------------" << std::endl << std::endl;
	default_vector.push_back(42);
	  std::cout << "myvector contains:";
  	for (Vector<int>::iterator it = 	default_vector.begin() ; it != 	default_vector.end(); ++it)
    	std::cout << ' ' << it;
  	std::cout << '\n';
}
void	vector_test_modifiers_functions(void)
{
	Vector <int> default_vector;
	Vector <int> fill_vector(4, 500);
	Vector <int> copy_vector(fill_vector);
	default_vector = fill_vector;
	std::cout << "-------------- MODIFIERS FUNCTIONS ---------------" << std::endl << std::endl;
	std::cout << "--------------	 PUSH_BACK ---------------" << std::endl << std::endl;
	default_vector.push_back(10);
	default_vector.push_back(25);
	default_vector.display_array();
	std::cout << "--------------	 POP_BACK ---------------" << std::endl << std::endl;
	std::cout << "I'm removing the last element" << std::endl;
	default_vector.pop_back();
	default_vector.display_array();
	std::cout << "--------------	 SWAP ---------------" << std::endl << std::endl;
	std::cout << "I'm swapping 2 vector" << std::endl;
	default_vector.swap(fill_vector);
	default_vector.display_array();
	std::cout << std::endl;
	fill_vector.display_array();
	std::cout << "--------------	 CLEAR ---------------" << std::endl << std::endl;
	std::cout << "I'm clearing all the vector" << std::endl;
	fill_vector.clear();
	fill_vector.display_array();
	fill_vector.push_back(25);
	fill_vector.push_back(600);
	fill_vector.display_array();
	std::cout << "--------------	 ASSIGN ---------------" << std::endl << std::endl;
	std::cout << "I'm assigning all the vector" << std::endl;
	fill_vector.assign(10, 10);
	fill_vector.display_array();
	std::cout << "--------------	 ERASE ---------------" << std::endl << std::endl;
	std::cout << "I'm erasing the 5th element the vector" << std::endl;
	fill_vector.erase(fill_vector.begin() + 5);
	fill_vector.display_array();
	std::cout << "I'm erasing the 5th to the 10th element the vector" << std::endl;
	fill_vector.erase(fill_vector.begin() + 5, fill_vector.begin() + 10 );
	fill_vector.display_array();
}

void	vector_test_capacity_functions(void)
{
	Vector <int> default_vector;
	Vector <int> fill_vector(4, 500);
	Vector <int> copy_vector(fill_vector);
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
	Vector <int> default_vector;
	Vector <int> fill_vector(4, 500);
	Vector <int> copy_vector(fill_vector);
	default_vector = fill_vector;
	std::cout << std::endl;
}
void	vector_test(void)
{
	//vector_constructor_test();
	//vector_test_capacity_functions();
	vector_test_modifiers_functions();
	//vector_test_iterator_functions();
	//vector_test_element_access_functions();
	//vector_test_relational_operator_functions();
}

int main(void)
{
	vector_test();
}