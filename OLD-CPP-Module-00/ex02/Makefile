# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/08 09:38:20 by takkatao          #+#    #+#              #
#    Updated: 2021/11/09 15:30:24 by takkatao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=account

SRCDIR=.
SOURCES = $(MAIN_SOURCE) $(SUB_SOURCES)


MAIN_SOURCE = tests.cpp

SUB_SOURCES  =	Account.cpp


OBJS  = $(SOURCES:.cpp=.o)
SUB_OBJS =$(SUB_SOURCES:.cpp=.o)

-include $(DEPENDS)
DEPENDS = $(OBJS:.o=.d)

CXX = clang++
CXXFLAGS		=	-Wall -Wextra -Werror -std=c++98 -pedantic -MMD  -MP# -g3 -fsanitize=address
RM				= /bin/rm -f

.PHONY: all clean fclean re test

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) -o $(NAME) $(OBJS)

.cpp.o:
	$(CXX) $(CXXFLAGS) -o $@ -c $*.cpp

clean:
	$(RM) $(OBJS) 
	$(RM) $(DEPENDS)
	
fclean:clean
	$(RM) $(NAME)

re:fclean all

test:$(NAME)
	./$(NAME) > output.txt && diff 19920104_091532.log output.txt

