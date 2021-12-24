#pragma once
#ifndef RBTree_HPP
#define RBTree_HPP

#include <algorithm>
#include <memory>
#include <iostream>
#include "pair.hpp"
#include "RBTreeIterator.hpp"
#include "RBNode.hpp"
#include "utils.hpp"


namespace ft
{


	template <typename Arg1, typename Arg2, typename Result>
	struct binary_function
	{
		typedef Arg1	first_argument_type;
		typedef Arg2	second_argument_type;
		typedef Result	result_type;
	};

	 template<typename _Key, typename _Val, typename _KeyOfValue,
	   typename _Compare, typename _Alloc = std::allocator<_Val> >
    class RBTree
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
			typedef ft::RbTreeIterator<value_type>									iterator;
			typedef ft::RbTreeConstIterator<value_type>								const_iterator;
			typedef ft::reverse_iterator<iterator>									reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>							const_reverse_iterator;

		private:
			typedef typename allocator_type::template rebind<RBNode<_Val> >::other		node_allocator_type;
			typedef RBNode<value_type>*													node;
			typedef const RBNode<value_type>*											const_node;
			
		public:
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
			RBTree() {}

			RBTree(const _Compare& comp, const allocator_type& alloc = allocator_type())
				: _comp(comp), _alloc(alloc), _size(0) { __create_header(); }

	 		RBTree(const RBTree& x) 
				: _comp(x._comp), _alloc(x._alloc), _size(x._size)
			{
				__create_header();
				if (x.header->parent != 0)
					header->parent = __copy(x);
			}

			RBTree&	operator=(const RBTree& x)
			{
				if (this != &x)
				{
					clear();
					_comp = x._comp;
					get_key = x.get_key;
					if (x.header->parent != 0)
						header->parent = __copy(x);
				}
				return (*this);
			}

			~RBTree() 
			{
				erase(header->parent);
				node_alloc.deallocate(header, 1);
			}

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

			pair<iterator, bool>	insert_unique(const value_type& val)
			{
				typedef pair<iterator, bool>	_res;
				ft::pair<node, node>	res = __getPosInsert(get_key(val));

				_res	ret;
				if (res.second)
					return _res(insert(res.first, res.second, val), true);
				return _res(iterator(res.first), false);
			}

			iterator				insert_unique(iterator position, const value_type& val)
			{
				pair<node, node>	res = __insertPos(position, get_key(val));

				iterator	ret;
				if (res.second)
					return insert(res.first, res.second, val);
				return iterator(res.first);
			}

			template <typename InputIterator>
			void					insert_range_unique(InputIterator first, InputIterator last)
			{
				for (; first != last; ++first)
					insert_unique(end(), *first);
			}

			void					erase(iterator position)
			{
				if (position != end())
					__erase_aux(position);
			}

			size_type				erase(const key_type& k)
			{
				ft::pair <iterator, iterator>	p = _equal_range(k);
				const size_type					old_size = _size;

				__erase_aux(p.first, p.second);
				return old_size - _size;
			}

			void					erase(iterator first, iterator last)
			{
				__erase_aux(first, last);
			}

			void					swap(RBTree& t)
			{
				ft::swap(header, t.header);
				ft::swap(_size, t._size);
			}

			void					clear()
			{
				erase(header->parent);
				__reset_header();
				_size = 0;
			}

			iterator				find(const key_type& k)
			{
				iterator	j = __lower_bound(header->parent, header, k);
				if (j == end() || _comp(k, get_key(j._M_node->value)))
					return end();
				return j;
			}
			
			const_iterator			find(const key_type& k) const
			{
				const_iterator	j = __lower_bound(header->parent, header, k);
				if (j == end() || _comp(k, get_key(j._M_node->value)))
					return end();
				return j;
			}

			iterator				__lower_bound(const key_type& k) { return __lower_bound(header->parent, header, k); }
			
			const_iterator			__lower_bound(const key_type& k) const { return __lower_bound(header->parent, header, k); }

			iterator				__upper_bound(const key_type& k) { return __upper_bound(header->parent, header, k); }

			const_iterator			__upper_bound(const key_type& k) const { return __upper_bound(header->parent, header, k); }

			pair<iterator,iterator>	equal_range(const key_type& k) { return _equal_range(k); }
			
			pair<const_iterator,const_iterator>	equal_range(const key_type& k) const { return _equal_range(k); }

