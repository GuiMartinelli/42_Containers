/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:47:01 by guferrei          #+#    #+#             */
/*   Updated: 2022/09/29 22:32:35 by guferrei         ###   ########.fr       */
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
#include "node.hpp"

template< typename T,
			typename _Compare = ft::less<T>,
			typename _Alloc = std::allocator< Node< T > > >
class RBTree
{
private:
	Node< T >	*_content;
	Node< T >	*_nil;
	_Alloc		_alloc;
	_Compare	_comp;
	size_t		_size;

	Node< T >	*createNode(const T& data) {
		Node< T >	*node = this->_alloc.allocate(1);
		node->data = data;
		node->parent = NULL;
		node->left = this->_nil;
		node->right = this->_nil;
		node->color = RED;
		return node;
	}

	void	copy(Node< T > *node, Node< T > *nil) {
		if (!node || node == nil)
			return ;
		this->insert(node->data);
		this->copy(node->left, nil);
		this->copy(node->right, nil);
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
		if (aux->left != this->_nil)
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
		if (aux->right != this->_nil)
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

				if (aux && aux != this->_nil && aux->color == RED) {
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

				if (aux && aux != this->_nil && aux->color == RED) {
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

	short	getColor(Node< T > *node) {
		if (!node || node->color == BLACK)
			return (BLACK);
		return (node->color);
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
				if (child != this->_nil) {
					child->parent = node->parent;
					child->color = BLACK;
				}
				this->_alloc.deallocate(node, 1);
			} else {
				node->parent->right = child;
				if (child != this->_nil) {
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

public:
	RBTree() {
		this->_content = NULL;
		this->_nil = createNode(T());
		this->_size = 0;
	} ;

	RBTree(RBTree const & obj) {
		*this = obj;
	} ;

	~RBTree() {
		destroy(this->_content);
		_alloc.deallocate(this->_nil, sizeof(Node< T > *));
	};

	RBTree&	operator=(RBTree const & obj) {
		this->destroy(this->getRoot());
		this->copy(obj.getRoot(), obj.getNil());

		return *this;
	}

	void	swap(RBTree& obj) {
		Node< T >	*root;
		Node< T >	*nil;
		int			size;

		root = obj._content;
		nil = obj._nil;
		size = obj._size;

		obj._content = this->_content;
		obj._nil = this->_nil;
		obj._size = this->_size;

		this->_content = root;
		this->_nil = nil;
		this->_size = size;
	}

	Node< T >	*predecessor(Node< T > *node) {
		Node< T >	*aux;

		aux = node->left;
		while (aux->right != this->_nil)
			aux = aux->right;
		return aux;
	}

	Node< T >	*sucessor(Node< T > *node) {
		Node< T >	*aux;

		aux = node->right;
		while (aux->left != this->_nil)
			aux = aux->left;
		return aux;
	}

	bool	insert(const T& data) {
		Node< T > *node = createNode(data);
		Node< T > *par = NULL;
		Node< T > *aux = this->_content;

		while (aux && aux != this->_nil) {
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

	bool	insert(const T& hint, const T& data) {
		Node< T > *node = createNode(data);
		Node< T > *par = NULL;
		Node< T > *aux = this->search(this->_content, hint);

		while (aux && aux != this->_nil) {
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

	Node< T >	*BSTRemove(Node< T > *node, const T& data) {
		if (!node)
			return node;
		if (this->_comp(data, node->data))
			return BSTRemove(node->left, data);
		if(this->_comp(node->data, data))
			return BSTRemove(node->right, data);
		if (!node->left && !node->right)
			return node;

		Node< T >	*temp = sucessor(node);
		if (!temp)
			temp = predecessor(node);
		node->data = temp->data;
		return BSTRemove(node->right, temp->data);
	}

	void	remove(const T& data) {
		Node< T >	*node = BSTRemove(this->_content, data);
		if (node)
			this->_size--;
		removeFix(node);
	}

	Node< T >	*search(Node< T > *node, const T& key) const {
		if (!node || (!_comp(node->data, key) && !_comp(key, node->data)))
			return node;
		if (_comp(key, node->data))
			return search(node->left, key);
		else
			return search(node->right, key);
	}

	Node< T >	*min() const {
		Node< T >	*temp;

		temp = this->_content;
		while (temp->left != this->_nil)
			temp = temp->left;
		return temp;
	}

	Node< T >	*min(Node< T > *node) const {
		Node< T >	*temp;

		temp = node;
		while (temp->left != this->_nil)
			temp = temp->left;
		return temp;
	}

	Node< T >	*max() const {
		Node< T >	*temp;

		temp = this->_content;
		while (temp->right != this->_nil)
			temp = temp->right;
		return temp;
	}

	Node< T >	*max(Node< T > *node) const {
		Node< T >	*temp;

		temp = node;
		while (temp->right != this->_nil)
			temp = temp->right;
		return temp;
	}

	void	destroy(Node< T > *node) {
		if (node && node != this->_nil) {
			destroy(node->left);
			destroy(node->right);
			_alloc.deallocate(node, sizeof(Node< T > *));
			this->_size--;
		}
	}

	Node< T >	*getRoot() const {
		return this->_content;
	}

	Node< T >	*getNil() const {
		return this->_nil;
	}

	size_t	getSize() const {
		return this->_size;
	}
};

#endif
