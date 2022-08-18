/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:47:01 by guferrei          #+#    #+#             */
/*   Updated: 2022/08/17 21:02:39 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_HPP
#define RBTREE_HPP
#define RED true
#define BLACK false

#include <iostream>
#include <memory>
#include "../Pair.hpp"
#include "../Less.hpp"

template< typename T >
struct Node
{
	T		data;
	Node*	right;
	Node*	left;
	Node*	parent;
	bool	color;
};

template< typename T,
			typename _Compare = ft::less<T>,
			typename _Alloc = std::allocator< Node< T > > >
class RBTree
{
private:

	Node< T >	*_content;
	int			_size;
	_Alloc		_alloc;
	_Compare	_comp;

public:

	RBTree() {
		this->_content = NULL;
		this->_size = 0;
	} ;

	RBTree(RBTree const & obj) {} ;

	~RBTree() {
		destroy(this->_content);
	} ;

	Node< T >	*createNode(T data) {
		Node< T >	*node = this->_alloc.allocate(1);
		node->data = data;
		node->parent = NULL;
		node->left = NULL;
		node->right = NULL;
		node->color = RED;
		return node;
	}

	Node< T >	*getUncle(Node< T > *node) {
		Node< T >	*par = node->parent;

		if (this->_comp(par->data, par->parent->data))
			return par->parent->right;
		else
			return par->parent->left;
	}

	bool	insert(T data) {
		Node< T >	*node;
		Node< T >	*par = NULL;
		Node< T >	*temp = this->_content;

		while(temp) {
			par = temp;
			if (this->_comp(data, par->data))
				temp = temp->left;
			else if (this->_comp(par->data, data))
				temp = temp->right;
			else
				return false;
		}
		node = createNode(data);
		node->parent = par;

		if (!par) {
			node->color = BLACK;
			this->_content = node;
			return true;
		}
		if (this->_comp(data, par->data))
			par->left = node;
		else
			par->right = node;
		if (!par->color) {
			if (this->_comp(data, par->data))
				par->left = node;
			else
				par->right = node;
		} else {
			if (getUncle(node)->color) {
				getUncle(node)->color = !getUncle(node)->color;
				par->color = !par->color;
				if (par->parent != this->_content)
					par->parent->color = !par->parent->color;
			}
			//ROTATION
		}
		return true;
	};

	Node< T >	*search(Node< T > *node, T key) const {
		if (!node || (!_comp(node->data, key) && !_comp(key, node->data)))
			return node;
		if (_comp(key, node->data))
			return search(node->left, key);
		else
			return search(node->right, key);
	}

	Node< T >	*remove(Node< T > *node, T key) {
		//SOON
		return NULL;
	}

	Node< T >	*min(Node< T > *node) const {
		Node< T >	*temp;

		temp = node;
		while (temp->left)
			temp = temp->left;
		return temp;
	}

	Node< T >	*max(Node< T > *node) const {
		Node< T >	*temp;

		temp = node;
		while (temp->right)
			temp = temp->right;
		return temp;
	}

	void	destroy(Node< T > *node) {
		if (node) {
			destroy(node->left);
			destroy(node->right);
			_alloc.deallocate(node, sizeof(Node< T > *));
		}
	}

	void	print(Node< T > *node) const {
		if (node) {
			print(node->left);
			std::cout << node->data << " -> ";
			if (node->color)
				std::cout << "RED" << std::endl;
			else
				std::cout << "BLACK" << std::endl;
			print(node->right);
		}
	}

	Node< T >	*getRoot() const {
		return this->_content;
	}
};

#endif
