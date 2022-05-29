/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:26:04 by vbachele          #+#    #+#             */
/*   Updated: 2022/05/30 00:05:45 by vincent          ###   ########.fr       */
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
	std::cout << "-------------- SIZE ---------------" << std::endl << std::endl;
	std::cout << "Size = " << default_vector.size() << std::endl;
	std::cout << "-------------- CAPACITY ---------------" << std::endl << std::endl;
	std::cout << "Capacity = " << default_vector.capacity() << std::endl;
	std::cout << "-------------- MAX SIZE ---------------" << std::endl << std::endl;
	std::cout << "Max_Size = " << default_vector.max_size() << std::endl;
}

int main(void)
{
	vector_Test();
}