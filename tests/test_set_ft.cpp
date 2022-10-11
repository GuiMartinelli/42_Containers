/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set_ft.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:55:35 by guferrei          #+#    #+#             */
/*   Updated: 2022/10/11 16:16:14 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../set.hpp"
#include "../utility.hpp"
#include <stdexcept>

int	main(void) {
	ft::set<char>	s1;
	ft::set<char>	s2;
	ft::pair<ft::set<char>::iterator, ft::set<char>::iterator>	p;
	ft::pair<ft::set<char>::iterator, bool>						p2;
	clock_t			start;
	clock_t			end;


	std::cout << std::endl << "=================== FT::SET TEST ===================" << std::endl << std::endl;

	start = clock();

	std::cout << "1. Testing empty and insert" << std::endl;

	std::cout << "\t1.1 Empty before insert: " << s1.empty() << std::endl;
	s1.insert('B');
	std::cout << "\t1.2 Empty after insert: " << s1.empty() << std::endl << std::endl;

	//===================================================================================

	std::cout << "2. Testing size and insert" << std::endl;

	std::cout << "\t2.1 Size: " << s1.size() << std::endl;
	s1.insert('P');
	std::cout << "\t2.2 Size: " << s1.size() << std::endl;
	s1.insert('A');
	std::cout << "\t2.3 Size: " << s1.size() << std::endl;
	s1.insert('W');
	std::cout << "\t2.4 Size: " << s1.size() << std::endl;
	s1.insert('S');
	std::cout << "\t2.5 Size: " << s1.size() << std::endl;
	s1.insert('C');
	std::cout << "\t2.6 Size: " << s1.size() << std::endl << std::endl;

	//===================================================================================

	std::cout << "3. Testing Iterators" << std::endl;

	ft::set<char>::iterator			it1 = s1.begin();
	ft::set<char>::iterator			it2 = s1.end();
	ft::set<char>::reverse_iterator	rit1 = s1.rbegin();
	ft::set<char>::reverse_iterator	rit2 = s1.rend();

	std::cout << "\t3.1 Printing set using iterator: ";
	while (it1 != it2) {
		std::cout << *it1 << ", ";
		it1++;
	}

	std::cout << std::endl << "\t3.2 Printing set using reverse_iterator: ";
	while (rit1 != rit2) {
		std::cout << *rit1 << ", ";
		rit1++;
	}
	std::cout << std::endl << std::endl;

	//===================================================================================

	std::cout << "4. Testing Erase" << std::endl;

	it1 = s1.begin();

	std::cout << "\t4.1 Printing set before erasing first value with iterator: ";
	while (it1 != it2) {
		std::cout << *it1 << ", ";
		it1++;
	}
	s1.erase(s1.begin());
	it1 = s1.begin();
	std::cout << std::endl << "\t4.2 Printing set before erasing first value with iterator: ";
	while (it1 != it2) {
		std::cout << *it1 << ", ";
		it1++;
	}

	it1 = s1.begin();
	std::cout << std::endl << std::endl << "\t4.3 Printing set before erasing value 'C': ";
	while (it1 != it2) {
		std::cout << *it1 << ", ";
		it1++;
	}
	s1.erase('C');
	it1 = s1.begin();
	std::cout << std::endl << "\t4.4 Printing set after erasing value 'C': ";
	while (it1 != it2) {
		std::cout << *it1 << ", ";
		it1++;
	}
	std::cout << std::endl;

	//===================================================================================

	std::cout << std::endl << "5. Testing Find" << std::endl;

	std::cout << "\t5.1 Finding 'P': ";
	it1 = s1.find('P');
	std::cout << *it1 << std::endl;
	std::cout << "\t5.2 Finding non-existent element: ";
	it1 = s1.find('Y');
	if (it1 == s1.end())
		std::cout << "set end" << std::endl;

	//===================================================================================

	std::cout << std::endl << "6. Testing Count" << std::endl;

	std::cout << "\t6.1 Counting element 'P': " << s1.count('P') << std::endl;
	std::cout << "\t6.2 Counting non-existent element: " << s1.count('Z') << std::endl;

	//===================================================================================

	std::cout << std::endl << "7. Testing Lower_Bound, Upper_Bound and Equal_Range" << std::endl;

	it1 = s1.lower_bound('P');
	std::cout << "\t7.1 Lower Bound of 'P' is: " << *it1 << std::endl;
	it1 = s1.upper_bound('P');
	std::cout << "\t7.2 Upper Bound of 'P' is: " << *it1 << std::endl;

	p = s1.equal_range('P');
	std::cout << "\t7.3 Equal Range first of 'P' is: " << *p.first << std::endl;
	it1 = s1.upper_bound('P');
	std::cout << "\t7.4 Equal Range second of 'P' is: " << *p.second << std::endl;

	//===================================================================================

	std::cout << std::endl << "8. Testing iterator insertion" << std::endl;

	s2.insert('Z');
	s2.insert('K');
	s2.insert('O');

	it1 = s2.begin();
	it2 = s2.end();

	std::cout << "\t8.1 Printing s2: ";
	while (it1 != it2) {
		std::cout << *it1 << ", ";
		it1++;
	}

	it1 = s1.begin();
	it2 = s1.end();

	std::cout << std::endl << "\t8.2 Printing s1 before inserting s2: ";
	while (it1 != it2) {
		std::cout << *it1 << ", ";
		it1++;
	}

	s1.insert(s2.begin(), s2.end());

	it1 = s1.begin();
	it2 = s1.end();

	std::cout << std::endl << "\t8.3 Printing s1 after inserting s2: ";
	while (it1 != it2) {
		std::cout << *it1 << ", ";
		it1++;
	}

	//===================================================================================

	std::cout << std::endl << std::endl << "9. Testing insert return" << std::endl;

	p2 = s1.insert('M');

	std::cout << "\t9.1 Boolean return after trying to insert 'M': " << p2.second << std::endl ;

	p2 = s1.insert('S');

	std::cout << "\t9.2 Boolean return after trying to insert 'S': " << p2.second << std::endl ;

	//===================================================================================


	std::cout << std::endl << "10. Testing swap" << std::endl;

	it1 = s1.begin();
	it2 = s1.end();

	std::cout << "\t10.1 Printing s1 before swap: ";
	while (it1 != it2) {
		std::cout << *it1 << ", ";
		it1++;
	}

	it1 = s2.begin();
	it2 = s2.end();

	std::cout << std::endl << "\t10.2 Printing s2 before swap: ";
	while (it1 != it2) {
		std::cout << *it1 << ", ";
		it1++;
	}

	s1.swap(s2);

	it1 = s1.begin();
	it2 = s1.end();

	std::cout << std::endl << "\t10.3 Printing s1 after swap: ";
	while (it1 != it2) {
		std::cout << *it1 << ", ";
		it1++;
	}

	it1 = s2.begin();
	it2 = s2.end();

	std::cout << std::endl << "\t10.4 Printing s2 after swap: ";
	while (it1 != it2) {
		std::cout << *it1 << ", ";
		it1++;
	}

	//===================================================================================

	std::cout << std::endl << std::endl << "11. Testing non-Members operators" << std::endl;

	std::cout << "\t11.1 s1 == s2: " << (s1 == s2) << std::endl;
	std::cout << "\t11.2 s1 != s2: " << (s1 != s2) << std::endl;
	std::cout << "\t11.3 s1 < s2: " << (s1 < s2) << std::endl;
	std::cout << "\t11.4 s1 > s2: " << (s1 > s2) << std::endl;
	std::cout << "\t11.5 s1 <= s2: " << (s1 <= s2) << std::endl;
	std::cout << "\t11.6 s1 >= s2: " << (s1 >= s2) << std::endl;

	//===================================================================================

	std::cout << std::endl << "12. Testing clear" << std::endl;

	std::cout << "\t12.1 s2 size before clear: " << s2.size() << std::endl;
	s2.clear();
	std::cout << "\t12.2 s2 size after clear: " << s2.size() << std::endl;

	//===================================================================================

	end = clock();

	std::cout << std::endl << "Execution time: " << std::fixed << (double)(end - start) << " miliseconds" << std::endl;
}