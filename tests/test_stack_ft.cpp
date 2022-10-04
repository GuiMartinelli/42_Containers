/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack_ft.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:06:53 by guferrei          #+#    #+#             */
/*   Updated: 2022/10/04 19:17:38 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../stack.hpp"

int	main(void) {
	ft::stack<char>	st;
	clock_t			start;
	clock_t			end;


	std::cout << std::endl << "=================== FT::STACK TEST ===================" << std::endl << std::endl;

	start = clock();

	std::cout << "1. Testing empty and push" << std::endl;

	std::cout << "    1.1 Empty before push: " << st.empty() << std::endl;
	st.push('a');
	std::cout << "    1.2 Empty after push: " << st.empty() << std::endl << std::endl;

	std::cout << "2. Testing top" << std::endl;

	std::cout << "    2.1 Top before push('b'): " << st.top() << std::endl;
	st.push('b');
	std::cout << "    2.2 Top after push('b'): " << st.top() << std::endl << std::endl;

	std::cout << "3. Testing size" << std::endl;

	std::cout << "    3.1 Size before push('c'): " << st.size() << std::endl;
	st.push('c');
	std::cout << "    3.2 Size after push('c'): " << st.size() << std::endl << std::endl;

	std::cout << "4. Testing pop" << std::endl;

	std::cout << "    4.1 Top before pop: " << st.top() << std::endl;
	st.pop();
	std::cout << "    4.2 Top after pop: " << st.top() << std::endl << std::endl;

	end = clock();

	std::cout << std::endl << "Execution time: " << std::fixed << (double)(end - start) << " miliseconds" << std::endl;
}