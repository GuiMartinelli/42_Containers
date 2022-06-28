#include "Vector.hpp"
#include <vector>
#include <iostream>

// int	main(void) {
// 	std::vector<int>	vec1;
// 	ft::vector<int>		vec2;

// 	std::cout << vec2.max_size() << std::endl;
// 	std::cout << vec1.max_size() << std::endl << std::endl;
// 	for (int i = 0; i < 100; i++) {
// 		vec1.push_back(i);
// 		vec2.push_back(i);
// 		std::cout << i << ": " << vec1.size() << " / " << vec1.capacity() << "  |  ";
// 		std::cout << vec2.size() << " / " << vec2.capacity() << std::endl;
// 	}

// 	std::cout << std::endl;

// 	std::cout << "Operator[] : " << vec1[5] << "  |  " << vec2[5] << std::endl;
// 	vec1[5] = 42;
// 	vec2[5] = 42;
// 	std::cout << "Operator[] : " << vec1[5] << "  |  " << vec2[5] << std::endl << std::endl;

// 	std::cout << "Front : " << vec1.front() << "  |  " << vec2.front() << std::endl << std::endl;

// 	std::cout << "Back : " << vec1.back() << "  |  " << vec2.back() << std::endl << std::endl;

// 	vec1.pop_back();
// 	vec2.pop_back();

// 	std::cout << "Back : " << vec1.back() << "  |  " << vec2.back() << std::endl << std::endl;

// 	std::cout << "Size : " << vec1.size() << "  |  " << vec2.size() << std::endl;
// 	vec1.resize(12);
// 	vec2.resize(12);
// 	std::cout << "Size : " << vec1.size() << "  |  " << vec2.size() << std::endl << std::endl;

// 	vec1.resize(5, 42);
// 	vec2.resize(5, 42);

// 	for (int i = 0; i < 6; i++) {
// 		std::cout << vec1[i] << "  |  " << vec2[i] << std::endl;
// 	}

// 	std::cout << "Back : " << vec1.back() << "  |  " << vec2.back() << std::endl << std::endl;

// 	std::cout << vec1.size() << " / " << vec1.capacity() << "  |  ";
// 	std::cout << vec2.size() << " / " << vec2.capacity() << std::endl << std::endl;

// 	vec1.resize(200, 42);
// 	vec2.resize(200, 42);

// 	for (int i = 0; i < 10; i++) {
// 		std::cout << vec1.at(i) << "  |  " << vec2.at(i) << std::endl;
// 	}
// 	std::cout << "[150] : " << vec1[150] << "  |  " << vec2[150] << std::endl << std::endl;

// 	std::cout << "Back : " << vec1.back() << "  |  " << vec2.back() << std::endl << std::endl;


// 	std::cout << vec1.size() << " / " << vec1.capacity() << "  |  ";
// 	std::cout << vec2.size() << " / " << vec2.capacity() << std::endl;

// 	std::cout << std::endl;

// 	std::cout << "Empty : " << vec1.empty() << "  |  " << vec2.empty() << std::endl << std::endl;
// 	vec1.clear();
// 	vec2.clear();
// 	std::cout << "Empty : " << vec1.empty() << "  |  " << vec2.empty() << std::endl << std::endl;

// 	std::cout << vec1.size() << " / " << vec1.capacity() << "  |  ";
// 	std::cout << vec2.size() << " / " << vec2.capacity() << std::endl;

// 	vec1.push_back(21);
// 	vec2.push_back(21);

// 	std::cout << vec1.size() << " / " << vec1.capacity() << "  |  ";
// 	std::cout << vec2.size() << " / " << vec2.capacity() << std::endl;

// 	vec1.resize(5, 42);
// 	vec2.resize(5, 42);

// 	std::cout << vec1.size() << " / " << vec1.capacity() << "  |  ";
// 	std::cout << vec2.size() << " / " << vec2.capacity() << std::endl;

// 	for (int i = 0; i < 5; i++) {
// 		std::cout << vec1.at(i) << "  |  " << vec2.at(i) << std::endl;
// 	}
// }

int	main(void) {
	ft::vector<int>	vc;
	ft::vector<int>::iterator	it1;
	ft::vector<int>::iterator	it2;

	vc.push_back(1);
	vc.push_back(2);
	vc.push_back(3);
	vc.push_back(4);
	vc.push_back(5);

	it1 = vc.begin();
	it2 = vc.end();

	for (; it1 < it2; it1++)
		std::cout << "Number is: " << *it1 << std::endl;
}