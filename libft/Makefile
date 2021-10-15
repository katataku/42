# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/08 09:38:20 by takkatao          #+#    #+#              #
#    Updated: 2021/10/15 15:32:54 by takkatao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

SRCDIR=.
SOURCES  = ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_lstadd_back.c \
	ft_lstclear.c \
	ft_lstdelone.c \
	ft_lstlast.c \
	ft_lstnew.c \
	ft_lstsize.c \
	ft_memccpy.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_split.c \
	ft_strcat.c \
	ft_strchr.c \
	ft_strcmp.c \
	ft_strcpy.c \
	ft_strdup.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strncat.c \
	ft_strncmp.c \
	ft_strncpy.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_tolower.c \
	ft_toupper.c 

BONUS_SOURCES = 	ft_lstmap.c \
	ft_lstiter.c \
	ft_lstadd_front.c \



OBJS  = $(SOURCES:.c=.o)

CC = gcc
CFLAGS		=	-Werror -Wall -Wextra -fsanitize=address# -g3 -fsanitize=address
RM				= /bin/rm -f


all: $(NAME)

$(NAME):$(OBJS)
	ar -rcs $(NAME) $(OBJS)

bonus:$(NAME)
	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.c.o::
	$(CC) $(CFLAGS) -o $@ -c $*.c

clean:
	$(RM) $(OBJS)

fclean:clean
	$(RM) -f $(NAME)

re:fclean all

.PHONY: all clean fclean re bonus
