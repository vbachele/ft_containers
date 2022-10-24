#ifndef VECTOR_HPP
# define VECTOR_HPP
#include <iostream>
#include <memory>
#include <iostream>
#include <cstdlib>
#include "limits"
#include "./Vector_iterators.hpp"
#include "./lexicographical_compare.hpp"
#include "./equal.hpp"
#include "./ReverseIterator.hpp"
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
		typedef T											value_type;
		typedef Alloc										allocator_type;
		typedef size_t										size_type;
		typedef value_type*									pointer;
		typedef const value_type*							const_pointer;
		typedef value_type&									reference;
		typedef const value_type&							const_reference;
		typedef ft::vector_iterator<value_type>				iterator;
		typedef ft::vector_iterator<const value_type>		const_iterator;
		typedef ft::reverse_iterator<iterator>				reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

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
		iterator begin() { return iterator(this->_array); }

		iterator end() { return iterator(this->_array + _size); }

		const_iterator begin() const { return const_iterator(this->_array); }

		const_iterator end() const { return const_iterator(this->_array + _size); }

		reverse_iterator rbegin() { return(reverse_iterator(end())); }
		const_reverse_iterator rbegin() const { return(const_reverse_iterator(end()));}
		reverse_iterator rend() { return reverse_iterator(this->begin()); }
		const_reverse_iterator rend() const{ return const_reverse_iterator(this->begin()); }

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
				throw std::out_of_range("Index out of range");
			return (this->_array[n]);
		};
		reference 			operator[] (size_type n) {return(this->_array[n]);};
		const_reference 	operator[] (size_type n) const {return(this->_array[n]);};
		reference front() {return (this->_array[0]);};
		const_reference front() const {return (this->_array[0]);};
		reference back() {return (this->_array[this->size() -1]);};
		const_reference back() const {return (this->_array[this->size() -1]);};
	/*std::allocator<T>
	**==========================================
	** NON-MEMBER FUNCTION OVERLOAD DECLARATIONS
	**==========================================
	*/
	//void swap (vector& x, vector& y);

	private:
		allocator_type	_alloc;
		size_type		_size; // size of the container
		size_type		_capacity; // size of the memory
		pointer			_array; // pointer to the array

	protected:
		template<class InputIt>
		size_type iterator_distance(InputIt first, InputIt last)
		{
			size_type count = 0;
			for (;first != last; first++) {
				count++;
			}
			return count;
		}
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
	}
/*** copy constructor ***/
	template < class T, class Alloc >
	vector<T,Alloc>::vector(const vector& x)
	{
		this->_size = 0;
		this->_alloc = std::allocator<T>();
		this->_capacity = 0;
		this->_array = 0;
		*this = x;
	}

