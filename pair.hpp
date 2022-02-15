#pragma once

#ifndef pair_HPP
#define pair_HPP

namespace ft
{

	template<class L, class R>
	struct pair
	{

		typedef L	first_type;
		typedef R	second_type;

		first_type first;
		second_type second;
		
		pair() : first(), second() { }
		pair(const L & lft, const R & rht) : first(lft), second(rht) { }
		template<class U1, class U2>
		pair(const pair<U1, U2> & p) : first(p.first), second(p.second) {}
		pair & operator=(const pair & copy)
		{
			if (this != &copy)
			{
				first = copy.first;
				second = copy.second;
			}
			return *this;
		}
	};

	template<class L, class R>
	ft::pair<L,R>	make_pair(L f, R s)
	{
		return ft::pair<L, R>(f, s);
	}


	template <class L, class R>
	bool operator==(const ft::pair<L,R> & lhs, const ft::pair<L,R>& rhs)
	{
		return (lhs.first == rhs.first && lhs.second == lhs.second);
	}

	template<class L, class R>
	bool operator!=(const ft::pair<L,R> & lhs, const ft::pair<L,R> & rhs)
	{
		return (!(lhs == rhs));
	}

	template<class L, class R>
	bool operator<(const ft::pair<L,R> & lhs, const ft::pair<L,R> & rhs)
	{
		return ((lhs.first < rhs.first) || ((lhs.first == rhs.first) && lhs.second < rhs.second));
	}

	template<class L, class R>
	bool operator<=(const ft::pair<L,R> & lhs, const ft::pair<L,R> & rhs)
	{
		return (!(rhs < lhs));
	}

	template<class L, class R>
	bool operator>(const ft::pair<L,R>& lhs, const ft::pair<L,R>& rhs)
	{
		return (rhs < lhs);
	}

	template<class L, class R>
	bool operator>=(const ft::pair<L,R>& lhs, const ft::pair<L,R>& rhs)
	{
		return (!(lhs < rhs));
	}


	template <typename pair>
	struct Select1st
	{
		typename pair::first_type&			operator()(pair& x) const { return x.first; }
		const typename pair::first_type&	operator()(const pair& x) const { return x.first; }
	};
}

#endif
