/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:25:56 by vbachele          #+#    #+#             */
/*   Updated: 2022/05/30 00:07:42 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP
#include "iostream"
// #include "limits"
#pragma once

/*
**==========================
**    CLASS DECLARATION
**==========================
*/
// std::allocator<T> Alloc is used to define the storage allocation model
template < class T, class Alloc = std::allocator<T> > 
class Vector 
{
public:
/***************** TYPEDEF **************/
	typedef T							value_type;
	typedef	Alloc						allocator_type;
	typedef size_t						size_type;
	typedef value_type*					pointer;

/***************** CANONICAL FORM **************/
	//default/empty constructor
	explicit Vector (const allocator_type& alloc = allocator_type());
	//fill constructor - with n elements for the array. Each element is a copy of val.
	explicit Vector (size_type n, const value_type& val = value_type(),
							const allocator_type& alloc = allocator_type());
	// //range constructor
	// template <class InputIterator>
    //      Vector (InputIterator first, InputIterator last,
    //              const allocator_type& alloc = allocator_type());
	//copy constructor
	Vector (const Vector& x);
	Vector& operator= (const Vector& x);
	~Vector();

/***************** MEMBER FUNCTIONS **************/
	size_type 	size() const;
	size_type 	capacity() const;
	size_type	max_size() const;
	
private:
	pointer				_array; // Adress of the array - We are using a pointer to allow a dynamic allocation of the memory during runtime of the program 
	size_type 			_size; // size of the array
	size_type 			_capacity; //size for the memory
	allocator_type		_alloc;
	
};

/*
**==========================
**     CANONICAL FORM    
**==========================
*/

template <typename T, typename Alloc>  
Vector<T, Alloc>::Vector(const allocator_type& alloc)
{
	this->_size = 0;
	this->_capacity = 0;
	this->_alloc = alloc;
	this->_array = NULL;
	std::cout << "-------------- DEFAULT CONSTRUCTOR ---------------" << std::endl << std::endl;
	std::cout << "Constructor is called" << std::endl;
	std::cout << "Initial Capacity is: " << _capacity << std::endl;
	std::cout << "size is: " << _size << std::endl << std::endl;
}

template <typename T, typename Alloc>
Vector<T, Alloc>::Vector(size_type n, const value_type& val,
                 const allocator_type& alloc)
{
	this->_size = n;
	this->_capacity = n;
	this->_alloc = alloc;
	this->_array = new value_type[n]();
	std::cout << "-------------- FILL CONSTRUCTOR ---------------" << std::endl << std::endl;
	std::cout << "Initial Capacity is: " << _capacity << std::endl;
	std::cout << "size is: " << _size << std::endl;
	for (size_type i = 0; i < n; i++)
	{
		this->_array[i] = val; 
		std::cout << "Value of the Array: " << this->_array[i] << std::endl;
	}
	std::cout << std::endl;
}
// Vector::Vector(Vector const &src)
// {
// 	std::cout << "Constructor with grade is called" << std::endl;
// 	*this = src; // copy all the element of src in the current instance
// }

template <typename T, typename Alloc>
Vector <T, Alloc>::Vector(const Vector &x)
{
	std::cout << "-------------- COPY CONSTRUCTOR ---------------" << std::endl << std::endl;
	std::cout << "Copy Constructor is called" << std::endl;
	this->_size = x._size;
	this->_capacity = x._capacity;
	this->_alloc = x._alloc;
	this->_array = NULL;
	this->_array = _alloc.allocate(this->_capacity); // here I allocate in the memory the capacity
	size_type i = 0;
	while (i < this->_size)
	{
		_alloc.construct(&_array[i], x._array[i]);
		std::cout << "Value of the Array: " << _array[i] << std::endl;
		i++;
	}
	std::cout << "Initial Capacity is: " << _capacity << std::endl;
	std::cout << "size is: " << _size << std::endl << std::endl;
	return ;
}

template <typename T, typename Alloc> 
Vector<T, Alloc>::~Vector()
{
	std::cout << "-------------- DESTRUCTOR ---------------" << std::endl << std::endl;
	if (this->_array)
	{
		std::cout << "I delete an member of my array" << std::endl;
		delete [] this->_array;
		this->_array = NULL;
	}
	std::cout << "Destructor is called" << std::endl;
}

template <typename T, typename Alloc> 
Vector<T, Alloc> &Vector<T, Alloc>::operator= (const Vector<T, Alloc> & x)
{
	std::cout << "-------------- OPERATOR == ---------------" << std::endl << std::endl;
	if (this->_array)
	{
		delete[] this->_array;
		this->_array = NULL;
	}
	this->_size = x._size;
	this->_capacity = x._capacity;
	this->_alloc = x._alloc;
	this->_array = _alloc.allocate(this->_capacity); 
	for (size_type i = 0; i < this->_size; i++)
	{
		_alloc.construct(&_array[i], x._array[i]);
		std::cout << "Value of the Array: " << _array[i] << std::endl;
	}
	std::cout << "Initial Capacity is: " << this->_capacity << std::endl;
	std::cout << "size is: " << this->_size << std::endl;
	return (*(this));
}


/*
**==========================
**    MEMBER FUNCTIONS
**==========================
*/

template <typename T, typename Alloc>
size_t	Vector<T, Alloc>::size(void) const
{
	return(this->_size);
} 

template <typename T, typename Alloc>
size_t Vector<T, Alloc>::capacity(void) const
{
	return(this->_capacity);
}

// Return the maximum finite value representable by the numeric type T
template <typename T, typename Alloc>
size_t	Vector<T, Alloc>::max_size() const
{ 
	return (std::numeric_limits<size_type>::max());
}

#endif