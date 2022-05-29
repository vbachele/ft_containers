/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:26:04 by vbachele          #+#    #+#             */
/*   Updated: 2022/05/29 19:08:46 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"

void	vector_Test(void)
{
	/***************** Test Constructor **************/
	std::cout << "-------------- VECTOR TEST ---------------" << std::endl << std::endl;
	Vector <int> default_vector;
	Vector <int> fill_vector(4, 500);
	Vector <int> copy_vector(fill_vector);
	default_vector = fill_vector;
	
}

int main(void)
{
	vector_Test();
}