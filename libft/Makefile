CC = gcc
RM				= rm -f
CFLAGS		=	-Werror -Wall -Wextra# -g3 -fsanitize=address

SRCDIR=.
SOURCES  = $(wildcard $(SRCDIR)/*.c)
OBJS  = $(SOURCES:.c=.o)

all:libft

libft:
	ar -rcs libft.a $(OBJS)

fclean:
	/bin/rm -f bsq
