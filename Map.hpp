/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 20:47:11 by guferrei          #+#    #+#             */
/*   Updated: 2022/08/17 21:08:07 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <memory>
#include <stdexcept>
#include "Less.hpp"
#include "Pair.hpp"
#include "RBTree.hpp"
#include "Iterator.hpp"
#include "Reverse_iterator.hpp"

namespace ft
{
	template< typename _Key,
			typename _Tp,
			typename _Compare = ft::less<_Key>,
			typename _Alloc = std::allocator< ft::pair<const _Key, _Tp > > >
	class map {
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

					result_type	operator()(const first_argument_type& lhs, const second_argument_type& rhs) const {
						return comp(lhs.first, rhs.first);
					}
			};
			
			//Member Functions

			map() {
				this->_root = this->_alloc.allocate(1);
				this->_size = 0;
			}

			~map() {
			}

			//Element Access

			mapped_type&	operator[] (const key_type& k) {
				Node*	aux;

				aux = this->_root;
				while(aux->data) {
					if (value_compare(aux->data.first, k))
						aux = aux->lChild;
					else if (value_compare(k, aux->data.first))
						aux = aux->rChild;
					else
						return (&aux->data.second);
				}
				aux = new Node(k);
				this->size++;
				return (&aux->data.second);
			}

			mapped_type&	at(const key_type& k) {
				Node*	aux;

				aux = this->_root;
				while(aux->data) {
					if (value_compare(aux->data.first, k))
						aux = aux->lChild;
					else if (value_compare(k, aux->data.first))
						aux = aux->rChild;
					else
						return (&aux->data.second);
				}
				throw std::exception();
			}

			mapped_type&	at(const key_type& k) const {
				Node*	aux;

				aux = this->_root;
				while(aux->data) {
					if (value_compare(aux->data.first, k))
						aux = aux->lChild;
					else if (value_compare(k, aux->data.first))
						aux = aux->rChild;
					else
						return (&aux->data.second);
				}
				throw std::exception();
			}

			//Iterators

			//Capacity

			bool	empty() const {
				if (this->_root)
					return false;
				return true;
			}

			size_type	size() const {
				return this->size;
			}

			size_type	max_size() const {
				return _alloc.max_size();
			}

			//Modifers

			//Lookup

			//Observers
		private:
			RBTree<value_type>	*_root;
			size_t				_size;
			_Alloc				_alloc;
			_Compare			comp;

	};
}

#endif