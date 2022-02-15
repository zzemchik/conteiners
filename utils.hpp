#pragma once
#ifndef UTILS_HPP
#define UTILS_HPP
#include "iterator.hpp"

namespace ft {

	template<typename T, T v>
	struct integral_constant
	{
      typedef integral_constant<T, v>   type;
	};
	
	typedef integral_constant<bool, true>     true_type;

  	typedef integral_constant<bool, false>    false_type;

	template<typename>struct __is_integral_h : public false_type { };
		
	template<>struct __is_integral_h<bool> : public true_type { };

	template<>struct __is_integral_h<char> : public true_type { };

	template<>struct __is_integral_h<signed char> : public true_type { };

	template<>struct __is_integral_h<unsigned char> : public true_type { };

	template<>struct __is_integral_h<wchar_t> : public true_type { };

	template<>struct __is_integral_h<short> : public true_type { };

	template<>struct __is_integral_h<unsigned short> : public true_type { };

	template<>struct __is_integral_h<int> : public true_type { };

	template<>struct __is_integral_h<unsigned int> : public true_type { };

	template<>struct __is_integral_h<long>: public true_type { };

	template<>struct __is_integral_h<unsigned long> : public true_type { };

	template<>struct __is_integral_h<long long> : public true_type { };

	template<>struct __is_integral_h<unsigned long long> : public true_type { };

	template<typename _Tp>struct is_integral : public __is_integral_h<_Tp>::type { };



	template< class InputIt1, class InputIt2 >
	bool equal( InputIt1 first1, InputIt1 last1, InputIt2 first2 )
	{

		for (; first1 != last1; ++first1, ++first2)
			if (!(*first1 == *first2))
			return false;
		return true;
	}

	template< class InputIt1, class InputIt2, class BinaryPredicate >
	bool equal( InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate p )
	{
		for (; first1 != last1; ++first1, ++first2)
			if (!p(*first1 == *first2))
			return false;
		return true;
	}

	template<class InputIt1, class InputIt2>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
									InputIt2 first2, InputIt2 last2)
	{
		for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2)
		{
			if (*first1 < *first2)
				return (true);
			if (*first2 < *first1)
				return (false);
		}
		return ((first1 == last1) && (first2 != last2));
	}

	template<class InputIt1, class InputIt2, class Compare>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
									InputIt2 first2, InputIt2 last2, Compare comp)
	{
		for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2)
		{
			if (comp(*first1, *first2))
				return (true);
			if (comp(*first2, *first1))
				return (false);
		}
		return ((first1 == last1) && (first2 != last2));
	}

	template< class OutputIt, class Size, class T >
	void fill_n( OutputIt first, Size count, const T& value )
	{
		for (Size i = 0; i < count; ++i)
		{
			*first = value;
			++first;
		}
	}

	template< class ForwardIt, class T >
	void fill( ForwardIt first, ForwardIt last, const T& value )
	{
		while (first != last)
		{
			*first = value;
			++first;
		}
	}

	template <typename T>
	void	swap(T& a, T& b)
	{
		T	tmp = a;
		a = b;
		b = tmp;
	}
}

#endif