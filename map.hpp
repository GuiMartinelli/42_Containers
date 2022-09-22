/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 20:47:11 by guferrei          #+#    #+#             */
/*   Updated: 2022/09/22 17:19:09 by guferrei         ###   ########.fr       */
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
			typedef _Key												key_type;
			typedef _Tp													mapped_type;
			typedef pair<_Key, _Tp >									value_type;
			typedef size_t												size_type;
			typedef ptrdiff_t											difference_type;
			typedef _Compare											key_compare;
			typedef _Alloc												allocator_type;
			typedef value_type &										reference;
			typedef const value_type &									const_reference;
			typedef value_type *										pointer;
			typedef value_type const *									const_pointer;
			typedef ft::tree_bidirectional_iterator<value_type>			iterator;
			typedef ft::tree_bidirectional_iterator<value_type>			const_iterator;
			typedef ft::reverse_tree_bidirectional_iterator<value_type>	reverse_iterator;
			typedef ft::reverse_tree_bidirectional_iterator<value_type>	reverse_const_iterator;

			class value_compare : public binary_function<value_type, value_type, bool> {
				friend class map;

				protected:
					_Compare	comp;
					value_compare(_Compare c) : comp(c) {};
			
				public:
					typedef bool		result_type;
					typedef value_type	first_argument_type;
					typedef value_type	second_argument_type;

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

			map&	operator=(const map& obj) {
				this->_content = obj._content;
			
				return *this;
			}

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
				return iterator(this->_content.min(), this->_content.getNil(), this->_content.min(), this->_content.max());
			}

			const_iterator	cbegin() const {
				return const_iterator(this->_content.min(), this->_content.getNil(), this->_content.min(), this->_content.max());
			}

			iterator	end() {
				return iterator(this->_content.getNil(), this->_content.getNil(), this->_content.min(), this->_content.max());
			}

			const_iterator	cend() const {
				return const_iterator(this->_content.getNil(), this->_content.getNil(), this->_content.min(), this->_content.max());
			}

			reverse_iterator	rbegin() {
				return reverse_iterator(this->_content.min(), this->_content.getNil(), this->_content.min(), this->_content.max());
			}

			reverse_const_iterator	crbegin() const {
				return reverse_const_iterator(this->_content.min(), this->_content.getNil(), this->_content.min(), this->_content.max());
			}

			reverse_iterator	rend() {
				return reverse_iterator(this->_content.getNil(), this->_content.getNil(), this->_content.min(), this->_content.max());
			}

			reverse_const_iterator	crend() const {
				return reverse_const_iterator(this->_content.getNil(), this->_content.getNil(), this->_content.min(), this->_content.max());
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
				insNode = iterator(this->_content.search(this->_content.getRoot(), value), this->_content.getNil(), this->_content.min(), this->_content.max());
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

			void	erase(iterator first, iterator last) {
				iterator	aux;

				while (first != last) {
					aux = first;
					first++;
					this->erase(*aux);
				}
			}

			size_type	erase(const key_type& k) {
				if (this->find(k) != this->cend()) {
					this->_content.remove(ft::make_pair(k, mapped_type()));
					return 1;
				}
				return 0;
			}

			// void	swap(map& obj) {
			// }

			//Lookup

			// iterator	find(const key_type& key) {
			// }

			// const_iterator	find(const key_type& key) const {
			// }

			size_type	count(const key_type& key) const {
				if (this->find(key) != this->cend())
					return 1;
				return 0;
			}

			// pair<iterator, iterator>	equal_range(const key_type& key) {
			// }

			// pair<iterator, iterator>	equal_range(const key_type& key) const {
			// }

			iterator	lower_bound(const key_type& key) {
				iterator	it = this->begin();
				iterator	end = this->end();

				while (it != end) {
					if (!comp(it->data->first, key))
						break;
					it++;
				}
				return it;
			}

			const_iterator	lower_bound(const key_type& key) const {
				const_iterator	it = this->cbegin();
				const_iterator	end = this->cend();

				while (it != end) {
					if (!comp(it->data->first, key))
						break;
					it++;
				}
				return it;
			}

			iterator	upper_bound(const key_type& key) {
				iterator	it = this->begin();
				iterator	end = this->end();

				while (it != end) {
					if (comp(key, it->data->first))
						break;
					it++;
				}
				return it;
			}

			const_iterator	upper_bound(const key_type& key) const {
				const_iterator	it = this->cbegin();
				const_iterator	end = this->cend();

				while (it != end) {
					if (comp(key, it->data->first))
						break;
					it++;
				}
				return it;
			}

			//Observers

			key_compare	key_comp() const {
				return (comp);
			}

			value_compare	value_comp() const {
				return value_comp();
			}

		private:
			RBTree<value_type>	_content;
			allocator_type		_alloc;
			_Compare			comp;

	};
}

#endif