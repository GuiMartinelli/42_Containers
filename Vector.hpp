/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 21:28:39 by guferrei          #+#    #+#             */
/*   Updated: 2022/06/27 21:24:28 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>

namespace ft
{
	template<typename T>
	class vector
	{
	private:
		T*					_content;
		unsigned int		_size;
		unsigned int		_capacity;
		std::allocator<T>	alloc;

	public:
		// class iterator;

		//Member Functions
		vector() {
			this->_content = alloc.allocate(1);
			this->_size = 0;
			this->_capacity = 1;
		};

		~vector() {
			alloc.deallocate(this->_content, this->_size);
		};

		//Capacity
		size_t	size() const {
			return this->_size;
		}

		size_t	max_size() const {
			return alloc.max_size();
		}

		void	resize(unsigned int n) {
			if (n > this->_capacity) {
				T*	resized = alloc.allocate(n);
				for (int i = 0; i < this->_capacity; i++) {
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

		unsigned int	capacity() const {
			return this->_capacity;
		}

		bool	empty() const {
			return (this->_size == 0 ? true : false);
		}

		//RESERVE

		//Element Access
		T const &	operator[](int n) const {
			return this->_content[n];
		}

		T &	operator[](int n) {
			return this->_content[n];
		}

		T const &	at(int n) const {
			return this->_content[n];
		}

		T &	at(int n) {
			return this->_content[n];
		}

		T const &	front() const {
			return this->_content[0];
		}

		T &	front() {
			return this->_content[0];
		}

		T const &	back() const {
			return this->_content[this->_size - 1];
		}

		T &	back() {
			return this->_content[this->_size - 1];
		}

		//Modifiers

		void	push_back(T x) {
			if (this->_size == this->_capacity) {
				this->resize(this->_capacity * 2);
			}
			this->_content[this->_size] = x;
			this->_size++;
		}

		void	pop_back() {
			this->_content[this->_size - 1] = 0;
			this->_size--;
		}

		void	clear() {
			this->resize(1);
			this->_size = 0;
		}

		std::allocator<T> &	get_allocator() const {
			return this->alloc;
		}

		//ITERATORS
		class iterator
		{
		protected:
			T*	it;

		public:
			iterator() {};

			iterator(T *ptr) {
				this->it = ptr;
			};

			iterator(iterator const & obj) {
				*this = obj;
			};

			~iterator() {};

			iterator &	operator=(iterator const & obj) {
				if (this != &obj)
					this->it = obj.it;
				return *this;
			};

			T	operator*() {
				return (*this->it);
			}

			bool	operator<(iterator const & obj) {
				return (this->it < obj.it);
			}

			bool	operator>(iterator const & obj) {
				return (this->it > obj.it);
			}

			bool	operator<=(iterator const & obj) {
				return (this->it <= obj.it);
			}

			bool	operator>=(iterator const & obj) {
				return (this->it >= obj.it);
			}

			bool	operator==(iterator const & obj) {
				return (this->it == obj.it);
			}

			iterator	operator++() {
				this->it++;

				return *this;
			}

			iterator	operator--() {
				this->it--;

				return *this;
			}

			iterator	operator++(T) {
				iterator	tmp(*this);
				this->it++;

				return tmp;
			}

			iterator	operator--(T) {
				iterator	tmp(*this);
				this->it--;

				return tmp;
			}
		};

		class	reverse_iterator : public iterator {
		public:
			reverse_iterator() {};

			reverse_iterator(T *ptr) {
				this->it = ptr;
			};

			reverse_iterator(reverse_iterator const & obj) {
				*this = obj;
			};
			
			~reverse_iterator() {};

			bool	operator<(reverse_iterator const & obj) {
				return !(this->it < obj.it);
			}

			bool	operator>(reverse_iterator const & obj) {
				return !(this->it > obj.it);
			}

			bool	operator<=(reverse_iterator const & obj) {
				return !(this->it <= obj.it);
			}

			bool	operator>=(reverse_iterator const & obj) {
				return !(this->it >= obj.it);
			}

			reverse_iterator	operator++() {
				this->it--;

				return *this;
			}

			reverse_iterator	operator--() {
				this->it++;

				return *this;
			}

			reverse_iterator	operator++(T) {
				reverse_iterator	tmp(*this);
				this->it--;

				return tmp;
			}

			reverse_iterator	operator--(T) {
				reverse_iterator	tmp(*this);
				this->it++;

				return tmp;
			}
		};

		iterator	begin() {
			iterator	it(this->_content);

			return it;
		}

		iterator	end() {
			iterator	it(this->_content + this->_size);
			
			return it;
		}

		iterator	cbegin() {
			iterator const	it(this->_content);

			return it;
		}

		iterator	cend() {
			iterator const	it(this->_content + this->_size);
			
			return it;
		}

		reverse_iterator	rbegin() {
			reverse_iterator	it(this->_content + (this->_size - 1));

			return it;
		}

		reverse_iterator	rend() {
			reverse_iterator	it(this->_content);

			return it;
		}

		reverse_iterator	crbegin() {
			reverse_iterator const	it(this->_content + (this->_size - 1));

			return it;
		}

		reverse_iterator	crend() {
			reverse_iterator const	it(this->_content);
			
			return it;
		}
	};
}

#endif