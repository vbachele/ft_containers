#ifndef REVERSE_ITERATORS_HPP
# define REVERSE_ITERATORS_HPP
#include "./Vector.hpp"
#include <algorithm>
#include "./Traits_iterators.hpp"
#include "Vector_iterators.hpp"

/*
**==========================
** CLASS REVERSE ITERATOR
**==========================
*/
namespace ft
{
	template<class Iterator>
	class reverse_iterator : public Iterator
	{
	public:
	// iterator _traits is the type trait class that provides uniform interface
		typedef 		Iterator 												iterator_type;
		typedef typename iterator_traits<iterator_type>::iterator_category		iterator_category;
		typedef typename iterator_traits<iterator_type>::value_type				value_type;
		typedef typename iterator_traits<iterator_type>::difference_type		difference_type;
		typedef typename iterator_traits<iterator_type>::pointer				pointer;
		typedef typename iterator_traits<iterator_type>::reference				reference;

	/*
	**==========================
	**  CONSTRUCTOR/DESTRUCTOR
	**==========================
	*/
		reverse_iterator(iterator_type())
		{
			this->_ptr = iterator_type();
		}

		reverse_iterator(iterator_type it)
		{
			this->_ptr = it;
		}

		reverse_iterator(const reverse_iterator& x)
		{
			this->_ptr = x._ptr;
		}

		template<class U>
		reverse_iterator(const reverse_iterator<U> &other) : _ptr(other.base()) {}

		~reverse_iterator() {}

		iterator_type base() const
		{
			return (this->_ptr);
		}

		reference operator*() const
		{
			Iterator it = this->_ptr;
      	  	--it;
			return(*it);
		}

		reverse_iterator operator+(difference_type n) const
		{
			return (reverse_iterator (_ptr - n));
		}

		reverse_iterator operator-(difference_type n) const { return reverse_iterator(_ptr + n); };

		// reverse_iterator operator-(difference_type n) const
		// {
		// 	return (reverse_iterator (_ptr + n));
		// }

		reverse_iterator& operator+= (difference_type n)
		{
			this->_ptr -= n;
			return (*this);
		}

		reverse_iterator& operator-= (difference_type n)
		{
			this->_ptr += n;
			return (*this);
		}

		reverse_iterator& operator++()
		{
			--this->_ptr;
			return (*this);
		}

		reverse_iterator operator++(int)
		{
			reverse_iterator tmp = *this;
			++*this;
			return (tmp);
		}

		reverse_iterator& operator--()
		{
			++this->_ptr;
			return (*this);
		}

		reverse_iterator operator--(int)
		{
			reverse_iterator tmp = *this;
			--this->_ptr;
			return (tmp);
		}

		pointer operator->() const
		{
			return &(operator*());
		}

		reference operator[] (difference_type n) const
		{
			return *(*this + n);
		}
		protected:
			iterator_type _ptr;
	};

	/*
	**==========================
	**  REVERSE NON MEMBER FUNCTIONS
	**==========================
	*/
	template <class Iterator>
	inline bool operator== (const reverse_iterator<Iterator>& lhs,
		const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template <class Iterator>
	inline bool operator!= (const reverse_iterator<Iterator>& lhs,
		const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template <class Iterator>
	inline bool operator< (const reverse_iterator<Iterator>& lhs,
		const reverse_iterator<Iterator>& rhs)
	{
		return(lhs.base() > rhs.base());
	}

	template <class Iterator>
	inline bool operator<= (const reverse_iterator<Iterator>& lhs,
		const reverse_iterator<Iterator>& rhs)
	{
		return(lhs.base() >= rhs.base());
	}

	template <class Iterator>
	inline bool operator> (const reverse_iterator<Iterator>& lhs,
		const reverse_iterator<Iterator>& rhs)
	{
		return(lhs.base() < rhs.base());
	}

	template <class Iterator>
	inline bool operator>= (const reverse_iterator<Iterator>& lhs,
		const reverse_iterator<Iterator>& rhs)
	{
		return(lhs.base() <= rhs.base());
	}

	template <class Iterator>
	inline reverse_iterator<Iterator> operator+ (typename reverse_iterator<Iterator>::difference_type n,
		const reverse_iterator<Iterator>& rev_it)
	{
		return (reverse_iterator<Iterator>(rev_it.base() - n));
	}

	template <class Iterator>
	inline reverse_iterator<Iterator> operator- (typename reverse_iterator<Iterator>::difference_type n,
		const reverse_iterator<Iterator>& rev_it)
	{
		return (reverse_iterator<Iterator>(rev_it.base() + n));
	}
}

#endif