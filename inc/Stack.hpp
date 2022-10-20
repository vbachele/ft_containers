#ifndef STACK_HPP
# define STACK_HPP
#include "Vector.hpp"
#include "iostream"

namespace ft
{
	template< class T, class Container = ft::vector<T> >
	class stack
	{
	public:
		typedef Container					container_type;
		typedef typename Container::value_type		value_type;
		typedef typename Container::size_type		size_type;
		typedef typename Container::reference		reference;
		typedef typename Container::const_reference	const_reference;

	Container _container;
	/*
	**==========================
	**  Constructor functions
	**==========================
	*/

	/*** constructor ***/
	explicit stack( const Container& cont = Container() )
	{
		this->_container = cont;
	}

	/*** destructor ***/
	~stack() {}

	/*** operator= ***/
	stack& operator=( const stack& other )
	{
		this->_container = other.c;
	}

	/*
	**==========================
	**     Element access
	**==========================
	*/

	reference top()
	{
		return(this->_container.back());
	}

	const_reference top() const
	{
		return(this->_container.back());
	}

	/*
	**==========================
	**     CAPACITY
	**==========================
	*/

	bool empty() const
	{
		return(this->_container.empty());
	}

	size_type size() const
	{
		return (this->_container.size());
	}

	/*
	**==========================
	**     MODIFIERS
	**==========================
	*/

	void push( const value_type& value )
	{
		this->_container.push_back(value);
	}

	void pop()
	{
		this->_container.pop_back();
	}

	};

	template< class T, class Container >
	bool operator==( const stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
	{
		return(lhs._container == rhs._container);
	}

	template< class T, class Container >
	bool operator!=( const stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
	{
		return(lhs._container != rhs._container);
	}

	template< class T, class Container >
	bool operator<( const stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
	{
		return(lhs._container < rhs._container);
	}

	template< class T, class Container >
	bool operator<=( const stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
	{
		return(lhs._container <= rhs._container);
	}

	template< class T, class Container >
	bool operator>( const stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
	{
		return(lhs._container > rhs._container);
	}

	template< class T, class Container >
	bool operator>=( const stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
	{
		return(lhs._container >= rhs._container);
	}

}

#endif