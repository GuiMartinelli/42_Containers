/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack_std.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:06:59 by guferrei          #+#    #+#             */
/*   Updated: 2022/10/04 19:41:50 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <deque>

int	main(void) {
	std::stack<char>	st;
	std::stack<char>	st2;
	clock_t				start;
	clock_t				end;


	std::cout << std::endl << "=================== STD::STACK TEST ===================" << std::endl << std::endl;

	start = clock();

	std::cout << "1. Testing empty and push" << std::endl;

	std::cout << "    1.1 Empty before push: " << st.empty() << std::endl;
	st.push('a');
	std::cout << "    1.2 Empty after push: " << st.empty() << std::endl << std::endl;

	//===================================================================================

	std::cout << "2. Testing top" << std::endl;

	std::cout << "    2.1 Top before push('b'): " << st.top() << std::endl;
	st.push('b');
	std::cout << "    2.2 Top after push('b'): " << st.top() << std::endl << std::endl;

	//===================================================================================

	std::cout << "3. Testing size" << std::endl;

	std::cout << "    3.1 Size before push('c'): " << st.size() << std::endl;
	st.push('c');
	std::cout << "    3.2 Size after push('c'): " << st.size() << std::endl << std::endl;

	//===================================================================================

	std::cout << "4. Testing pop" << std::endl;

	std::cout << "    4.1 Top before pop: " << st.top() << std::endl;
	st.pop();
	std::cout << "    4.2 Top after pop: " << st.top() << std::endl << std::endl;

	//===================================================================================

	std::cout << "5. Testing non-Members operators" << std::endl;

	st2.push('a');
	st2.push('b');

	std::cout << "    5.1 st == st2: " << (st == st2) << std::endl;
	std::cout << "    5.2 st != st2: " << (st != st2) << std::endl;
	std::cout << "    5.3 st < st2: " << (st < st2) << std::endl;
	std::cout << "    5.4 st > st2: " << (st > st2) << std::endl;
	std::cout << "    5.5 st <= st2: " << (st <= st2) << std::endl;
	std::cout << "    5.6 st >= st2: " << (st >= st2) << std::endl << std::endl;

	//===================================================================================

	std::cout << "5. Testing different inner container" << std::endl;

	std::stack<char, std::deque<char> >	st3;

	st3.push('A');
	st3.pop();

	end = clock();

	std::cout << std::endl << "Execution time: " << std::fixed << (double)(end - start) << " miliseconds" << std::endl;
}