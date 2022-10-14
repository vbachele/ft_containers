#ifndef ITERATORS_HPP
# define ITERATORS_HPP
#include "./Vector.hpp"
#include <algorithm>


namespace ft
{
	template <class T>
	class vector_iterator
	{
		public :
			typedef std::random_access_iterator_tag iterator_category; //tag of our iterator
			typedef std::ptrdiff_t					difference_type; // use to identify distance between iterators steps
			typedef T								value_type;
			typedef value_type*						pointer;
			typedef value_type&						reference;

		/*
		**==========================
		**    CANONICAL FORM
		**==========================
		*/
		vector_iterator()
		{
			this->_ptr = NULL;
		}

		vector_iterator(pointer ptr)
		{
			this->_ptr = ptr;
		}

		vector_iterator(const vector_iterator &x)
		{
			this->_ptr = x._ptr;
		}

		~vector_iterator() {}

		pointer	get_ptr() const
		{
			return (this->_ptr);
		}

		/*
		**==========================
		**   IMPLEMENT OPERATORS
		**==========================
		*/

		//renvoie la valeur pointé par l'iterator
		reference operator*() const
		{
			return *this->_ptr;
		}

		//renvoie l'addresse du pointer de l'iterator
		pointer operator->()
		{
			return this->_ptr;
		}

		vector_iterator& operator++() // prefix incrementation
		{
			this->_ptr++;
			return *this;
		}

		vector_iterator operator++(int) // postfix incrementation
		{
			vector_iterator tmp = *this;
			++(*this);
			return tmp;
		}

		vector_iterator& operator--()
		{
			this->_ptr--;
			return *this;
		}

		vector_iterator& operator--(int)
		{
			vector_iterator tmp = *this;
			++(*this);
			return tmp;
		}

		vector_iterator& operator=(const vector_iterator &other)
		{
			if (this != other)
				this->_ptr = other._ptr;
			return *this;
		}

		vector_iterator& operator+=(value_type n)
		{
			this->_ptr += n;
			return *this;
		}

		vector_iterator& operator-=(value_type n)
		{
			this->_ptr += n;
			return *(this);
		}

		vector_iterator& operator[](value_type n) //access to the element n
		{
			return *(this->_ptr + n);
		}

		difference_type operator-(const vector_iterator &other) const // take 2 operators and do the difference between iterators
		{
			difference_type res = this->_ptr - other._ptr;
			return(res);
		}

		difference_type operator+(const vector_iterator &other) const // take 2 operators and do the addition between the 2iterators
		{
			difference_type res = this->_ptr + other._ptr;
			return(res);
		}


		bool operator==(const vector_iterator &other)
		{
			return(this->_ptr == other._ptr);
		}

		bool operator!=(const vector_iterator &other)
		{
			return(this->_ptr != other._ptr);
		}

		bool operator>(const vector_iterator &other)
		{
			bool b = this->_ptr > other->_ptr;
			return b;
		}

		bool operator>=(const vector_iterator &other)
		{
			bool b = this->_ptr >= other->_ptr;
			return b;
		}

		bool operator<(const vector_iterator &other)
		{
			bool b = this->_ptr < other._ptr;
			return b;
		}

		bool operator<=(const vector_iterator &other)
		{
			bool b = this->_ptr <= other._ptr;
			return b;
		}

		private :
			pointer _ptr;
	};

	template <typename Iterator>
	std::ostream &operator<<(std::ostream &o, vector_iterator<Iterator> &rhs)
	{
		o << *rhs.get_ptr();
   		return o;
	}
}

#endif