/*** range constructor ***/
	template <class T, class Alloc>
	vector<T, Alloc>::vector(iterator first, iterator last,
			const allocator_type& alloc)
	{
		this->_size = 0;
		this->_capacity = 0;
		this->_alloc = alloc;
		this->_array = 0;
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
		clear();
		if (this->_capacity < x._size)
			reserve(x._capacity);
		this->_size = x._size;
		for (size_type i = 0; i < x._size; i++)
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
		return this->_alloc.max_size();
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
		if (n < _size)
		{
			this->erase(this->begin() + n, this->end());
		}
		else if (n > _size)
		{
			this->insert(this->end(), n - this->_size, val);
		}
	}

	template < class T, class Alloc >
	bool vector<T, Alloc>::empty() const
	{
		if (this->size() == 0)
			return(1);
		return (0);
	}

	template <class T, class Alloc >
	void vector <T, Alloc>::reserve(size_type n)
	{
		if (n > this->max_size())
			throw std::length_error("vector::reserve");
		if (n > this->capacity()) {
			pointer tmp = this->_array;
			this->_array = this->_alloc.allocate(n);
			this->_capacity = n;
			for (size_t i = 0; i < this->_size; i++) {
				_alloc.construct(this->_array + i, *(tmp +i));
				_alloc.destroy(tmp + i);
			}
			_alloc.deallocate(tmp, this->_capacity);
		}
	}

		template < class T, class Alloc >
	size_t vector <T, Alloc>::capacity() const
	{
		return (this->_capacity);
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
		size_type n = iterator_distance(first, last);
		this->clear();
		if (n > this->_capacity)
		{
			// ternaire if this capacity, on fait reserve(n) sinon capacity
			this->_capacity == 0 ? reserve(n) : reserve(this->_capacity * 2);
		}
		while (this->_size < n) {
			this->push_back(*first++);
		}
	}
	template <class T, class Alloc>
	void vector<T, Alloc>::assign(size_type n, const value_type& val)
	{
		this->clear();
		if (n > this->_capacity)
		{
			// ternaire if this capacity, on fait reserve(n) sinon capacity
			this->_capacity == 0 ? reserve(n) : reserve(this->_capacity * 2);
		}
		while (this->_size < n) {
			this->push_back(val);
		}
	}

	template <class T, class Alloc>
	void vector<T, Alloc>::insert(iterator position, size_type n,
												const value_type& val)
	{
		size_type index = position - this->begin();
		if (n)
		{
			if (this->size() + n > this->capacity())
			{
				reserve((this->size() + n) * 1.5);
			}
			for (size_type i = this->_size; i > index; i--)
			{
				this->_alloc.construct(this->_array + i + n - 1, *(this->_array + i -1));
				this->_alloc.destroy(this->_array + i - 1);
			}
			for (size_type i = 0; i < n; i++)
			{
				this->_alloc.construct(this->_array + index + i, val);
				this->_size++;
			}
		}
	}

	template <class T, class Alloc>
	typename vector<T,Alloc>::iterator
			vector<T, Alloc>::insert(iterator position, const value_type& val)
	{
		size_type index = position - this->begin();
		if (this->size() == 0)
			this->push_back(val);
		else
		{
			if (this->size() == this->capacity())
				reserve(this->capacity() * 2);
			for(size_type i = this->size(); i > index; i--)
			{
				this->_alloc.construct(this->_array + i, *(this->_array + i - 1));
				this->_alloc.destroy(this->_array + i - 1); // move to +1 the value of the array
			}
			this->_alloc.construct(this->_array + index, val); // put the value at the right pos
			this->_size++;
		}
		return(iterator(this->_array + index));
	}

	template <class T, class Alloc>
	void vector<T, Alloc>::insert(iterator pos, iterator first, iterator last)
	{
		size_type count = iterator_distance(first, last);
		ft::vector<value_type, Alloc> tmp(first, last);
		size_type position = pos - begin();
		while(count--)
		{
			this->insert(begin() + position, tmp[count]);
		}
	}

	template <typename T, typename Alloc>
	typename vector<T, Alloc>::iterator vector<T, Alloc>::erase(iterator pos)
	{
		iterator ret = pos == this->end() ? this->end() : pos;
		while (pos + 1 != this->end()) {
			*pos = *(pos + 1);
			pos++;
		}
		this->pop_back();
		return ret;
	}

	template <typename T, typename Alloc>
	typename vector<T, Alloc>::iterator vector<T, Alloc>::erase(iterator first,
											iterator last)
	{
		iterator start = first;
		iterator end = this->end();
		size_type count = last - first;
		if (count == 0) return last;

		while (first + count != this->end()) {
			*(first) = *(first + count);
			first++;
		}
		while (count--) {
			this->pop_back();
		}
		if (last == end) {
			return this->end();
		}
		return iterator(start);
	}

	template <class T, class Alloc>
	void vector<T, Alloc>::push_back(const value_type& val)
	{
		if (this->_size != this->_capacity)
		{
			this->_alloc.construct(this->_array + this->_size, val);
			this->_size++;
		}
		else
		{
			this->_capacity == 0 ? reserve(1) : reserve(this->_capacity * 2);
			this->_alloc.construct(this->_array + this->_size, val);
			this->_size++;
		}
	}

	template <class T, class Alloc>
	void vector<T, Alloc>::pop_back()
	{
		if(this->_size)
		{
			this->_alloc.destroy(&this->_array[this->size() - 1]);
			this->_size -= 1;
		}
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
			throw std::out_of_range("Index out of range");
		return (this->_array[n]);
	}

	/*
	**==========================
	** NON-MEMBER FUNCTION OVERLOAD
	**==========================
	*/

	template< class T, class Alloc >
	bool operator==( const ft::vector<T,Alloc>& lhs,
					 const ft::vector<T,Alloc>& rhs ) {
		return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	};

	template<class T, class Alloc>
	bool operator!=(const ft::vector<T,Alloc>& lhs,
					const ft::vector<T,Alloc>& rhs) { return !(lhs == rhs); };

	template<class T, class Alloc>
	bool operator<(const ft::vector<T,Alloc>& lhs,
				   const ft::vector<T,Alloc>& rhs) {
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	};

	template<class T, class Alloc>
	bool operator<=(const ft::vector<T,Alloc>& lhs,
					const ft::vector<T,Alloc>& rhs) {
		return !(rhs < lhs);
	};

	template<class T, class Alloc>
	bool operator>(const ft::vector<T,Alloc>& lhs,
				   const ft::vector<T,Alloc>& rhs) {
		return rhs < lhs;
	};

	template<class T, class Alloc>
	bool operator>=(const ft::vector<T,Alloc>& lhs,
					const ft::vector<T,Alloc>& rhs) {
		return !(lhs < rhs);
	};

	template <class T, class Alloc>
	void swap(vector<T,Alloc>& x, vector<T,Alloc>& y)
	{
		y.swap(x);
	}
}

#endif