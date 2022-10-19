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
			typedef vector_iterator 				iterator;

		/*
		**==========================
		**    CANONICAL FORM
		**==========================
		*/
		vector_iterator()
		{
			this->_ptr = NULL;
		}

		vector_iterator(pointer const ptr)
		{
			this->_ptr = ptr;
		}

		vector_iterator(const vector_iterator &x)
		{
			this->_ptr = x._ptr;
		}

		template<class Iter>
		vector_iterator(const vector_iterator<Iter>& i) : _ptr(i.base()) {};

		~vector_iterator() {}

		pointer	base() const
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
		pointer operator->() const
		{
			return this->_ptr;
		}

		iterator& operator++() // prefix incrementation
		{
			this->_ptr++;
			return *this;
		}

		iterator operator++(int) // postfix incrementation
		{
			iterator tmp = *this;
			++this->_ptr;
			return (tmp);
		}

		iterator& operator--()
		{
			this->_ptr--;
			return (*this);
		}

		iterator operator--(int)
		{
			iterator tmp = *this;
			--this->_ptr;
			return tmp;
		}

		iterator& operator=(const iterator &other)
		{
			if (this != &other)
				this->_ptr = other._ptr;
			return (*this);
		}

		iterator& operator+=(difference_type n)
		{
			this->_ptr += n;
			return (*this);
		}

		iterator& operator-=(difference_type n)
		{
			this->_ptr += n;
			return *this;
		}

		reference operator[](size_t n) //access to the element n
		{
			return (this->_ptr[n]);
		}

		difference_type operator-(const iterator &other) const // take 2 operators and do the difference between iterators
		{
			difference_type res = this->_ptr - other._ptr;
			return(res);
		}

		iterator	operator+(const difference_type &n) const {
			return iterator(_ptr + n);
		}

		difference_type operator+(const iterator &other) const // take 2 operators and do the addition between the 2iterators
		{
			difference_type res = this->_ptr + other._ptr;
			return(res);
		}

		iterator	operator-(const difference_type &n) const {
			return iterator(_ptr - n);
		}

		private :
			pointer _ptr;
	};

/*
**==========================
** NON MEMBER FUNCTION BOOL
**==========================
*/
	template<typename IteratorL, typename IteratorR>
	inline bool
	operator==(const vector_iterator<IteratorL>& lhs,
			   const vector_iterator<IteratorR>& rhs) {
		return lhs.base() == rhs.base(); }

	template<typename IteratorL, typename IteratorR>
	inline bool
	operator!=(const vector_iterator<IteratorL>& lhs,
			   const vector_iterator<IteratorR>& rhs) {
		return lhs.base() != rhs.base(); }

	template<typename IteratorL, typename IteratorR>
	inline bool
	operator<(const vector_iterator<IteratorL>& lhs,
			  const vector_iterator<IteratorR>& rhs) {
		return lhs.base() < rhs.base(); }

	template<typename IteratorL, typename IteratorR>
	inline bool
	operator>(const vector_iterator<IteratorL>& lhs,
			  const vector_iterator<IteratorR>& rhs)
	{ return lhs.base() > rhs.base(); }

	template<typename IteratorL, typename IteratorR>
	inline bool
	operator<=(const vector_iterator<IteratorL>& lhs,
			   const vector_iterator<IteratorR>& rhs)
	{ return lhs.base() <= rhs.base(); }

	template<typename IteratorL, typename IteratorR>
	inline bool
	operator>=(const vector_iterator<IteratorL>& lhs,
			   const vector_iterator<IteratorR>& rhs)
	{ return lhs.base() >= rhs.base(); }

	template<class IteratorL, class IteratorR>
	inline typename vector_iterator<IteratorL>::difference_type
	operator-(const vector_iterator<IteratorL>& lhs,
				const vector_iterator<IteratorR>& rhs) {
		return lhs.base() - rhs.base();
	}

	template<class IteratorL, class IteratorR>
	inline typename vector_iterator<IteratorL>::difference_type
	operator+(const vector_iterator<IteratorL>& lhs,
			  const vector_iterator<IteratorR>& rhs) {
		return lhs.base() + rhs.base();
	}

	template<typename Iterator>
	inline vector_iterator<Iterator>
	operator+(typename vector_iterator<Iterator>::difference_type lhs,
				const vector_iterator<Iterator>& rhs) {
		return vector_iterator<Iterator>(rhs.base() + lhs);
	}

	template<typename Iterator>
	inline vector_iterator<Iterator>
	operator-(typename vector_iterator<Iterator>::difference_type lhs,
			  const vector_iterator<Iterator>& rhs) {
		return vector_iterator<Iterator>(rhs.base() - lhs);
	}
}




