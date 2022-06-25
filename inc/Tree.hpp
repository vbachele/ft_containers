/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:10:07 by vbachele          #+#    #+#             */
/*   Updated: 2022/06/25 19:38:34 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
#define TREE_HPP
// For our binary tree, struct is a class public by default

namespace ft
{
template <class T>
struct BSTNode
{
	T				value_type;
	struct BSTNode	*parent;
	struct BSTNode 	*left;
	struct BSTNode 	*right;
	bool			last;

	BSTNode(T v, BSTNode *p, BSTNode *l, BSTNode *r, bool e)
	{
		value_type = v;
		parent = p;
		left = l;
		right = r;
		e = false;
	}
	~BSTNode() {};
};
}

#endif