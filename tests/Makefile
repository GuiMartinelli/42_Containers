# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 21:01:54 by guferrei          #+#    #+#              #
#    Updated: 2022/10/05 21:07:02 by guferrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=c++

FLAGS=-Wall -Wextra -Werror -std=c++98

BIN= ./test_map_std ./test_map_ft ./test_set_std ./test_set_ft ./test_stack_std \
	./test_stack_ft ./test_vector_std ./test_vector_ft

all: map set stack vector

map:
	$(CC) $(FLAGS) test_map_std.cpp -o test_map_std
	$(CC) $(FLAGS) test_map_ft.cpp -o test_map_ft

set:
	$(CC) $(FLAGS) test_set_std.cpp -o test_set_std
	$(CC) $(FLAGS) test_set_ft.cpp -o test_set_ft

stack:
	$(CC) $(FLAGS) test_stack_std.cpp -o test_stack_std
	$(CC) $(FLAGS) test_stack_ft.cpp -o test_stack_ft

vector:
	$(CC) $(FLAGS) test_vector_std.cpp -o test_vector_std
	$(CC) $(FLAGS) test_vector_ft.cpp -o test_vector_ft

clean:
	rm $(BIN)

fclean: clean

re: clean all
