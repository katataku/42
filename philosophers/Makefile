NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror -O2 -g -fsanitize=thread
XSYSCALL_SRCS = $(addprefix srcs/xsyscall/, \
		xclose.c xfork.c xopen.c xpipe.c xwaitpid.c xdup2.c \
		)
XLIBFT_SRCS = $(addprefix srcs/xlibft/, \
		ft_xcalloc.c ft_xlstnew.c ft_xsplit.c ft_xstrdup.c ft_xstrjoin.c \
		)
SRCS = main.c $(XSYSCALL_SRCS) $(XLIBFT_SRCS)
OBJS = $(SRCS:%.c=%.o)
LIBS = -lft -Llibft -lreadline 
INCS = -Ilibft/includes -Iincludes 

$(NAME): $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) $(LIBS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCS) -o $@ -c $<

all: $(NAME)

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
