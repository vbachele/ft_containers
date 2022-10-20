#ifndef MAP_HPP
# define MAP_HPP

#include <iostream>

namespace ft
{
	template< class Key, class T, class Compare = std::less<Key>,
		class Allocator = std::allocator<std::pair<const Key, T>>>
	class map
	{
	public:
		typedef key										key_type;
		typedef T										mapped_type;
		typedef std::pair<const Key, T>					value_type;
		typedef size_t									size_type;
		typedef ptrdiff_t								difference_type;
		typedef Compare									key_compare;
		typedef Allocator								allocator_type;
		typedef value_type&								reference;
		typedef const value_type&						const_reference;
		typedef typename Allocator::pointer				pointer;
		typedef typename Allocator::const_pointer		const_pointer;
		typedef typename RBTree::iterator				iterator;
		typedef typename RBTree::const_iterator			const_iterator;
		typedef typename RBTree::reverse_iterator		reverse_iterator;
		typedef typename RBTree::const_reverse_iterator	const_reverse_iterator;

	private:
		//RBTree	_tree;

	public:
	

	};
}


#endif