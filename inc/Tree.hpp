/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:10:07 by vbachele          #+#    #+#             */
/*   Updated: 2022/06/15 17:12:12 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
#define TREE_HPP
// For our binary tree, struct is a class public by default

namespace ft
{
template <class T>
struct node
{
	T				value_type;
	struct node		*parent;
	struct node 	*left;
	struct node 	*right;

	node(T v, node *p, node *l, node *r)
	{
		value_type = v;
		parent = p;
		left = l;
		right = r;
	}
	~node() {};
};
}

#endif