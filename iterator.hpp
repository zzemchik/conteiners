#pragma once
#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include <iostream>
namespace ft {


	struct input_iterator_tag { };
	struct output_iterator_tag { };
	struct forward_iterator_tag : public input_iterator_tag { };
	struct bidirectional_iterator_tag : public forward_iterator_tag { };
	struct random_access_iterator_tag : public bidirectional_iterator_tag { };


	
	template<typename _Iterator>
    struct iterator_traits
    {
      typedef typename _Iterator::iterator_category iterator_category;
      typedef typename _Iterator::value_type        value_type;
      typedef typename _Iterator::difference_type   difference_type;
      typedef typename _Iterator::pointer           pointer;
      typedef typename _Iterator::reference         reference;
    };

	template<typename _Iterator>
	struct iterator_traits<_Iterator*>
	{
	typedef ft::random_access_iterator_tag iterator_category;
	typedef _Iterator                         value_type;
	typedef ptrdiff_t                   difference_type;
	typedef _Iterator*                        pointer;
	typedef _Iterator&                        reference;
	};

	template<typename _Iterator>
	struct iterator_traits<const _Iterator*>
	{
	typedef ft::random_access_iterator_tag iterator_category;
	typedef _Iterator                         value_type;
	typedef ptrdiff_t                  		 	difference_type;
	typedef const _Iterator*                  pointer;
	typedef const _Iterator&                  reference;
	};


	
	template<
    class Category,
    class T,
	typename Distance = ptrdiff_t,
    class Pointer = T*,
    class Reference = T&>
		struct iterator {
			typedef Category 	iterator_category;
			typedef T			value_type;
			typedef Distance	difference_type;;
			typedef Pointer		pointer;
			typedef Reference	reference;
	};

	template <typename T>
	struct bidirectional_iterator : ft::iterator<ft::bidirectional_iterator_tag, T>
	{
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::value_type			value_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type		difference_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::pointer				pointer;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::reference				reference;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::iterator_category		iterator_category;
	};
	
	template < typename T>
	class Random_Access_Iterator : public iterator<ft::random_access_iterator_tag, T> {
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type		value_type;
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type	difference_type;
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::reference			reference;
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::pointer			pointer;
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category	iterator_category;
		

		
		pointer ptr;

		public:
			Random_Access_Iterator() : ptr(0) {}
			Random_Access_Iterator(pointer ptr) : ptr(ptr) { }
			Random_Access_Iterator(const Random_Access_Iterator & r) { *this = r; }
			Random_Access_Iterator & operator=(const Random_Access_Iterator & c) {if (*this != c) ptr = c.ptr; return (*this); }
			virtual ~Random_Access_Iterator() {}

			pointer base() { return ptr; }

			Random_Access_Iterator & operator--() {--ptr; return *this; }
			Random_Access_Iterator & operator++() {++ptr; return *this; }
			Random_Access_Iterator & operator--(int) {Random_Access_Iterator t(ptr); --ptr; return t; }
			Random_Access_Iterator & operator++(int) {Random_Access_Iterator t(ptr); --ptr; return t; }
			Random_Access_Iterator & operator+=(difference_type n) { ptr += n; return *this; }
			Random_Access_Iterator operator+(difference_type n) { return ptr + n; }
			Random_Access_Iterator & operator-=(difference_type n) { ptr -= n; return *this; }
			Random_Access_Iterator operator-(difference_type n) { return ptr - n; }
			reference operator*() const {return *ptr; }
			pointer		 operator->() {return ptr; }
			reference	operator[](difference_type n) {return *(ptr + n); }




	};
	template <typename T>
	bool operator<(Random_Access_Iterator<T> a, Random_Access_Iterator<T> b) { return a.base() < b.base(); }
	template <typename T>
	bool operator<=(Random_Access_Iterator<T> a, Random_Access_Iterator<T> b) { return a.base() <= b.base(); }
	template <typename T>
	bool operator>(Random_Access_Iterator<T> a, Random_Access_Iterator<T> b) { return a.base() > b.base(); }
	template <typename T>
	bool operator>=(Random_Access_Iterator<T> a, Random_Access_Iterator<T> b) { return a.base() >= b.base(); }
	template <typename T>
	bool operator==(Random_Access_Iterator<T> a, Random_Access_Iterator<T> b) { return a.base() == b.base(); }
	template <typename T>
	bool operator!=(Random_Access_Iterator<T> a, Random_Access_Iterator<T> b) { return a.base() != b.base(); }

	template< class Iter >
	class reverse_iterator {

