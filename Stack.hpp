/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 12:18:40 by guferrei          #+#    #+#             */
/*   Updated: 2022/09/10 12:51:55 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include "Vector.hpp"

namespace ft {

	template < class T, class Container = ft::vector<T> >
	class stack
	{
	protected:
		Container	_data;

	public:
		//Member Type

		typedef Container					container_type;
		typedef typename Container::value_type		value_type;
		typedef typename Container::size_type		size_type;
		typedef typename Container::reference		reference;
		typedef typename Container::const_reference	const_reference;

		//Member Functions

		stack() {};

		~stack() {};

		stack&	operator=(stack& obj) {
			this->_data = obj._data;
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
}

#endif