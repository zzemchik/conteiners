#pragma once

#ifndef REVERSEITERATOR_HPP
#define REVERSEITERATOR_HPP

#include "iteratorTreats.hpp"

namespace ft
{
	template< class Iter >
	class reverse_iterator {

		public:
			typedef Iter																iterator_type;
			typedef typename ft::iterator_traits<iterator_type>::difference_type		difference_type;
			typedef typename ft::iterator_traits<iterator_type>::value_type				value_type;
			typedef typename ft::iterator_traits<iterator_type>::pointer				pointer;
			typedef typename ft::iterator_traits<iterator_type>::reference				reference;	
			typedef typename ft::iterator_traits<iterator_type>::iterator_category		iterator_category; 

			reverse_iterator() : _ptr() {}
			explicit reverse_iterator(iterator_type it) : _ptr(it) {}
			reverse_iterator(const reverse_iterator& c) : _ptr(c._ptr) { }
			template< class _Iter >
			reverse_iterator(const reverse_iterator<_Iter>& c) : _ptr(c.base()) { }
			reverse_iterator & operator=(const reverse_iterator & c) { if (*this != c) _ptr = c._ptr; return (*this); }
			~reverse_iterator() {}
			iterator_type base() const { return _ptr; }

			reverse_iterator & operator++() {--_ptr; return *this; }
			reverse_iterator	operator++(int) {reverse_iterator t(_ptr); --_ptr; return t; }

			reverse_iterator & operator--() {++_ptr; return *this; }
			reverse_iterator	operator--(int) {reverse_iterator t(_ptr); ++_ptr; return t; }

			reverse_iterator & operator+=(difference_type n) { _ptr -= n; return *this; }
			reverse_iterator operator+(difference_type n) { return _ptr - n; }

			reverse_iterator & operator-=(difference_type n) { _ptr += n; return *this; }
			reverse_iterator operator-(difference_type n) { return _ptr + n; }

			reference operator*() const {iterator_type t = _ptr; return *(--t); }
			pointer		 operator->() const {return &(operator*()); }
			reference	operator[](difference_type n) {return base()[-n - 1]; }

		private:
			iterator_type	_ptr;
	};
	template <class Iterator>
	bool operator==(const reverse_iterator<Iterator>& a, const reverse_iterator<Iterator>& b) { return a.base() == b.base(); }

	template <class LeftIt, class RightIt>
	bool operator==(const reverse_iterator<LeftIt>& a, const reverse_iterator<LeftIt>& b) { return a.base() == b.base(); }

	template <class Iterator>
	bool operator!=(const reverse_iterator<Iterator>& a, const reverse_iterator<Iterator>& b) { return a.base() != b.base(); }

	template <class LeftIt, class RightIt>
	bool operator!=(const reverse_iterator<LeftIt>& a, const reverse_iterator<LeftIt>& b) { return a.base() != b.base(); }

	template <class Iterator>
	bool operator<(const reverse_iterator<Iterator>& a, const reverse_iterator<Iterator>& b) { return a.base() < b.base(); }

	template <class LeftIt, class RightIt>
	bool operator<(const reverse_iterator<LeftIt>& a, const reverse_iterator<LeftIt>& b)	{ return a.base() < b.base(); }

	template <class Iterator>
	bool operator<=(const reverse_iterator<Iterator>& a, const reverse_iterator<Iterator>& b)	{ return a.base() <= b.base(); }

	template <class LeftIt, class RightIt>
	bool operator<=(const reverse_iterator<LeftIt>& a, const reverse_iterator<LeftIt>& b) { return a.base() <= b.base(); }

	template <class Iterator>
	bool operator>(const reverse_iterator<Iterator>& a, const reverse_iterator<Iterator>& b)	{ return a.base() > b.base(); }

	template <class LeftIt, class RightIt>
	bool operator>(const reverse_iterator<LeftIt>& a, const reverse_iterator<LeftIt>& b)	{ return a.base() > b.base(); }

	template <class Iterator>
	bool operator>=(const reverse_iterator<Iterator>& a, const reverse_iterator<Iterator>& b)	{ return a.base() >= b.base(); }

	template <class LeftIt, class RightIt>
	bool operator>=(const reverse_iterator<LeftIt>& a, const reverse_iterator<LeftIt>& b)	{ return a.base() >= b.base(); }

	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type	operator-(const reverse_iterator<Iterator>& a,
																	const reverse_iterator<Iterator>& b)	{ return a.base() - b.base(); }

	template <class LeftIt, class RightIt>
	typename reverse_iterator<LeftIt>::difference_type	operator-(const reverse_iterator<LeftIt>& a,
																const reverse_iterator<RightIt>& b) { return a.base() - b.base(); }

	template <class Iterator>
	reverse_iterator<Iterator>	operator+(typename reverse_iterator<Iterator>::difference_type n,
											const reverse_iterator<Iterator>& it)	{ return reverse_iterator<Iterator>(it.base() - n); }											
}

#endif
