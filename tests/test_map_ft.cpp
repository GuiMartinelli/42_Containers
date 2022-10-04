/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_ft.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:35:54 by guferrei          #+#    #+#             */
/*   Updated: 2022/10/04 20:14:58 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <istream>
#include "../map.hpp"
#include "../utility.hpp"

int	main(void) {
	ft::map<int, const char*>	m1;
	clock_t			start;
	clock_t			end;


	std::cout << std::endl << "=================== FT::MAP TEST ===================" << std::endl << std::endl;

	start = clock();

	std::cout << "1. Testing Empty and Insert" << std::endl;

	std::cout << "    1.1 Empty before insert: " << m1.empty() << std::endl;
	m1.insert(ft::make_pair<int, const char *>(1, "One"));
	std::cout << "    1.2 Empty after insert: " << m1.empty() << std::endl << std::endl;

	//===================================================================================

	std::cout << "2. Testing Size and Insert" << std::endl;

	std::cout << "    2.1 Size: " << m1.size() << std::endl;
	m1.insert(ft::make_pair<int, const char *>(5, "Five"));
	std::cout << "    2.2 Size: " << m1.size() << std::endl;
	m1.insert(ft::make_pair<int, const char *>(9, "Nine"));
	std::cout << "    2.3 Size: " << m1.size() << std::endl;
	m1.insert(ft::make_pair<int, const char *>(2, "Two"));
	std::cout << "    2.4 Size: " << m1.size() << std::endl;
	m1.insert(ft::make_pair<int, const char *>(3, "Three"));
	std::cout << "    2.5 Size: " << m1.size() << std::endl;
	m1.insert(ft::make_pair<int, const char *>(7, "Seven"));
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

	end = clock();

	std::cout << std::endl << "Execution time: " << std::fixed << (double)(end - start) << " miliseconds" << std::endl;
}