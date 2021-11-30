#pragma once

#ifndef RANDOMACCESSITERATOR_HPP
#define RANDOMACCESSITERATOR_HPP

#include "iteratorTreats.hpp"

namespace ft
{
	template < typename T>
	class Random_Access_Iterator : public iterator<ft::random_access_iterator_tag, T> 
	{
		public:
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type		value_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type	difference_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::reference			reference;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::pointer			pointer;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category	iterator_category;

			Random_Access_Iterator() : ptr(0) {}
			Random_Access_Iterator(pointer ptr) : ptr(ptr) { }
			Random_Access_Iterator(const Random_Access_Iterator & r) { this->ptr = r.ptr; }

			template < typename _T>
			Random_Access_Iterator(const Random_Access_Iterator<_T> & r) { this->ptr = r.ptr; }

			Random_Access_Iterator & operator=(const Random_Access_Iterator & c) {if (*this != c) ptr = c.ptr; return (*this); }
			virtual ~Random_Access_Iterator() {}

			pointer base() const { return ptr; }

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
		private:
			pointer ptr;
	};


	template <typename T>
	typename ft::Random_Access_Iterator<T>::difference_type	operator-(const ft::Random_Access_Iterator<T> a, const ft::Random_Access_Iterator<T> b) 
	{ return (a.base() - b.base()); }
	template <typename L, typename R>
	typename ft::Random_Access_Iterator<L>::difference_type	operator-(const ft::Random_Access_Iterator<L> a, const ft::Random_Access_Iterator<R> b)
	{ return (a.base() - b.base()); }

	template <typename T>
	ft::Random_Access_Iterator<T>	operator+(typename ft::Random_Access_Iterator<T>::difference_type n, const ft::Random_Access_Iterator<T> it)
	{ return ft::Random_Access_Iterator<T>(it.base() + n); }

	template <typename T>
	bool operator<(Random_Access_Iterator<T> a, Random_Access_Iterator<T> b) { return a.base() < b.base(); }
	template <typename L, typename R>
	bool	operator<(const ft::Random_Access_Iterator<L> a, const ft::Random_Access_Iterator<R> b) { return (a.base() < b.base()); }

	template <typename T>
	bool operator<=(Random_Access_Iterator<T> a, Random_Access_Iterator<T> b) { return a.base() <= b.base(); }
	template <typename L, typename R>
	bool	operator<=(const ft::Random_Access_Iterator<L> a, const ft::Random_Access_Iterator<R> b) { return (a.base() <= b.base()); }

	template <typename T>
	bool operator>(Random_Access_Iterator<T> a, Random_Access_Iterator<T> b) { return a.base() > b.base(); }
	template <typename L, typename R>
	bool	operator>(const ft::Random_Access_Iterator<L> a, const ft::Random_Access_Iterator<R> b) { return (a.base() > b.base()); }

	template <typename T>
	bool operator>=(Random_Access_Iterator<T> a, Random_Access_Iterator<T> b) { return a.base() >= b.base(); }
	template <typename L, typename R>
	bool	operator>=(const ft::Random_Access_Iterator<L> a, const ft::Random_Access_Iterator<R> b) { return (a.base() >= b.base()); }

	template <typename T>
	bool operator==(Random_Access_Iterator<T> a, Random_Access_Iterator<T> b) { return a.base() == b.base(); }
	template <typename L, typename R>
	bool	operator==(const ft::Random_Access_Iterator<L> a, const ft::Random_Access_Iterator<R> b) { return (a.base() == b.base()); }

	template <typename T>
	bool operator!=(Random_Access_Iterator<T> a, Random_Access_Iterator<T> b) { return a.base() != b.base(); }
	template <typename L, typename R>
	bool	operator!=(const ft::Random_Access_Iterator<L> a, const ft::Random_Access_Iterator<R> b) { return (a.base() != b.base()); }

}

#endif
