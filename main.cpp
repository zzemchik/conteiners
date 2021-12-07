
#include "vector.hpp"
#include <type_traits>
#include <vector>
#include <iostream>
#include <cmath>
#include <stack>
#include "stack.hpp"
#include <set>

int main()
{

	// {
	// 	ft::stack<int> s;

	// }

	{
		std::string str;
		str = "123456789";
		std::cout << str.c_str() + 3 << std::endl;
	}
	// {
	// 	std::vector<int> a;
	// 	a.push_back(1);
	// 	a.push_back(1);
	// 	a.push_back(1);

	// 	std::vector<int> b;
	// 	b.push_back(3);

	// 	a.swap(b);

	// 	std::cout << a.capacity() << " " << a.size() << std::endl;
	// 	std::cout << b.capacity() << " " << b.size() << std::endl;


	// }
	// {
	// 	std::vector<int> a;
	// 	a.push_back(1);
	// 	a.push_back(2);
	// 	a.push_back(2);
	// 	a.push_back(2);
	// 	a.push_back(2);

	// 	std::cout << a.capacity() << " " << a.size() << std::endl; 
	// 	a.resize(4, 3);
	// 	std::cout << a.capacity() << " " << a.size() <<  std::endl; 
	// 	for (size_t i = 0; i < a.size(); ++i)
	// 		std::cout << a[i] << " ";
	// 	std::cout << std::endl;
	// }

	
	// {
	// 	ft::vector<int> a;
	// 	a.push_back(1);
	// 	a.push_back(2);
	// 	a.push_back(2);
	// 	a.push_back(2);
	// 	a.push_back(2);

	// 	std::cout << a.capacity() << " " << a.size() << std::endl; 
	// 	a.resize(4, 3);
	// 	std::cout << a.capacity() << " " << a.size() <<  std::endl; 
	// 	for (size_t i = 0; i < a.size(); ++i)
	// 		std::cout << a[i] << " ";
	// 	std::cout << std::endl;
	// }
	/*
	{
		std::vector<int> a;
		a.push_back(1);
		a.push_back(2);
		a.push_back(3);
		a.push_back(4);
		a.push_back(5);
		a.push_back(6);
		a.push_back(7);
		a.push_back(8);

		std::cout << a.capacity() << " " << a.size() << std::endl;
		*a.erase(a.end() - 1);

		std::cout << *(a.erase(a.begin() + 1, a.begin() + 3)) << std::endl;
		std::cout << *a.erase(a.begin() + 2) << std::endl;
		a.pop_back();

		for (size_t i = 0; i < a.size(); ++i)
			std::cout << a[i] << " ";
		std::cout << std::endl;
		std::cout << a.capacity() << " " << a.size() << std::endl;
		
	}
	std::cout << std::endl;
	std::cout << std::endl;

		{
		ft::vector<int> a;
		a.push_back(1);
		a.push_back(2);
		a.push_back(3);
		a.push_back(4);
		a.push_back(5);
		a.push_back(6);
		a.push_back(7);
		a.push_back(8);
		std::cout << a.capacity() << " " << a.size() << std::endl;
		*a.erase(a.end() - 1);
		std::cout << *(a.erase(a.begin() + 1, a.begin() + 3)) << std::endl;
		std::cout << *a.erase(a.begin() + 2) << std::endl;
		a.pop_back();

		for (size_t i = 0; i < a.size(); ++i)
			std::cout << a[i] << " ";
		std::cout << std::endl;
		std::cout << a.capacity() << " " << a.size() << std::endl;
		
	}

	pow(2, 2);










	// test insert
	{
		std::string str = "qergsdhjhgkgh";

		std::vector<char> vec;
		vec.insert(vec.begin(), 60);
		vec.insert(vec.begin(), 60);
		vec.insert(vec.begin(), 60, 60);
		vec.insert(vec.begin() + 30, str.begin(), str.end());

		ft::vector<char> vec1;
		vec1.insert(vec1.begin(), 60);
		vec1.insert(vec1.begin(), 60);
		vec1.insert(vec1.begin(), 60, 60);
		vec1.insert(vec1.begin() + 30, str.begin(), str.end());

		bool flag = true;
		for (size_t i = 0; i < vec.size(); i++)
			if (vec[i] != vec1[i])
			{
				flag = true;
				break;
			}

		if (flag)
			std::cout << "true";
		else
		{
			for (size_t i = 0; i < vec.size(); i++)
				std::cout << vec[i] << " ";
			std::cout << std::endl;
			for (size_t i = 0; i < vec1.size(); i++)
				std::cout << vec1[i] << " ";
		}
	}
	std::cout << std::endl;
	*/

}