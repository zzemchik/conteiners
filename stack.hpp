#pragma once

#ifndef STACK_HPP
#define STACH_HPP
#include "vector.hpp"

namespace ft
{
	template <class T, class Conteiner = ft::vector<T> >
	class stack
	{
		public:
			typedef typename Conteiner::value_type		value_type;
			typedef typename Conteiner::reference		reference;
			typedef typename Conteiner::const_reference	const_reference;
			typedef typename Conteiner::size_type		size_type;
			typedef	      	Conteiner					container_type;

			explicit stack( const container_type& cont = container_type() ) : _vector() { }

			stack( const stack& other ) { *this = other; } ;
			
			stack & operator=(const stack & oter) { _vector = oter._vector; }
			
			~stack() {};

			reference top() { return _vector.back(); }

			reference top() const { return _vector.back(); }	

			bool empty() const { return _vector.empty(); }

			size_type size() const { return _vector.size(); }

			void 	push(const T & __value) { _vector.push_back(__value); }
			
			void 	pop() { _vector.pop_back(); }

		private:
			container_type _vector;
	};

	template <class T, class Container>
	bool operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return (lhs.c == rhs.c); }

	template <class T, class Container>
	bool operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs){ return (!(lhs == rhs)); }

	template <class T, class Container>
	bool operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return (lhs.c < rhs.c); }

	template <class T, class Container>
	bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return (!(rhs < lhs)); }

	template <class T, class Container>
	bool operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return (rhs < lhs); }

	template <class T, class Container>
	bool operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return (!(lhs < rhs)); }
}

#endif