/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 20:47:11 by guferrei          #+#    #+#             */
/*   Updated: 2022/07/21 21:30:24 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <memory>
#include <stdexcept>
#include "Pair.hpp"
#include "Iterator.hpp"
#include "Reverse_iterator.hpp"



namespace ft
{
	template< typename _Key,
			typename _Tp,
			typename _Compare,
			typename _Alloc = std::allocator< ft::pair<const _Key, _Tp > > >
	class map {

		struct Node
		{
			ft::pair<const _Key, _Tp >	data;
			Node						*rChild;
			Node						*lChild;
		};

		private:
			Node	*root;
			size_t	size;
			_Alloc	alloc;

		public:
			typedef _Key						key_type;
			typedef _Tp							mapped_type;
			typedef ft::pair<const _Key, _Tp >	value_type;
			typedef size_t						size_type;
			typedef ptrdiff_t					difference_type;
			typedef _Compare					key_compare;
			typedef _Alloc						allocator_type;
			typedef value_type &				reference;
			typedef const value_type &			const_reference;
			//pointer
			//const_pointer
			//iterator
			//const_iterator
			//reverse_iterator
			//const_reverse_iterator

			class value_compare
			{
				protected:
					_Compare	comp;
			
				public:
					typedef bool		result_type;
					typedef value_type	first_argument_type;
					typedef value_type	second_argument_type;
			
					value_compare() {};

					result_type	operator()(const first_argument_type& lhs, const second_argument_type& rhs) const; {
						return comp(lhs.first, rhs.first);
					}
			};
			
			//Member Functions

			//Element Access

			//Iterators

			//Capacity

			bool	empty() const {
				if (this->root)
					return false;
				return true;
			}

			size_type	size() const {
				return this->size;
			}

			size_type	max_size() const {
				return alloc.max_size();
			}

			//Modifers

			//Lookup

			//Observers
	};
}

#endif