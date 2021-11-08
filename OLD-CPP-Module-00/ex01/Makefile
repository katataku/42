# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/08 09:38:20 by takkatao          #+#    #+#              #
#    Updated: 2021/11/08 18:06:45 by takkatao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=phonebook

SRCDIR=.
SOURCES = $(MAIN_SOURCE) $(SUB_SOURCES)


MAIN_SOURCE = main.cpp

SUB_SOURCES  =	phonebook.cpp\
			contact.cpp


OBJS  = $(SOURCES:.cpp=.o)
SUB_OBJS =$(SUB_SOURCES:.cpp=.o)

CC = clang++
CFLAGS		=	-Wall -Wextra -Werror# -g3 -fsanitize=address
RM				= /bin/rm -f

.PHONY: all clean fclean re test

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

.cpp.o:
	$(CC) $(CFLAGS) -o $@ -c $*.cpp

clean:
	$(RM) $(OBJS)
	
fclean:clean
	$(RM) $(NAME)

re:fclean all

test:$(SUB_OBJS)
	g++ -std=c++11 ./test/test.cpp $(SUB_OBJS) -lgtest_main -lgtest && ./a.out && $(RM) ./a.out

