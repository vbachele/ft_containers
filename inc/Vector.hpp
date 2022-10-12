#ifndef VECTOR_HPP
# define VECTOR_HPP
#include <iostream>
#include <memory>

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

	/*** Constructor ***/
		explicit vector (const allocator_type& alloc = allocator_type());
		explicit vector (size_type n, const value_type& val = value_type(),
			const allocator_type& alloc = allocator_type());
		template <class InputIterator> vector (InputIterator first, InputIterator last,
			const allocator_type& alloc = allocator_type());
		vector (const vector& x);
	/*** End of constructor ***/

	private:
		allocator_type	_alloc;
		size_type		_size; // size of the container
		size_type		_capacity; // size of the memory
		pointer			_array; // pointer to the array
	};

/*
**==========================
** FUNCTION DEFINITION
**==========================
*/

/*** Constructors ***/
	template < class T, class Alloc >
	vector<T,Alloc>::vector(const allocator_type &Alloc)
	{
		this->_size = 0;
		this->_capacity = 0;
		this->_alloc = alloc; // memory of the type
		this->_array = NULL;
	}

	template < class T, class Alloc >
	vector<T,Alloc>::vector(size_type n, const value_type &val,
			const allocator_type &alloc)
	{
		this->_size = n;
		this->_alloc = alloc;
		this->_capacity = n;
		this->_array = alloc.allocate(this->capacity); // allocation for memory of the capacity for the array
		for (i = 0; i < this->size ; i++)
			this->_array[i] = val;
	}
	
	template < class T, class Alloc >
	vector<T,Alloc>::vector(const vector& x)
	{

	}
}
/*** End of constructor ***/

#endif