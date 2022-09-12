/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 12:18:40 by guferrei          #+#    #+#             */
/*   Updated: 2022/09/12 19:16:52 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

namespace ft {

	template < class T, class Container = ft::vector<T> >
	class stack
	{
	protected:
		Container	_data;

		template < class Tp, class Cont >
		friend bool	operator==(stack< Tp, Cont > const & lhs, stack< Tp, Cont > const & rhs);

		template < class Tp, class Cont >
		friend bool	operator!=(stack< Tp, Cont > const & lhs, stack< Tp, Cont > const & rhs);

		template < class Tp, class Cont >
		friend bool	operator<(stack< Tp, Cont > const & lhs, stack< Tp, Cont > const & rhs);

		template < class Tp, class Cont >
		friend bool	operator<=(stack< Tp, Cont > const & lhs, stack< Tp, Cont > const & rhs);

		template < class Tp, class Cont >
		friend bool	operator>(stack< Tp, Cont > const & lhs, stack< Tp, Cont > const & rhs);

		template < class Tp, class Cont >
		friend bool	operator>=(stack< Tp, Cont > const & lhs, stack< Tp, Cont > const & rhs);

		template < class Tp, class Cont >
		friend void	swap(stack< Tp, Cont > & lhs, stack< Tp, Cont > & rhs);

	public:
		//Member Type

		typedef Container							container_type;
		typedef typename Container::value_type		value_type;
		typedef typename Container::size_type		size_type;
		typedef typename Container::reference		reference;
		typedef typename Container::const_reference	const_reference;

		//Member Functions

		stack() {};

		~stack() {};

		stack&	operator=(stack& obj) {
			this->_data = obj._data;

			return *this;
		};

		//Element Access

		reference	top() {
			return this->_data.back();
		}

		const_reference	top() const {
			return this->_data.back();
		}

		//Capacity

		bool	empty() const {
			return this->_data.empty();
		}

		size_type	size() const {
			return this->_data.size();
		}

		//Modifiers

		void	push( const value_type& value) {
			this->_data.push_back(value);
		}

		void	pop() {
			this->_data.pop_back();
		}
	};

	//Operator Overload
	template < class T, class Container = ft::vector<T> >
	bool	operator==(stack< T, Container > const & lhs, stack< T, Container > const & rhs) {
		return rhs._data == lhs._data;
	}

	template < class T, class Container = ft::vector<T> >
	bool	operator!=(stack< T, Container > const & lhs, stack< T, Container > const & rhs) {
		return rhs._data != lhs._data;
	}

	template < class T, class Container = ft::vector<T> >
	bool	operator<(stack< T, Container > const & lhs, stack< T, Container > const & rhs) {
		return rhs._data < lhs._data;
	}

	template < class T, class Container = ft::vector<T> >
	bool	operator<=(stack< T, Container > const & lhs, stack< T, Container > const & rhs) {
		return rhs._data <= lhs._data;
	}

	template < class T, class Container = ft::vector<T> >
	bool	operator>(stack< T, Container > const & lhs, stack< T, Container > const & rhs) {
		return rhs._data > lhs._data;
	}

	template < class T, class Container = ft::vector<T> >
	bool	operator>=(stack< T, Container > const & lhs, stack< T, Container > const & rhs) {
		return rhs._data >= lhs._data;
	}

	template < class T, class Container = ft::vector<T> >
	void	swap(stack< T, Container > & lhs, stack< T, Container > & rhs) {
		stack< T, Container >	aux1;
		stack< T, Container >	aux2;

		while (lhs.size() > 0) {
			aux1.push(lhs.top());
			lhs.pop();
		}
		while (rhs.size() > 0) {
			aux2.push(rhs.top());
			rhs.pop();
		}
		while (aux2.size() > 0) {
			lhs.push(aux2.top());
			aux2.pop();
		}
		while (aux1.size() > 0) {
			rhs.push(aux1.top());
			aux1.pop();
		}
	}
}

#endif