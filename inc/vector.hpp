/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:25:56 by vbachele          #+#    #+#             */
/*   Updated: 2022/05/26 18:17:16 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

// allocator is what will allocate memory efficiently
template < class T, class Alloc = allocator<T> >
class vector
{
public:
	//default/empty constructor
	explicit vector (const allocator_type& alloc = allocator_type()){

	}
	//fill constructor - with n elements. Each element is a copy of val.
	explicit vector (size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type());
	//range constructor - need iterator
	template <class InputIterator>
         vector (InputIterator first, InputIterator last,
                 const allocator_type& alloc = allocator_type());
	//copy constructor
	vector (const vector& x);
private:

}



#endif