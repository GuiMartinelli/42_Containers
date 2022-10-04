/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_std.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:35:57 by guferrei          #+#    #+#             */
/*   Updated: 2022/10/04 19:48:51 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <utility>

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

	end = clock();

	std::cout << std::endl << "Execution time: " << std::fixed << (double)(end - start) << " miliseconds" << std::endl;
}