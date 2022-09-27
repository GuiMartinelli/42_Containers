/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:20:57 by guferrei          #+#    #+#             */
/*   Updated: 2022/09/27 20:04:37 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iostream>
#include "node.hpp"

namespace ft
{
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag :public bidirectional_iterator_tag {};

	template <
		class Category,
		class T,
		class Distance = std::ptrdiff_t,
		class Pointer = T*,
		class Reference = T& >
	struct iterator {
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	iterator_category;
		};

	template< class Iter >
	struct iterator_traits {
		typedef typename Iter::difference_type		difference_type;
		typedef typename Iter::value_type			value_type;
		typedef typename Iter::pointer				pointer;
		typedef typename Iter::reference			reference;
		typedef typename Iter::iterator_category	iterator_category;
	};

	template< class T >
	struct iterator_traits< T* > {
		typedef std::ptrdiff_t				difference_type;
		typedef T							value_type;
		typedef T*							pointer;
		typedef T&							reference;
		typedef random_access_iterator_tag	iterator_category;
	};

	template< class T >
	struct iterator_traits< const T* > {
		typedef std::ptrdiff_t				difference_type;
		typedef T							value_type;
		typedef T*							pointer;
		typedef T&							reference;
		typedef random_access_iterator_tag	iterator_category;
	};

	template <typename T>
	class bidirectional_iterator : public iterator <random_access_iterator_tag,
													T >
	{
	protected:
		T	data;

	public:
		typedef T															iterator_type;
		typedef typename iterator_traits<iterator_type>::iterator_category	iterator_category;
		typedef typename iterator_traits<iterator_type>::value_type			value_type;
		typedef typename iterator_traits<iterator_type>::difference_type	difference_type;
		typedef typename iterator_traits<iterator_type>::pointer			pointer;
		typedef typename iterator_traits<iterator_type>::reference			reference;

		bidirectional_iterator() {};

		bidirectional_iterator(T ptr) {
			this->data = ptr;
		};

		bidirectional_iterator(bidirectional_iterator const & obj) {
			*this = obj;
		};

		~bidirectional_iterator() {};

		bidirectional_iterator &	operator=(bidirectional_iterator const & obj) {
			if (this != &obj)
				this->data = obj.data;
			return *this;
		};

		bool	operator==(bidirectional_iterator const & obj) {
			return (this->data == obj.data);
		}

		bool	operator!=(bidirectional_iterator const & obj) {
			return (this->data != obj.data);
		}

		bidirectional_iterator	operator++() {
			this->data++;

			return *this;
		}

		bidirectional_iterator	operator--() {
			this->data--;

			return *this;
		}

		bidirectional_iterator	operator++(int) {
			bidirectional_iterator	tmp(*this);
			this->data++;

			return tmp;
		}

		bidirectional_iterator	operator--(int) {
			bidirectional_iterator	tmp(*this);
			this->data--;

			return tmp;
		}

		reference	operator*() {
			return (*data);
		}

		pointer	operator->() {
			return data;
		}
	};

	template <typename T>
	class	bidirectional_reverse_iterator : public bidirectional_iterator<T> {
		public:
			bidirectional_reverse_iterator() {};

			bidirectional_reverse_iterator(T ptr) {
				this->data = ptr;
			};

			bidirectional_reverse_iterator(bidirectional_reverse_iterator const & obj) {
				*this = obj;
			};
			
			~bidirectional_reverse_iterator() {};

			bidirectional_reverse_iterator	operator++() {
				this->data--;

				return *this;
			}

			bidirectional_reverse_iterator	operator--() {
				this->data++;

				return *this;
			}

			bidirectional_reverse_iterator	operator++(int) {
				bidirectional_reverse_iterator	tmp(*this);
				this->data--;

				return tmp;
			}

			bidirectional_reverse_iterator	operator--(int) {
				bidirectional_reverse_iterator	tmp(*this);
				this->data++;

				return tmp;
			}
	};

	template <typename T>
	class tree_bidirectional_iterator
	// : public iterator <random_access_iterator_tag, T >
	{
	protected:
		Node< T >	*_data;
		Node< T >	*_nil;
		Node< T >	*_begin;
		Node< T >	*_end;

	public:
		typedef T															iterator_type;
		// typedef typename iterator_traits<iterator_type>::iterator_category	iterator_category;
		// typedef typename iterator_traits<iterator_type>::value_type			value_type;
		// typedef typename iterator_traits<iterator_type>::difference_type	difference_type;
		// typedef typename iterator_traits<iterator_type>::pointer			pointer;
		// typedef typename iterator_traits<iterator_type>::reference			reference;

		tree_bidirectional_iterator() {};

		tree_bidirectional_iterator(Node< T > *ptr, Node< T > *nil, Node< T > *begin, Node< T > *end) {
			this->_data = ptr;
			this->_nil = nil;
			this->_begin = begin;
			this->_end = end;
		};

		tree_bidirectional_iterator(tree_bidirectional_iterator const & obj) {
			*this = obj;
		};

		~tree_bidirectional_iterator() {};

		tree_bidirectional_iterator &	operator=(tree_bidirectional_iterator const & obj) {
			if (this != &obj) {
				this->_data = obj._data;
				this->_nil = obj._nil;
				this->_begin = obj._begin;
				this->_end = obj._end;
			}
			return *this;
		};

		bool	operator==(tree_bidirectional_iterator const & obj) {
			return (this->_data == obj._data);
		}

		bool	operator!=(tree_bidirectional_iterator const & obj) {
			return (this->_data != obj._data);
		}

		tree_bidirectional_iterator	operator++() {
			if (this->_data == this->_nil)
				this->_data = this->_begin;
			else if (this->_data->right != this->_nil) {
				this->_data = this->_data->right;
				while (this->_data->left != this->_nil)
					this->_data = this->_data->left;
			} else {
				while (this->_data->parent && (this->_data != this->_data->parent->left))
					this->_data = this->_data->parent;
				this->_data = this->_data->parent;
			}

			if (this->_data == this->_nil)
				this->_data = NULL;

			return *this;
		}

		tree_bidirectional_iterator	operator--() {
			if (this->_data == this->_nil)
				this->_data = this->_end;
			else if (this->_data->left != this->_nil) {
				this->_data = this->_data->left;
				while (this->_data->right != this->_nil)
					this->_data = this->_data->right;
			} else {
				while (this->_data->parent && (this->_data != this->_data->parent->right))
					this->_data = this->_data->parent;
				this->_data = this->_data->parent;
			}

			if (this->_data == this->_nil)
				this->_data = NULL;

			return *this;
		}

		tree_bidirectional_iterator	operator++(int) {
			tree_bidirectional_iterator	tmp(*this);

			if (this->_data == this->_nil)
				this->_data = this->_begin;
			else if (this->_data->right != this->_nil) {
				this->_data = this->_data->right;
				while (this->_data->left != this->_nil)
					this->_data = this->_data->left;
			} else {
				while (this->_data->parent && (this->_data != this->_data->parent->left))
					this->_data = this->_data->parent;
				this->_data = this->_data->parent;
			}

			if (this->_data == this->_nil)
				this->_data = NULL;

			return tmp;
		}

		tree_bidirectional_iterator	operator--(int) {
			tree_bidirectional_iterator	tmp(*this);

			if (this->_data == this->_nil)
				this->_data = this->_end;
			else if (this->_data->left != this->_nil) {
				this->_data = this->_data->left;
				while (this->_data->right != this->_nil)
					this->_data = this->_data->right;
			} else {
				while (this->_data->parent && (this->_data != this->_data->parent->right))
					this->_data = this->_data->parent;
				this->_data = this->_data->parent;
			}

			if (this->_data == this->_nil)
				this->_data = NULL;

			return tmp;
		}

		T	&operator*() {
			return (_data->data);
		}

		T	*operator->() {
			return &_data->data;
		}
	};

	template <typename T>
	class reverse_tree_bidirectional_iterator : public tree_bidirectional_iterator< T >
	{
	public:
		reverse_tree_bidirectional_iterator() {};

		reverse_tree_bidirectional_iterator(Node< T > *ptr, Node< T > *nil, Node< T > *begin, Node< T > *end) {
			this->_data = ptr;
			this->_nil = nil;
			this->_begin = begin;
			this->_end = end;
		};

		reverse_tree_bidirectional_iterator(reverse_tree_bidirectional_iterator const & obj) {
			*this = obj;
		};

		~reverse_tree_bidirectional_iterator() {};

		reverse_tree_bidirectional_iterator &	operator=(reverse_tree_bidirectional_iterator const & obj) {
			if (this != &obj) {
				this->_data = obj._data;
				this->_nil = obj._nil;
				this->_begin = obj._begin;
				this->_end = obj._end;
			}
			return *this;
		};

		reverse_tree_bidirectional_iterator	operator--() {
			if (this->_data == this->_nil)
				this->_data = this->_begin;
			else if (this->_data->right != this->_nil) {
				this->_data = this->_data->right;
				while (this->_data->left != this->_nil)
					this->_data = this->_data->left;
			} else {
				while (this->_data->parent && (this->_data != this->_data->parent->left))
					this->_data = this->_data->parent;
				this->_data = this->_data->parent;
			}

			if (this->_data == this->_nil)
				this->_data = NULL;

			return *this;
		}

		reverse_tree_bidirectional_iterator	operator++() {
			if (this->_data == this->_nil)
				this->_data = this->_end;
			else if (this->_data->left != this->_nil) {
				this->_data = this->_data->left;
				while (this->_data->right != this->_nil)
					this->_data = this->_data->right;
			} else {
				while (this->_data->parent && (this->_data != this->_data->parent->right))
					this->_data = this->_data->parent;
				this->_data = this->_data->parent;
			}

			if (this->_data == this->_nil)
				this->_data = NULL;

			return *this;
		}

		reverse_tree_bidirectional_iterator	operator--(int) {
			reverse_tree_bidirectional_iterator	tmp(*this);

			if (this->_data == this->_nil)
				this->_data = this->_begin;
			else if (this->_data->right != this->_nil) {
				this->_data = this->_data->right;
				while (this->_data->left != this->_nil)
					this->_data = this->_data->left;
			} else {
				while (this->_data->parent && (this->_data != this->_data->parent->left))
					this->_data = this->_data->parent;
				this->_data = this->_data->parent;
			}

			if (this->_data == this->_nil)
				this->_data = NULL;

			return tmp;
		}

		reverse_tree_bidirectional_iterator	operator++(int) {
			reverse_tree_bidirectional_iterator	tmp(*this);

			if (this->_data == this->_nil)
				this->_data = this->_end;
			else if (this->_data->left != this->_nil) {
				this->_data = this->_data->left;
				while (this->_data->right != this->_nil)
					this->_data = this->_data->right;
			} else {
				while (this->_data->parent && (this->_data != this->_data->parent->right))
					this->_data = this->_data->parent;
				this->_data = this->_data->parent;
			}

			if (this->_data == this->_nil)
				this->_data = NULL;

			return tmp;
		}
	};

	template <typename T>
	class random_access_iterator : public bidirectional_iterator<T> {
	public:
		typedef T															iterator_type;
		typedef typename iterator_traits<iterator_type>::iterator_category	iterator_category;
		typedef typename iterator_traits<iterator_type>::value_type			value_type;
		typedef typename iterator_traits<iterator_type>::difference_type	difference_type;
		typedef typename iterator_traits<iterator_type>::pointer			pointer;
		typedef typename iterator_traits<iterator_type>::reference			reference;

		random_access_iterator() {};

		random_access_iterator(random_access_iterator const & obj) {
			*this = obj;
		};

		random_access_iterator(T ptr) {
			this->data = ptr;
		};

		~random_access_iterator() {};

		random_access_iterator &	operator=(random_access_iterator const & obj) {
			if (this != &obj)
				this->data = obj.data;
			return *this;
		};

		random_access_iterator	operator+(difference_type n) {
			random_access_iterator	aux;

			aux = this->data;
			for (; n > 0; n--)
				aux++;
			return (aux);
		}

		random_access_iterator	operator-(difference_type n) {
			random_access_iterator	aux;

			aux = this->data;
			for (; n > 0; n--)
				aux--;
			return (aux);
		}

		int	operator+(random_access_iterator const & obj) {
			return (this->data + obj.data);
		}

		int	operator-(random_access_iterator const & obj) {
			return (this->data - obj.data);
		}

		bool	operator<(random_access_iterator const & obj) {
			return (this->data < obj.data);
		}

		bool	operator>(random_access_iterator const & obj) {
			return (this->data > obj.data);
		}

		bool	operator<=(random_access_iterator const & obj) {
			return (this->data <= obj.data);
		}

		bool	operator>=(random_access_iterator const & obj) {
			return (this->data >= obj.data);
		}

		random_access_iterator	operator+=(difference_type n) {
			for (; n > 0; n--)
				this->data++;
			return (this->data);
		}

		random_access_iterator	operator-=(difference_type n) {
			for (; n > 0; n--)
				this->data--;
			return (this->data);
		}

		T&	operator[](int n) {
			return this->data[n];
		}
	};

	template <typename T>
	class	random_access_reverse_iterator : public bidirectional_reverse_iterator<T> {
		public:
			random_access_reverse_iterator() {};

			random_access_reverse_iterator(T ptr) {
				this->data = ptr;
			};

			random_access_reverse_iterator(random_access_reverse_iterator const & obj) {
				*this = obj;
			};
			
			~random_access_reverse_iterator() {};

			bool	operator<(random_access_reverse_iterator const & obj) {
				return !(this->data < obj.data);
			}

			bool	operator>(random_access_reverse_iterator const & obj) {
				return !(this->data > obj.data);
			}

			bool	operator<=(random_access_reverse_iterator const & obj) {
				return !(this->data <= obj.data);
			}

			bool	operator>=(random_access_reverse_iterator const & obj) {
				return !(this->data >= obj.data);
			}
	};
}

#endif