			friend bool				operator==(const RBTree& x, const RBTree& y)
			{ return x.size() == y.size() && ft::equal(x.begin(), x.end(), y.begin()); }
			friend bool				operator<(const RBTree& x, const RBTree& y)
			{ return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end()); }
			friend bool				operator!=(const RBTree& x, const RBTree& y)
			{ return !(x == y); }
			friend bool				operator>(const RBTree& x, const RBTree& y)
			{ return y < x; }
			friend bool				operator<=(const RBTree& x, const RBTree& y)
			{ return !(y < x); }
			friend bool				operator>=(const RBTree& x, const RBTree& y)
			{ return !(x < y); }

		private:
			void	__reset_header()
			{
				header->left = header;
				header->right = header;
				header->parent = 0;
			}

			void	__create_header()
			{
				header = node_alloc.allocate(1);
				__reset_header();
				header->color = red;
			}

			node	__create_node(const value_type& x)
			{
				node	tmp = node_alloc.allocate(1);
				_alloc.construct(&(tmp->value), x);
				tmp->left = 0;
				tmp->right = 0;
				tmp->parent = 0;
				tmp->color = black;
				return tmp;
			}

			ft::pair<node, node>	__getPosInsert(const key_type k)
			{
				typedef ft::pair<node, node>	res;
				node	x = static_cast<node>(header->parent);
				node	y = header;
				bool	comp = true;
				while (x != 0)
				{
					y = x;
					comp = _comp(k, get_key(x->value));
					x = comp ? x->left : x->right;
				}
				iterator	j = iterator(y);
				if (comp)
				{
					if (j == begin())
						return res(x, y);
					else
						--j;
				}
				if (_comp(get_key(j._M_node->value), k))
					return res(x, y);
				return res(j._M_node, 0);
			}

			void					__tree_rotate_left(node x, node& r)
			{
				node const y = x->right;

				x->right = y->left;
				if (y->left !=0)
					y->left->parent = x;
				y->parent = x->parent;
				if (x == r)
					r = y;
				else if (x == x->parent->left)
					x->parent->left = y;
				else
					x->parent->right = y;
				y->left = x;
				x->parent = y;
			}

			void					__tree_rotate_right(node x, node& r)
			{
				node const y = x->left;
				
				x->left = y->right;
				if (y->right != 0)
					y->right->parent = x;
				y->parent = x->parent;
				if (x == r)
					r = y;
				else if (x == x->parent->right)
					x->parent->right = y;
				else
					x->parent->left = y;
				y->right = x;
				x->parent = y;
			}

			void					__insert_and_rebalance(const bool insert_left, node x, node p)
			{
				x->parent = p;
				x->left = 0;
				x->right = 0;
				x->color = red;
				if (insert_left)
				{
					p->left = x;
					if (p == header)
					{
						header->parent = x;
						header->right = x;
					}
					else if (p == header->left)
						header->left = x;
				}
				else
				{
					p->right = x;
					if (p == header->right)
						header->right = x;
				}
				node&	r = header->parent;
				while (x != r && x->parent->color == red)
				{
					node const xpp = x->parent->parent;
					if (x->parent == xpp->left)
					{
						node const y = xpp->right;
						if (y && y->color == red)
						{
							x->parent->color = black;
							y->color = black;
							xpp->color = red;
							x = xpp;
						}
						else
						{
							if (x == x->parent->right)
							{
								x = x->parent;
								__tree_rotate_left(x, r);
							}
							x->parent->color = black;
							xpp->color = red;
							__tree_rotate_right(xpp, r);
						}
					}
					else
					{
						node const y = xpp->left;
						if (y && y->color == red)
						{
							x->parent->color = black;
							y->color = black;
							xpp->color = red;
							x = xpp;
						}
						else
						{
							if (x == x->parent->left)
							{
								x = x->parent;
								__tree_rotate_right(x, r);
							}
							x->parent->color = black;
							xpp->color = red;
							__tree_rotate_left(xpp, r);
						}
					}
				}
				r->color = black;
			}

			iterator				__insert(node x, node p, const value_type& val)
			{
				bool insert_left = (x != 0 || p == header || _comp(get_key(val), get_key(p->value)));
				node	z = __create_node(val);
				__insert_and_rebalance(insert_left, z, p);
				++_size;
				return iterator(z);
			}

			node					__leftmost() { return header->left; }

			node					__rightmost() { return header->right; }

			pair<node, node>		__insertPos(iterator pos, const key_type& k)
			{
				typedef pair<node, node>	_res;

				if (pos._M_node == header)
				{
					node	rig = __rightmost();
					if (_size > 0 && _comp(get_key(rig->value), k))
						return _res(0, rig);
					else
						return __getPosInsert(k);
				}
				else if (_comp(k, get_key(pos._M_node->value)))
				{
					node	lft = __leftmost();
					iterator	before = pos;
					if (pos._M_node == lft)
						return _res(lft, lft);
					else if (_comp(get_key((--before)._M_node->value), k))
					{
						if (before._M_node->right == 0)
							return _res(0, before._M_node);
						else
							return _res(pos._M_node, pos._M_node);
					}
					else
						return __getPosInsert(k);
				}
				else if (_comp(get_key(pos._M_node->value), k))
				{
					node	rig = __rightmost();
					iterator	after = pos;
					if (pos._M_node == rig)
						return _res(0, rig);
					else if (_comp(k, get_key((++after)._M_node->value)))
					{
						if (pos._M_node->right == 0)
							return _res(0, pos._M_node);
						else
							return _res(after._M_node, after._M_node);
					}
					else
						return __getPosInsert(k);
				}
				else
					return _res(pos._M_node, 0);
			}

			node					__minimum(node x)
			{
				while (x->left)
					x = x->left;
				return (x);
			}

			node					__maximum(node x)
			{
				while (x->right)
					x = x->right;
				return (x);
			}

			node					__rebalance_for_erase(node z)
			{
				node&	root = header->parent;
				node&	lft = header->left;
				node&	rig = header->right;
				node	y = z;
				node	x = 0;
				node	x_parent = 0;

				if (y->left == 0)
					x = y->right;
				else if (y->right == 0)
					x = y->left;
				else
				{
					y = y->right;
					while (y->left != 0)
						y = y->left;
					x = y->right;
				}
				if (y != z)
				{
					z->left->parent = y;
					y->left = z->left;
					if (y != z->right)
					{
						x_parent = y->parent;
						if (x) x->parent = y->parent;
							y->parent->left = x;
						y->right = z->right;
						z->right->parent = y;
					}
					else
						x_parent = y;
					if (root == z)
						root = y;
					else if (z->parent->left == z)
						z->parent->left = y;
					else
						z->parent->right = y;
					y->parent = z->parent;
					ft::swap(y->color, z->color);
					y = z;
				}
				else
				{
					x_parent = y->parent;
					if (x)
						x->parent = y->parent;
					if (root == z)
						root = x;
					else if (z->parent->left == z)
						z->parent->left = x;
					else
						z->parent->right = x;
					if (lft == z)
					{
						if (z->right == 0)
							lft = z->parent;
						else
							lft = __minimum(x);
					}
					if (rig == z)
					{
						if (z->left == 0)
							rig = z->parent;
						else
							rig = __maximum(x);
					}
				}
				if (y->color != red)
				{
					while (x != root && (x == 0 || x->color == black))
						if (x == x_parent->left)
						{
							node	w = x_parent->right;
							if (w->color == red)
							{
								w->color = black;
								x_parent->color = red;
								__tree_rotate_left(x_parent, root);
								w = x_parent->right;
							}
							if ((w->left == 0 || w->left->color == black) && \
								(w->right == 0 || w->right->color == black))
							{
								w->color = red;
								x = x_parent;
								x_parent = x_parent->parent;
							}
							else
							{
								if (w->right == 0 || w->right->color == black)
								{
									w->left->color = black;
									w->color = red;
									__tree_rotate_right(w, root);
									w = x_parent->right;
								}
								w->color = x_parent->color;
								x_parent->color = black;
								if (w->right)
									w->right->color = black;
								__tree_rotate_left(x_parent, root);
								break;
							}
						}
						else
						{
							node	w = x_parent->left;
							if (w->color == red)
							{
								w->color = black;
								x_parent->color = red;
								__tree_rotate_right(x_parent, root);
								w = x_parent->left;
							}
							if ((w->right == 0 || w->right->color == black) && \
								(w->left == 0 || w->left->color == black))
							{
								w->color = red;
								x = x_parent;
								x_parent = x_parent->parent;
							}
							else
							{
								if (w->left == 0 || w->left->color == black)
								{
									w->right->color = black;
									w->color = red;
									__tree_rotate_left(w, root);
									w = x_parent->left;
								}
								w->color = x_parent->color;
								x_parent->color = black;
								if (w->left)
									w->left->color = black;
								__tree_rotate_right(x_parent, root);
								break;
							}
						}
					if (x)
						x->color = black;
				}
				return y;
			}

			void					__drop_node(node p)
			{
				_alloc.destroy(&(p->value));
				node_alloc.deallocate(p, 1);
			}

			void					__erase_aux(iterator position)
			{
				node	y = __rebalance_for_erase(position._M_node);

				__drop_node(y);
				--_size;
			}

			iterator				__lower_bound(node x, node y, const key_type& k)
			{
				while (x != 0)
				{
					if (!_comp(get_key(x->value), k))
					{
						y = x;
						x = x->left;
					}
					else
						x = x->right;
				}
				return iterator(y);
			}

			const_iterator			__lower_bound(const_node x, const_node y, const key_type& k) const
			{
				while (x != 0)
				{
					if (!_comp(get_key(x->value), k))
					{
						y = x;
						x = x->left;
					}
					else
						x = x->right;
				}
				return const_iterator(y);
			}

			iterator				__upper_bound(node x, node y, const key_type& k)
			{
				while (x != 0)
				{
					if (_comp(k, get_key(x->value)))
					{
						y = x;
						x = x->left;
					}
					else
						x = x->right;
				}
				return iterator(y);
			}

			const_iterator			__upper_bound(const_node x, const_node y, const key_type& k) const
			{
				while (x != 0)
				{
					if (_comp(k, get_key(x->value)))
					{
						y = x;
						x = x->left;
					}
					else
						x = x->right;
				}
				return const_iterator(y);
			}

			ft::pair<iterator, iterator>	_equal_range(const key_type& k)
			{
				typedef ft::pair<iterator, iterator> _res;
				node	x = header->parent;
				node	y = header;

				while (x != 0)
				{
					if (_comp(get_key(x->value), k))
						x = x->right;
					else if (_comp(k, get_key(x->value)))
					{
						y = x;
						x = x->left;
					}
					else
					{
						node	xu(x);
						node	yu(y);
						y = x;
						x = x->left;
						xu = xu->right;
						return _res(__lower_bound(x, y, k), __upper_bound(xu, yu, k));
					}
				}
				return _res(iterator(y), iterator(y));
			}

			ft::pair<const_iterator, const_iterator>	_equal_range(const key_type& k) const
			{
				typedef ft::pair<const_iterator, const_iterator> _res;
				node	x = header->parent;
				node	y = header;

				while (x != 0)
				{
					if (_comp(get_key(x->value), k))
						x = x->right;
					else if (_comp(k, get_key(x->value)))
					{
						y = x;
						x = x->left;
					}
					else
					{
						node	xu(x);
						node	yu(y);
						y = x;
						x = x->left;
						xu = xu->right;
						return _res(__lower_bound(x, y, k), __upper_bound(xu, yu, k));
					}
				}
				return _res(const_iterator(y), const_iterator(y));
			}

			void					__erase_aux(iterator first, iterator last)
			{
				if (first == begin() && last == end())
					clear();
				else
					while (first != last)
						__erase_aux(first++);
			}

			void					erase(node x)
			{
				while (x != 0)
				{
					erase(x->right);
					node y = x->left;
					__drop_node(x);
					x = y;
				}
			}

			node					__clone(node x)
			{
				node	tmp = __create_node(x->value);

				tmp->color = x->color;
				return tmp;
			}

			node					__copy(node x, node p)
			{
				node	top = __clone(x);

				top->parent = p;
				if (x->right)
					top->right = __copy(x->right, top);
				p = top;
				x = x->left;
				while (x != 0)
				{
					node	y = __clone(x);
					p->left = y;
					y->parent = p;
					if (x->right)
						y->right = __copy(x->right, y);
					p = y;
					x = x->left;
				}
				return top;
			}

			node					__copy(const RBTree& x)
			{
				node	root = __copy(x.header->parent, header);
				header->left = __minimum(root);
				header->right = __maximum(root);
				_size = x._size;
				return root;
			}
	};

}


#endif