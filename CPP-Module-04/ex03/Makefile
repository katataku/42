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
	$(SRCSDIR)/main.cpp\
	$(SRCSDIR)/Ice.cpp\
	$(SRCSDIR)/Cure.cpp\
	$(SRCSDIR)/Character.cpp\
	$(SRCSDIR)/AMateria.cpp\
	$(SRCSDIR)/MateriaSource.cpp\

	
	
	

OBJSDIR		= ./obj
OBJS 		= $(addprefix $(OBJSDIR)/, $(notdir $(SRCS:.cpp=.o)))

DEPENDS   		= $(OBJS:.o=.d)

CC 				= c++
CFLAGS			= -Werror -Wall -Wextra -MMD -MP
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


gtestdir	=   ./gtest_modules
gtest	   =   $(gtestdir)/gtest $(gtestdir)/googletest-release-1.11.0

testdir = ./test

$(gtest):
	mkdir -p $(gtestdir)
	curl -OL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.tar.gz
	tar -xvzf release-1.11.0.tar.gz googletest-release-1.11.0
	rm -rf release-1.11.0.tar.gz
	python googletest-release-1.11.0/googletest/scripts/fuse_gtest_files.py $(gtestdir)
	mv googletest-release-1.11.0 $(gtestdir)

.PHONY:test
test: $(NAME)
	cd test && ./test.sh
# test: $(gtest) 
# 	clang++ -std=c++11 $(testdir)/gtest.cpp \
# 	$(gtestdir)/googletest-release-1.11.0/googletest/src/gtest_main.cc \
# 	$(gtestdir)/gtest/gtest-all.cc \
# 	-DDEBUG -g -fsanitize=integer -fsanitize=address \
# 	-I$(gtestdir) -I$(includes) -lpthread $(srcs_test) -o tester
# 	./tester
# 	rm tester
	



-include $(DEPENDS)