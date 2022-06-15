/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:39:13 by vbachele          #+#    #+#             */
/*   Updated: 2022/06/15 17:59:26 by vbachele         ###   ########.fr       */
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
	typedef T										mapped_type;
	typedef std::pair<Key,mapped_type> 				value_type;
	typedef Alloc									allocator_type;
	typedef size_t									size_type;
	typedef std::ptrdiff_t 							difference_type;
	typedef Compare									key_compare;
	typedef node<value_type> 						node_type;
	// typedef	value_type&								reference;
	// typedef const value_type&						cont_reference;
	// typedef value_type*								pointer;
	// typedef const value_type*						const_pointer;

	/***************** iterator typedef **************/
	typedef map_iterator<value_type, node_type *>				iterator;
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
	virtual ~map() {
			std::cout << "WORKING_2" << std::endl;
		}
};
}

#endif