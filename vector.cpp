
#include <iostream>
#include "iterator.hpp"
namespace mystd {
	template <class T, class Alloc = std::allocator<T> >
	class vector {
		private:
		
			typedef T													value_type;
			typedef	T&													reference;
			typedef	size_t												size_type;
			typedef Alloc												Allocator;
			typedef ptrdiff_t											difference_type;
			typedef	const T&											const_reference;
			typedef typename Alloc::pointer								pointer;
			typedef typename Alloc::const_pointer						const_pointer;
			typedef mystd::Random_Access_Iterator<value_type> 			iterator;
			typedef mystd::Random_Access_Iterator<const value_type> 	const_iterator;
			typedef mystd::reverse_iterator<iterator> 					reverce_iterator;
			typedef mystd::reverse_iterator<const_iterator> 	const_reverce_iterator;

			T 				*_arr;
			size_type 			_size;
			size_type			_member_size;
			

			void memberx2( void ) {

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


			// const C &_const_reference;
			protected:
			T		_value_type;

		public:
			vector() : _size(0), _member_size(0) {
				_arr = new T;
			}
			vector(const int & size) : _size(size), _member_size(size) {
				_arr = new T(size);
			}
			~vector() { delete [] _arr; }

			vector(const vector & v) { *this = v; }

			vector &operator=(const vector & v) {
				delete [] _arr;
				_member_size = v.capacity();
			}





			bool empty() { return _member_size == 0 ? true : false; }





			void push_back(const T & value) {
				if (_member_size == _size)
					memberx2();
				_arr[_size] = value;
				++_size;
			}


			size_t size( void ) { return _size; }
			T & operator[](const size_t & it) {
				if (it >= _size)
					throw "it > _size"; 
				return (_arr[it]);
			}
			T & operator==(const vector<T> & vec)
			{
				// _size = vec.size();
				// delete [] _arr;
				// for (size_t i = 0; i < vec::_arr.size(); i++)
				// 	_arr[i] = vec::_arr[i];
			}
			size_type capacity( void ) { return _member_size; }
	};

}
#include <vector>
int main()
{

	try {
		{
			std::vector<int> a;
			mystd::vector<int> b;
			if (a.empty() != b.empty())
				throw ("KO::test empty");
		}
		{
			std::vector<int> a(1);
			mystd::vector<int> b(1);
			if (a.empty() != b.empty())
				throw ("KO::test empty");
		}
	}
	catch (const char * str)
	{
		std::cout << str << std::endl;
	}
	try {
		mystd::vector<int> vec;
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);
		for (size_t i = 0; i < vec.size(); i++)
		{
			std::cout << vec[i] << " ";
		}
		std::cout << std::endl;
		std::cout << vec.capacity() << " " << vec.size() << std::endl;

		std::vector<int> a;
		std::cout << a.empty() << std::endl;
	}
	catch (const char * str)
	{
		std::cout << str << std::endl;
	}
}