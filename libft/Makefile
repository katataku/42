# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/08 09:38:20 by takkatao          #+#    #+#              #
#    Updated: 2021/11/04 09:25:50 by takkatao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

SRCDIR=.
SOURCES  = $(PART1_SOURCES) $(PART2_SOURCES) $(PART2_SUB_SOURCES)

PART1_SOURCES = \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c 

PART2_SOURCES = \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c

PART2_SUB_SOURCES = \
	ft_lstadd_back.c \
	ft_lstclear.c \
	ft_lstdelone.c \
	ft_lstlast.c \
	ft_lstnew.c \
	ft_lstsize.c

BONUS_SOURCES = \
	ft_lstmap.c \
	ft_lstiter.c \
	ft_lstadd_front.c

OBJS  = $(SOURCES:.c=.o)
BONUS_OBJS  = $(BONUS_SOURCES:.c=.o)

ifdef WITH_BONUS
OBJS += $(BONUS_OBJS)
endif

CC = gcc
CFLAGS		=	-Werror -Wall -Wextra# -g3 -fsanitize=address
RM				= /bin/rm -f

.PHONY: all clean fclean re bonus

all: bonus

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: 
	@make $(NAME) WITH_BONUS=1

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $*.c

clean:
	$(RM) $(OBJS)
	$(RM) $(BONUS_OBJS)

fclean:clean
	$(RM) -f $(NAME)

re:fclean all

