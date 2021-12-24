#pragma once

#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft
{

	template<class L, class R>
	struct pair
	{

		typedef L	first_type;
		typedef R	second_type;

		L first;
		R second;
		
		pair() : first(), second() { }
		pair(const L & lft, const R & rht) : first(lft), second(rht) { }
		template <class L1, class R1>
		pair(const pair<L1, R1> & copy) : first(copy.first), second(copy.second) {}
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
	pair<L,R>	make_pair(const L & first, const R & second)
	{
		pair<L, R> _pair(first, second);
		return (_pair);
	}


	template <class L, class R>
	bool operator==(const pair<L,R>& lhs, const pair<L,R>& rhs)
	{
		return (lhs.first == rhs.first && lhs.second == lhs.second);
	}

	template<class L, class R>
	bool operator!=(const pair<L,R>& lhs, const pair<L,R>& rhs)
	{
		return (!(lhs == rhs));
	}

	template<class L, class R>
	bool operator<(const pair<L,R>& lhs, const pair<L,R>& rhs)
	{
		return ((lhs.first < rhs.first) || ((lhs.first == rhs.first) && lhs.second < rhs.second));
	}

	template<class L, class R>
	bool operator<=(const pair<L,R>& lhs, const pair<L,R>& rhs)
	{
		return (!(rhs < lhs));
	}

	template<class L, class R>
	bool operator>(const pair<L,R>& lhs, const pair<L,R>& rhs)
	{
		return (rhs < lhs);
	}

	template<class L, class R>
	bool operator>=(const pair<L,R>& lhs, const pair<L,R>& rhs)
	{
		return (!(lhs < rhs));
	}

}

#endif
