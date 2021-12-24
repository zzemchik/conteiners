#pragma once
#ifndef TBTREEITERATOR_HPP
#define TBTREEITERATOR_HPP
#include "iterator.hpp"
#include "RBTree.hpp"
#include "RBNode.hpp"

namespace ft
{
	template<typename _Tp>
    struct RbTreeIterator : public ft::bidirectional_iterator<const _Tp>
    {
	public:
		typedef _Tp  														value_type;
		typedef typename ft::bidirectional_iterator<_Tp>::iterator_category	iterator_category;
		typedef typename ft::bidirectional_iterator<_Tp>::difference_type		difference_type;
		typedef typename ft::bidirectional_iterator<_Tp>::pointer				pointer;
		typedef typename ft::bidirectional_iterator<_Tp>::reference			reference;
		typedef RbTreeIterator<_Tp>		     								iterator;
		typedef RBNode<_Tp>*												_Base_ptr;
		typedef RBNode<_Tp>*												_Link_type;
		_Base_ptr _node;

		RbTreeIterator() : _node() {}

		~RbTreeIterator() {}

		explicit RbTreeIterator(_Base_ptr x) : _node(x) {}

		RbTreeIterator(const RbTreeIterator& copy) : _node(copy._node) {}

		template <typename Iter>
			RbTreeIterator(const RbTreeIterator<Iter>& copy) : _node(copy._node) {}

		RbTreeIterator	&operator=(const RbTreeIterator & other)
		{
			if (this != &other)
				_node = other._node;
			return (*this);
		}

		reference operator*() const { return _node->value; }

		pointer operator->() const { return &(_node->value); }

		iterator & operator++() { _node = RBTreeIncrement() ; return *this; }

		iterator operator++(int)
		{
			iterator __tmp = *this;
			_node = _Rb_tree_increment(_node);
			return __tmp;
		}
	iterator & operator--() {_node = RBTreeDecrement() ; return *this;}

		iterator operator--(int)
		{
			iterator __tmp = *this;
			_node = RBTreeDecrement(_node);
			return __tmp;
		}

		_Base_ptr	RBTreeIncrement()
		{
			_Base_ptr x = _node;
			if (x->right != 0)
			{
				x = x->right;
				while (x->left != 0)
					x = x->left;
			}
			else
			{
				_Base_ptr y = x->parent;
				while (x == y->right)
				{
					x = y;
					y = y->parent;
				}
				if (x->right != y)
					x = y;
			}
			return x;
		}
		_Base_ptr	RBTreeDecrement()
		{
			_Base_ptr	x = _node;
			if (x->color == red && x->parent->parent == x)
				x = x->right;
			else if (x->left != 0)
			{
				_Base_ptr	y = x->left;
				while (y->right != 0)
					y = y->right;
				x = y;
			}
			else
			{
				_Base_ptr	y = x->parent;
				while (x == y->left)
				{
					x = y;
					y = y->parent;
				}
				x = y;
			}
			return x;
		}

	};

	template<class T>
	bool	operator==(const RbTreeIterator<T> & x, const RbTreeIterator<T> & y) { return x._node == y._node; }
	template<class T>
	bool	operator!=(const RbTreeIterator<T>&x, const RbTreeIterator<T>&y) { return x._M_node != y._M_node; }


	template<typename _Tp>
    struct RbTreeConstIterator : public ft::bidirectional_iterator<const _Tp>
    {
	public:
		typedef _Tp  														value_type;
		typedef typename ft::bidirectional_iterator<_Tp>::iterator_category	iterator_category;
		typedef typename ft::bidirectional_iterator<_Tp>::difference_type		difference_type;
		typedef typename ft::bidirectional_iterator<_Tp>::pointer				pointer;
		typedef typename ft::bidirectional_iterator<_Tp>::reference			reference;
		typedef RbTreeConstIterator<_Tp>		     						iterator;
		typedef RBNode<_Tp>*												_Base_ptr;
		typedef RBNode<_Tp>*												_Link_type;
		_Base_ptr _node;

		RbTreeConstIterator() : _node() {}

		~RbTreeConstIterator() {}

		explicit RbTreeConstIterator(_Base_ptr x) : _node(x) {}

		RbTreeConstIterator(const RbTreeConstIterator& copy) : _node(copy._node) {}

		template <typename Iter>
			RbTreeConstIterator(const RbTreeConstIterator<Iter>& copy) : _node(copy._node) {}

		RbTreeConstIterator	&operator=(const RbTreeConstIterator & other)
		{
			if (this != &other)
				_node = other._node;
			return (*this);
		}

		reference operator*() const { return _node->value; }

		pointer operator->() const { return &(_node->value); }

		iterator & operator++() { _node = RBTreeIncrement() ; return *this; }

		iterator operator++(int)
		{
			iterator __tmp = *this;
			_node = _Rb_tree_increment(_node);
			return __tmp;
		}
	iterator & operator--() {_node = RBTreeDecrement() ; return *this;}

		iterator operator--(int)
		{
			iterator __tmp = *this;
			_node = RBTreeDecrement(_node);
			return __tmp;
		}

		_Base_ptr	RBTreeIncrement()
		{
			_Base_ptr x = _node;
			if (x->right != 0)
			{
				x = x->right;
				while (x->left != 0)
					x = x->left;
			}
			else
			{
				_Base_ptr y = x->parent;
				while (x == y->right)
				{
					x = y;
					y = y->parent;
				}
				if (x->right != y)
					x = y;
			}
			return x;
		}
		_Base_ptr	RBTreeDecrement()
		{
			_Base_ptr	x = _node;
			if (x->color == red && x->parent->parent == x)
				x = x->right;
			else if (x->left != 0)
			{
				_Base_ptr	y = x->left;
				while (y->right != 0)
					y = y->right;
				x = y;
			}
			else
			{
				_Base_ptr	y = x->parent;
				while (x == y->left)
				{
					x = y;
					y = y->parent;
				}
				x = y;
			}
			return x;
		}

	};

	template<class T>
	bool	operator==(const RbTreeConstIterator<T> & x, const RbTreeConstIterator<T> & y) { return x._node == y._node; }
	template<class T>
	bool	operator!=(const RbTreeConstIterator<T>&x, const RbTreeConstIterator<T>&y) { return x._M_node != y._M_node; }
}

#endif