/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:26:04 by vbachele          #+#    #+#             */
/*   Updated: 2022/06/26 17:26:29 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
#include "../inc/Vector.hpp"
#include "../inc/Stack.hpp"
#include "../inc/Iterators.hpp"
#include "../inc/Map.hpp"
#endif


/*
**==========================
**     VECTOR TEST
**==========================
*/

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

void	vector_test_non_members_function_overload()
{
	STD::vector<int> foo (3,100);   // three ints with a value of 100
 	STD::vector<int> bar (2,200);   // two ints with a value of 200

	std::cout << "-------------- OPERATOR == && OPERATOR != ---------------" << std::endl << std::endl;
	std::cout << "test 1 : is not equal" << std::endl;
	if (foo != bar)
		std::cout << "foo is not equal to bar";
	STD::vector<int> foo_2 (2,100);   // three ints with a value of 100
 	STD::vector<int> bar_2 (2,100);   // two ints with a value of 200
	std::cout << "test 2 : is equal" << std::endl;
	if (foo_2 == bar_2)
		std::cout << "foo is equal to bar" << std::endl;

	std::cout << "-------------- OPERATOR <= && OPERATOR <= ---------------" << std::endl << std::endl;
	std::cout << "test 3 : is inferior <";
	STD::vector<int> foo_3 (3,100);   // three ints with a value of 100
 	STD::vector<int> bar_3 (3,200);   // two ints with a value of 200
	if (foo_3 < bar_3)
		std::cout << "foo is inferior to bar" << std::endl;
	std::cout << "test 4 : is inferior <=";
	STD::vector<int> foo_4 (4,200);   // three ints with a value of 100
 	STD::vector<int> bar_4 (4,200);   // two ints with a value of 200
	if (foo_4 <= bar_4)
		std::cout << "foo is equal to bar" << std::endl;

	std::cout << "-------------- OPERATOR >= && OPERATOR >= ---------------" << std::endl << std::endl;
	std::cout << "test 5 : is superior >";
	STD::vector<int> foo_5 (5,300);   // three ints with a value of 100
 	STD::vector<int> bar_5 (5,200);   // two ints with a value of 200
	if (foo_5 > bar_5)
		std::cout << "foo is superior to bar" << std::endl << std::endl;
	std::cout << "test 6 : is equal >=";
	STD::vector<int> foo_6 (6,200);   // three ints with a value of 100
 	STD::vector<int> bar_6 (6,200);   // two ints with a value of 200
	if (foo_6 >= bar_6)
		std::cout << "foo is equal to bar" << std::endl;
	std::cout << "-------------- SWAP ---------------" << std::endl << std::endl;
	std::cout << "BEFORE SWAPPING" << std::endl;
	display_vector(foo_6);
    std::cout << std::endl;
	foo_6.swap(bar_5);
	std::cout << "AFTER SWAPPING" << std::endl;
	display_vector(foo_6);
	 std::cout << std::endl;
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

void	vector_test_iterator_functions(void)
{
	STD::vector <int> default_vector;
	STD::vector <int> fill_vector(4, 500);
	STD::vector <int> copy_vector(fill_vector);
	default_vector = fill_vector;
	std::cout << "-------------- ITERATOR FUNCTIONS ---------------" << std::endl << std::endl;
	std::cout << "-------------- BEGIN ---------------" << std::endl << std::endl;
	//STD::vector<int>::iterator it = default_vector.begin();
	//std::cout << it << std::endl;
	std::cout << "-------------- END ---------------" << std::endl << std::endl;
	default_vector.push_back(42);
	  std::cout << "myvector contains:";
  //	for (STD::vector<int>::iterator it = 	default_vector.begin() ; *it != 	default_vector.end(); ++it)
   // 	std::cout << ' ' << *it;
  	std::cout << '\n';
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
	std::cout << "I'm clearing all the vector" << std::endl;
	fill_vector.clear();
	display_vector(fill_vector);
	fill_vector.push_back(25);
	fill_vector.push_back(600);
	display_vector(fill_vector);
	std::cout << "--------------	 ASSIGN ---------------" << std::endl << std::endl;
	std::cout << "I'm assigning all the vector" << std::endl;
	fill_vector.assign(10, 10);
	display_vector(fill_vector);
	std::cout << "I'm assigning with iterators the vector" << std::endl;
	STD::vector<int>::iterator it;
  	it = fill_vector.begin()+1;
	fill_vector.assign(it,fill_vector.end()-1);
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
	vector_test_iterator_functions();
	vector_test_element_access_functions();
	vector_test_non_members_function_overload();
	vector_test_reverse_iterator();
}

/*
**==========================
**     STACK TEST
**==========================
*/

void	stack_test_members_functions()
{
	STD::vector<int> vector(10, 50);
	STD::vector<int> vector2(0, 0);
	STD::stack<int> first;
	//STD::stack<int> second (vector);
	STD::stack<int,STD::vector<int> > third;  // empty stack using vector
  	STD::stack<int,STD::vector<int> > fourth (vector);
  	STD::stack<int,STD::vector<int> > fifth (vector2);
	std::cout << "------------------------ 			STACK MEMBERS FUNCTIONS TESTS 		-------------------------" << std::endl << std::endl;
	std::cout << "------------------------ SIZE TEST -------------------------" << std::endl << std::endl;
	std::cout << "size is of the 1st stack: " << fourth.size() << std::endl;
	std::cout << "size is of the 2nd stack: " << fifth.size() << std::endl;
	std::cout << "------------------------ EMPTY TEST -------------------------" << std::endl << std::endl;
	std::cout << "1st stacksize is empty (0) == no, (1) == yes ===> " << fourth.empty() << std::endl;
	std::cout << "2nd stacksize is empty (0) == no, (1) == yes ===> " << fifth.empty() << std::endl;
	std::cout << "------------------------ PUSH TEST -------------------------" << std::endl << std::endl;
	std::cout << "ADDING 42 at the top of the stack" << std::endl;
	fourth.push(42);
	std::cout << "------------------------ TOP TEST -------------------------" << std::endl << std::endl;
	std::cout << "The top element of the stack is " << fourth.top() << std::endl;
	std::cout << "------------------------ POP TEST -------------------------" << std::endl << std::endl;
	fourth.pop();
	std::cout << "I remove the last element of the stack, the new element at the top of the stack: " << fourth.top() << std::endl;

}

void	stack_test_relational_operators()
{
	std::cout << "------------------------ 			STACK RELATIONAL OPERATOR TESTS 		-------------------------" << std::endl << std::endl;
	STD::vector<int> vector(10, 50);
	STD::vector<int> vector2(0, 0);
	STD::stack<int> first;
	//STD::stack<int> second (vector);
  	STD::stack<int,STD::vector<int> > fourth (vector);
  	STD::stack<int,STD::vector<int> > fifth (vector2);
	std::cout << "------------------------ OPERATOR == TEST -------------------------" << std::endl << std::endl;
	if (fourth == fifth)
		std::cout << "LHS && RHS are EQUAL"  << std::endl;
	else
		std::cout << "LHS && RHS are not EQUAL"  << std::endl;
	std::cout << "------------------------ OPERATOR != TEST -------------------------" << std::endl << std::endl;
	if (fourth != fifth)
		std::cout << "LHS && RHS are NOT EQUAL"  << std::endl;
	else
		std::cout << "LHS && RHS are EQUAL"  << std::endl;
	std::cout << "------------------------ OPERATOR < TEST -------------------------" << std::endl << std::endl;
	if (fourth < fifth)
		std::cout << "LHS < RHS"  << std::endl;
	else
		std::cout << "LHS > RHS"  << std::endl;
	std::cout << "------------------------ OPERATOR <= TEST -------------------------" << std::endl << std::endl;
	if (fourth <= fifth)
		std::cout << "LHS <= RHS"  << std::endl;
	else
		std::cout << "LHS >= RHS"  << std::endl;
	std::cout << "------------------------ OPERATOR > TEST -------------------------" << std::endl << std::endl;
	if (fourth > fifth)
		std::cout << "LHS > RHS"  << std::endl;
	else
		std::cout << "LHS < RHS"  << std::endl;
	std::cout << "------------------------ OPERATOR >= TEST -------------------------" << std::endl << std::endl;
	if (fourth >= fifth)
		std::cout << "LHS >= RHS"  << std::endl;
	else
		std::cout << "LHS <= RHS"  << std::endl;
}

void	stack_test()
{
	std::cout << "------------------------ STACK TEST --------------------------" << std::endl << std::endl;
	stack_test_members_functions();
	stack_test_relational_operators();
}

/*
**==========================
**     MAP TEST
**==========================
*/

void	utils_test()
{

}

void	map_test()
{
	STD::map<int, int> Vincent;
	STD::map<int, int> Robin(Vincent);
	Vincent.insert(STD::pair<char,int>('z',200) );
}

int 	main(void)
{
	//vector_test();
	//stack_test();
	//utils_test();
	map_test();
}