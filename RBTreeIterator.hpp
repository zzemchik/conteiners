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
		typedef _Tp  															value_type;
		typedef typename ft::bidirectional_iterator<_Tp>::iterator_category		iterator_category;
		typedef typename ft::bidirectional_iterator<_Tp>::difference_type		difference_type;
		typedef typename ft::bidirectional_iterator<_Tp>::pointer				pointer;
		typedef typename ft::bidirectional_iterator<_Tp>::reference				reference;
		typedef RbTreeIterator<_Tp>		     									iterator;
		typedef RBNode<_Tp>*													_Base_ptr;
		typedef RBNode<_Tp>*													_Link_type;
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
			_node = RBTreeIncrement();
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
		friend bool	operator==(const iterator & x, const iterator & y) { return x._node == y._node; }
		friend bool	operator!=(const iterator & x, const iterator & y) { return x._node != y._node; }
	};

	template<typename _Tp>
    struct RbTreeConstIterator : public ft::bidirectional_iterator<const _Tp>
    {
	public:
		typedef _Tp  															value_type;
		typedef typename ft::bidirectional_iterator<_Tp>::iterator_category		iterator_category;
		typedef typename ft::bidirectional_iterator<_Tp>::difference_type		difference_type;
		typedef typename ft::bidirectional_iterator<const _Tp>::pointer				pointer;
		typedef typename ft::bidirectional_iterator<const _Tp>::reference				reference;
		typedef RbTreeConstIterator<_Tp>		     							_Self;
		typedef const RBNode<_Tp>*													_Base_ptr;
		typedef const RBNode<_Tp>*													_Link_type;
		typedef RbTreeIterator<_Tp>		     									iterator;
		_Base_ptr _node;
		RbTreeConstIterator() : _node() {}

		explicit RbTreeConstIterator(_Base_ptr x) : _node(x) {}
		
		~RbTreeConstIterator() {}


		RbTreeConstIterator(const RbTreeConstIterator& copy) : _node(copy._node) {}

		template <typename Iter>
		RbTreeConstIterator(const RbTreeIterator<Iter>& copy) : _node(copy._node) {}

		RbTreeConstIterator	&operator=(const RbTreeConstIterator & other)
		{
			if (this != &other)
				_node = other._node;
			return (*this);
		}

		reference operator*() const { return _node->value; }

		pointer operator->() const { return &(_node->value); }
		
		iterator	_M_const_cast() const { return iterator(const_cast<_Base_ptr>(_node)); }

		_Self & operator++() { _node = RBTreeIncrement() ; return *this; }

		_Self operator++(int)
		{
			_Self __tmp = *this;
			_node = RBTreeIncrement(_node);
			return __tmp;
		}

		_Self & operator--() {_node = RBTreeDecrement() ; return *this;}

		_Self operator--(int)
		{
			_Self __tmp = *this;
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
		friend bool	operator==(const _Self & x, const _Self & y) { return x._node == y._node; }
		friend bool	operator!=(const _Self & x, const _Self & y) { return x._node != y._node; }
	};
}

#endif