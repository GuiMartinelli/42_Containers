/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 20:47:11 by guferrei          #+#    #+#             */
/*   Updated: 2022/09/15 15:56:25 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <memory>
#include <stdexcept>
#include <cstddef>
#include "functional.hpp"
#include "utility.hpp"
#include "RBTree.hpp"
#include "iterator.hpp"

namespace ft
{
	template< typename _Key,
			typename _Tp,
			typename _Compare = ft::less<_Key>,
			typename _Alloc = std::allocator< pair<_Key, _Tp > > >
	class map {
		public:
			typedef _Key													key_type;
			typedef _Tp														mapped_type;
			typedef pair<_Key, _Tp >										value_type;
			typedef size_t													size_type;
			typedef ptrdiff_t												difference_type;
			typedef _Compare												key_compare;
			typedef _Alloc													allocator_type;
			typedef value_type &											reference;
			typedef const value_type &										const_reference;
			typedef value_type *											pointer;
			typedef value_type const *										const_pointer;
			typedef ft::bidirectional_iterator<value_type>					iterator;
			typedef ft::bidirectional_iterator<const value_type>			const_iterator;
			typedef ft::bidirectional_reverse_iterator<value_type>			reverse_iterator;
			typedef ft::bidirectional_reverse_iterator<const value_type>	reverse_const_iterator;

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

			map() {}

			map(iterator first, iterator last) {}

			map(const map& obj) {
				*this = obj;
			}

			map&	operator=(const map& obj) {}

			~map() {}

			allocator_type	getAllocator() const {
				return this->_alloc;
			}

			//Element Access

			mapped_type&	at(const key_type& k) {
				pointer	aux = this->_content.search(this->_content.getRoot(), ft::make_pair(k, mapped_type()));

				if (aux)
					return (aux->second);
				else
					throw std::exception();
			}

			mapped_type&	operator[] (const key_type& k) {
				pointer	aux = this->_content.search(this->_content.getRoot(), ft::make_pair(k, mapped_type()));

				if (aux)
					return (aux->second);
				this->_content.insert(ft::make_pair(k, std::string()));
				aux = this->_content.search(this->_content.getRoot(), k);
				return aux->second;
			}

			//Iterators

			iterator	begin() {
				return iterator(this->_content.min());
			}

			const_iterator	cbegin() const {
				return const_iterator(this->_content.min());
			}

			iterator	end() {
				return iterator();
			}

			const_iterator	cend() const {
				return const_iterator();
			}

			reverse_iterator	rbegin() {
				return reverse_iterator();
			}

			reverse_const_iterator	crbegin() const {
				return reverse_const_iterator();
			}

			reverse_iterator	rend() {
				return reverse_iterator();
			}

			reverse_const_iterator	crend() const {
				return reverse_const_iterator();
			}

			//Capacity

			bool	empty() const {
				return (this->_content) ? true : false;
			}

			size_type	size() const {
				return this->_content.getSize();
			}

			size_type	max_size() const {
				return _alloc.max_size();
			}

			//Modifers

			void	clear() {
				this->_content.destroy(this->_content.getRoot());
				this->_size = 0;
			}

			pair<iterator, bool>	insert(const value_type& value) {
				bool					ins;
				iterator				insNode;

				ins = this->_content.insert(value);
				insNode = iterator(this->_content.search(this->_content.getRoot(), value));
				return (ft::make_pair(insNode, ins));
			}

			// iterator	insert(iterator hint, const value_type& value) {
			// }

			// template< class InputIt >
			// void	insert(InputIt first, InputIt last) {
			// }

			void	erase(value_type *pos) {
				this->_content.remove(pos);
			}

			// void	erase(iterator first, iterator last) {
			// }

			size_type	erase(const key_type& k) {
				this->_content.remove(ft::make_pair(k, mapped_type()));

				return 1;
			}

			// void	swap(map& obj) {
			// }

			//Lookup

			// size_type	count(const key_type& key) const {
			// }

			// iterator	find(const key_type& key) {
			// }

			// const_iterator	find(const key_type& key) const {
			// }

			// pair<iterator, iterator>	equal_range(const key_type& key) {
			// }

			// pair<iterator, iterator>	equal_range(const key_type& key) const {
			// }

			// iterator	lower_bound(const key_type& key) {
			// }

			// const iterator	lower_bound(const key_type& key) const {
			// }

			// iterator	upper_bound(const key_type& key) {
			// }

			// const iterator	upper_bound(const key_type& key) const {
			// }

			//Observers

			key_compare	key_comp() const {
				return (new key_compare(comp));
			}

			// ft::map::value_compare	value_comp() const {
			// }

		private:
			RBTree<value_type>	_content;
			allocator_type		_alloc;
			_Compare			comp;

	};
}

#endif