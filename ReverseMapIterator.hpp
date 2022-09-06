/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReverseMapIterator.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 19:49:50 by guferrei          #+#    #+#             */
/*   Updated: 2022/09/05 19:55:53 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSEMAPITERATOR_HPP
#define REVERSEMAPITERATOR_HPP

#include <iostream>

namespace ft
{
	template<typename T>
	class ReverseMapIterator
	{
	protected:
	T*	data;

	public:
		ReverseMapIterator() {
			this->data = NULL;
		}

		ReverseMapIterator(T* ptr) {
			this->data = ptr;
		}

		~ReverseMapIterator();
	};
}

#endif