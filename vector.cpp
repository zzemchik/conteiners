
#include <iostream>
#include "iterator.hpp"
namespace ft {
	template <class T, class Alloc = std::allocator<T> >
	class vector {

		public:
			typedef T													value_type;
			typedef	T&													reference;
			typedef	size_t												size_type;
			typedef Alloc												allocator_type;
			typedef ptrdiff_t											difference_type;
			typedef	const T&											const_reference;
			typedef typename Alloc::pointer								pointer;
			typedef typename Alloc::const_pointer						const_pointer;
			typedef ft::Random_Access_Iterator<value_type> 				iterator;
			typedef ft::Random_Access_Iterator<const value_type> 		const_iterator;
			typedef ft::reverse_iterator<iterator> 						reverce_iterator;
			typedef ft::reverse_iterator<const_iterator> 				const_reverce_iterator;
			

			explicit vector(const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _start(0), _end_arr(0), _end_memory(0) { }
			explicit vector(const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _start(0), _end_arr(0), _end_memory(0) { }
			size_type capacity( void ) { return _member_size; }

		private:

			pointer _start;
			pointer _end_arr;
			pointer _end_memory;
			Allocator	_alloc;

			void __init_member( void ) {

				if (_member_size == 0)
				{
					T *tmp = _arr;
					_arr = new T(1);
					_member_size = 1;
					delete [] tmp;
				}
				else
				{
					T *tmp = _arr;
					_arr = new T(_member_size * 2);
					for (size_t i = 0; i < _member_size; i++)
						_arr[i] = tmp[i];
					_member_size *= 2;
					delete [] tmp;
				}
			}
	};
}

int main()
{

	// try {
	// 	{
	// 		std::vector<int> a;
	// 		ft::vector<int> b;
	// 		if (a.empty() != b.empty())
	// 			throw ("KO::test empty");
	// 	}
	// 	{
	// 		std::vector<int> a(1);
	// 		ft::vector<int> b(1);
	// 		if (a.empty() != b.empty())
	// 			throw ("KO::test empty");
	// 	}
	// }
	// catch (const char * str)
	// {
	// 	std::cout << str << std::endl;
	// }
	// try {
	// 	ft::vector<int> vec;
	// 	vec.push_back(1);
	// 	vec.push_back(2);
	// 	vec.push_back(3);
	// 	for (size_t i = 0; i < vec.size(); i++)
	// 	{
	// 		std::cout << vec[i] << " ";
	// 	}
	// 	std::cout << std::endl;
	// 	std::cout << vec.capacity() << " " << vec.size() << std::endl;

	// 	std::vector<int> a;
	// 	std::cout << a.empty() << std::endl;
	// }
	// catch (const char * str)
	// {
	// 	std::cout << str << std::endl;
	// }

}