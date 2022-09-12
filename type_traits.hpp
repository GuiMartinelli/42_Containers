/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 13:51:39 by guferrei          #+#    #+#             */
/*   Updated: 2022/09/12 11:12:56 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_TRAITS_HPP
#define TYPE_TRAITS_HPP

namespace ft
{
	template< typename, bool>
	struct enable_if {};

	template< typename T >
	struct enable_if<T, true> {
		typedef T	type;
	};

	template< class T, T v >
	struct integral_constant {
		static const T value = v;
	};

	typedef integral_constant<bool, false>	false_type;
	typedef integral_constant<bool, true>	true_type;

	template< typename T >
	struct is_integral : false_type {};

	template<>
	struct is_integral<bool> : true_type {};

	template<>
	struct is_integral<char> : true_type {};

	template<>
	struct is_integral<wchar_t> : true_type {};

	template<>
	struct is_integral<signed char> : true_type {};

	template<>
	struct is_integral<short int> : true_type {};

	template<>
	struct is_integral<int> : true_type {};

	template<>
	struct is_integral<long int> : true_type {};

	template<>
	struct is_integral<long long int> : true_type {};

	template<>
	struct is_integral<unsigned char> : true_type {};

	template<>
	struct is_integral<unsigned short int> : true_type {};

	template<>
	struct is_integral<unsigned int> : true_type {};

	template<>
	struct is_integral<unsigned long int> : true_type {};

	template<>
	struct is_integral<unsigned long long int> : true_type {};
}


#endif