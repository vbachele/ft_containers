/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:26:04 by vbachele          #+#    #+#             */
/*   Updated: 2022/06/01 17:51:11 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"

void	vector_Test(void)
{
	/***************** Test Constructor **************/
	std::cout << "------------------------ VECTOR TEST --------------------------" << std::endl << std::endl;
	std::cout << "------------------------ CONSTRUCTOR TESTS -------------------------" << std::endl << std::endl;
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
	std::cout << "--------------	 SWAP ---------------" << std::endl << std::endl;
	std::cout << "I'm swapping 2 vector" << std::endl;
	std::cout << "--------------	 CLEAR ---------------" << std::endl << std::endl;
	std::cout << "I'm clearing all the vector" << std::endl;
	fill_vector.clear();
	fill_vector.display_array();
	fill_vector.push_back(25);
	fill_vector.push_back(600);
	fill_vector.display_array();
}

int main(void)
{
	vector_Test();
}