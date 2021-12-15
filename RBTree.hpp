#pragma once
#ifndef RBTREE_HPP
#define RBTREE_HPP

#include <algorithm>
#include <memory>
#include <iostream>
#include "pair.hpp"
#include "RBTreeIterator.hpp"

namespace ft
{
	enum _Rb_tree_color 
	{
		red = false, black = true 
	};

	template <class T>
	struct RBNode
	{
		public:
			typedef T		value_type;
			value_type		value;
			RBNode 			*left; 
			RBNode 			*right;
			bool			color;

			RBNode()
			{
				left = 0;
				right = 0;
			}
			RBNode(const RBNode & c)
			{
				this->left = c.left;
				this->right = c.right;
				this->value = c.value;
			}
	};



	 template<typename _Key, typename _Val, typename _KeyOfValue,
	   typename _Compare, typename _Alloc = std::allocator<_Val> >
    class RBtree
	{
		public:
			typedef _Key															key_type;
			typedef _Val															value_type;
			typedef value_type*														pointer;
			typedef const value_type*												const_pointer;
			typedef value_type&														reference;
			typedef const value_type&												const_reference;
			typedef size_t															size_type;
			typedef ptrdiff_t														difference_type;
			typedef _Alloc															allocator_type;
			typedef ft::_Rb_tree_iterator<value_type>								iterator;
			typedef ft::_Rb_tree_iterator_const<value_type>							const_iterator;
			typedef ft::reverse_iterator<_Rb_tree_iterator>							reverse_iterator;
			typedef ft::reverse_iterator<_Rb_tree_iterator_const>					const_reverse_iterator;

		private:

		typedef typename allocator_type::template rebind<RBNode<Val> >::other		node_allocator_type;
		typedef RBNode<value_type>*													node;
		typedef const RBNode<value_type>*											const_node;
			RBNode<value_type> *_Node;
			_Compare																_comp;
			allocator_type															_alloc;
			node_allocator_type														node_alloc;
			node																	header;
			size_type																_size;
			_KeyOfValue																get_key;

		protected:
			typedef RBNode<value_type>*												link_type;
			typedef const RBNode<value_type>*										const_link_type;
		
		public:
			RBtree() {}
			RBtree(const Compare& comp, const allocator_type& alloc = allocator_type())
			: _comp(comp), _alloc(alloc), _size(0) { create_header(); }
	 		RBtree(const RBTree& x) : _comp(x._comp), _alloc(x._alloc), _size(x._size)
			{
				create_header();
				if (x.header->parent != 0)
					header->parent = copy(x);
			}
			RBTree&	operator=(const RBTree& x)
			{
				if (this != &x)
				{
					clear();
					_comp = x._comp;
					get_key = x.get_key;
					if (x.header->parent != 0)
						header->parent = copy(x);
				}
				return (*this);
			}
			~RBTree() { erase(header->parent); node_alloc.deallocate(header, 1); }

			iterator				begin() { return iterator(header->left); }
			const_iterator			begin() const { return const_iterator(header->left); }
			iterator				end() { return iterator(header); }
			const_iterator			end() const { return const_iterator(header); }
			reverse_iterator		rbegin() { return reverse_iterator(end()); }
			const_reverse_iterator	rbegin() const { return const_reverse_iterator(end()); }
			reverse_iterator		rend() { return reverse_iterator(begin()); }
			const_reverse_iterator	rend() const { return const_reverse_iterator(begin()); }

			bool					empty() const { return !_size; }
			size_type				size() const { return _size; }
			size_type				max_size() const { return node_alloc.max_size(); }
			


	};

}


#endif