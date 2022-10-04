/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_std.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:35:57 by guferrei          #+#    #+#             */
/*   Updated: 2022/10/04 20:56:09 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <utility>
#include <stdexcept>

int	main(void) {
	std::map<int, const char*>	m1;
	clock_t			start;
	clock_t			end;


	std::cout << std::endl << "=================== STD::MAP TEST ===================" << std::endl << std::endl;

	start = clock();

	std::cout << "1. Testing empty and insert" << std::endl;

	std::cout << "    1.1 Empty before insert: " << m1.empty() << std::endl;
	m1.insert(std::make_pair<int, const char *>(1, "One"));
	std::cout << "    1.2 Empty after insert: " << m1.empty() << std::endl << std::endl;

	//===================================================================================

	std::cout << "2. Testing size and insert" << std::endl;

	std::cout << "    2.1 Size: " << m1.size() << std::endl;
	m1.insert(std::make_pair<int, const char *>(5, "Five"));
	std::cout << "    2.2 Size: " << m1.size() << std::endl;
	m1.insert(std::make_pair<int, const char *>(9, "Nine"));
	std::cout << "    2.3 Size: " << m1.size() << std::endl;
	m1.insert(std::make_pair<int, const char *>(2, "Two"));
	std::cout << "    2.4 Size: " << m1.size() << std::endl;
	m1.insert(std::make_pair<int, const char *>(3, "Three"));
	std::cout << "    2.5 Size: " << m1.size() << std::endl;
	m1.insert(std::make_pair<int, const char *>(7, "Seven"));
	std::cout << "    2.6 Size: " << m1.size() << std::endl << std::endl;

	//===================================================================================

	std::cout << "3. Testing Element Access" << std::endl;

	std::cout << "    3.1 Accessing mapped string to key 2 with []: " << m1[2] << std::endl;
	std::cout << "    3.2 Accessing mapped string to key 2 with at: " << m1.at(2) << std::endl;
	std::cout << "    3.3 Accessing mapped string to key 7 with []: " << m1[7] << std::endl;
	std::cout << "    3.4 Accessing mapped string to key 7 with at: " << m1.at(7) << std::endl;
	try {
		std::cout << "    3.2 Accessing non-existent key with at: " << m1.at(12);
	} catch (const std::out_of_range& e) {
		std::cout << "key not found!" << std::endl << std::endl;
	}

	//===================================================================================

	std::cout << "4. Testing Iterators" << std::endl;

	std::map<int, const char *>::iterator			it1 = m1.begin();
	std::map<int, const char *>::iterator			it2 = m1.end();
	std::map<int, const char *>::reverse_iterator	rit1 = m1.rbegin();
	std::map<int, const char *>::reverse_iterator	rit2 = m1.rend();

	std::cout << "    4.1 Printing map using iterator: ";
	while (it1 != it2) {
		std::cout << "[" << it1->first << "]->" << it1->second << ", ";
		it1++;
	}

	std::cout << std::endl << "    4.2 Printing map using reverse_iterator: ";
	while (rit1 != rit2) {
		std::cout << "[" << rit1->first << "]->" << rit1->second << ", ";
		rit1++;
	}
	std::cout << std::endl << std::endl;

	//===================================================================================

	std::cout << "5. Testing Erase" << std::endl;

	it1 = m1.begin();

	std::cout << "    5.1 Printing map before erasing first value with iterator: ";
	while (it1 != it2) {
		std::cout << "[" << it1->first << "]->" << it1->second << ", ";
		it1++;
	}
	m1.erase(m1.begin());
	it1 = m1.begin();
	std::cout << std::endl << "    5.2 Printing map before erasing first value with iterator: ";
	while (it1 != it2) {
		std::cout << "[" << it1->first << "]->" << it1->second << ", ";
		it1++;
	}

	it1 = m1.begin();
	std::cout << std::endl << std::endl << "    5.3 Printing map before erasing key 7: ";
	while (it1 != it2) {
		std::cout << "[" << it1->first << "]->" << it1->second << ", ";
		it1++;
	}
	m1.erase(7);
	it1 = m1.begin();
	std::cout << std::endl << "    5.4 Printing map before erasing key 7: ";
	while (it1 != it2) {
		std::cout << "[" << it1->first << "]->" << it1->second << ", ";
		it1++;
	}
	std::cout << std::endl;

	//===================================================================================

	std::cout << std::endl << "6. Testing Find" << std::endl;

	std::cout << "    6.1 Finding element 3: ";
	it1 = m1.find(3);
	std::cout << "[" << it1->first << "]->" << it1->second << std::endl;
	std::cout << "    6.1 Finding non-existent element: ";
	it1 = m1.find(423);
	if (it1 == m1.end())
		std::cout << "Map end" << std::endl;

	//===================================================================================

	std::cout << std::endl << "7. Testing Count" << std::endl;

	std::cout << "    7.1 Counting element 5: " << m1.count(5) << std::endl;
	std::cout << "    7.2 Counting non-existent element: " << m1.count(423) << std::endl;

	//===================================================================================

	end = clock();

	std::cout << std::endl << "Execution time: " << std::fixed << (double)(end - start) << " miliseconds" << std::endl;
}