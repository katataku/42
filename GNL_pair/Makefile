# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/08 09:38:20 by takkatao          #+#    #+#              #
#    Updated: 2021/11/25 13:44:44 by takkatao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	 	= get_next_line

SRCSDIR		= ./src
SRCS 	 	= \
	$(SRCSDIR)/get_next_line.c\
	$(SRCSDIR)/get_next_line_utils.c

OBJSDIR		= ./obj
OBJS 		= $(addprefix $(OBJSDIR)/, $(notdir $(SRCS:.c=.o)))

DEPENDS   		= $(OBJS:.o=.d)

CC 				= gcc
CFLAGS			= -Werror -Wall -Wextra -MMD -MP -D BUFFER_SIZE=1024
DEGUB_CFLAGS	= -g3 -fsanitize=address fsanitize=leak
RM				= /bin/rm -f
INCLUDES 		= -I./includes


.PHONY: all
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o get_next_line $(OBJS)
	
$(OBJSDIR)/%.o: $(SRCSDIR)/%.c
	mkdir -p $(OBJSDIR)
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES)

.PHONY:clean
clean:
	$(RM) $(OBJS) $(DEPENDS)

.PHONY:fclean
fclean:clean
	$(RM) $(NAME)

.PHONY:re
re:fclean all

.PHONY:submit
submit:
	mkdir -p submit
	cp src/get_next_line.c submit/
	cp src/get_next_line_utils.c submit/
	cp includes/get_next_line.h submit/
	
-include $(DEPENDS)