		typedef Iter																iterator_type;
		typedef typename ft::iterator_traits<iterator_type>::difference_type		difference_type;
		typedef typename ft::iterator_traits<iterator_type>::value_type				value_type;
		typedef typename ft::iterator_traits<iterator_type>::pointer				pointer;
		typedef typename ft::iterator_traits<iterator_type>::reference				reference;	
		typedef typename ft::iterator_traits<iterator_type>::iterator_category		iterator_category; 

		reverse_iterator() : ptr() {}
			explicit reverse_iterator(iterator_type it) : ptr(it) {}
			reverse_iterator(const reverse_iterator& c)  { *this = c; }
			reverse_iterator & operator=(const reverse_iterator & c) { if (*this != c) ptr = c._it; return (*this); }
			~reverse_iterator() {}
			pointer base() { return ptr; }
			reverse_iterator & operator--() {--ptr; return *this; }
			reverse_iterator & operator++() {++ptr; return *this; }
			reverse_iterator & operator--(int) {reverse_iterator t(ptr); --ptr; return t; }
			reverse_iterator & operator++(int) {reverse_iterator t(ptr); --ptr; return t; }
			reverse_iterator & operator+=(difference_type n) { ptr += n; return *this; }
			reverse_iterator operator+(difference_type n) { return ptr + n; }
			reverse_iterator & operator-=(difference_type n) { ptr -= n; return *this; }
			reverse_iterator operator-(difference_type n) { return ptr - n; }
			reference operator*() const {return *ptr; }
			pointer		 operator->() {return ptr; }
			reference	operator[](difference_type n) {return *(ptr + n); }
		private:
			iterator_type	ptr;
	};
	template <class Iterator>
	bool operator==(const reverse_iterator<Iterator>& lit, const reverse_iterator<Iterator>& rit) { return lit.base() == rit.base(); }

	template <class LeftIt, class RightIt>
	bool operator==(const reverse_iterator<LeftIt>& lit, const reverse_iterator<LeftIt>& rit) { return lit.base() == rit.base(); }

	template <class Iterator>
	bool operator!=(const reverse_iterator<Iterator>& lit, const reverse_iterator<Iterator>& rit) { return lit.base() != rit.base(); }

	template <class LeftIt, class RightIt>
	bool operator!=(const reverse_iterator<LeftIt>& lit, const reverse_iterator<LeftIt>& rit) { return lit.base() != rit.base(); }

	template <class Iterator>
	bool operator<(const reverse_iterator<Iterator>& lit, const reverse_iterator<Iterator>& rit) { return lit.base() < rit.base(); }

	template <class LeftIt, class RightIt>
	bool operator<(const reverse_iterator<LeftIt>& lit, const reverse_iterator<LeftIt>& rit)	{ return lit.base() < rit.base(); }

	template <class Iterator>
	bool operator<=(const reverse_iterator<Iterator>& lit, const reverse_iterator<Iterator>& rit)	{ return lit.base() <= rit.base(); }

	template <class LeftIt, class RightIt>
	bool operator<=(const reverse_iterator<LeftIt>& lit, const reverse_iterator<LeftIt>& rit) { return lit.base() <= rit.base(); }

	template <class Iterator>
	bool operator>(const reverse_iterator<Iterator>& lit, const reverse_iterator<Iterator>& rit)	{ return lit.base() > rit.base(); }

	template <class LeftIt, class RightIt>
	bool operator>(const reverse_iterator<LeftIt>& lit, const reverse_iterator<LeftIt>& rit)	{ return lit.base() > rit.base(); }

	template <class Iterator>
	bool operator>=(const reverse_iterator<Iterator>& lit, const reverse_iterator<Iterator>& rit)	{ return lit.base() >= rit.base(); }

	template <class LeftIt, class RightIt>
	bool operator>=(const reverse_iterator<LeftIt>& lit, const reverse_iterator<LeftIt>& rit)	{ return lit.base() >= rit.base(); }

	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type	operator-(const reverse_iterator<Iterator>& lit,
																	const reverse_iterator<Iterator>& rit)	{ return lit.base() - rit.base(); }

	template <class LeftIt, class RightIt>
	typename reverse_iterator<LeftIt>::difference_type	operator-(const reverse_iterator<LeftIt>& lit,
																const reverse_iterator<RightIt>& rit) { return lit.base() - rit.base(); }

	template <class Iterator>
	reverse_iterator<Iterator>	operator+(typename reverse_iterator<Iterator>::difference_type n,
											const reverse_iterator<Iterator>& it)	{ return reverse_iterator<Iterator>(it.base() - n); }


	template< class InputIt >
	typename ft::iterator_traits<InputIt>::difference_type distance( InputIt first, InputIt last ) {
		typename ft::iterator_traits<InputIt>::difference_type i;
		for (i = 0; first != last; ++i)
			++first;
		return (i);
	}
	
}


#endif