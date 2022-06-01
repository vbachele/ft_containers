/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:43:07 by vincent           #+#    #+#             */
/*   Updated: 2022/05/29 16:06:53 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// #include "Vector.hpp"
// /***************** Canonical form **************/

// template <typename T, typename Alloc>  
// Vector<T, Alloc>::Vector(const allocator_type& alloc) : _size(0), _capacity(5), _array(new value_type[_capacity]), _alloc(alloc)
// {
// 	std::cout << "Constructor is called" << std::endl;
// 	std::cout << "Initial Capacity is:" << _capacity <<std::endl;
// 	std::cout << "size is:" << _size << std::endl;
// }

// // Vector::Vector(Vector const &src)
// // {
// // 	std::cout << "Constructor with grade is called" << std::endl;
// // 	*this = src; // copy all the element of src in the current instance
// // }

// template <typename T, typename Alloc> 
// Vector<T, Alloc>::~Vector()
// {
// 	if (this->_array)
// 	{
// 		delete [] this->_array;
// 		this->_array = NULL;
// 	}
// 	std::cout << "Destructor is called" << std::endl;
// }

// Vector &Vector::operator=(Vector const &obj)
// {
// 	std::cout << "Copy assignment operator called" << std::endl;
// 	return *this;
// }