/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:39:13 by vbachele          #+#    #+#             */
/*   Updated: 2022/06/19 18:09:32 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP
#include "iostream"
#include "./Tree.hpp"
#include "./Iterators.hpp"
namespace ft
{
template < class Key,                                     // map::key_type
           class T,                                       // map::mapped_type
           class Compare = std::less<Key>,                     // map::key_compare
           class Alloc = std::allocator<std::pair<const Key,T> > >   // map::allocator_type
class map
{
public:
	/***************** TYPEDEF **************/
	typedef T												mapped_type;
	typedef std::pair<Key,mapped_type> 						value_type;
	typedef Alloc											allocator_type;
	typedef size_t											size_type;
	typedef std::ptrdiff_t 									difference_type;
	typedef Compare											key_compare;
	typedef BSTNode<value_type> 							node_type;
	// typedef	value_type&								reference;
	// typedef const value_type&						cont_reference;
	// typedef value_type*								pointer;
	// typedef const value_type*						const_pointer;

	class Binary_function
    {
    public:
        typedef bool result_type;
        typedef value_type first_argument_type;
        typedef value_type second_argument_type;
    };

	class value_compare : public Binary_function
    {
    public:
        Compare comp;
        value_compare(Compare c) : comp(c) {}
        bool operator()(const value_type &x, const value_type &y) const { return comp(x.first, y.first); }
    };
	
	/***************** iterator typedef **************/
	typedef map_iterator<value_type, node_type *>			iterator;
	typedef const map_iterator<value_type, node_type *> 	const_iterator;
	typedef ft::reverse_iterator<iterator>					reverse_iterator;
	typedef const ft::reverse_iterator<const_iterator>		const_reverse_iterator;

protected :
	allocator_type	_alloc;
	size_type		_size;
	key_compare		_key_compare;
	node_type		*_root;

public :
/*
**==========================
**  CONSTRUCTORS FUNCTIONS
**==========================
*/
	explicit map (const key_compare& comp = key_compare(),
		const allocator_type& alloc = allocator_type())
		: _alloc(alloc), _size(0),  _key_compare(comp) {
			std::cout << "WORKING" << std::endl;
		}
	// template <class InputIterator>
	// map (InputIterator first, InputIterator last,
	// 	const key_compare& comp = key_compare(),
	// 	const allocator_type& alloc = allocator_type());
	map (const map& x) : _alloc(x._alloc), _size(x._size), _key_compare(x._key_compare) {}
	virtual ~map() 
	{
		std::cout << "WORKING_2" << std::endl;
	}
/*
**==========================
**  MEMBER FUNCTIONS
**==========================
*/
	/*** Creating and return a new node ***/
	node_type *add_node(value_type const &val, node_type *parent)
	{
		node_type *temp = _alloc.allocate(1); // allocation pour un nouveau noeud
		this->_alloc.construct(temp, node_type(val, NULL, NULL, parent, false)); // construit le noeud avec la key et le parent
		this->_size++;
		return (temp);
	}

	node_type *insert_node(const value_type &val, node_type *current, node_type *parent)
	{
		if (!current)
			return add_node(val, parent);
	}

};
}

#endif