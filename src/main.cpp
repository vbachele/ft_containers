/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:26:04 by vbachele          #+#    #+#             */
/*   Updated: 2022/06/11 16:34:47 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"
#include "randomit.hpp"

void	vector_test_non_members_function_overload()
{
	Vector<int> foo (3,100);   // three ints with a value of 100
 	Vector<int> bar (2,200);   // two ints with a value of 200

	std::cout << "-------------- OPERATOR == && OPERATOR != ---------------" << std::endl << std::endl;
	std::cout << "test 1 : is not equal" << std::endl;
	if (foo != bar)
		std::cout << "foo is not equal to bar";
	Vector<int> foo_2 (2,100);   // three ints with a value of 100
 	Vector<int> bar_2 (2,100);   // two ints with a value of 200
	std::cout << "test 2 : is equal" << std::endl;
	if (foo_2 == bar_2)
		std::cout << "foo is equal to bar" << std::endl;

	std::cout << "-------------- OPERATOR <= && OPERATOR <= ---------------" << std::endl << std::endl;
	std::cout << "test 3 : is inferior <";
	Vector<int> foo_3 (3,100);   // three ints with a value of 100
 	Vector<int> bar_3 (3,200);   // two ints with a value of 200
	if (foo_3 < bar_3)
		std::cout << "foo is inferior to bar" << std::endl;
	std::cout << "test 4 : is inferior <=";
	Vector<int> foo_4 (4,200);   // three ints with a value of 100
 	Vector<int> bar_4 (4,200);   // two ints with a value of 200
	if (foo_4 <= bar_4)
		std::cout << "foo is equal to bar" << std::endl;

	std::cout << "-------------- OPERATOR >= && OPERATOR >= ---------------" << std::endl << std::endl;
	std::cout << "test 5 : is superior >";
	Vector<int> foo_5 (5,300);   // three ints with a value of 100
 	Vector<int> bar_5 (5,100);   // two ints with a value of 200
	if (foo_5 > bar_5)
		std::cout << "foo is inferior to bar" << std::endl << std::endl;
	std::cout << "test 6 : is equal >=";
	Vector<int> foo_6 (6,200);   // three ints with a value of 100
 	Vector<int> bar_6 (6,200);   // two ints with a value of 200
	if (foo_6 >= bar_6)
		std::cout << "foo is equal to bar" << std::endl;
	std::cout << "-------------- SWAP ---------------" << std::endl << std::endl;
	std::cout << "BEFORE SWAPPING" << std::endl;
	foo_6.display_array();
	foo_6.swap(bar_5);
	std::cout << "AFTER SWAPPING" << std::endl;
	foo_6.display_array();
}

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
	std::cout << "I'm assigning with iterators the vector" << std::endl;
	Vector<int>::iterator it;
  	it = fill_vector.begin()+1;
	fill_vector.assign(it,fill_vector.end()-1);
	fill_vector.display_array();
	std::cout << "--------------	 INSERT ---------------" << std::endl << std::endl;
	std::cout << "I'm filling with 3 new elements the vector" << std::endl;
	it = fill_vector.begin();
	fill_vector.insert(it, 3, 34);
	fill_vector.display_array();
	std::cout << "I'm filling with a single element at pos 2 the vector" << std::endl;
	it = fill_vector.begin() + 1;
	fill_vector.insert(it, 20);
	it = fill_vector.begin();
	fill_vector.display_array();
	std::cout << "I'm filling with a first and last iterator the vector" << std::endl;
	Vector<int> anothervector(2, 400);
	fill_vector.insert(it, anothervector.begin(), anothervector.end());
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
	//vector_test_modifiers_functions();
	//vector_test_iterator_functions();
	//vector_test_element_access_functions();
	vector_test_non_members_function_overload();
}

int main(void)
{
	vector_test();
}