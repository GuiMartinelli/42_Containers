/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 19:40:50 by guferrei          #+#    #+#             */
/*   Updated: 2022/09/05 21:09:14 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPITERATOR_HPP
#define MAPITERATOR_HPP

#include <iostream>

namespace ft
{
	template<typename T>
	class MapIterator
	{
	protected:
	T*	data;

	public:
		MapIterator() {
			this->data = NULL;
		}

		MapIterator(T* ptr) {
			this->data = ptr;
		}

		~MapIterator() {};
	};
}

#endif
