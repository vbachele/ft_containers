#ifndef VECTOR_HPP
# define VECTOR_HPP
#include <iostream>
#include <memory>
#include <iostream>
#include <cstdlib>
#include "limits"
#pragma once


namespace ft
{
/*
**==========================
**     CLASS DEFINITION
**==========================
*/
	template < class T, class Alloc = std::allocator<T> >
	class vector {
	public:
	/*** typedef (giving new names) ***/
		typedef T						value_type;
		typedef Alloc					allocator_type;
		typedef size_t					size_type;
		typedef value_type*				pointer;

	/*
	**==========================
	**     MEMBERS FUNCTIONS
	**==========================
	*/
	/*** Constructors ***/
		explicit vector (const allocator_type& alloc = allocator_type());
		explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
		//template <class InputIterator> vector (InputIterator first, InputIterator last,
			//const allocator_type& alloc = allocator_type());
		vector (const vector& x);

	/*** destructor ***/
		~vector ();

	/*** operator= ***/
		vector& operator=(const vector& x);

		
	/*
	**==========================
	**     OTHER FUNCTIONS
	**==========================
	*/

	private:
		allocator_type	_alloc;
		size_type		_size; // size of the container
		size_type		_capacity; // size of the memory
		pointer			_array; // pointer to the array
	};

/*
**==========================
** FUNCTIONS DEFINITION
**==========================
*/

/*** Constructors ***/
	template < typename T, typename Alloc >
	vector<T,Alloc>::vector(const allocator_type &alloc)
	{
		this->_size = 0;
		this->_capacity = 0;
		this->_alloc = alloc; // memory of the type
		this->_array = NULL;
	}

	template < typename T, typename Alloc >
	vector<T,Alloc>::vector(size_type n, const value_type& val, const allocator_type& alloc)
	{
		this->_size = n;
		this->_alloc = alloc;
		this->_capacity = n;
		this->_array = _alloc.allocate(this->_capacity); // allocation for memory of the capacity for the array
		for (size_type i = 0; i < this->_size ; i++)
			this->_array[i] = val;
	}

	template < class T, class Alloc >
	vector<T,Alloc>::vector(const vector& x)
	{
		this->_size = x._size;
		this->_alloc = x._alloc;
		this->_capacity = x._capacity;
		this->_array = _alloc.allocate(this->_capacity);
		for (size_type i = 0; i < this->_size ; i++)
			this->_array[i] = x._array[i];
	}
	// template <class InputIterator> vector (InputIterator first, InputIterator last,
	// 		const allocator_type& alloc = allocator_type());
	// template < class T, class Alloc >
	// vector

	/*** destructor ***/
	template < class T, class Alloc >
	vector<T,Alloc>::~vector()
	{
		for(size_type i = 0; i < this->_size; i++)
			this->_alloc.destroy(&this->_array[i]);
		this->_alloc.deallocate(this->_array, this->_capacity);
	}

	/*** operator= ***/
	template < class T, class Alloc >
	vector<T, Alloc> &vector<T, Alloc>::operator=(const vector<T, Alloc>& x)
	{
		for (size_type i = 0; i < this->_size; i++)
			this->_alloc.destroy(&this->_array[i]);
		this->_size = x._size;
		this->_alloc = x._alloc;
		this->_capacity = x._capacity;
		this->_array = _alloc.allocate(this->_capacity);
		for (size_type i = 0; i < this->_size ; i++)
			this->_array[i] = x._array[i];
		return (*(this));
	}

	/*
	**==========================
	**     OTHER FUNCTIONS
	**==========================
	*/
}

#endif