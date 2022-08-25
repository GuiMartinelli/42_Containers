/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:47:01 by guferrei          #+#    #+#             */
/*   Updated: 2022/08/25 19:57:54 by guferrei         ###   ########.fr       */
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

	Node< T >	*getUncle(Node< T > *node) const {
		Node< T >	*par = node->parent;

		if (this->_comp(par->data, par->parent->data))
			return par->parent->right;
		else
			return par->parent->left;
	}

	void leftRotate(Node< T > *node) {
		Node< T > *aux = node->right;

		node->right = aux->left;
		if (aux->left)
			aux->left->parent = node;
		aux->parent = node->parent;
		if (!node->parent)
			this->_content = aux;
		else if (node == node->parent->left)
			node->parent->left = aux;
		else
			node->parent->right = aux;
		aux->left = node;
		node->parent = aux;
	}

	void rightRotate(Node< T > *node) {
		Node< T > *aux = node->left;

		node->left = aux->right;
		if (aux->right)
			aux->right->parent = node;
		aux->parent = node->parent;
		if (!node->parent)
			this->_content = aux;
		else if (node == node->parent->right)
			node->parent->right = aux;
		else
			node->parent->left = aux;
		aux->right = node;
		node->parent = aux;
	}


	void insertFix(Node< T > *node) {
		Node< T >	*aux;

		while (node->parent->color == RED) {
			if (node->parent == node->parent->parent->right) {
				aux = getUncle(node);

				if (aux && aux->color == RED) {
					aux->color = BLACK;
					node->parent->color = BLACK;
					node->parent->parent->color = RED;
					node = node->parent->parent;
				} else {
					if (node == node->parent->left) {
						node = node->parent;
						rightRotate(node);
					}
					node->parent->color = BLACK;
					node->parent->parent->color = RED;
					leftRotate(node->parent->parent);
				}
			} else {
				aux = getUncle(node);

				if (aux && aux->color == RED) {
					aux->color = BLACK;
					node->parent->color = BLACK;
					node->parent->parent->color = RED;
					node = node->parent->parent;
				} else {
					if (node == node->parent->right) {
						node = node->parent;
						leftRotate(node);
					}
					node->parent->color = BLACK;
					node->parent->parent->color = RED;
					rightRotate(node->parent->parent);
				}
			}
			if (node == this->_content)
				break;
		}
		this->_content->color = BLACK;
	}

	bool	insert(T data) {
		Node< T > *node = createNode(data);
		Node< T > *par = NULL;
		Node< T > *aux = this->_content;

		while (aux) {
			par = aux;
			if (this->_comp(node->data, aux->data)) {
			aux = aux->left;
			} else if (this->_comp(aux->data, node->data)) {
			aux = aux->right;
			} else {
			return false;
			}
		}

		node->parent = par;
		if (!par) {
			this->_content = node;
		} else if (node->data < par->data) {
			par->left = node;
		} else {
			par->right = node;
		}

		if (!node->parent) {
			node->color = BLACK;
			return true;
		}
		if (!node->parent->parent) {
			return true;
		}

		insertFix(node);
		return true;
	}

	Node< T >	*search(Node< T > *node, T key) const {
		if (!node || (!_comp(node->data, key) && !_comp(key, node->data)))
			return node;
		if (_comp(key, node->data))
			return search(node->left, key);
		else
			return search(node->right, key);
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
