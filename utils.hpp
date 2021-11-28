

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

	template<>struct __is_integral_h<char16_t> : public true_type { };

	template<>struct __is_integral_h<char32_t> : public true_type { };

	template<>struct __is_integral_h<short> : public true_type { };

	template<>struct __is_integral_h<unsigned short> : public true_type { };

	template<>struct __is_integral_h<int> : public true_type { };

	template<>struct __is_integral_h<unsigned int> : public true_type { };

	template<>struct __is_integral_h<long>: public true_type { };

	template<>struct __is_integral_h<unsigned long> : public true_type { };

	template<>struct __is_integral_h<long long> : public true_type { };

	template<>struct __is_integral_h<unsigned long long> : public true_type { };

	template<typename _Tp>struct is_integral : public __is_integral_h<_Tp>::type { };


}