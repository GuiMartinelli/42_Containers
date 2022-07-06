/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 21:19:10 by guferrei          #+#    #+#             */
/*   Updated: 2022/07/06 20:27:55 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "Iterator.hpp"

namespace ft {
	template <typename T>
	class	reverse_iterator : public iterator<T> {
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
}

#endif