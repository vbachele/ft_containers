/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:21:14 by vbachele          #+#    #+#             */
/*   Updated: 2022/06/14 18:22:03 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	STACK_HPP
# define STACK_HPP
#include "iostream"

namespace ft
{
	// We define the Container as a vector of type T
template <class T, class Container = vector<T> >
class stack
{
	public :
		typedef T									value_type;
		typedef	Container							container_type;
		typedef typename container_type::size_type size_type;

	public :
		//We give a container_type vector as parameter
		stack (const container_type& ctnr = container_type()) : _under_container(ctnr) {}
		virtual ~stack() {};
	/*
	**==========================
	**     MEMBERS FUNCTIONS
	**==========================
	*/
	size_type size() const
		{
			size_type size = this->_under_container.size();
			return (size);
		}
	bool empty(void) const
	{
		bool res = this->_under_container.size() == 0;
		return (res);
	}

	container_type get_container_type(void) const
	{
		return (this->_under_container);
	}

	value_type	&top()
	{
		return(this->_under_container.back());
	}
	const value_type& top() const
	{
		return(this->_under_container.back());
	}

	void push (const value_type& val)
	{
		this->_under_container.push_back(val);
	}

	void pop()
	{
		this->_under_container.pop_back();
	}


	protected :
		container_type	_under_container; // here it is a sub container
};

template <class T, class Container>
bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{
	bool res = lhs.get_container_type() != rhs.get_container_type();
	return (res);
}
template <class T, class Container>
bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{
	return (!(lhs == rhs));
}
template <class T, class Container>
bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{
	bool res = lhs.get_container_type() < rhs.get_container_type();
	return (res);
}
template <class T, class Container>
bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{
	bool res = lhs.get_container_type() <= rhs.get_container_type();
	return (res);
}
template <class T, class Container>
bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{
	return (!(lhs < rhs));
}
template <class T, class Container>
bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{
	return (!(lhs <= rhs));
}

}

#endif