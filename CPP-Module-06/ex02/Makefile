# **************************************************************************** #
#																			  #
#														 :::	  ::::::::	#
#	Makefile										   :+:	  :+:	:+:	#
#													 +:+ +:+		 +:+	  #
#	By: takkatao <takkatao@student.42tokyo.jp>	 +#+  +:+	   +#+		 #
#												 +#+#+#+#+#+   +#+			#
#	Created: 2021/10/08 09:38:20 by takkatao		  #+#	#+#			  #
#	Updated: 2021/12/12 13:35:11 by takkatao		 ###   ########.fr		#
#																			  #
# **************************************************************************** #

NAME	 	= a.out

SRCSDIR		= ./src
SRCS 	 	= \
	$(SRCSDIR)/main.cpp

OBJSDIR		= ./obj
OBJS 		= $(addprefix $(OBJSDIR)/, $(notdir $(SRCS:.cpp=.o)))

DEPENDS   		= $(OBJS:.o=.d)

CC 				= c++
CFLAGS			= -Werror -Wall -Wextra -MMD -MP -std=c++98
DEGUB_CFLAGS	= -g -fsanitize=address fsanitize=leak
RM				= /bin/rm -f
INCLUDES 		= -I./includes


.PHONY: all
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	
$(OBJSDIR)/%.o: $(SRCSDIR)/%.cpp
	mkdir -p $(OBJSDIR)
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES)

.PHONY:clean
clean:
	$(RM) $(OBJS)
	$(RM) $(DEPENDS)

.PHONY:fclean
fclean:clean
	$(RM) $(NAME)

.PHONY:re
re:fclean all

-include $(DEPENDS)