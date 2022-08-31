/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:19:12 by guferrei          #+#    #+#             */
/*   Updated: 2022/08/30 21:19:44 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft
{
	template<typename T1, typename T2>
	class pair
	{
	public:
		T1	first;
		T2	second;

		typedef T1	first_type;
		typedef T2	second_type;

		pair(first_type first) : first(first) {
		}

		pair(first_type first, second_type second) : first(first) {
			this->second = second;
		}

		// pair(pair const & obj) {
		// 	*this = obj;
		// }

		// pair &	operator=(pair const & obj) {
		// 	if (this != &obj) {
		// 		this->first = obj.first;
		// 		this->second = obj.second;
		// 	}
		// 	return *this;
		// }

		~pair();
	};

	template<typename T1, typename T2>
	pair<T1, T2>	*make_pair(T1 x, T2 y) {
		return (new ft::pair<T1, T2>(x, y));
	}
}

#endif
