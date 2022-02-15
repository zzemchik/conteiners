#pragma once

#ifndef ITERATORTREATS_HPP
#define ITERATORTREATS_HPP

#include <cstddef>

namespace ft
{


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
	typedef ft::random_access_iterator_tag 			iterator_category;
	typedef _Iterator								value_type;
	typedef ptrdiff_t								difference_type;
	typedef _Iterator*								pointer;
	typedef _Iterator&								reference;
	};

	template<typename _Iterator>
	struct iterator_traits<const _Iterator*>
	{
	typedef ft::random_access_iterator_tag			iterator_category;
	typedef _Iterator								value_type;
	typedef ptrdiff_t								difference_type;
	typedef const _Iterator*						pointer;
	typedef const _Iterator&						reference;
	};


	
	template<class Category, class T, typename Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
		struct iterator {
			typedef Category 	iterator_category;
			typedef T			value_type;
			typedef Distance	difference_type;;
			typedef Pointer		pointer;
			typedef Reference	reference;
	};

}

#endif