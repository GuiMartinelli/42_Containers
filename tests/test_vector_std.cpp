/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector_std.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:06:43 by guferrei          #+#    #+#             */
/*   Updated: 2022/10/04 19:06:50 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

int	main(void) {
	std::vector<int>	vec1;
	clock_t				start;
	clock_t				end;

	std::cout << std::endl << "=================== STD::VECTOR TEST ===================" << std::endl << std::endl;

	start = clock();

	std::cout << "1. Testing push_back" << std::endl;

	for (int i = 0; i < 5; i++) {
		vec1.push_back((i * i));
	}

	std::cout << "    1.1 Vector content: ";
	for (std::vector<int>::size_type i = 0; i < vec1.size(); i++) {
		std::cout << vec1[i] << " ";
	}
	std::cout << std::endl << "    1.2 Vector size: " << vec1.size() << std::endl;
	std::cout << "    1.3 Vector max_size: " << vec1.max_size() << std::endl;
	std::cout << "    1.4 Vector capacity: " << vec1.capacity() << std::endl << std::endl;

	//===================================================================================

	std::cout << "2. Testing resize" << std::endl;
	std::cout << "    2.1 Vector size before: " << vec1.size() << std::endl;
	vec1.resize(6);
	std::cout << "    2.2 Vector size after: " << vec1.size() << std::endl;

	std::cout << "    2.3 Vector content after bigger resize: ";
	for (std::vector<int>::size_type i = 0; i < vec1.size(); i++) {
		std::cout << vec1[i] << " ";
	}

	std::cout << std::endl << "    2.4 Vector size before: " << vec1.size() << std::endl;
	vec1.resize(5);
	std::cout << "    2.5 Vector size after: " << vec1.size() << std::endl;

	std::cout << "    2.6 Vector content after smaller resize: ";
	for (std::vector<int>::size_type i = 0; i < vec1.size(); i++) {
		std::cout << vec1[i] << " ";
	}

	//===================================================================================

	std::cout << std::endl << std::endl << "3. Testing pop_back" << std::endl;
	
	vec1.pop_back();
	std::cout << "    3.1 Vector content after pop_back: ";
	for (std::vector<int>::size_type i = 0; i < vec1.size(); i++) {
		std::cout << vec1[i] << " ";
	}
	std::cout << std::endl << "    3.2 Vector size: " << vec1.size() << std::endl << std::endl;

	//===================================================================================

	std::cout << "4. Testing iterators" << std::endl;

	std::vector<int>::iterator	it = vec1.begin();

	std::cout << "    4.1 Printing with iterators: ";
	while (it != vec1.end()) {
		std::cout << *it << " ";
		it++;
	}

	std::vector<int>::reverse_iterator	rev_it = vec1.rend();

	std::cout << std::endl << "    4.2 Printing with reverse_iterators: ";
	while (rev_it != vec1.rbegin()) {
		rev_it--;
		std::cout << *rev_it << " ";
	}

	//===================================================================================

	std::cout << std::endl << std::endl << "5. Testing insert" << std::endl;

	std::vector<int>	vec2;

	for (int i = 0; i < 6; i++) {
		vec2.push_back((i * 10));
	}

	it = vec1.begin();
	vec1.insert(it, 42);


	std::cout << "    5.1 Printing after inserting 42 at the beggining: ";
	while (it != vec1.end()) {
		std::cout << *it << " ";
		it++;
	}

	vec1.insert(vec1.end(), vec2.begin(), vec2.end());

	it = vec1.begin();

	std::cout << std::endl << "    5.2 Printing after inserting vec2 in vec1: ";
	while (it != vec1.end()) {
		std::cout << *it << " ";
		it++;
	}

	//===================================================================================

	std::cout << std::endl << std::endl << "6. Testing erase" << std::endl;
	it = vec1.begin();
	vec1.erase(it);

	std::cout << "    6.1 Printing after erasing 42: ";
	while (it != vec1.end()) {
		std::cout << *it << " ";
		it++;
	}

	it = vec1.begin();
	it++;

	vec1.erase(vec1.begin(), it);

	std::cout << std::endl << "    6.2 Printing after erasing 2 first elements: ";
	while (it != vec1.end()) {
		std::cout << *it << " ";
		it++;
	}

	//===================================================================================

	std::cout << std::endl << std::endl << "7. Testing equal operator" << std::endl;

	it = vec1.begin();
	std::cout << "    7.1 Printing vec1: ";
	while (it != vec1.end()) {
		std::cout << *it << " ";
		it++;
	}

	it = vec2.begin();
	std::cout << std::endl << "    7.2 Printing vec2 before equal: ";
	while (it != vec2.end()) {
		std::cout << *it << " ";
		it++;
	}

	vec2 = vec1;

	it = vec2.begin();
	std::cout << std::endl << "    7.3 Printing vec2 after equal: ";
	while (it != vec2.end()) {
		std::cout << *it << " ";
		it++;
	}

	//===================================================================================

	std::cout << std::endl << std::endl << "8. Testing empty and clear" << std::endl;

	std::cout << "    8.1 Empty before clear: " << vec2.empty() << std::endl;
	vec2.clear();
	std::cout << "    8.2 Empty after clear: " << vec2.empty() << std::endl << std::endl;

	//===================================================================================

	std::cout << "9. Testing swap" << std::endl;

	for(int i = 0; i < 3; i++)
		vec2.push_back(i);

	it = vec1.begin();
	std::cout << "    9.1 Printing vec1 before swap: ";
	while (it != vec1.end()) {
		std::cout << *it << " ";
		it++;
	}

	it = vec2.begin();
	std::cout << std::endl << "    9.2 Printing vec2 before swap: ";
	while (it != vec2.end()) {
		std::cout << *it << " ";
		it++;
	}

	vec2.swap(vec1);

	it = vec1.begin();
	std::cout << std::endl << "    9.3 Printing vec1 after swap: ";
	while (it != vec1.end()) {
		std::cout << *it << " ";
		it++;
	}

	it = vec2.begin();
	std::cout << std::endl << "    9.4 Printing vec2 after swap: ";
	while (it != vec2.end()) {
		std::cout << *it << " ";
		it++;
	}

	//===================================================================================

	std::cout << std::endl << std::endl << "10. Testing assing" << std::endl;

	it = vec2.begin();
	std::cout << "    10.1 Printing vec2: ";
	while (it != vec2.end()) {
		std::cout << *it << " ";
		it++;
	}

	it = vec1.begin();
	std::cout << std::endl << "    10.2 Printing vec1 before assign: ";
	while (it != vec1.end()) {
		std::cout << *it << " ";
		it++;
	}

	vec1.assign(vec2.begin(), vec2.end());

	it = vec1.begin();
	std::cout << std::endl << "    10.3 Printing vec1 after assign: ";
	while (it != vec1.end()) {
		std::cout << *it << " ";
		it++;
	}

	//===================================================================================

	std::cout << std::endl << std::endl << "11. Testing element access" << std::endl;

	std::cout << "    11.1 Testing at 2nd position: " << vec1.at(2) << std::endl;
	std::cout << "    11.2 Testing front: " << vec1.front() << std::endl;
	std::cout << "    11.3 Testing back: " << vec1.back() << std::endl;
	std::cout << "    11.3 Testing data: " << *vec1.data() << std::endl;

	//===================================================================================

	std::cout << std::endl << "12. Testing reserve" << std::endl;

	std::cout << "    12.1 Capacity before reserve: " << vec1.capacity() << std::endl;
	vec1.reserve(72);
	std::cout << "    12.1 Capacity after reserve: " << vec1.capacity() << std::endl;

	//===================================================================================

	std::cout << std::endl << "13. Testing non-Members operators" << std::endl;

	vec1.clear();
	vec2.clear();

	for(int i = 0; i < 5; i++) {
		vec1.push_back(i);
		vec2.push_back(100 - i);
	}

	it = vec1.begin();
	std::cout << std::endl << "    -Printing vec1: ";
	while (it != vec1.end()) {
		std::cout << *it << " ";
		it++;
	}
	
	
	it = vec2.begin();
	std::cout << std::endl << "    -Printing vec2: ";
	while (it != vec2.end()) {
		std::cout << *it << " ";
		it++;
	}

	std::cout << std::endl << std::endl << "    13.1 vec1 == vec2: " << (vec1 == vec2) << std::endl;
	std::cout << "    13.2 vec1 != vec2: " << (vec1 != vec2) << std::endl;
	std::cout << "    13.3 vec1 < vec2: " << (vec1 < vec2) << std::endl;
	std::cout << "    13.4 vec1 > vec2: " << (vec1 > vec2) << std::endl;
	std::cout << "    13.5 vec1 <= vec2: " << (vec1 <= vec2) << std::endl;
	std::cout << "    13.6 vec1 >= vec2: " << (vec1 >= vec2) << std::endl;

	end = clock();

	std::cout << std::endl << "Execution time: " << std::fixed << (double)(end - start) << " miliseconds" << std::endl;
}