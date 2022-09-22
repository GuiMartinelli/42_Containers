/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:19:19 by guferrei          #+#    #+#             */
/*   Updated: 2022/09/22 16:19:41 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
#define NODE_HPP

template< typename T >
struct Node
{
	T		data;
	Node*	right;
	Node*	left;
	Node*	parent;
	short	color;
};

#endif
