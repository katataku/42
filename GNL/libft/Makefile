# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/08 09:38:20 by takkatao          #+#    #+#              #
#    Updated: 2021/11/21 05:52:50 by takkatao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	 	= libft.a

LIBFT_A			= libft.a
LIBFT_SRCSDIR	= .
LIBFT_SRCS 	 	= \
	$(LIBFT_SRCSDIR)/ft_isalpha.c \
	$(LIBFT_SRCSDIR)/ft_isdigit.c \
	$(LIBFT_SRCSDIR)/ft_isalnum.c \
	$(LIBFT_SRCSDIR)/ft_isascii.c \
	$(LIBFT_SRCSDIR)/ft_isprint.c \
	$(LIBFT_SRCSDIR)/ft_strlen.c \
	$(LIBFT_SRCSDIR)/ft_memset.c \
	$(LIBFT_SRCSDIR)/ft_bzero.c \
	$(LIBFT_SRCSDIR)/ft_memcpy.c \
	$(LIBFT_SRCSDIR)/ft_memmove.c \
	$(LIBFT_SRCSDIR)/ft_strlcpy.c \
	$(LIBFT_SRCSDIR)/ft_strlcat.c \
	$(LIBFT_SRCSDIR)/ft_toupper.c \
	$(LIBFT_SRCSDIR)/ft_tolower.c \
	$(LIBFT_SRCSDIR)/ft_strchr.c \
	$(LIBFT_SRCSDIR)/ft_strrchr.c \
	$(LIBFT_SRCSDIR)/ft_strncmp.c \
	$(LIBFT_SRCSDIR)/ft_memchr.c \
	$(LIBFT_SRCSDIR)/ft_memcmp.c \
	$(LIBFT_SRCSDIR)/ft_strnstr.c \
	$(LIBFT_SRCSDIR)/ft_atoi.c \
	$(LIBFT_SRCSDIR)/ft_calloc.c \
	$(LIBFT_SRCSDIR)/ft_strdup.c \
	$(LIBFT_SRCSDIR)/ft_substr.c \
	$(LIBFT_SRCSDIR)/ft_strjoin.c \
	$(LIBFT_SRCSDIR)/ft_strtrim.c \
	$(LIBFT_SRCSDIR)/ft_split.c \
	$(LIBFT_SRCSDIR)/ft_itoa.c \
	$(LIBFT_SRCSDIR)/ft_strmapi.c \
	$(LIBFT_SRCSDIR)/ft_striteri.c \
	$(LIBFT_SRCSDIR)/ft_putchar_fd.c \
	$(LIBFT_SRCSDIR)/ft_putendl_fd.c \
	$(LIBFT_SRCSDIR)/ft_putnbr_fd.c \
	$(LIBFT_SRCSDIR)/ft_putstr_fd.c\
	$(LIBFT_SRCSDIR)/ft_lstadd_back.c \
	$(LIBFT_SRCSDIR)/ft_lstclear.c \
	$(LIBFT_SRCSDIR)/ft_lstdelone.c \
	$(LIBFT_SRCSDIR)/ft_lstlast.c \
	$(LIBFT_SRCSDIR)/ft_lstnew.c \
	$(LIBFT_SRCSDIR)/ft_lstsize.c \
	$(LIBFT_SRCSDIR)/ft_lstmap.c \
	$(LIBFT_SRCSDIR)/ft_lstiter.c \
	$(LIBFT_SRCSDIR)/ft_lstadd_front.c

LIBFT_OBJSDIR   = $(LIBFT_SRCSDIR)
LIBFT_OBJS 		= $(addprefix $(LIBFT_OBJSDIR)/, $(notdir $(LIBFT_SRCS:.c=.o)))

DEPENDS   		=  $(LIBFT_OBJS:.o=.d)

CC 				= gcc
CFLAGS			= -Werror -Wall -Wextra -MMD -MP
DEGUB_CFLAGS	= -g3 -fsanitize=address fsanitize=leak
RM				= /bin/rm -f
INCLUDES 		= -I../includes


.PHONY: all
all: $(NAME)

$(NAME):$(LIBFT_OBJS)
	ar rcs $(LIBFT_A) $(LIBFT_OBJS)

$(LIBFT_OBJSDIR)/%.o: $(LIBFT_SRCSDIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES)

.PHONY:clean
clean:
	$(RM) $(LIBFT_OBJS)
	$(RM) $(DEPENDS)

.PHONY:fclean
fclean:clean
	$(RM) $(NAME)

.PHONY:re
re:fclean all

-include $(DEPENDS)