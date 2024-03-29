/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 18:55:01 by guferrei          #+#    #+#             */
/*   Updated: 2022/10/19 17:00:27 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
#define SET_HPP

#include "algorithm.hpp"
#include "functional.hpp"
#include "iterator.hpp"
#include "rb_tree.hpp"
#include "utility.hpp"
#include <memory>

namespace ft {
	template< class Key, class Compare = less<Key>, class Allocator = std::allocator<Key> >
	class set {
		public:
			typedef Key														key_type;
			typedef Key														value_type;
			typedef size_t													size_type;
			typedef std::ptrdiff_t											difference_type;
			typedef Compare													key_compare;
			typedef Compare													value_compare;
			typedef Allocator												allocator_type;
			typedef value_type&												reference;
			typedef const value_type&										const_reference;
			typedef typename Allocator::pointer								pointer;
			typedef typename Allocator::const_pointer						const_pointer;
			typedef tree_bidirectional_iterator<value_type>					iterator;
			typedef tree_bidirectional_iterator<value_type>					const_iterator;
			typedef reverse_tree_bidirectional_iterator<value_type>			reverse_iterator;
			typedef reverse_tree_bidirectional_iterator<const value_type>	const_reverse_iterator;

			//Member Functions

			set() {};

			set(iterator first, iterator last) {
				this->insert(first, last);
			};

			set(const set& obj) {
				*this = obj;
			}

			~set() {};

			set&	operator=(const set& obj) {
				this->clear();
				this->inset(obj.begin(), obj.end());
				this->_comp = obj._comp;
				this->_alloc = obj._alloc;
			}

			allocator_type	get_allocator() const {
				return this->_alloc;
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
				return reverse_iterator(this->_content.max(), this->_content.getNil(), this->_content.min(), this->_content.max());
			}

			const_reverse_iterator	crbegin() const {
				const_reverse_iterator temp(this->_content.max(), this->_content.getNil(), this->_content.min(), this->_content.max());
			}

			reverse_iterator	rend() {
				return reverse_iterator(this->_content.getNil(), this->_content.getNil(), this->_content.min(), this->_content.max());
			}

			const_reverse_iterator	crend() const {
				return const_reverse_iterator(this->_content.getNil(), this->_content.getNil(), this->_content.min(), this->_content.max());
			}

			//Capacity

			bool	empty() const {
				return (this->_content.getSize() == 0) ? true : false;
			}

			size_type	size() const {
				return this->_content.getSize();
			}

			size_type	max_size() const {
				return _alloc.max_size();
			}

			//Modifers

			void	clear() {
				this->_content.clear();
			}

			pair<iterator, bool>	insert(const value_type& value) {
				bool					ins;
				iterator				insNode;

				ins = this->_content.insert(value);
				insNode = iterator(this->_content.search(this->_content.getRoot(), value), this->_content.getNil(), this->_content.min(), this->_content.max());
				return (ft::make_pair(insNode, ins));
			}

			iterator	insert(iterator hint, const value_type& value) {
				iterator				it;

				this->_content.insert(*hint, value);
				it = iterator(this->_content.search(this->_content.getRoot(), value), this->_content.getNil(), this->_content.min(), this->_content.max());
				return it;
			}

			template< class InputIt >
			void	insert(InputIt first, InputIt last) {
				while (first != last) {
					this->_content.insert(*first);
					first++;
				}
			}

			void	erase(iterator pos) {
				this->_content.remove(*pos);
			}

			void	erase(iterator first, iterator last) {
				iterator	aux;

				while (first != last) {
					aux = first;
					first++;
					this->erase(aux);
				}
			}

			size_type	erase(const key_type& k) {
				if (this->find(k) != this->end()) {
					this->_content.remove(k);
					return 1;
				}
				return 0;
			}

			void	swap(set& obj) {
				allocator_type		alloc;
				this->_content.swap(obj._content);

				alloc = this->_alloc;
				obj._alloc = this->_alloc;
				this->_alloc = alloc;
			}

			//Lookup

			iterator	find(const key_type& key) {
				return iterator(this->_content.search(this->_content.getRoot(), key), this->_content.getNil(), this->_content.min(), this->_content.max());
			}

			const_iterator	find(const key_type& key) const {
				return const_iterator(this->_content.search(this->_content.getRoot(), key), this->_content.getNil(), this->_content.min(), this->_content.max());
			}

			size_type	count(const key_type& key) const {
				if (this->find(key) != this->cend())
					return 1;
				return 0;
			}

			pair<iterator, iterator>	equal_range(const key_type& key) {
				return ft::make_pair<iterator, iterator>(this->lower_bound(key), this->upper_bound(key));
			}

			pair<iterator, iterator>	equal_range(const key_type& key) const {
				return ft::make_pair<iterator, iterator>(this->lower_bound(key), this->upper_bound(key));
			}

			iterator	lower_bound(const key_type& key) {
				iterator	it = this->begin();
				iterator	end = this->end();

				while (it != end) {
					if (!comp(*it, key))
						break;
					it++;
				}
				return it;
			}

			const_iterator	lower_bound(const key_type& key) const {
				const_iterator	it = this->cbegin();
				const_iterator	end = this->cend();

				while (it != end) {
					if (!comp(*it, key))
						break;
					it++;
				}
				return it;
			}

			iterator	upper_bound(const key_type& key) {
				iterator	it = this->begin();
				iterator	end = this->end();

				while (it != end) {
					if (comp(key, *it))
						break;
					it++;
				}
				return it;
			}

			const_iterator	upper_bound(const key_type& key) const {
				const_iterator	it = this->cbegin();
				const_iterator	end = this->cend();

				while (it != end) {
					if (comp(key, *it))
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
			rb_tree<value_type>	_content;
			Allocator			_alloc;
			Compare				comp;
	};

	template< class Key, class Compare, class Alloc >
	bool	operator==(const set<Key, Compare, Alloc>& lhs, const set<Key, Compare, Alloc>& rhs) {
		return (ft::equal(lhs.cbegin(), lhs.cend(), rhs.cbegin())
				&& lhs.size() == rhs.size());
	}

	template< class Key, class Compare, class Alloc >
	bool	operator!=(const set<Key, Compare, Alloc>& lhs, const set<Key, Compare, Alloc>& rhs) {
		return (!(lhs == rhs));
	}

	template< class Key, class Compare, class Alloc >
	bool	operator<(const set<Key, Compare, Alloc>& lhs, const set<Key, Compare, Alloc>& rhs) {
			return (ft::lexicographical_compare(lhs.cbegin(), lhs.cend(), rhs.cbegin(), rhs.cend()));
	}

	template< class Key, class Compare, class Alloc >
	bool	operator<=(const set<Key, Compare, Alloc>& lhs, const set<Key, Compare, Alloc>& rhs) {
		return (lhs < rhs || lhs == rhs);
	}

	template< class Key, class Compare, class Alloc >
	bool	operator>(const set<Key, Compare, Alloc>& lhs, const set<Key, Compare, Alloc>& rhs) {
		return (ft::lexicographical_compare(rhs.cbegin(), rhs.cend(), lhs.cbegin(), lhs.cend()));
	}

	template< class Key, class Compare, class Alloc >
	bool	operator>=(const set<Key, Compare, Alloc>& lhs, const set<Key, Compare, Alloc>& rhs) {
		return (lhs > rhs || lhs == rhs);
	}

	template< class Key, class Compare, class Alloc >
	void	swap(set<Key, Compare, Alloc>& lhs, set<Key, Compare, Alloc>& rhs) {
		lhs.swap(rhs);
	}
}

#endif