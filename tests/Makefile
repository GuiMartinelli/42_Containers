# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 21:01:54 by guferrei          #+#    #+#              #
#    Updated: 2022/10/10 15:47:30 by guferrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=c++

CFLAGS=-Wall -Wextra -Werror -std=c++98

BIN= ./test_map_std ./test_map_ft ./test_set_std ./test_set_ft ./test_stack_std \
	./test_stack_ft ./test_vector_std ./test_vector_ft

all: map set stack vector

map: test_map_std test_map_ft

test_map_std:
	$(CC) $(CFLAGS) test_map_std.cpp -o test_map_std

test_map_ft:
	$(CC) $(CFLAGS) test_map_ft.cpp -o test_map_ft

set: test_set_std test_set_ft

test_set_std:
	$(CC) $(CFLAGS) test_set_std.cpp -o test_set_std

test_set_ft:
	$(CC) $(CFLAGS) test_set_ft.cpp -o test_set_ft

stack: test_stack_std test_stack_ft

test_stack_std:
	$(CC) $(CFLAGS) test_stack_std.cpp -o test_stack_std

test_stack_ft:
	$(CC) $(CFLAGS) test_stack_ft.cpp -o test_stack_ft

vector: test_vector_std test_vector_ft

test_vector_std:
	$(CC) $(CFLAGS) test_vector_std.cpp -o test_vector_std

test_vector_ft:
	$(CC) $(CFLAGS) test_vector_ft.cpp -o test_vector_ft

clean:
	rm $(BIN)

fclean: clean

re: clean all
