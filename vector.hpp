#pragma once
#include "iterator.hpp"
#include "utils.hpp"
#include <algorithm>

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
			typedef ft::reverse_iterator<iterator> 						reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> 				const_reverse_iterator;
			
			//Member functions
			
			explicit vector(const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _start(0), _end_arr(0), _end_memory(0) { }

			explicit vector(size_type __count, const T& value = T(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _start(0), _end_arr(0), _end_memory(0)
			{
				typedef typename ft::is_integral<size_type>::type	Integral;
				__init(__count, value, Integral());
			}

			template< class InputIt >
			vector(InputIt first, InputIt last, const allocator_type& alloc = allocator_type()) : _alloc(alloc), _start(0), _end_arr(0), _end_memory(0)
			{
				assign(first, last);
			}

			~vector() { __free_memory(); }

			vector(vector & other) : _alloc(other._alloc), _start(0), _end_arr(0), _end_memory(0) { *this = other; }

			vector& operator=(const vector& other)
			{
				if (*this != other)
				{
					_alloc = other._alloc;
					if (capacity() < other.capacity())
					{
						if (_start != 0)
							__free_memory();
						_start = _alloc.allocate(other.capacity());
						_end_memory = _start + other.capacity();
					}
					_end_arr = _start;
					for (size_type i = 0; i < other.size(); ++i)
					{
						_alloc.construct(_end_arr, other[i]);
						++_end_arr;
					}
				}
				return *this;
			}

			void assign(size_type __count, const T& value)
			{
				typedef typename ft::is_integral<size_type>::type	Integral;
				__assign(__count, value, Integral());
			}

			template< class InputIt >
			void assign(InputIt first, InputIt last)
			{
				typedef typename ft::is_integral<InputIt>::type	Integral;
				__assign(first, last, Integral());

			}

			allocator_type get_allocator() const { return _alloc; }
			//Element access

			reference at(size_type pos)
			{
				std::string s = "vector::at: n (which is " + std::to_string(pos) + ") >= this->size() (which is ";
				s += std::to_string(size()) + ")";
				if (pos >= size())
					throw std::out_of_range(s.c_str());
				return *(_start + pos);
			}

			const_reference at(size_type pos) const
			{
				std::string s = "vector::at: n (which is " + std::to_string(pos) + ") >= this->size() (which is ";
				s += std::to_string(size()) + ")";
				if (pos >= size())
					throw std::out_of_range(s.c_str());
				return *(_start + pos);
			}

			reference operator[](size_type __number) { return *(_start + __number); }

			const_reference operator[](size_type __number) const { return *(_start + __number); }

			reference front() { return *_start; }

			const_reference front() const { return *_start; }

			reference back() { return *_end_arr; }

			const_reference back() const { return *_end_arr; }

			T* data() { return _start; }

			const T* data() const { return _start; }

			// iterator
			iterator				begin() { return _start; }

			const_iterator			begin() const { return _start; }

			iterator				end() { return _end_arr; }
			
			const_iterator			end() const { return _end_arr; }
			
			reverse_iterator		rbegin() { return reverse_iterator(end()); }
			
			const_reverse_iterator	rbegin() const { return const_reverse_iterator(end()); }
			
			reverse_iterator		rend() { return reverse_iterator(begin()); }
			
			const_reverse_iterator	rend() const { return reverse_iterator(begin()); }

			//	capacity
			bool	empty( void ) { return ((_end_memory - _start) == 0); }

			size_type size( void ) const { return _end_arr - _start; }

			size_type max_size( void ) { return _alloc.max_size(); }

			void reserve(size_type __count)
			{
				if (__count > this->max_size())
					throw std::length_error("vector::reserve");
				if (__count < this->capacity())
					return ;
				if (__count == 0)
					__count = 1;
				size_type size_tmp = this->size();
				size_type size_capasite_tmp = this->capacity();
				pointer		start_tmp = _start;
				pointer		end_arr_tmp = _end_arr;

				_start = _alloc.allocate(__count);
				_end_arr = _start;
				_end_memory = _start + __count;
				while (start_tmp != end_arr_tmp)
				{
					_alloc.construct(_end_arr, *start_tmp);
					_alloc.destroy(start_tmp);
					++_end_arr;
					++start_tmp;
				}
				start_tmp -= size_tmp;
				_alloc.deallocate(start_tmp, size_capasite_tmp);
				
			}

			size_type capacity( void ) const { return _end_memory - _start; }

			// Modifiers

			void clear( void ) { __realloc_memory(0); }

			iterator insert( iterator pos, const T& value )
			{
				size_type i = &(*pos) - _start;
				
				insert(pos, 1, value);

				return (_start + i);
			}

			void insert(iterator pos, size_type __count, const T& value)
			{
				typedef typename ft::is_integral<size_type>::type	Integral;
				__insert(pos, __count, value, Integral());
			}

			template< class InputIt >
			void insert( iterator pos, InputIt first, InputIt last )
			{
				typedef typename ft::is_integral<InputIt>::type	Integral;
				__insert(pos, first, last, Integral());
			}

			iterator erase( iterator first, iterator last )
			{
				if (first == last)
					return last;
				
				size_type size_s = &(*first) - _start;
				if (last == end())
				{
					size_type size_for_last = end() - first;
					_end_arr -= size_for_last;
					return end();
				}
				else
				{
					while (last != end())
					{
						*first = *last;
						++first;
						++last;
					}
					_end_arr -= _end_arr - &(*first);
				}
				return _start + size_s;

			}
			iterator erase( iterator pos ) { return erase(pos, pos + 1); }

			void push_back(const T & value)
			{
				if (_end_arr == _end_memory)
					reserve(this->capacity() * 2);
				_alloc.construct(_end_arr, value);
				++this->_end_arr;
			}

			void pop_back( void ) { if (begin() != end()) erase(--end()); }

			void resize( size_type count, T value = T() )
			{
				if (count == size())
					return ;
				if (count < size())
				{
					pointer _tmpStart;
					_tmpStart = _alloc.allocate(count);
					pointer _tmpEnd = _tmpStart;
					for (size_type i = 0; i < count; ++i)
					{
						_alloc.construct(_tmpEnd, *(_start + i));
						++_tmpEnd;
					}
					__realloc_memory(count);
					_start = _tmpStart;
					_end_arr= _tmpEnd;
					_end_memory = _tmpEnd;
				}
				else
				{
					while (count > capacity())
						reserve(capacity() * 2);
					while (size() != count)
					{
						_alloc.construct(_end_arr, value);
						++_end_arr;
					}
				}
			}

			void					swap(vector& other)
			{
				if (&other == this)
					return ;
				allocator_type	temp_alloc = _alloc;
				pointer			temp_start = _start;
				pointer			temp_end_arr = _end_arr;
				pointer			temp_end_of_storage = _end_memory;
				_alloc = 			other._alloc;
				_start = 			other._start;
				_end_arr = 			other._end_arr;
				_end_memory = 		other._end_memory;
				other._alloc = temp_alloc;
				other._start = temp_start;
				other._end_arr = temp_end_arr;
				other._end_memory = _end_memory;
			}
		private:

			pointer _start;
			pointer _end_arr;
			pointer _end_memory;
			allocator_type	_alloc;
			template <class iter>
			void __init(iter first, iter last, ft::false_type)
			{
				difference_type __count = ft::distance(first, last);
				_start = _alloc.allocate(__count);
				_end_arr = _start;
				_end_memory = _start + __count;
				while (first != last)
				{
					_alloc.construct(_end_arr, *first);
					++first;
					++_end_arr;
				}
			}

			void __init(size_type __count, const value_type & value, ft::true_type)
			{
				_start = _alloc.allocate(__count);
				_end_arr = _start;
				_end_memory = _start + __count;
				for (size_type i = 0; i < __count; ++i)
				{
					_alloc.construct(_end_arr, value);
					++_end_arr;
				}
			}
			template< class InputIt >
			void __assign(InputIt first, InputIt last, ft::false_type)
			{
			
				InputIt last_iter = first;
				size_type __count = ft::distance(first, last);
				if (__count > capacity())
				{
					__realloc_memory(__count);
					for (size_type i = 0; i < __count; ++i)
					{
						_alloc.construct(_end_arr, *first);
						++_end_arr;
						++first;
					}
				}
				else if (__count > size())
				{
					pointer last_start = _start;
					for (size_type i = 0; i < __count; ++i)
					{
						if (__count < size())
						{
							*_start = *first;
							++_start;
						}
						else
						{
							_alloc.construct(_end_arr, *first);
							++_end_arr;
						}
						++first; 
					}
					_start = last_start;
					first = last_iter;
				}
				else
				{

						pointer last_start = _start;
					for (size_type i = 0; i < __count; ++i)
					{
						*_start = *first;
						++_start;
						++first; 
					}
					_start = last_start;
					first = last_iter;
				}
			}

			void __assign( size_type __count, const T& value, ft::true_type)
			{
				if (__count > capacity())
				{
					__realloc_memory( __count );
					for (size_type i = 0; i < __count; ++i)
					{
						_alloc.construct(_end_arr, value);
						++_end_arr; 
					}
				}
				else if (__count > size())
				{
					ft::fill(begin(), end(), value);
					size_type add_element = __count - size();
					while (add_element--)
					{
						_alloc.construct(_end_arr, value);
						++_end_arr;
					}
				}
				else
					ft::fill_n(begin(), __count, value);
			}

			void __insert(iterator pos, size_type __count, const T& value, ft::true_type)
			{
				
				if (__count == 0)
					return ;
				size_type it = &(*pos) - _start;
 				while (size() + __count > capacity())
					reserve(capacity() * 2);
				pointer start_tmp = _alloc.allocate(size() - it);
				pointer end_tmp = start_tmp;
				for (size_type i = 0; i < __count; ++i)
				{
					if (it + i < size())
					{
						_alloc.construct(end_tmp, *(_start + it + i));
						++end_tmp;
						*(_start + it + i) = value;
					}
					else
					{
						_alloc.construct(_end_arr, value);
						++_end_arr;
					}
				}
				for (size_type i = it + __count; i < size(); ++i)
				{
					_alloc.construct(end_tmp, *(_start + i));
					++end_tmp;
				}
				size_type size_tmp = end_tmp - start_tmp;
				for (size_type i = it + __count; i < size(); ++i)
				{
					*(_start + i) = *start_tmp;
					_alloc.destroy(start_tmp);
					++start_tmp;
				}
				while (start_tmp != end_tmp)
				{
					_alloc.construct(_end_arr, *start_tmp);
					++_end_arr;
					_alloc.destroy(start_tmp);
					++start_tmp;
				}
				start_tmp -= size_tmp;
				_alloc.deallocate(start_tmp, size_tmp);
			}

			template <class InputIt>
			void __insert(iterator pos, InputIt first, InputIt last, ft::false_type)
			{
				size_type __count = last - first;
				if (__count == 0)
					return ;
				size_type it = &(*pos) - _start;
				while (size() + __count > capacity())
					reserve(capacity() * 2);
				pointer start_tmp = _alloc.allocate(size() - it);
				pointer end_tmp = start_tmp;

				for (size_type i = 0; i < __count; ++i)
				{
					
					if (it + i < size())
					{
						_alloc.construct(end_tmp, *(_start + it + i));
						++end_tmp;
						*(_start + it + i) = *first;
					}
					else
					{
						_alloc.construct(_end_arr, *first);
						++_end_arr;
					}
					++first;
				}
				for (size_type i = it + __count; i < size(); ++i)
				{
					_alloc.construct(end_tmp, *(_start + i));
					++end_tmp;
				}
				size_type size_tmp = end_tmp - start_tmp;
				for (size_type i = it + __count; i < size(); ++i)
				{
					*(_start + i) = *start_tmp;
					_alloc.destroy(start_tmp);
					++start_tmp;
				}
				while (start_tmp != end_tmp)
				{
					_alloc.construct(_end_arr, *start_tmp);
					++_end_arr;
					_alloc.destroy(start_tmp);
					++start_tmp;
				}
				start_tmp -= size_tmp;
				_alloc.deallocate(start_tmp, size_tmp);
			}

			void __realloc_memory(size_type __count)
			{
				if (__count > _alloc.max_size())
					throw std::length_error("vector::reserve");
				if (_start != 0)
					__free_memory();
				_start = _alloc.allocate(__count);
				_end_arr = _start;
				_end_memory = _start + __count;
			}

			void __free_memory( void )
			{
				pointer	tmp = _start;

				while (tmp != _end_arr)
				{
					_alloc.destroy(tmp);
					++tmp;
				}
				_alloc.deallocate(_start, capacity());
			}

	};

	template< class T, class Alloc >
	bool operator==( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs )
	{
		if (lhs.size() != rhs.size())
			return false;
		for (size_t it = 0; it < rhs.size(); ++it)
		{
			if (lhs[it] != rhs[it])
				return (false);
		}
		return true;
	}

	template< class T, class Alloc >
	bool operator!=( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs ) { return !(lhs == rhs); }

	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); }

	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (!(rhs < lhs));}

	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (rhs < lhs); }

	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (!(lhs < rhs));}

	template< class T, class Alloc >
	void swap( vector<T,Alloc>& lhs, vector<T,Alloc>& rhs ) { lhs.swap(rhs); }
}
