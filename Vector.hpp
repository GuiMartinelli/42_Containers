/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 21:28:39 by guferrei          #+#    #+#             */
/*   Updated: 2022/06/30 17:05:01 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>
#include <stdexcept>

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

			iterator	operator+=(int n) {
				for (; n > 0; n--)
					this->it++;
				return (this->it);
			}

			iterator	operator-=(int n) {
				for (; n > 0; n--)
					this->it--;
				return (this->it);
			}

			iterator	operator+(int n) {
				iterator	aux;

				aux = this->it;
				for (; n > 0; n--)
					aux++;
				return (aux);
			}

			iterator	operator-(int n) {
				iterator	aux;

				aux = this->it;
				for (; n > 0; n--)
					aux--;
				return (aux);
			}

			int	operator+(iterator const & obj) {
				return (this->it + obj.it);
			}

			int	operator-(iterator const & obj) {
				return (this->it - obj.it);
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
				for (int i = 0; i < obj._size; i++)
					this->_content[i] = obj._content[i];
				this->_size = obj._size;
			}

			return *this;
		}

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
		T const &	operator[](int n) const {
			return this->_content[n];
		}

		T &	operator[](int n) {
			return this->_content[n];
		}

		T const &	at(size_t n) const {
			if (n >= this->_size)
				throw std::exception();
			return this->_content[n];
		}

		T &	at(size_t n) {
			if (n >= this->_size)
				throw std::exception();
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

		void	assign(size_t count, const T& value) {
			if (count > this->_capacity)
				this->resize(count + 1);
			if (count > this->_size)
				this->_size = static_cast<int>(count);
			for (size_t i = 0; i <= count; i++) {
				this->_content[i] = value;
			}
		}

		void	assign(vector<T>::iterator & first, vector<T>::iterator & last) {
			if ((last - first) > this->_capacity)
				this->resize((last - first) + 1);
			for (int i = 0; first <= last; i++) {
				first++;
				this->_content[i] = *first;
			}
		}

		void	assign(vector<T>::iterator const & first, vector<T>::iterator const & last) {
			if ((last - first) > this->_capacity)
				this->resize((last - first) + 1);
			for (int i = 0; first <= last; i++) {
				first++;
				this->_content[i] = *first;
			}
		}

		void	push_back(T const & x) {
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
			int	index;
			int	resized;
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
			for (int aux = this->_size; aux >= (index + count); aux--)
				this->_content[aux] = this->_content[aux - count];
			for (int i = 0; i < count; i++)
				this->_content[index + i] = *(begin + i);
			return pos;
		}

		iterator	erase(iterator pos) {
			iterator	aux;

			aux = this->begin();
			for (int index = pos - aux; index < (this->_size - 1); index++)
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
			for (int index = begin - aux; index < this->_size; index++) {
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

		std::allocator<T> &	get_allocator() const {
			return this->alloc;
		}

		//ITERATORS

		iterator	begin() {
			iterator	it(this->_content);

			return it;
		}

		iterator	end() {
			iterator	it(this->_content + this->_size);
			
			return it;
		}

		iterator	begin() const {
			iterator const	it(this->_content);

			return it;
		}

		iterator	end() const {
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

		reverse_iterator	rbegin() const {
			reverse_iterator const	it(this->_content + (this->_size - 1));

			return it;
		}

		reverse_iterator	rend() const {
			reverse_iterator const	it(this->_content);
			
			return it;
		}
	};
}

#endif
