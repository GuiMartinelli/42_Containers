/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:20:57 by guferrei          #+#    #+#             */
/*   Updated: 2022/09/14 21:05:22 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iostream>

namespace ft
{
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag :public bidirectional_iterator_tag {};

	template <
		class Category,
		class T,
		class Distance = std::ptrdiff_t,
		class Pointer = T*,
		class Reference = T& >
	struct iterator {
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	iterator_category;
		};

	template< class Iter >
	struct iterator_traits {
		typedef typename Iter::difference_type		difference_type;
		typedef typename Iter::value_type			value_type;
		typedef typename Iter::pointer				pointer;
		typedef typename Iter::reference			reference;
		typedef typename Iter::iterator_category	iterator_category;
	};

	template< class T >
	struct iterator_traits< T* > {
		typedef std::ptrdiff_t				difference_type;
		typedef T							value_type;
		typedef T*							pointer;
		typedef T&							reference;
		typedef random_access_iterator_tag	iterator_category;
	};

	template< class T >
	struct iterator_traits< const T* > {
		typedef std::ptrdiff_t				difference_type;
		typedef T							value_type;
		typedef T*							pointer;
		typedef T&							reference;
		typedef random_access_iterator_tag	iterator_category;
	};

	template <typename T>
	class bidirectional_iterator {
	protected:
		T*	data;

	public:
		bidirectional_iterator() {};

		bidirectional_iterator(T *ptr) {
			this->data = ptr;
		};

		bidirectional_iterator(bidirectional_iterator const & obj) {
			*this = obj;
		};

		~bidirectional_iterator() {};

		bidirectional_iterator &	operator=(bidirectional_iterator const & obj) {
			if (this != &obj)
				this->data = obj.data;
			return *this;
		};

		bool	operator==(bidirectional_iterator const & obj) {
			return (this->data == obj.data);
		}

		bool	operator!=(bidirectional_iterator const & obj) {
			return (this->data != obj.data);
		}

		bidirectional_iterator	operator++() {
			this->data++;

			return *this;
		}

		bidirectional_iterator	operator--() {
			this->data--;

			return *this;
		}

		bidirectional_iterator	operator++(T) {
			bidirectional_iterator	tmp(*this);
			this->data++;

			return tmp;
		}

		bidirectional_iterator	operator--(T) {
			bidirectional_iterator	tmp(*this);
			this->data--;

			return tmp;
		}

		T&	operator*() {
			return *data;
		}

		T*	operator->() {
			return data;
		}
	};

	template <typename T>
	class random_access_iterator : public bidirectional_iterator<T> {
	public:
		random_access_iterator() {};

		random_access_iterator(random_access_iterator const & obj) {
			*this = obj;
		};

		random_access_iterator(T *ptr) {
			this->data = ptr;
		};

		~random_access_iterator() {};

		random_access_iterator &	operator=(random_access_iterator const & obj) {
			if (this != &obj)
				this->data = obj.data;
			return *this;
		};

		random_access_iterator	operator+(int n) {
			random_access_iterator	aux;

			aux = this->data;
			for (; n > 0; n--)
				aux++;
			return (aux);
		}

		random_access_iterator	operator-(int n) {
			random_access_iterator	aux;

			aux = this->data;
			for (; n > 0; n--)
				aux--;
			return (aux);
		}

		int	operator+(random_access_iterator const & obj) {
			return (this->data + obj.data);
		}

		int	operator-(random_access_iterator const & obj) {
			return (this->data - obj.data);
		}

		bool	operator<(random_access_iterator const & obj) {
			return (this->data < obj.data);
		}

		bool	operator>(random_access_iterator const & obj) {
			return (this->data > obj.data);
		}

		bool	operator<=(random_access_iterator const & obj) {
			return (this->data <= obj.data);
		}

		bool	operator>=(random_access_iterator const & obj) {
			return (this->data >= obj.data);
		}

		random_access_iterator	operator+=(int n) {
			for (; n > 0; n--)
				this->data++;
			return (this->data);
		}

		random_access_iterator	operator-=(int n) {
			for (; n > 0; n--)
				this->data--;
			return (this->data);
		}

		T&	operator[](int n) {
			return this->data[n];
		}
	};
}

#endif
