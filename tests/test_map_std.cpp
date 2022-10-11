/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_std.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:35:57 by guferrei          #+#    #+#             */
/*   Updated: 2022/10/11 16:17:23 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <utility>
#include <stdexcept>

int	main(void) {
	std::map<int, const char*>	m1;
	std::map<int, const char*>	m2;
	std::pair<std::map<int, const char *>::iterator, std::map<int, const char *>::iterator>	p;
	std::pair<std::map<int, const char *>::iterator, bool>	p2;
	clock_t			start;
	clock_t			end;


	std::cout << std::endl << "=================== STD::MAP TEST ===================" << std::endl << std::endl;

	start = clock();

	std::cout << "1. Testing empty and insert" << std::endl;

	std::cout << "\t1.1 Empty before insert: " << m1.empty() << std::endl;
	m1.insert(std::make_pair<int, const char *>(1, "One"));
	std::cout << "\t1.2 Empty after insert: " << m1.empty() << std::endl << std::endl;

	//===================================================================================

	std::cout << "2. Testing size and insert" << std::endl;

	std::cout << "\t2.1 Size: " << m1.size() << std::endl;
	m1.insert(std::make_pair<int, const char *>(5, "Five"));
	std::cout << "\t2.2 Size: " << m1.size() << std::endl;
	m1.insert(std::make_pair<int, const char *>(9, "Nine"));
	std::cout << "\t2.3 Size: " << m1.size() << std::endl;
	m1.insert(std::make_pair<int, const char *>(2, "Two"));
	std::cout << "\t2.4 Size: " << m1.size() << std::endl;
	m1.insert(std::make_pair<int, const char *>(3, "Three"));
	std::cout << "\t2.5 Size: " << m1.size() << std::endl;
	m1.insert(std::make_pair<int, const char *>(7, "Seven"));
	std::cout << "\t2.6 Size: " << m1.size() << std::endl << std::endl;

	//===================================================================================

	std::cout << "3. Testing Element Access" << std::endl;

	std::cout << "\t3.1 Accessing mapped string to key 2 with []: " << m1[2] << std::endl;
	std::cout << "\t3.2 Accessing mapped string to key 2 with at: " << m1.at(2) << std::endl;
	std::cout << "\t3.3 Accessing mapped string to key 7 with []: " << m1[7] << std::endl;
	std::cout << "\t3.4 Accessing mapped string to key 7 with at: " << m1.at(7) << std::endl;
	try {
		std::cout << "\t3.2 Accessing non-existent key with at: " << m1.at(12);
	} catch (const std::out_of_range& e) {
		std::cout << "key not found!" << std::endl << std::endl;
	}

	//===================================================================================

	std::cout << "4. Testing Iterators" << std::endl;

	std::map<int, const char *>::iterator			it1 = m1.begin();
	std::map<int, const char *>::iterator			it2 = m1.end();
	std::map<int, const char *>::reverse_iterator	rit1 = m1.rbegin();
	std::map<int, const char *>::reverse_iterator	rit2 = m1.rend();

	std::cout << "\t4.1 Printing map using iterator: ";
	while (it1 != it2) {
		std::cout << "[" << it1->first << "]->" << it1->second << ", ";
		it1++;
	}

	std::cout << std::endl << "\t4.2 Printing map using reverse_iterator: ";
	while (rit1 != rit2) {
		std::cout << "[" << rit1->first << "]->" << rit1->second << ", ";
		rit1++;
	}
	std::cout << std::endl << std::endl;

	//===================================================================================

	std::cout << "5. Testing Erase" << std::endl;

	it1 = m1.begin();

	std::cout << "\t5.1 Printing map before erasing first value with iterator: ";
	while (it1 != it2) {
		std::cout << "[" << it1->first << "]->" << it1->second << ", ";
		it1++;
	}
	m1.erase(m1.begin());
	it1 = m1.begin();
	std::cout << std::endl << "\t5.2 Printing map after erasing first value with iterator: ";
	while (it1 != it2) {
		std::cout << "[" << it1->first << "]->" << it1->second << ", ";
		it1++;
	}

	it1 = m1.begin();
	std::cout << std::endl << std::endl << "\t5.3 Printing map before erasing key 7: ";
	while (it1 != it2) {
		std::cout << "[" << it1->first << "]->" << it1->second << ", ";
		it1++;
	}
	m1.erase(7);
	it1 = m1.begin();
	std::cout << std::endl << "\t5.4 Printing map after erasing key 7: ";
	while (it1 != it2) {
		std::cout << "[" << it1->first << "]->" << it1->second << ", ";
		it1++;
	}
	std::cout << std::endl;

	//===================================================================================

	std::cout << std::endl << "6. Testing Find" << std::endl;

	std::cout << "\t6.1 Finding element 3: ";
	it1 = m1.find(3);
	std::cout << "[" << it1->first << "]->" << it1->second << std::endl;
	std::cout << "\t6.2 Finding non-existent element: ";
	it1 = m1.find(423);
	if (it1 == m1.end())
		std::cout << "Map end" << std::endl;

	//===================================================================================

	std::cout << std::endl << "7. Testing Count" << std::endl;

	std::cout << "\t7.1 Counting element 5: " << m1.count(5) << std::endl;
	std::cout << "\t7.2 Counting non-existent element: " << m1.count(423) << std::endl;

	//===================================================================================

	std::cout << std::endl << "8. Testing Lower_Bound, Upper_Bound and Equal_Range" << std::endl;

	it1 = m1.lower_bound(3);
	std::cout << "\t8.1 Lower Bound of 3 is: [" << it1->first << "] " << it1->second << std::endl;
	it1 = m1.upper_bound(3);
	std::cout << "\t8.2 Upper Bound of 3 is: [" << it1->first << "] " << it1->second << std::endl;

	p = m1.equal_range(3);
	std::cout << "\t8.3 Equal Range first of 3 is: [" << p.first->first << "] " << p.first->second << std::endl;
	it1 = m1.upper_bound(3);
	std::cout << "\t8.4 Equal Range second of 3 is: [" << p.second->first << "] " << p.second->second << std::endl;

	//===================================================================================

	std::cout << std::endl << "9. Testing iterator insertion" << std::endl;

	m2.insert(std::make_pair<int, const char *>(-2, "Negative Two"));
	m2.insert(std::make_pair<int, const char *>(4, "Four"));
	m2.insert(std::make_pair<int, const char *>(15, "Fifteen"));

	it1 = m2.begin();
	it2 = m2.end();

	std::cout << "\t9.1 Printing m2: ";
	while (it1 != it2) {
		std::cout << "[" << it1->first << "]->" << it1->second << ", ";
		it1++;
	}

	it1 = m1.begin();
	it2 = m1.end();

	std::cout << std::endl << "\t9.2 Printing m1 before inserting m2: ";
	while (it1 != it2) {
		std::cout << "[" << it1->first << "]->" << it1->second << ", ";
		it1++;
	}

	m1.insert(m2.begin(), m2.end());

	it1 = m1.begin();
	it2 = m1.end();

	std::cout << std::endl << "\t9.3 Printing m1 after inserting m2: ";
	while (it1 != it2) {
		std::cout << "[" << it1->first << "]->" << it1->second << ", ";
		it1++;
	}

	//===================================================================================

	std::cout << std::endl << std::endl << "10. Testing insert return" << std::endl;

	p2 = m1.insert(std::make_pair<int, const char *>(12, "Twelve"));

	std::cout << "\t10.1 Boolean return after trying to insert 12: " << p2.second << std::endl ;

	p2 = m1.insert(std::make_pair<int, const char *>(2, "Two"));

	std::cout << "\t10.2 Boolean return after trying to insert 2: " << p2.second << std::endl ;

	//===================================================================================


	std::cout << std::endl << "11. Testing swap" << std::endl;

	it1 = m1.begin();
	it2 = m1.end();

	std::cout << "\t11.1 Printing m1 before swap: ";
	while (it1 != it2) {
		std::cout << "[" << it1->first << "]->" << it1->second << ", ";
		it1++;
	}

	it1 = m2.begin();
	it2 = m2.end();

	std::cout << std::endl << "\t11.2 Printing m2 before swap: ";
	while (it1 != it2) {
		std::cout << "[" << it1->first << "]->" << it1->second << ", ";
		it1++;
	}

	m1.swap(m2);

	it1 = m1.begin();
	it2 = m1.end();

	std::cout << std::endl << "\t11.3 Printing m1 after swap: ";
	while (it1 != it2) {
		std::cout << "[" << it1->first << "]->" << it1->second << ", ";
		it1++;
	}

	it1 = m2.begin();
	it2 = m2.end();

	std::cout << std::endl << "\t11.4 Printing m2 after swap: ";
	while (it1 != it2) {
		std::cout << "[" << it1->first << "]->" << it1->second << ", ";
		it1++;
	}

	//===================================================================================

	std::cout << std::endl << std::endl << "12. Testing non-Members operators" << std::endl;

	std::cout << "\t12.1 m1 == m2: " << (m1 == m2) << std::endl;
	std::cout << "\t12.2 m1 != m2: " << (m1 != m2) << std::endl;
	std::cout << "\t12.3 m1 < m2: " << (m1 < m2) << std::endl;
	std::cout << "\t12.4 m1 > m2: " << (m1 > m2) << std::endl;
	std::cout << "\t12.5 m1 <= m2: " << (m1 <= m2) << std::endl;
	std::cout << "\t12.6 m1 >= m2: " << (m1 >= m2) << std::endl;

	//===================================================================================

	std::cout << std::endl << "13. Testing clear" << std::endl;

	std::cout << "\t13.1 m2 size before clear: " << m2.size() << std::endl;
	m2.clear();
	std::cout << "\t13.2 m2 size after clear: " << m2.size() << std::endl;

	//===================================================================================

	end = clock();

	std::cout << std::endl << "Execution time: " << std::fixed << (double)(end - start) << " miliseconds" << std::endl;
}