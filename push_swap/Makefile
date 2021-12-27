# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/08 09:38:20 by takkatao          #+#    #+#              #
#    Updated: 2021/12/27 13:23:58 by takkatao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	 	= push_swap
SRCSDIR		= ./src
SRCS 	 	= \
	$(SRCSDIR)/push_swap.c\
	$(SRCSDIR)/push.c\
	$(SRCSDIR)/swap.c\
	$(SRCSDIR)/rotate.c\
	$(SRCSDIR)/reverse_rotate.c\
	$(SRCSDIR)/main.c\
	$(SRCSDIR)/utils_lst.c\
	$(SRCSDIR)/utils_print.c\
	

OBJSDIR		= ./obj
OBJS 		= $(addprefix $(OBJSDIR)/, $(notdir $(SRCS:.c=.o)))


LIBFT_DIR	= ./libft
LIBFT_A			= $(LIBFT_DIR)/libft.a
LIBFT_SRCS 	 	= \
	$(LIBFT_DIR)/ft_isalpha.c \
	$(LIBFT_DIR)/ft_isdigit.c \
	$(LIBFT_DIR)/ft_isalnum.c \
	$(LIBFT_DIR)/ft_isascii.c \
	$(LIBFT_DIR)/ft_isprint.c \
	$(LIBFT_DIR)/ft_strlen.c \
	$(LIBFT_DIR)/ft_memset.c \
	$(LIBFT_DIR)/ft_bzero.c \
	$(LIBFT_DIR)/ft_memcpy.c \
	$(LIBFT_DIR)/ft_memmove.c \
	$(LIBFT_DIR)/ft_strlcpy.c \
	$(LIBFT_DIR)/ft_strlcat.c \
	$(LIBFT_DIR)/ft_toupper.c \
	$(LIBFT_DIR)/ft_tolower.c \
	$(LIBFT_DIR)/ft_strchr.c \
	$(LIBFT_DIR)/ft_strrchr.c \
	$(LIBFT_DIR)/ft_strncmp.c \
	$(LIBFT_DIR)/ft_memchr.c \
	$(LIBFT_DIR)/ft_memcmp.c \
	$(LIBFT_DIR)/ft_strnstr.c \
	$(LIBFT_DIR)/ft_atoi.c \
	$(LIBFT_DIR)/ft_calloc.c \
	$(LIBFT_DIR)/ft_strdup.c \
	$(LIBFT_DIR)/ft_substr.c \
	$(LIBFT_DIR)/ft_strjoin.c \
	$(LIBFT_DIR)/ft_strtrim.c \
	$(LIBFT_DIR)/ft_split.c \
	$(LIBFT_DIR)/ft_itoa.c \
	$(LIBFT_DIR)/ft_strmapi.c \
	$(LIBFT_DIR)/ft_striteri.c \
	$(LIBFT_DIR)/ft_putchar_fd.c \
	$(LIBFT_DIR)/ft_putendl_fd.c \
	$(LIBFT_DIR)/ft_putnbr_fd.c \
	$(LIBFT_DIR)/ft_putstr_fd.c\
	$(LIBFT_DIR)/ft_lstadd_back.c \
	$(LIBFT_DIR)/ft_lstclear.c \
	$(LIBFT_DIR)/ft_lstdelone.c \
	$(LIBFT_DIR)/ft_lstlast.c \
	$(LIBFT_DIR)/ft_lstnew.c \
	$(LIBFT_DIR)/ft_lstsize.c \
	$(LIBFT_DIR)/ft_lstmap.c \
	$(LIBFT_DIR)/ft_lstiter.c \
	$(LIBFT_DIR)/ft_lstadd_front.c

LIBFT_OBJSDIR   = $(LIBFT_DIR)
LIBFT_OBJS 		= $(addprefix $(LIBFT_OBJSDIR)/, $(notdir $(LIBFT_SRCS:.c=.o)))

DEPENDS   		= $(OBJS:.o=.d) $(LIBFT_OBJS:.o=.d)

CC 				= gcc
CFLAGS			= -Werror -Wall -Wextra -MMD -MP
DEGUB_CFLAGS	= -g3 -fsanitize=address
RM				= /bin/rm -f
INCLUDES 		= -I./includes


.PHONY: all
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) -o $@  $(OBJS) $(LIBFT_A) $(INCLUDES)


$(OBJSDIR)/%.o: $(SRCSDIR)/%.c
	mkdir -p $(OBJSDIR)
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES)

$(LIBFT_A): $(LIBFT_OBJS)
	ar rcs $(LIBFT_A) $(LIBFT_OBJS)

$(LIBFT_OBJSDIR)/%.o: $(LIBFT_DIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES)

.PHONY:clean
clean:
	$(RM) $(OBJS)
	$(RM) $(LIBFT_OBJS)
	$(RM) $(DEPENDS)

.PHONY:fclean
fclean:clean
	$(RM) $(NAME)

.PHONY:re
re:fclean all

.PHONY:test
test:$(NAME)
	cd push_swap_tester && python3 push_swap_tester.py -l 5 -c 500 
	cd push_swap_tester && python3 push_swap_tester.py -l 100 -c 500 
#	cd push_swap_tester && python3 push_swap_tester.py -l 500 -c 500 

.PHONY:visual
visual:$(NAME)
	cp $(NAME) ./test
	cd test && python3 pyviz.py `ruby -e "puts (0..100).to_a.shuffle.join(' ')"` 

-include $(DEPENDS)