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
		RBTree	_tree;

/*
**==========================
** CLASS VALUE COMPARE
**==========================
*/
	protected:
		class value_compare
		{
			typedef bool 		result_type;
			typedef value_type	first_argument_type;
			typedef value_type	second_argument_type;


			protected:
				Compare _comp;
			/*** constructor ***/
			value_compare()
			{
				this->_comp = Compare;
			}

			~value_compare() {}

			bool operator()( const value_type& lhs, const value_type& rhs ) const
			{
				comp(lhs.first, rhs.first);
			}
		};

	public:

/*
**==========================
**   CONSTRUCTORS
**==========================
*/
	/*** constructors ***/
		map()
		{
			this->_tree = RBTree(key_comp(), allocator_type());
		}

		explicit map( const Compare& comp,
              const Allocator& alloc = Allocator() )
		{
			this->_tree = RBTree(comp, alloc);
		}

		// template< class InputIt >
		// map( InputIt first, InputIt last, const Compare& comp = Compare(),
     	// 	const Allocator& alloc = Allocator() )
		// {

		// }

		map( const map& other )
		{
			tree.insertUnique(other.begin(), other.end());
		}

	/*** destructors ***/
		~map() {}

	/*** operator= ***/
		map& operator=( const map& other )
		{
			if (this != other)
				this->_tree = other._tree;
			return (*this);
		}

/*
**==========================
**     ELEMENT ACCESS
**==========================
*/
	T& at( const Key& key )
	{
		return (this->_tree.find(key)->second);
	}

	const T& at( const Key& key ) const
	{
		return (this->_tree.find(key)->second);
	}

	mapped_type& operator[](const Key& key)
	{
		iterator ret = this->_tree.find(key);
		if (ret != this->end())
		{
				mapped_type &value = this->at(key);
				return value;
		}
		else
		{
			return (this->insert(value_type(key, mapped_type()))).first->second;
		}

/*
**==========================
**   OBSERVERS
**==========================
*/

		key_compare key_comp() const
		{
			return this->_tree.key_comp();
		}

		map::value_compare value_comp() const
		{
			return value_compare();
		}

	};
}


#endif