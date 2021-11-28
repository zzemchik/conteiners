
#include "vector.hpp"
#include <type_traits>
#include <vector>
#include <iostream>

int main()
{
	{

		ft::vector<char> a(3);
		ft::vector<char> e;
		e.push_back(90);
		e.push_back(89);
		e.push_back(88);
		e.push_back(87);
		e.push_back(86);
		for (int i = 0; i < e.size(); ++i)
		{
			std::cout << e[i] << " ";
		}
		std::cout << e.capacity() << " " << e.size() << std::endl;
		const std::string extra(6, 'b');
		a.assign(extra.begin(), extra.end());
		a.insert(a.begin(), 84);
		for (int i = 0; i < a.size(); ++i)
		{
			std::cout << a[i] << " ";
		}
		std::cout << a.capacity() << std::endl;
	}
	std::cout << std::endl;
	{

		std::vector<char> a(3);
		std::vector<char> e;
		e.push_back(90);
		e.push_back(89);
		e.push_back(88);
		e.push_back(87);
		e.push_back(86);
		for (int i = 0; i < e.size(); ++i)
		{
			std::cout << e[i] << " ";
		}
		std::cout << e.capacity()  << " " << e.size() << std::endl;
		const std::string extra(6, 'b');
		a.insert(a.begin(), 84);
		a.assign(extra.begin(), extra.end());
		for (int i = 0; i < a.size(); ++i)
		{
			std::cout << a[i] << " ";
		}
		std::cout << a.capacity() << std::endl;
	}
	// ft::vector<int> a(3);
	// std::cout << a.size() << " " << a.capacity() << std::endl;
}