// /*
// **==========================
// ** CLASS REVERSE ITERATOR
// **==========================
// */
// namespace ft
// {
// 	template<class Iterator>
// 	class reverse_iterator
// 	{
// 	public:
// 	// iterator _traits is the type trait class that provides uniform interface
// 		typedef 		Iterator 												iterator_type;
// 		typedef typename iterator_traits<iterator_type>::iterator_category		iterator_category;
// 		typedef typename iterator_traits<iterator_type>::value_type				value_type;
// 		typedef typename iterator_traits<iterator_type>::difference_type		difference_type;
// 		typedef typename iterator_traits<iterator_type>::pointer				pointer;
// 		typedef typename iterator_traits<iterator_type>::reference				reference;

// 	/*
// 	**==========================
// 	**  CONSTRUCTOR/DESTRUCTOR
// 	**==========================
// 	*/
// 		reverse_iterator()
// 		{
// 			this->_ptr = NULL;
// 		}

// 		reverse_iterator(iterator_type it)
// 		{
// 			this->_ptr = it;
// 		}

// 		reverse_iterator(const reverse_iterator& x)
// 		{
// 			this->_ptr = x._ptr;
// 		}

// 		~reverse_iterator() {}

// 		iterator_type base() const
// 		{
// 			return (this->_ptr);
// 		}

// 		reference operator*() const
// 		{
// 			iterator_type it = this->_ptr;
//       	  	it--;
// 			return(*it);
// 		}

// 		reverse_iterator operator+(difference_type n) const
// 		{
// 			reverse_iterator res = this->_ptr - n;
// 			return (res);
// 		}

// 		reverse_iterator operator-(difference_type n) const
// 		{
// 			reverse_iterator res = this->_ptr + n;
// 			return (res);
// 		}

// 		reverse_iterator& operator+= (difference_type n)
// 		{
// 			this->_ptr -= n;
// 			return (this);
// 		}

// 		reverse_iterator& operator-= (difference_type n)
// 		{
// 			this->_ptr += n;
// 			return (this);
// 		}

// 		reverse_iterator& operator++()
// 		{
// 			this->_ptr--;
// 			return (*this);
// 		}

// 		reverse_iterator& operator++(int)
// 		{
// 			reverse_iterator tmp = *this;
// 			this->_ptr--;
// 			return (tmp);
// 		}

// 		reverse_iterator& operator--()
// 		{
// 			++this->_ptr;
// 			return (*this);
// 		}

// 		reverse_iterator& operator--(int)
// 		{
// 			reverse_iterator tmp = *this;
// 			++this->_ptr;
// 			return (tmp);
// 		}

// 		pointer operator->() const
// 		{
// 			return &(operator*());
// 		}

// 		reference operator[] (difference_type n) const
// 		{
// 			return (this->base()[n-1]);
// 		}
// 		private:
// 			iterator_type _ptr;
// 	};

// 	/*
// 	**==========================
// 	**  REVERSE NON MEMBER FUNCTIONS
// 	**==========================
// 	*/
// 	template <class Iterator>
// 	inline bool operator== (const reverse_iterator<Iterator>& lhs,
// 		const reverse_iterator<Iterator>& rhs)
// 	{
// 		return (lhs.base() == rhs.base());
// 	}

// 	template <class Iterator>
// 	inline bool operator!= (const reverse_iterator<Iterator>& lhs,
// 		const reverse_iterator<Iterator>& rhs)
// 	{
// 		return (lhs.base() != rhs.base());
// 	}

// 	template <class Iterator>
// 	inline bool operator< (const reverse_iterator<Iterator>& lhs,
// 		const reverse_iterator<Iterator>& rhs)
// 	{
// 		return(lhs.base() > rhs.base());
// 	}

// 	template <class Iterator>
// 	inline bool operator<= (const reverse_iterator<Iterator>& lhs,
// 		const reverse_iterator<Iterator>& rhs)
// 	{
// 		return(lhs.base() >= rhs.base());
// 	}

// 	template <class Iterator>
// 	inline bool operator> (const reverse_iterator<Iterator>& lhs,
// 		const reverse_iterator<Iterator>& rhs)
// 	{
// 		return(lhs.base() < rhs.base());
// 	}

// 	template <class Iterator>
// 	inline bool operator>= (const reverse_iterator<Iterator>& lhs,
// 		const reverse_iterator<Iterator>& rhs)
// 	{
// 		return(lhs.base() <= rhs.base());
// 	}

// 	template <class Iterator>
// 	inline reverse_iterator<Iterator> operator+ (typename reverse_iterator<Iterator>::difference_type n,
// 		const reverse_iterator<Iterator>& rev_it)
// 	{
// 		return (reverse_iterator<Iterator>(rev_it.base() - n));
// 	}

// 	template <class Iterator>
// 	inline reverse_iterator<Iterator> operator- (typename reverse_iterator<Iterator>::difference_type n,
// 		const reverse_iterator<Iterator>& rev_it)
// 	{
// 		return (reverse_iterator<Iterator>(rev_it.base() + n));
// 	}
// }

#endif