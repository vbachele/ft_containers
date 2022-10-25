#ifndef REVERSE_ITERATORS_HPP
# define REVERSE_ITERATORS_HPP
#include "Traits_iterators.hpp"

/*
**==========================
** CLASS REVERSE ITERATOR
**==========================
*/
namespace ft {

	template<class Iter>
	class reverse_iterator : public Iter {
		public:
			typedef Iter iterator_type;
			typedef typename ft::iterator_traits<Iter>::iterator_category iterator_category;
			typedef typename ft::iterator_traits<Iter>::value_type value_type;
			typedef typename ft::iterator_traits<Iter>::difference_type difference_type;
			typedef typename ft::iterator_traits<Iter>::pointer pointer;
			typedef typename ft::iterator_traits<Iter>::reference reference;

			reverse_iterator() : current(iterator_type()) {}

			explicit reverse_iterator(iterator_type x) : current(x) {}

			explicit reverse_iterator(const reverse_iterator& x) : current(x.current) {}

			template<class U>
			reverse_iterator(const reverse_iterator<U> &other) : current(other.base()) {}

			iterator_type
			base() const { return current; };

			reference operator*() const { Iter tmp = current; return *(--tmp); };
			pointer operator->() const { return &(operator*()); };

			reference
			operator[](difference_type n) const { return *(*this + n); };

			reverse_iterator& operator++() { --current; return *this; };
			reverse_iterator& operator--() { ++current; return *this; };
			reverse_iterator operator++(int) {reverse_iterator tmp = *this; ++*this; return tmp; };
			reverse_iterator operator--(int) {reverse_iterator tmp = *this; --*this; return tmp; };
			reverse_iterator operator+(difference_type n) const { return reverse_iterator(current - n); };
			reverse_iterator operator-(difference_type n) const { return reverse_iterator(current + n); };
			reverse_iterator& operator+=(difference_type n) { current -= n; return *this; };
			reverse_iterator& operator-=(difference_type n) { current += n; return *this; };


		protected:
			iterator_type current;

	};

	template <class Iterator>
	bool operator==(const reverse_iterator<Iterator> &lhs,
					const reverse_iterator<Iterator> &rhs) {
		return (lhs.base() == rhs.base());
	}

	template<class IteratorL, class IteratorR>
	bool operator==(const reverse_iterator<IteratorL>& lhs,
					const reverse_iterator<IteratorR>& rhs) {
		return lhs.base() == rhs.base();
	}

	template <class Iterator>
	bool operator!=(const reverse_iterator<Iterator> &lhs,
					const reverse_iterator<Iterator> &rhs) {
		return (lhs.base() != rhs.base());
	}

	template <class IteratorA, class IteratorB>
	bool operator!=(const reverse_iterator<IteratorA> &lhs,
					const reverse_iterator<IteratorB> &rhs) {
		return (lhs.base() != rhs.base());
	}

	template <class Iterator>
	bool operator<(const reverse_iterator<Iterator> &lhs,
				   const reverse_iterator<Iterator> &rhs) {
		return (lhs.base() > rhs.base());
	}

	template <class IteratorL, class IteratorR>
	bool operator<(const reverse_iterator<IteratorL> &lhs,
				   const reverse_iterator<IteratorR> &rhs) {
		return (lhs.base() > rhs.base());
	}

	template <class Iterator>
	bool operator<=(const reverse_iterator<Iterator> &lhs,
					const reverse_iterator<Iterator> &rhs) {
		return (lhs.base() >= rhs.base());
	}

	template <class IteratorL, class IteratorR>
	bool operator<=(const reverse_iterator<IteratorL> &lhs,
					const reverse_iterator<IteratorR> &rhs) {
		return (lhs.base() >= rhs.base());
	}

	template <class Iterator>
	bool operator>(const reverse_iterator<Iterator> &lhs,
				   const reverse_iterator<Iterator> &rhs) {
		return (lhs.base() < rhs.base());
	}

	template <class IteratorL, class IteratorR>
	bool operator>(const reverse_iterator<IteratorL> &lhs,
				   const reverse_iterator<IteratorR> &rhs) {
		return (lhs.base() < rhs.base());
	}

	template <class Iterator>
	bool operator>=(const reverse_iterator<Iterator> &lhs,
					const reverse_iterator<Iterator> &rhs) {
		return (lhs.base() <= rhs.base());
	}

	template <class IteratorL, class IteratorR>
	bool operator>=(const reverse_iterator<IteratorL> &lhs,
					const reverse_iterator<IteratorR> &rhs) {
		return (lhs.base() <= rhs.base());
	}


	template <class Iterator>
	reverse_iterator<Iterator>	operator+(
			typename reverse_iterator<Iterator>::difference_type n,
			const reverse_iterator<Iterator> &rev_it) {
		return (rev_it + n);
	}


	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-(
			const reverse_iterator<Iterator> &lhs,
			const reverse_iterator<Iterator> &rhs) {
		return (rhs.base() - lhs.base());
	}

	template<class IteratorL, class IteratorR>
	typename reverse_iterator<IteratorL>::difference_type
	operator-(const reverse_iterator<IteratorL>& lhs,
				const reverse_iterator<IteratorR>& rhs) {
		return rhs.base() - lhs.base();
	}


}

#endif
