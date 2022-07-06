/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 21:04:30 by guferrei          #+#    #+#             */
/*   Updated: 2022/07/06 20:16:40 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

namespace ft {
	template <typename T>
	class iterator {
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
}

#endif
