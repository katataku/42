# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/08 09:38:20 by takkatao          #+#    #+#              #
#    Updated: 2021/11/21 05:50:36 by takkatao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	 	= libftprintf.a
SRCSDIR		= ./src
SRCS 	 	= \
	$(SRCSDIR)/ft_printf.c\
	$(SRCSDIR)/number_utils.c\
	$(SRCSDIR)/print_utils_cspd.c\
	$(SRCSDIR)/print_utils_else.c

OBJSDIR		= ./obj
OBJS 		= $(addprefix $(OBJSDIR)/, $(notdir $(SRCS:.c=.o)))


LIBFT_DIR = ./libft
LIBFT_A			= $(LIBFT_DIR)/libft.a

DEPENDS   		= $(OBJS:.o=.d) $(LIBFT_OBJS:.o=.d)

CC 				= gcc
CFLAGS			= -Werror -Wall -Wextra -MMD -MP
DEGUB_CFLAGS	= -g3 -fsanitize=address fsanitize=leak
RM				= /bin/rm -f
INCLUDES 		= -I./includes


.PHONY: all
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A)
	ar rcs $(NAME) $(OBJS) 


$(OBJSDIR)/%.o: $(SRCSDIR)/%.c
	mkdir -p $(OBJSDIR)
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES)


.PHONY:$(LIBFT_A)
$(LIBFT_A): 
	make -C $(LIBFT_DIR)

.PHONY:clean
clean:
	$(RM) $(OBJS) $(DEPENDS)
	make  -C $(LIBFT_DIR) clean

.PHONY:fclean
fclean:clean
	$(RM) $(NAME)
	$(RM) $(LIBFT_A)

.PHONY:re
re:fclean all

.PHONY:test
test:$(NAME)
	make
	g++ -std=c++11 ./test/test_printf.cpp -lgtest_main -lgtest $(NAME) $(INCLUDES)&& ./a.out && $(RM) ./a.out

-include $(DEPENDS)