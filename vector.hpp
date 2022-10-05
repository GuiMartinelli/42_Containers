/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 21:28:39 by guferrei          #+#    #+#             */
/*   Updated: 2022/10/04 21:04:19 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>
#include <stdexcept>
#include <cstddef>
#include "iterator.hpp"
#include "algorithm.hpp"

namespace ft
{
	template< typename T, class Alloc = std::allocator<T> >
	class vector
	{
	private:
		T*					_content;
		unsigned int		_size;
		unsigned int		_capacity;
		Alloc				alloc;

	public:
		typedef	T													value_type;
		typedef	std::allocator<value_type>							allocator_type;
		typedef	value_type &										reference;
		typedef	value_type const &									const_reference;
		typedef	value_type *										pointer;
		typedef	value_type const *									const_pointer;
		typedef	ft::random_access_iterator<pointer>					iterator;
		typedef	ft::random_access_iterator<const_pointer>			const_iterator;
		typedef	ft::random_access_reverse_iterator<pointer>			reverse_iterator;
		typedef	ft::random_access_reverse_iterator<const_pointer>	const_reverse_iterator;
		typedef	ptrdiff_t											difference_type;
		typedef	size_t												size_type;

		//Member Functions
		vector() {
			this->_content = alloc.allocate(1);
			this->_size = 0;
			this->_capacity = 1;
		};

		vector(vector const & obj) {
			*this = obj;
		}

		~vector() {
			alloc.deallocate(this->_content, this->_size);
		};

		vector &	operator=(vector const & obj) {
			if (this != &obj) {
				this->_content = alloc.allocate(obj._capacity);
				for (size_type i = 0; i < obj._size; i++)
					this->_content[i] = obj._content[i];
				this->_size = obj._size;
			}

			return *this;
		}

		//Capacity
		size_type	size() const {
			return this->_size;
		}

		size_type	max_size() const {
			return alloc.max_size();
		}

		void	resize(unsigned int n) {
			if (n > this->_capacity) {
				T*	resized = alloc.allocate(n);
				for (unsigned int i = 0; i < this->_capacity; i++) {
					resized[i] = this->_content[i];
				}
				alloc.deallocate(this->_content, this->_size);
				this->_content = resized;
				this->_capacity = n;
			}
			else {
				this->_size = n;
			}
		}

		void	resize(unsigned int n, T value) {
			if (n < this->_capacity) {
				for (int i = this->_size; i < this->_capacity; i++) {
					this->_content[i] = value;
				}
			}
			else if (n > this->_capacity) {
				T*	resized = alloc.allocate(n);
				for (int i = 0; i < this->_size; i++) {
					resized[i] = this->_content[i];
				}
				for (int i = this->_size; i < n; i++) {
					resized[i] = value;
				}
				this->_capacity = n;
				alloc.deallocate(this->_content, this->_size);
				this->_content = resized;
			}
			this->_size = n;
		}

		size_t	capacity() const {
			return this->_capacity;
		}

		bool	empty() const {
			return (this->_size == 0 ? true : false);
		}

		void	reserve(size_t new_cap) {
			if (new_cap > this->_capacity)
				resize(new_cap);
		}

		//Element Access
		const_reference	operator[](size_t n) const {
			if (n >= this->_size)
				throw std::out_of_range("Out of Range");
			return this->_content[n];
		}

		reference	operator[](size_t n) {
			if (n >= this->_size)
				throw std::out_of_range("Out of Range");
			return this->_content[n];
		}

		const_reference	at(size_t n) const {
			if (n >= this->_size)
				throw std::out_of_range("Out of Range");
			return this->_content[n];
		}

		reference	at(size_t n) {
			if (n >= this->_size)
				throw std::out_of_range("Out of Range");
			return this->_content[n];
		}

		const_reference	front() const {
			return this->_content[0];
		}

		reference	front() {
			return this->_content[0];
		}

		const_reference	back() const {
			return this->_content[this->_size - 1];
		}

		reference	back() {
			return this->_content[this->_size - 1];
		}

		value_type*	data() {
			return this->_content;
		}

		const value_type*	data() const {
			return this->_content;
		}

		//Modifiers

		void	assign(size_t count, const T& value) {
			this->clear();
			for(size_t i = 0; i < count; i++)
				this->pop_back(value);
		}

		template <class InputIterator>
		void	assign(InputIterator first, InputIterator last) {
			this->clear();
			this->insert(this->begin(), first, last);
		}

		void	push_back(T const & x) {
			if (this->_size == this->_capacity) {
				this->resize(this->_capacity * 2);
			}
			this->_content[this->_size] = x;
			this->_size++;
		}

		void	pop_back() {
			if (this->_size > 1) {
				this->alloc.destroy(&this->_content[this->_size - 1]);
				this->_size--;
			}
		}

		iterator	insert(iterator pos, T const & value) {
			int	index;

			index = pos - (this->begin());
			if ((this->_size + 1) > this->_capacity) {
				this->resize(this->_capacity * 2);
				pos = this->begin() + index;
			}
			this->_size++;
			for (int aux = this->_size; aux >= index; aux--)
				this->_content[aux] = this->_content[aux - 1];
			this->_content[index] = value;
			return pos;
		}

		iterator	insert(iterator pos, size_t count, T const & value) {
			int	index;
			int	resized;

			index = pos - (this->begin());
			resized = this->_capacity;
			if ((this->_size + count) > this->_capacity) {
				while (resized < (this->_size + count))
					resized *= 2;
				this->resize(resized);
				pos = this->begin() + index;
			}
			this->_size += count;
			for (int aux = this->_size; aux >= (index + count); aux--)
				this->_content[aux] = this->_content[aux - count];
			for (int i = 0; i < count; i++)
				this->_content[index + i] = value;
			return pos;
		}

		iterator	insert(iterator pos, iterator begin, iterator end) {
			unsigned int	index;
			unsigned int	resized;
			int	count;

			if (begin > end)
				throw std::exception();
			index = pos - (this->begin());
			resized = this->_capacity;
			count = end - begin;
			if ((this->_size + count) > this->_capacity) {
				while (resized < (this->_size + count))
					resized *= 2;
				this->resize(resized);
				pos = this->begin() + index;
			}
			this->_size += count;
			for (unsigned int aux = this->_size; aux >= (index + count); aux--)
				this->_content[aux] = this->_content[aux - count];
			for (int i = 0; i < count; i++)
				this->_content[index + i] = *(begin + i);
			return pos;
		}

		iterator	erase(iterator pos) {
			iterator	aux;

			aux = this->begin();
			for (unsigned int index = pos - aux; index < (this->_size - 1); index++)
				this->_content[index] = this->_content[index + 1];
			this->_size--;
			return pos;
		}

		iterator	erase(iterator begin, iterator end) {
			iterator	aux;
			int			diff;

			if (begin > end)
				throw std::exception();
			diff = end - begin;
			aux = this->begin();
			for (unsigned int index = begin - aux; index < this->_size; index++) {
				this->_content[index] = this->_content[index + diff];
			}
			this->_size -= end - begin;
			return begin;
		}

		void	swap(vector& vec) {
			T*				auxContent;
			unsigned int	auxSize;
			unsigned int	auxCapacity;

			auxContent = vec._content;
			auxSize = vec.size();
			auxCapacity = vec.capacity();
			vec._content = this->_content;
			vec._size = this->_size;
			vec._capacity = this->_capacity;
			this->_content = auxContent;
			this->_size = auxSize;
			this->_capacity = auxCapacity;
		}

		void	clear() {
			this->resize(1);
			this->_size = 0;
		}

		//ALLOCATORS

		allocator_type	get_allocator() const {
			return allocator_type();
		}

		//ITERATORS

		iterator	begin() {
			return iterator(this->_content);
		}

		iterator	end() {
			return iterator(this->_content + this->_size);
		}

		const_iterator	cbegin() const {
			return const_iterator(this->_content);
		}

		const_iterator	cend() const {
			return const_iterator(this->_content + this->_size);
		}

		reverse_iterator	rbegin() {
			reverse_iterator	it(this->_content + (this->_size - 1));

			return it;
		}

		reverse_iterator	rend() {
			reverse_iterator	it(this->_content);
			it++;

			return it;
		}

		const_reverse_iterator	crbegin() const {
			const_reverse_iterator const	it(this->_content + (this->_size - 1));

			return it;
		}

		const_reverse_iterator	crend() const {
			const_reverse_iterator const	it(this->_content);
			it++;

			return it;
		}
	};

	//Operators Overload

	template <class T, class Alloc>
	bool	operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		return (ft::equal(lhs.cbegin(), lhs.cend(), rhs.cbegin())
				&& lhs.size() == rhs.size());
	}

	template <class T, class Alloc>
	bool	operator!=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		return (!(lhs == rhs));
	}

	template <class T, class Alloc>
	bool	operator<(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		return (ft::lexicographical_compare(lhs.cbegin(), lhs.cend(), rhs.cbegin(), rhs.cend()));
	}

	template <class T, class Alloc>
	bool	operator<=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		return (lhs < rhs || lhs == rhs);
	}

	template <class T, class Alloc>
	bool	operator>(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		return (ft::lexicographical_compare(rhs.cbegin(), rhs.cend(), lhs.cbegin(), lhs.cend()));
	}

	template <class T, class Alloc>
	bool	operator>=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		return (lhs > rhs || lhs == rhs);
	}

	template< class T, class Alloc >
	void	swap(vector< T, Alloc > lhs, vector < T, Alloc > rhs) {
		lhs.swap(rhs);
	}
}

#endif
