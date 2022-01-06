# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/08 09:38:20 by takkatao          #+#    #+#              #
#    Updated: 2022/01/06 14:45:37 by takkatao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	 	= push_swap
SRCSDIR		= ./src
SRCS 	 	= \
	$(SRCSDIR)/logic_large.c\
	$(SRCSDIR)/logic_mini.c\
	$(SRCSDIR)/push.c\
	$(SRCSDIR)/swap.c\
	$(SRCSDIR)/rotate.c\
	$(SRCSDIR)/reverse_rotate.c\
	$(SRCSDIR)/main.c\
	$(SRCSDIR)/utils_lst.c\
	$(SRCSDIR)/utils_lstgetter.c\
	$(SRCSDIR)/utils_print.c\
	$(SRCSDIR)/validation.c\
	
	

OBJSDIR		= ./obj
OBJS 		= $(addprefix $(OBJSDIR)/, $(notdir $(SRCS:.c=.o)))


LIBFT_DIR	= ./libft
LIBFT_A			= $(LIBFT_DIR)/libft.a
DEPENDS   		= $(OBJS:.o=.d) 

CC 				= gcc
CFLAGS			= -Werror -Wall -Wextra -MMD -MP 
DEGUB_CFLAGS	= -g3 -fsanitize=address
RM				= /bin/rm -f
INCLUDES 		= -I./includes

CFLAGS += $(DEGUB_CFLAGS)

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) -o $@  $(OBJS) $(LIBFT_A) $(INCLUDES)


$(OBJSDIR)/%.o: $(SRCSDIR)/%.c
	@mkdir -p $(OBJSDIR)
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES)

$(LIBFT_A):
	make -C $(LIBFT_DIR)

.PHONY:clean
clean:
	$(RM) $(OBJS)
	$(RM) $(LIBFT_OBJS)
	$(RM) $(DEPENDS)
	make -C $(LIBFT_DIR) clean

.PHONY:fclean
fclean:clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

.PHONY:re
re:fclean all

.PHONY:test
test:$(NAME)
	cd push_swap_tester && python3 push_swap_tester.py -l 5 -c 500 
	cd push_swap_tester && python3 push_swap_tester.py -l 100 -c 500 
	cd push_swap_tester && python3 push_swap_tester.py -l 500 -c 100 

.PHONY:visual
visual:$(NAME)
	cp $(NAME) ./test
#	cd test && python3 pyviz.py `ruby -e "puts (0..100).to_a.shuffle.join(' ')"` 
	cd test && python3 pyviz.py 2 1 3

-include $(DEPENDS)