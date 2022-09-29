/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:19:12 by guferrei          #+#    #+#             */
/*   Updated: 2022/09/29 10:12:19 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_HPP
#define UTILITY_HPP

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

		pair() : first(), second() {}

		pair(const first_type& a, const second_type& b) : first(a), second(b) { }

		template< class U, class V >
		pair(const pair<U, V>& obj) : first(obj.first), second(obj.second) {}

		pair&	operator=(const pair& obj) {
			if (this == &obj)
				return (*this);
			first = obj.first;
			second = obj.second;
			return (*this);
		}

		~pair() {};

		bool	operator==(const pair<T1, T2>& obj) const {
			return (this->first == obj.first && this->second == obj.second);
		}

		bool	operator!=(const pair<T1, T2>& p1) const {
			return (this->first != p1.first);
		}

		bool	operator<(const pair<T1, T2>& p1) const {
			return (this->first < p1.first);
		}

		bool	operator<=(const pair<T1, T2>& p1) const {
			return (this->first <= p1.first);
		}

		bool	operator>(const pair<T1, T2>& p1) const {
			return (this->first > p1.first);
		}

		bool	operator>=(const pair<T1, T2>& p1) const {
			return (this->first >= p1.first);
		}
	};

	template<class T1, class T2>
	pair<T1, T2>	make_pair(T1 x, T2 y) {
		return (pair<T1, T2>(x, y));
	}
}

#endif
