/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 13:51:39 by guferrei          #+#    #+#             */
/*   Updated: 2022/09/11 14:24:34 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_TRAITS_HPP
#define TYPE_TRAITS_HPP

namespace ft
{
	template< class T, T value >
	struct integral_constant;
	typedef integral_constant<bool, false>	false_type;
	typedef integral_constant<bool, true>	true_type;


	template< typename T >
	struct is_integral {
		typedef false_type	type;
	};

	template<>
	struct is_integral<int> {
		typedef true_type	type;
	};
}


#endif