

namespace ft
{

	template<class L, class R>
	struct pair
	{

		L first;
		R second;
		pair() : first(), second();
		pair(const L & lft, const R & rht) : first(lft), second(rht) { }
		template <class L1, class R1>
		pair(const pair<L1, L2> & copy) : first(copy.first), second(copy.second) {}
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
		pair<L, R> _pair(first,, second);
		return (_pair);
	}

}