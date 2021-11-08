# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/08 09:38:20 by takkatao          #+#    #+#              #
#    Updated: 2021/11/08 10:22:47 by takkatao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=megaphone

SRCDIR=.
SOURCES  = megaphone.cpp 

OBJS  = $(SOURCES:.c=.o)

CC = clang++
CFLAGS		=	-Wall -Wextra -Werror# -g3 -fsanitize=address
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

