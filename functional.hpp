/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functional.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 20:28:05 by guferrei          #+#    #+#             */
/*   Updated: 2022/09/11 13:24:42 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LESS_HPP
#define LESS_HPP

namespace ft {
	template<class T>
	struct less {
		bool	operator()(T const & x, T const & y) const {
			return x < y;
		}
	} ;
}

#endif