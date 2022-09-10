/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 12:18:40 by guferrei          #+#    #+#             */
/*   Updated: 2022/09/10 12:34:51 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include "Vector.hpp"

namespace ft {

	template < class T, class Container = ft::vector<T>>
	class Stack
	{
	protected:
		Container	_data;

	public:
		//Member Type

		typedef Container					container_type;
		typedef Container::value_type		value_type;
		typedef Container::size_type		size_type;
		typedef Container::reference		reference;
		typedef Container::const_reference	const_reference;

		//Member Functions

		Stack() {};
		~Stack() {};
		Stack&	operator=(Stack& obj) {};

		//Element Access

		reference	top() {};

		const_reference	top() const {};

		//Capacity

		bool	empty() const {
			return this->_data->empty();
		}

		size_type	size() const {
			return this->_data->size();
		}

		//Modifiers

		void	push( const value_type& value) {
			
		}

		void	pop() {
			
		}
	};
}

#endif