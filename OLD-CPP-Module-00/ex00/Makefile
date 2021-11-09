# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/08 09:38:20 by takkatao          #+#    #+#              #
#    Updated: 2021/11/09 17:57:19 by takkatao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=megaphone

SRCDIR=.
SOURCES  = megaphone.cpp 

OBJS  = $(SOURCES:.cpp=.o)

CC = clang++
CFLAGS		=	-std=c++98 -pedantic  -Wall -Wextra -Werror# -g3 -fsanitize=address
RM				= /bin/rm -f

.PHONY: all clean fclean re 

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

