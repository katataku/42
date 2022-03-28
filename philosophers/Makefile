NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror -O2 -g -fsanitize=thread
SRCS = main.c \
	srcs/init.c\
	srcs/philo.c\
	srcs/monitor.c\
	srcs/utils.c\
	srcs/ft_atoi.c

OBJS = $(SRCS:%.c=%.o)
LIBS = -lft -Llibft -lreadline 
INCS = -Ilibft/includes -Iincludes 

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) $(LIBS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCS) -o $@ -c $<


fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)
	make fclean -C libft

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
	make clean -C libft

re: fclean all

.PHONY: all fclean clean re

.PHONY: test
test: utest itest

.PHONY: ltest
ltest: ultest iltest

.PHONY: utest
utest:
	make -C tests/google_tests

.PHONY: ultest
ultest:
	make -C tests/google_tests ltest

.PHONY: itest
itest: $(NAME)
	bash ./tests/shell_scripts/main.sh
