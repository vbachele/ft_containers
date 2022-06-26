/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:39:13 by vbachele          #+#    #+#             */
/*   Updated: 2022/06/26 17:01:57 by vbachele         ###   ########.fr       */
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
           class Alloc = std::allocator<ft::pair<const Key, T> > >   // map::allocator_type
class map
{
public:
	/***************** TYPEDEF **************/
	typedef Key 											key_type;
	typedef T												mapped_type;
	// value_type is constitued of both key and value after passing by pair
	typedef ft::pair<const key_type, mapped_type> 			value_type;
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
	template <class InputIterator>
	map (InputIterator first, InputIterator last,
		const key_compare& comp = key_compare(),
		const allocator_type& alloc = allocator_type());
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
	/*** Creating/allocating and return a new node ***/
	node_type *add_node(value_type const &val, node_type *parent)
	{
		node_type *temp = _alloc.allocate(1); // allocation pour un nouveau noeud
		this->_alloc.construct(temp, node_type(val, NULL, NULL, parent, false)); // construit le noeud avec la key/value et le parent
		this->_size++;
		return (temp);
	}

	/*** inserting the node int the tree ***/
	node_type *insert_node(const value_type &val, node_type *current, node_type *parent)
	{
		if (!current) // if the current node is null
			return add_node(val, parent);
		if (current->last) // if we are in the last node
		{
			node_type *to_insert = add_node(val, parent);
			current->parent = to_insert;
			to_insert->right = current;
			current = to_insert;
			return current;
		}
		if (_key_compare(val.first, current->value_type.first))
			current->left = insert_node(val, current->left, current);
		else if (_key_compare(current->value_type.first, val.first))
			current->right = insert_node(val, current->right, current);
		return current;
	}

	node_type *insert_node_from_root(const value_type &val, node_type *current, node_type *parent = NULL)
	{
		if (!this->_root) // Si l'arbre est vide (root pas alloue et construit)
		{
			this->_root = add_node(val, NULL);
			node_type *last = add_node(value_type(key_type(), mapped_type()), this->_root);
			this->_size--;
			this->_root->right = last;
			last->last = true; // we indicate it it is the last node
			return (this->_root);
		}
		if (this->_root->last) //Si root est le seul element
		{
			node_type *new_root = add_node(val, NULL);
			this->_root->parent = new_root;
			new_root->right = this->_root;
			this->_root = new_root;
			return (this->_root);
		}
		//Si ne correspond pas aux deux cas precedents
		return insert_node(val, current, parent);
	}

	size_type get_size(void)
    {
        return (this->_size);
    }

	//Insert single element
	pair<iterator, bool> insert(const value_type &val)
	{
		size_t backup = this->get_size();
		insert_node_from_root(val, this->_root);
		return (pair<iterator, bool>(recursive_find_key(val.first, this->_root), backup != this->_size));
	}

	//insert with hint
	iterator insert(iterator position, const value_type &val)
	{
		(void)position;
		insert_node_from_root(val, this->_root);
		return iterator(recursive_find_key(val.first, this->_root));
	}

	// //insert range - A CHANGER POUR STD
	// template <class InputIterator>
	// void insert(typename std::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
	// {
	// 	while (first != last)
	// 	{
	// 		insert(*first);
	// 		first++;
	// 	}
	// }

	node_type *recursive_find_key(const key_type &key, node_type *current) const
	{
		if (!current || current->last) // if last node or we are in the last node in tree
			return (NULL);
		// Compare 2 keys if key < 1st value current node, we search again with the left node
		if (this->_key_compare(key, current->value.first))
			return recursive_find_key(key, current->left);
		else if (this->_key_compare(current->value.first, key)) // Compare 2 keys if key > 1st value current node, we search again with the right node
			return recursive_find_key(key, current->right);
		else // we found the key
			return (current);
	}
};
}

#endif