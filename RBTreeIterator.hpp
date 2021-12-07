#pragma once
#ifndef TBTREEITERATOR_HPP
#define TBTREEITERATOR_HPP
#include "iterator.hpp"
#include "RBTree.hpp"
namespace ft
{
	template<typename _Tp>
    struct _Rb_tree_iterator : public ft::bidirectional_iterator<const T>
    {
    typedef _Tp  									value_type;
    typedef _Tp& 									reference;
    typedef _Tp* 									pointer;
    typedef bidirectional_iterator_tag 				iterator_category;
    typedef ptrdiff_t								difference_type;
    typedef _Rb_tree_iterator<_Tp>		     		iterator;
    typedef ft::RBNode								RBNode;
    typedef ft::RBNode<_Tp>*						_Link_type;
    RBNode *_node;

    _Rb_tree_iterator() : _node() {}

	~_Rb_tree_iterator() {}

	_Rb_tree_iterator(RBNode __x) : _node(__x) {}

	reference operator*() const { return *static_cast<_Link_type>(RBNode)->value; }

    pointer operator->() const { return static_cast<_Link_type>(RBNode)->value; }

    iterator & operator++() {RBNode = RBTreeIncrement() ; return *this;}

	iterator operator++(int)
	{
		iterator __tmp = *this;
		RBNode = _Rb_tree_increment(RBNode);
		return __tmp;
    }
   iterator & operator--() {RBNode = RBTreeDecrement() ; return *this;}

	iterator operator--(int)
	{
		iterator __tmp = *this;
		RBNode = RBTreeDecrement(RBNode);
		return __tmp;
    }

	_Base_ptr	RBTreeIncrement()
	{
		RBNode	x = _node;
		if (x->right != 0)
		{
			x = x->right;
			while (x->left != 0)
				x = x->left;
		}
		else
		{
			RBNode	y = x->parent;
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
		RBNode	x = _node;
		if (x->color == red && x->parent->parent == x)
			x = x->right;
		else if (x->left != 0)
		{
			RBNode	y = x->left;
			while (y->right != 0)
				y = y->right;
			x = y;
		}
		else
		{
			RBNode	y = x->parent;
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
	bool	operator==(const _Rb_tree_iterator<T> & x, const _Rb_tree_iterator<T> & y) { return x._node == y._node; }
	template<class T>
	bool	operator!=(const _Rb_tree_iterator<T>&x, const _Rb_tree_iterator<T>&y) { return x._M_node != y._M_node; }


		 template<typename _Tp>
    struct _Rb_tree_iterator_const : public ft::bidirectional_iterator<const T>
    {
    typedef _Tp  									value_type;
    typedef _Tp& 									reference;
    typedef _Tp* 									pointer;
    typedef bidirectional_iterator_tag 				iterator_category;
    typedef ptrdiff_t								difference_type;
    typedef _Rb_tree_iterator_const<_Tp>		     		iterator;
    typedef ft::RBNode								RBNode;
    typedef ft::RBNode<_Tp>*						_Link_type;
    RBNode *_node;

    _Rb_tree_iterator_const() : _node() {}

	~_Rb_tree_iterator_const() {}

	_Rb_tree_iterator_const(RBNode __x) : _node(__x) {}

	reference operator*() const { return *static_cast<_Link_type>(RBNode)->value; }

    pointer operator->() const { return static_cast<_Link_type>(RBNode)->value; }

    iterator & operator++() {RBNode = RBTreeIncrement() ; return *this;}

	iterator operator++(int)
	{
		iterator __tmp = *this;
		RBNode = _Rb_tree_increment(RBNode);
		return __tmp;
    }
   iterator & operator--() {RBNode = RBTreeDecrement() ; return *this;}

	iterator operator--(int)
	{
		iterator __tmp = *this;
		RBNode = RBTreeDecrement(RBNode);
		return __tmp;
    }

	_Base_ptr	RBTreeIncrement()
	{
		RBNode	x = _node;
		if (x->right != 0)
		{
			x = x->right;
			while (x->left != 0)
				x = x->left;
		}
		else
		{
			RBNode	y = x->parent;
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
		RBNode	x = _node;
		if (x->color == red && x->parent->parent == x)
			x = x->right;
		else if (x->left != 0)
		{
			RBNode	y = x->left;
			while (y->right != 0)
				y = y->right;
			x = y;
		}
		else
		{
			RBNode	y = x->parent;
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
	bool	operator==(const _Rb_tree_iterator_const<T> & x, const _Rb_tree_iterator_const<T> & y) { return x._node == y._node; }
	template<class T>
	bool	operator!=(const _Rb_tree_iterator_const<T>&x, const _Rb_tree_iterator_const<T>&y) { return x._M_node != y._M_node; }
}

#endif