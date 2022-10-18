#ifndef VECTOR_HPP
# define VECTOR_HPP
#include <iostream>
#include <memory>
#include <iostream>
#include <cstdlib>
#include "limits"
#include "Iterators.hpp"
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
		typedef T										value_type;
		typedef Alloc									allocator_type;
		typedef size_t									size_type;
		typedef value_type*								pointer;
		typedef value_type&								reference;
		typedef const value_type&						const_reference;
		typedef vector_iterator<value_type>				iterator;
		typedef vector_iterator<value_type const>		const_iterator;
		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

	/*
	**==========================
	** MEMBERS CLASS DECLARATIONS
	**==========================
	*/
	/*** Constructors ***/
		explicit vector (const allocator_type& alloc = allocator_type());
		explicit vector (size_type n, const value_type& val = value_type(),
		const allocator_type& alloc = allocator_type());
		vector (iterator first, iterator last,
								const allocator_type& alloc = allocator_type());
		vector (const vector& x);

	/*** destructor ***/
		~vector ();

	/*** operator= ***/
		vector& operator=(const vector& x);
	/*
	**==========================
	**    CAPACITY DECLARATIONS
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
	**   ITERATORS DECLARATIONS
	**==========================
	*/
		iterator begin();
		const_iterator begin() const;
		iterator end();
		const_iterator end() const;
		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;
		reverse_iterator rend();
		const_reverse_iterator rend() const;

	/*
	**==========================
	**	MODIFIERS DECLARATIONS
	**==========================
	*/
		void assign (iterator first, iterator last);
		void assign (size_type n, const value_type& val);
		void push_back (const value_type& val);
		void pop_back();
		iterator insert (iterator position, const value_type& val);
		void insert (iterator position, size_type n, const value_type& val);
		void insert (iterator position, iterator first, iterator last);
		iterator erase (iterator position);
		iterator erase (iterator first, iterator last);
		void swap (vector& x);
		void clear();

	/*
	**==========================
	**	ELEMENT ACCESS DECLARATIONS
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
	**==========================================
	** NON-MEMBER FUNCTION OVERLOAD DECLARATIONS
	**==========================================
	*/
		void swap (vector& x, vector& y);
		void shift_left (size_type pos, size_type n);

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

/*** Default constructors ***/
	template < typename T, typename Alloc >
	vector<T,Alloc>::vector(const allocator_type &alloc)
	{
		this->_size = 0;
		this->_capacity = 0;
		this->_alloc = alloc; // memory of the type
		this->_array = NULL;
	}

