/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 14:26:38 by vincent           #+#    #+#             */
/*   Updated: 2022/06/26 16:44:29 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP
#include "../inc/Vector.hpp"


namespace ft
{

/*
**==========================
**  IS INTEGRAL FUNCTIONS
**==========================
*/
	template <class T, T v>
    class integral_constant
    {
    public:
        const static T value = v;
        typedef T value_type;
        typedef integral_constant<T, v> type;
        const value_type operator()() const { return value; }
    };

	typedef integral_constant<bool, true> true_type;
    typedef integral_constant<bool, false> false_type;

	template <class T>
    struct is_integral : public false_type
    {
    };

    template <class T>
    struct is_integral<const T> : public is_integral<T>
    {
    };

    template <class T>
    struct is_integral<volatile const T> : public is_integral<T>
    {
    };
    template <class T>
    struct is_integral<volatile T> : public is_integral<T>
    {
    };

	template <>
    struct is_integral<unsigned char> : public true_type
    {
    };

    template <>
    struct is_integral<unsigned short> : public true_type
    {
    };

    template <>
    struct is_integral<unsigned int> : public true_type
    {
    };

    template <>
    struct is_integral<unsigned long> : public true_type
    {
    };

    template <>
    struct is_integral<signed char> : public true_type
    {
    };
    template <>
    struct is_integral<short> : public true_type
    {
    };

    template <>
    struct is_integral<int> : public true_type
    {
    };

    template <>
    struct is_integral<long long int> : public true_type
    {
    };

    template <>
    struct is_integral<unsigned long long int> : public true_type
    {
    };

    template <>
    struct is_integral<char> : public true_type
    {
    };

    template <>
    struct is_integral<bool> : public true_type
    {
    };

/*
**==========================
**  lexicographical FUNCTIONS
**==========================
*/

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

/*
**==========================
**  ENABLE_IF FUNCTION
**==========================
*/

	template<bool B, class T = void>
	struct enable_if {};

	template<class T>
	struct enable_if<true, T> { typedef T type; };
}

/*
**==========================
**  PAIR FUNCTION
**==========================
*/
// std::pair is a class template that provides a way to store two heterogeneous objects as a single unit.
// A pair is a specific case of a std::tuple with two elements.
namespace ft
{
    template <class T1, class T2>
    class pair
    {
    public :
        typedef T1  first_type;  // here we will give the type int or float for exemple
        typedef T2  second_type;

        T1          first;
        T2          second;
        pair(void) : first(T1()), second (T2()) {}; // here it is initialized to 0
        template <typename U, typename V>
        // We find the first and second from src
        pair(pair<U, V> const &src) : first(src.first), second(src.second) {};
        pair(first_type const &x, second_type const &y) : first(x), second(y) {};
        pair &operator=(const pair &other)
        {
            if (this != &other)
            {
                first = other.first;
                second = other.second;
            }
            return (*this);
        }
    };

    template <class T1, class T2>
    bool operator==(const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs)
    {
        return (lhs.first == rhs.first && lhs.second == rhs.second);
    }

    template <class T1, class T2>
    bool operator!=(const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs)
    {
        return (!(lhs == rhs));
    }

    template <class T1, class T2>
    bool operator<(const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs)
    {
         return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
    }

    template <class T1, class T2>
    bool operator<=(const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs)
    {
        return (!(lhs < rhs));
    }

    template <class T1, class T2>
    bool operator>(const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs)
    {
        return (lhs < rhs);
    }

    template <class T1, class T2>
    bool operator>=(const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs)
    {
        return (!(lhs < rhs));
    }

    //Creates a std::pair object, deducing the target type from the types of arguments.
    template <typename T1, typename T2>
    pair<T1, T2> make_pair(T1 x, T2 y)
    {
        return (pair<T1, T2>(x, y));
    }
}


#endif