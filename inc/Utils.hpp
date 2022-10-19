#ifndef UTILS_HPP
#define UTILS_HPP
#include "./Vector_Iterators.hpp"

/*
**==========================
**  ITERATOR TRAITS
**==========================
*/

	/*** We define the iterator trait here ***/
	template <class Iterator>
	class iterator_traits
	{
	public:
		typedef typename Iterator::iterator_category iterator_category;
		typedef typename Iterator::value_type        value_type;
		typedef typename Iterator::difference_type   difference_type;
		typedef typename Iterator::pointer           pointer;
		typedef typename Iterator::reference         reference;
	};

	/*** The second iterator trait is for the case you have a pointer ***/
	template <class T>
	class iterator_traits<T *>
	{
	public:
		typedef std::random_access_iterator_tag 	iterator_category;
		typedef T                         		 	value_type;
		typedef std::ptrdiff_t                 		difference_type;
		typedef T*									pointer;
		typedef T&                        		 	reference;
	};

	template <class T>
	class iterator_traits<const T *>
	{
	public:
		typedef std::ptrdiff_t 					difference_type;
		typedef T 								value_type;
		typedef const T 						*pointer;
		typedef const T 						&reference;
		typedef std::random_access_iterator_tag iterator_category;
	};

#endif