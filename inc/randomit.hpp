/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomit.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:43:42 by vbachele          #+#    #+#             */
/*   Updated: 2022/06/03 17:51:48 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAMDOMIT_HPP
# define RAMDOMIT_HPP
#include "cstdlib"
#include "Vector.hpp"
#include "iostream"
#pragma once

template < typename T>
class	vector_iterator
{
public:
	typedef T							value_type; //here it is the pointer
	typedef	value_type					*pointer; //here is the reference, it is the same as &reference
	typedef value_type 					&reference;
public:
	vector_iterator()
	{
		std::cout << "THIS IS A TEST" << std::endl;
		this->_ptr = NULL;
	} // iterator sans rien
	vector_iterator(value_type *ptr) : _ptr(ptr) {} // iterator with a pointer
	vector_iterator(vector_iterator const &other) : _ptr(other._ptr) {} // iterator avec un autre iterator
	virtual ~vector_iterator() {}

	value_type *_ptr;
/***************** MEMBER FUNCTIONS **************/
	value_type	*get_ptr() const
	{
		return (this->_ptr);
	}

/***************** OPERATOR FUNCTIONS **************/

	vector_iterator	&operator=(const vector_iterator &rhs)
	{
		if (this != &rhs)
			this->_ptr = rhs._ptr;
		return (*this);
	}

	vector_iterator &operator++()
	{
		this->_ptr++;
		return (*this);
	}

	// bool &operator!=(const vector_iterator &other) const
	// {
	// 	bool b = this->_ptr != other._ptr; // If diff b = 1
	// 	return (b);
	// }

};


template <typename Iterator>
std::ostream &operator<<(std::ostream &o, vector_iterator<Iterator> &rhs)
{
	o << *rhs.get_ptr();
    return o;
}

template <typename It1, typename It2>
bool &operator!=(const vector_iterator<It1> &a, const vector_iterator<It2> &b)
{
		bool res = a.get_ptr() != b.get_ptr(); // If diff b = 1
		return (res);
}


#endif