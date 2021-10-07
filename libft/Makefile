CC = gcc
RM				= rm -f
CFLAGS		=	-Werror -Wall -Wextra# -g3 -fsanitize=address

SRCDIR=.
SOURCES  = $(wildcard $(SRCDIR)/*.c)
OBJDIR=./obj
OBJS  = $(SOURCES:.c=.o)

all:libft

libft:$(OBJS)
	ar -rcs libft.a $(OBJS)

$(OBJS):$(SOURCES)
	$(CC) $(CFLAGS) -o $@ -c $*.c

clean:
	/bin/rm $(OBJS)

fclean:clean
	/bin/rm -f libft.a

re:fclean all
