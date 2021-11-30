#pragma once

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iostream>
#include "randomAccessIterator.hpp"
#include "reverseIterator.hpp"
#include "iteratorTreats.hpp"

namespace ft 
{

	template <typename T>
	struct bidirectional_iterator : ft::iterator<ft::bidirectional_iterator_tag, T>
	{
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::value_type			value_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type		difference_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::pointer				pointer;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::reference				reference;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::iterator_category		iterator_category;
	};
	
	
	template< class InputIt >
	typename ft::iterator_traits<InputIt>::difference_type distance( InputIt first, InputIt last )
	{
		typename ft::iterator_traits<InputIt>::difference_type i;
		for (i = 0; first != last; ++i)
			++first;
		return (i);
	}
	
}


#endif