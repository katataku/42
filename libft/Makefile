# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/08 09:38:20 by takkatao          #+#    #+#              #
#    Updated: 2021/10/14 09:05:51 by takkatao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft
CC = gcc
CFLAGS		=	-Werror -Wall -Wextra# -g3 -fsanitize=address
RM				= /bin/rm -f

SRCDIR=.
SOURCES  = $(wildcard $(SRCDIR)/*.c)
OBJS  = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME):$(OBJS)
	ar -rcs $(NAME).a $(OBJS)

bonus:$(NAME)

$(OBJS):$(SOURCES)
	$(CC) $(CFLAGS) -o $@ -c $*.c

clean:
	$(RM) $(OBJS)

fclean:clean
	$(RM) -f $(NAME).a

re:fclean all

.PHONY: all clean fclean 