/*** Fill constructor ***/
	template < typename T, typename Alloc >
	vector<T,Alloc>::vector(size_type n, const value_type& val, const allocator_type& alloc)
	{
		this->_size = n;
		this->_alloc = alloc;
		this->_capacity = n;
		this->_array = _alloc.allocate(n); // allocation for memory of the capacity for the array
		for (size_type i = 0; i < n ; i++)
			this->_alloc.construct(this->_array + i, val);
			//this->_array[i] = val;
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

	template <class T, class Alloc>
	vector<T, Alloc>::vector(iterator first, iterator last,
			const allocator_type& alloc)
	{
		this->_size = last - first;
		this->_capacity = last - first;
		this->_alloc = alloc;
		this->_array = _alloc.allocate(this->_capacity);
		this->assign(first, last);
	}

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
		for (size_type i = 0; i < this->_size; i++)
			_alloc.construct(&_array[i], x._array[i]);
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
**	ITERATORS FUNCTIONS
**==========================
*/
	template <class T, class Alloc >
	typename vector<T,Alloc>::iterator vector<T,Alloc>::begin()
	{
		return(iterator(this->_array));
	}

	template <class T, class Alloc >
	typename vector<T,Alloc>::const_iterator vector<T,Alloc>::begin() const
	{
		return(const_iterator(this->_array));
	}

	template <class T, class Alloc >
	typename vector<T,Alloc>::iterator vector<T,Alloc>::end()
	{
		return(iterator(this->_array + this->_size));
	}

	template <class T, class Alloc >
	typename vector<T, Alloc>::const_iterator vector<T,Alloc>::end() const
	{
		return(const_iterator(this->_array + this->_size));
	}

	template <class T, class Alloc >
	typename vector<T,Alloc>::reverse_iterator vector<T,Alloc>::rbegin()
	{
		return(reverse_iterator(end()));
	}

	template <class T, class Alloc >
	typename vector<T,Alloc>::const_reverse_iterator vector<T,Alloc>::rbegin() const
	{
		return(const_reverse_iterator(end()));
	}

	template <class T, class Alloc >
	typename vector<T,Alloc>::reverse_iterator vector<T,Alloc>::rend()
	{
		return(iterator(begin()));
	}

	template <class T, class Alloc >
	typename vector<T,Alloc>::const_reverse_iterator vector<T,Alloc>::rend() const
	{
		return(const_reverse_iterator(begin()));
	}


/*
**==========================
**	MODIFIERS FUNCTIONS
**==========================
*/
// here we assign the value between first to last, the new size will be the difference between the 2

	template <class T, class Alloc>
	void vector<T, Alloc>::assign (iterator first, iterator last)
	{
		size_type n = last - first;
		reserve(n);
		for (size_type i = 0; i < n; i++, first++) {
			_alloc.destroy(_array + i);
			_alloc.construct(_array + i, *first);
		}
		_size = n;
	}
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
	void vector<T, Alloc>::insert(iterator position, size_type n,
												const value_type& val)
	{
		vector<T, Alloc> temp(position, this->end()); // temp to store the data of the end of the temp
		this->_size -= this->end() - position; // keeping the size before value n;
		for (size_type i = 0; i < n; i++)
			this->push_back(val);
		iterator begin = temp.begin();
		iterator end = temp.end();
		while (begin != end)
		{
			this->push_back(*begin);
			++begin;
		}
	}

	template <class T, class Alloc>
	typename vector<T,Alloc>::iterator
			vector<T, Alloc>::insert(iterator position, const value_type& val)
	{
		size_type n = position - this->begin();
		//reserve(this->_size + n);
		this->insert(position, 1, val);
		return(iterator(&this->_array[n]));
	}

	template <class T, class Alloc>
	void vector<T, Alloc>::insert(iterator position, iterator first, iterator last)
	{
		vector<T, Alloc> temp(position, this->end()); // what we want to save
		this->_size -= (this->end() - position); // our new size ending at position
		while (first != last)
		{
			this->push_back(*first);
			first++;
		} // inserting the value on front at the position
		iterator it_begin = temp.begin();
		iterator it_end = temp.end();
		while (it_begin != it_end)
		{
			this->push_back(*it_begin);
			++it_begin;
		} // Adding the rest of the value

	}

	template <typename T, typename Alloc>
	typename vector<T, Alloc>::iterator vector<T, Alloc>::erase(iterator position)
	{
		size_type pos = position - this->begin();
		this->_alloc.destroy(&this->_array[pos]);
		shift_left(pos, 1);
		this->_size -= 1;
		return iterator(_array + pos);
	}

	template <typename T, typename Alloc>
	typename vector<T, Alloc>::iterator vector<T, Alloc>::erase(iterator first,
											iterator last)
	{
		size_type diff = last - first;
		size_type i = first - begin();
		size_type n = last - begin();
		while (*first != *last) // we destroy the memory allocated between first and last
		{
			_alloc.destroy(&(*first));
			++first;
		}
		shift_left(n, i - n);
		this->_size -= diff;
		return iterator(this->_array + n); // we return at the iterator which points on last
	}

	template <class T, class Alloc>
	void vector<T, Alloc>::push_back(const value_type& val)
	{
		if (capacity() == size())
		{
			if (size() == 0)
				this->reserve(2); // I attribute the memory of 2 for the program
			else
			{
				this->reserve(capacity() + 1);
			}
		}
		this->_array[this->_size] = val;
		this->_size += 1;
	}

	template <class T, class Alloc>
	void vector<T, Alloc>::pop_back()
	{
		this->_alloc.destroy(&this->_array[this->size()]);
		this->_size -= 1;
	}

	template <class T, class Alloc>
	void vector<T, Alloc>::swap(vector &x)
	{
		std::swap(this->_array, x._array);
		std::swap(this->_size, x._size);
		std::swap(this->_capacity, x._capacity);
		std::swap(this->_alloc, x._alloc);
	}

	template <class T, class Alloc>
	void vector<T, Alloc>::clear()
	{
		if (_array) {
				for (size_t i = 0; i < _size; i++)
					_alloc.destroy(_array + i);
			}
		destroy_array(this->_size);
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

	template <class T, class Alloc>
	void vector<T, Alloc>::shift_left(size_type pos, size_type n) {
		for (; pos < _size && pos + n < _capacity; pos++) {
			_alloc.construct(_array + pos, _array[pos + n]);
			_alloc.destroy(_array + pos + n);
		}
	}

}

#endif