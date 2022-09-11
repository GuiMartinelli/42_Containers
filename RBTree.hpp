/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:47:01 by guferrei          #+#    #+#             */
/*   Updated: 2022/09/11 13:22:02 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_HPP
#define RBTREE_HPP
#define BLACK 0
#define RED 1
#define D_BLACK 2

#include <iostream>
#include <memory>
#include "functional.hpp"

template< typename T >
struct Node
{
	T		data;
	Node*	right;
	Node*	left;
	Node*	parent;
	short	color;
};

template< typename T,
			typename _Compare = ft::less<T>,
			typename _Alloc = std::allocator< Node< T > > >
class RBTree
{
private:

	Node< T >	*_content;
	_Alloc		_alloc;
	_Compare	_comp;
	size_t		_size;

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

	Node< T >	*predecessor(Node< T > *node) {
		Node< T >	*aux;

		aux = node->left;
		while (aux->right)
			aux = aux->right;
		return aux;
	}

	Node< T >	*sucessor(Node< T > *node) {
		Node< T >	*aux;

		aux = node->right;
		while (aux->left)
			aux = aux->left;
		return aux;
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

		this->_size++;
		node->parent = par;
		if (!par) {
			this->_content = node;
		} else if (this->_comp(node->data, par->data)) {
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

	short	getColor(Node< T > *node) {
		if (!node || node->color == BLACK)
			return (BLACK);
		return (RED);
	}

	void	removeFix(Node< T > *node) {
		if (!node)
			return ;
		if (node == this->_content) {
			this->_content = NULL;
			return ;
		}

		if (getColor(node) == RED
			|| getColor(node->right) == RED
			|| getColor(node->left) == RED) {
			Node< T >	*child = (node->left) ? node->left : node->right;

			if (node == node->parent->left) {
				node->parent->left = child;
				if (child) {
					child->parent = node->parent;
					child->color = BLACK;
				}
				this->_alloc.deallocate(node, 1);
			} else {
				node->parent->right = child;
				if (child) {
					child->parent = node->parent;
					child->color = BLACK;
				}
				this->_alloc.deallocate(node, 1);
			}
		} else {
			Node< T >	*sibling;
			Node< T >	*parent;
			Node< T >	*aux = node;

			aux->color = D_BLACK;
			while (aux != this->_content && getColor(aux) == D_BLACK) {
				parent = aux->parent;
				if (aux == parent->left) {
					sibling = parent->right;
					if (getColor(sibling) == RED) {
						sibling->color = BLACK;
						parent->color = RED;
						leftRotate(parent);
					} else {
						if (getColor(sibling->left) == BLACK
							&& getColor(sibling->right) == BLACK) {
							sibling->color = RED;
							if (getColor(parent) == RED)
								parent->color = BLACK;
							else
								parent->color = D_BLACK;
							aux = parent;
						} else {
							if (getColor(sibling->right) == BLACK) {
								sibling->left->color = BLACK;
								sibling->color = RED;
								rightRotate(sibling);
								sibling = parent->right;
							}
							sibling->color = parent->color;
							parent->color = BLACK;
							sibling->right->color = BLACK;
							leftRotate(parent);
							break ;
						}
					}
				} else {
					sibling = parent->left;
					if (getColor(sibling) == RED) {
						sibling->color = BLACK;
						parent->color = RED;
						rightRotate(parent);
					} else {
						if (getColor(sibling->left) == BLACK
							&& getColor(sibling->right) == BLACK) {
								sibling->color = RED;
								if (getColor(parent) == RED)
									parent->color = BLACK;
								else
									parent->color = D_BLACK;
								aux = parent;
						} else {
							if (getColor(sibling->left) == BLACK) {
								sibling->right->color = BLACK;
								sibling->color = RED;
								leftRotate(sibling);
								sibling = parent->left;
							}
							sibling->color = parent->color;
							parent->color = BLACK;
							sibling->left->color = BLACK;
							rightRotate(parent);
							break ;
						}
					}
				}
			}

			if (node == node->parent->left)
				node->parent->left = NULL;
			else
				node->parent->right = NULL;
			this->_alloc.deallocate(node, 1);
			this->_content->color = BLACK;
		}
	}

	Node< T >	*BSTRemove(Node< T > *node, T data) {
		if (!node)
			return node;
		if (this->_comp(data, node->data))
			return BSTRemove(node->left, data);
		if(this->_comp(node->data, data))
			return BSTRemove(node->right, data);
		if (!node->left || !node->right)
			return node;

		Node< T >	*temp = sucessor(node);
		if (node->parent) {
			if (node->parent->left == node)
				node->parent->left = temp;
			else
				node->parent->right = temp;
		}
		temp->parent = node->parent;
		temp->right = node->right;
		temp->left = node->left;
		return BSTRemove(node->right, temp->data);
	}

	void	remove(T data) {
		Node< T >	*node = BSTRemove(this->_content, data);
		if (node)
			this->_size--;
		removeFix(node);
	}

	T	*search(Node< T > *node, T key) const {
		if (!node || (!_comp(node->data, key) && !_comp(key, node->data)))
			return &node->data ;
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

	Node< T >	*getRoot() const {
		return this->_content;
	}

	size_t	getSize() const {
		return this->_size;
	}
};

#endif
