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
		typedef value_type&				reference;
		typedef const value_type&		const_reference;

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
	**    CAPACITY FUNCTIONS
	**==========================
	*/
		size_type 	size() const;
		size_type	set_size(size_type n) const;
		size_type 	max_size() const;
		void		destroy_array(size_type n);
		void		allocate_array(size_type n, value_type val);
		void 		resize (size_type n, value_type val = value_type());
		size_type 	capacity() const;
		bool 		empty() const;
		void 		reserve (size_type n);

	/*
	**==========================
	**	MODIFIERS FUNCTIONS
	**==========================
	*/
		//template <class InputIterator>  void assign (InputIterator first, InputIterator last);
		void assign (size_type n, const value_type& val);
		void push_back (const value_type& val);
		void pop_back();
		//iterator insert (iterator position, const value_type& val);
		//void insert (iterator position, size_type n, const value_type& val);
		//template <class InputIterator>    void insert (iterator position, InputIterator first, InputIterator last);
		//iterator erase (iterator position);iterator erase (iterator first, iterator last);
		void swap (vector& x);
		void clear();

	/*
	**==========================
	**	ELEMENT ACCESS
	**==========================
	*/
		reference 			at (size_type n);
		const_reference 	at (size_type n) const
		{
			if (n > this->size())
				throw std::out_of_range("number too high");
			return (this->_array[n]);
		};
		reference 			operator[] (size_type n);
		const_reference 	operator[] (size_type n) const {return(this->_array[n]);};
		reference front() {return (this->_array[0]);};
		const_reference front() const {return (this->_array[0]);};
		reference back() {return (this->_array[this->size() -1]);};
		const_reference back() const {return (this->_array[this->size() -1]);};
	/*
	**==========================
	** NON-MEMBER FUNCTION OVERLOAD
	**==========================
	*/
		void swap (vector& x, vector& y);
	private:
		allocator_type	_alloc;
		size_type		_size; // size of the container
		size_type		_capacity; // size of the memory
		pointer			_array; // pointer to the array
	};

/*
**==========================
** MEMBERS FUNCTIONS
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
			_alloc.construct(&_array[i], x._array[i]);
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
	**     CAPACITY FUNCTIONS
	**==========================
	*/
	template < class T, class Alloc >
	size_t vector <T, Alloc>::size() const
	{
		return(this->_size);
	}

	template < class T, class Alloc >
	size_t vector <T, Alloc>::set_size(size_type n) const
	{
		this->_size = n;
	}

	template < class T, class Alloc >
	size_t vector <T, Alloc>::max_size() const
	{
		return (std::numeric_limits<size_type>::max());
	}

	template <class T, class Alloc >
	void vector<T, Alloc>::destroy_array(size_type n)
	{
		if (this->_array)
		{
			for (size_type i = n; i > this->_size; i--)
				this->_alloc.destroy(&this->_array[i]);
		}
	}

	template<class T, class Alloc >
	void vector<T, Alloc>::allocate_array(size_type n, value_type val)
	{
		if (this->_array)
		{
			for (size_type i = this->_size; i < n; i++)
				this->_alloc.construct(&this->_array[i], val);
		}
	}

	template < class T, class Alloc >
	void vector<T, Alloc>::resize(size_type n, value_type val)
	{
		if (n > capacity())
			reserve(n);
		if (n < this->_size)
		{
			destroy_array(n);
			this->_size = n;
		}
		if (n > this->_size)
		{
			allocate_array(n, val);
			this->_size = n;
		}
	}

	template < class T, class Alloc >
	size_t vector <T, Alloc>::capacity() const
	{
		return (this->_capacity);
	}

	template <class T, class Alloc >
	bool vector<T, Alloc>::empty() const
	{
		if (this->size() == 0)
			return(1);
		return (0);
	}

	template <class T, class Alloc >
	void vector <T, Alloc>::reserve(size_type size)
	{
		if (size > max_size())
				throw std::length_error("vector::reserve");
		if (size > this->capacity())
		{
			pointer n = this->_alloc.allocate(size);
			for (size_type i = 0; i < this->size(); i++)
			{
				this->_alloc.construct(&n[i], this->_array[i]);
				this->_alloc.destroy(&this->_array[i]);
			}
			this->_alloc.deallocate(this->_array, this->_capacity);
			this->_array = n;
			this->_capacity = size;
		}
	}

/*
**==========================
**	MODIFIERS FUNCTIONS
**==========================
*/

	template <class T, class Alloc>
	void vector<T, Alloc>::assign(size_type n, const value_type& val)
	{
		reserve(n); // we just adjusted the tab in case of n > capacity
		for (size_type i = 0; i < n; i++)
		{
			this->_alloc.destroy(&this->_array[i]);
			this->_alloc.construct(&this->_array[i], val);
		}
		this->_size = n;
	}

	template <class T, class Alloc>
	void vector<T, Alloc>::push_back(const value_type& val)
	{
		if (this->_size == 0)
			this->_size = 2;
		if (this->_size == this->_capacity)
			reserve(this->_size + 1);
		this->_array[this->_size] = val;
		this->_size += 1;
	}

	template <class T, class Alloc>
	void vector<T, Alloc>::pop_back()
	{
		if (!this->empty())
		{
			this->_alloc.destroy(&this->_array[this->size()]);
			this->_size -= 1;
		}
	}

	template <class T, class Alloc>
	void vector<T, Alloc>::swap(vector &x)
	{
		std::swap(this->_size, x._size);
		std::swap(this->_capacity, x._capacity);
		std::swap(this->_alloc, x._alloc);
		std::swap(this->_array, x._array);
	}

	template <class T, class Alloc>
	void vector<T, Alloc>::clear()
	{
		if (_array) {
				for (size_t i = 0; i < _size; i++)
					_alloc.destroy(_array + i);
			}
		//destroy_array(this->_size);
		this->_size = 0;
	}

	/*
	**==========================
	**  ELEMENT ACCESS
	**==========================
	*/

	template<class T, class Alloc>
	T& vector<T,Alloc>::at(size_type n)
	{
		if (n > this->size())
			throw std::out_of_range("number too high");
		return (this->_array[n]);
	}

	template<class T, class Alloc>
	T& vector<T,Alloc>::operator[] (size_type n)
	{
		return(this->_array[n]);
	}

	/*
	**==========================
	** NON-MEMBER FUNCTION OVERLOAD
	**==========================
	*/

	template <class T, class Alloc>
	void vector<T, Alloc>::swap(vector<T,Alloc>& x, vector<T,Alloc>& y)
	{
		vector<T, Alloc> tmp;
		tmp = x;
		x = y;
		y = tmp;
	}

	// template <class T, class Alloc>
	// bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	// {
	// 	return ()
	// }

}

#endif