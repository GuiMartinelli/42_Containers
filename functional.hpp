/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functional.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 20:28:05 by guferrei          #+#    #+#             */
/*   Updated: 2022/09/19 20:22:52 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONAL_HPP
#define FUNCTIONAL_HPP

namespace ft {
	template <class Arg1, class Arg2, class Result>
	struct binary_fuction {
		typedef Arg1	first_argument_type;
		typedef Arg2	second_argument_type;
		typedef Result	result_type;
	};

	template<class T>
	struct less {
		bool	operator()(T const & x, T const & y) const {
			return x < y;
		}
	} ;
}

#endif