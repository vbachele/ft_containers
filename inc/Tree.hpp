/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:10:07 by vbachele          #+#    #+#             */
/*   Updated: 2022/06/26 17:17:21 by vbachele         ###   ########.fr       */
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
	struct BSTNode 	*left;
	struct BSTNode 	*right;
	struct BSTNode	*parent;
	bool			last;

	BSTNode(T v, BSTNode *l, BSTNode *r, BSTNode *p, bool e = false) : value_type(v), left(l), right(r), parent(p), last(e) {}
	~BSTNode() {};
};
}

#endif