/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 14:26:38 by vincent           #+#    #+#             */
/*   Updated: 2022/06/14 14:30:43 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP
#include "../inc/Vector.hpp"

namespace ft
{
	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
									InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return (false);
			else if (*first1 < *first2)
				return (true);
			++first1;
			++first2;
		}
		return (first2 != last2);
	}

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
}
#endif