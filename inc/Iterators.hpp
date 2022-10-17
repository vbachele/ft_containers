#ifndef ITERATORS_HPP
# define ITERATORS_HPP
#include "./Vector.hpp"
#include <algorithm>
#include "./Utils.hpp"


namespace ft
{
/*
**==========================
** CLASS VECTOR ITERATOR
**==========================
*/
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

		vector_iterator operator--(int)
		{
			vector_iterator tmp = *this;
			++(*this);
			return tmp;
		}

		vector_iterator& operator=(const vector_iterator &other)
		{
			if (this != &other)
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

		vector_iterator	operator+(const difference_type &n) const {
			return vector_iterator(_ptr + n);
		}

		difference_type operator+(const vector_iterator &other) const // take 2 operators and do the addition between the 2iterators
		{
			difference_type res = this->_ptr + other._ptr;
			return(res);
		}

		vector_iterator	operator-(const difference_type &n) const {
			return vector_iterator(_ptr - n);
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
/*
**==========================
** CLASS REVERSE ITERATOR
**==========================
*/
namespace ft
{
	template<class Iterator>
	class reverse_iterator
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
		reverse_iterator()
		{
			this->_ptr = NULL;
		}

		reverse_iterator(iterator_type it)
		{
			this->_ptr = it;
		}

		reverse_iterator(const reverse_iterator& x)
		{
			this->_ptr = x._ptr;
		}

		~reverse_iterator() {}

		iterator_type base() const
		{
			return (this->_ptr);
		}

		reference operator*() const
		{
			iterator_type it = this->_ptr;
      	  	it--;
			return(*it);
		}

		// reverse_iterator operator+ (difference_type n) const
		// {
		// 	reverse_iterator res = this->_ptr - n;
		// 	return (res);
		// }

		reverse_iterator operator+(difference_type n) const
		{
			reverse_iterator res = this->_ptr - n;
			return (res);
		}

		// reverse_iterator operator-(difference_type n) const
		// {
		// 	reverse_iterator res = this->_ptr - n;
		// 	return (res);
		// }

		reverse_iterator operator-(difference_type n) const
		{
			reverse_iterator res = this->_ptr + n;
			return (res);
		}

		reverse_iterator& operator+= (difference_type n)
		{
			this->_ptr -= n;
			return (this);
		}

		reverse_iterator& operator-= (difference_type n)
		{
			this->_ptr += n;
			return (this);
		}

		reverse_iterator& operator++()
		{
			--this->_ptr;
			return (*this);
		}

		reverse_iterator& operator++(int)
		{
			reverse_iterator tmp = *this
			*this;
			return (tmp);
		}

		reverse_iterator& operator--()
		{
			++this->_ptr;
			return (*this);
		}

		reverse_iterator& operator--(int)
		{
			reverse_iterator tmp = *this;
			++(*this);
			return (tmp);
		}

		pointer operator->() const
		{
			return &(operator*());
		}

		reference operator[] (difference_type n) const
		{
			return (this->base()[n-1]);
		}
		private:
			iterator_type _ptr;
	};

	/*
	**==========================
	**  REVERSE NON MEMBER FUNCTIONS
	**==========================
	*/
	template <class Iterator>
	bool operator== (const reverse_iterator<Iterator>& lhs,
		const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template <class Iterator>
	bool operator!= (const reverse_iterator<Iterator>& lhs,
		const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template <class Iterator>
	bool operator< (const reverse_iterator<Iterator>& lhs,
		const reverse_iterator<Iterator>& rhs)
	{
		return(lhs.base() > rhs.base());
	}

	template <class Iterator>
	bool operator<= (const reverse_iterator<Iterator>& lhs,
		const reverse_iterator<Iterator>& rhs)
	{
		return(lhs.base() >= rhs.base());
	}

	template <class Iterator>
	bool operator> (const reverse_iterator<Iterator>& lhs,
		const reverse_iterator<Iterator>& rhs)
	{
		return(lhs.base() < rhs.base());
	}

	template <class Iterator>
	bool operator>= (const reverse_iterator<Iterator>& lhs,
		const reverse_iterator<Iterator>& rhs)
	{
		return(lhs.base() <= rhs.base());
	}

	template <class Iterator>
	reverse_iterator<Iterator> operator+ (typename reverse_iterator<Iterator>::difference_type n,
		const reverse_iterator<Iterator>& rev_it)
	{
		return (reverse_iterator<Iterator>(rev_it.base() - n));
	}

	template <class Iterator>
	reverse_iterator<Iterator> operator- (typename reverse_iterator<Iterator>::difference_type n,
		const reverse_iterator<Iterator>& rev_it)
	{
		return (reverse_iterator<Iterator>(rev_it.base() + n));
	}
}

#endif