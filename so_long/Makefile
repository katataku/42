NAME	 	= so_long
SRCSDIR		= ./srcs
SRCS 	 	= \
	$(SRCSDIR)/main.c\
	$(SRCSDIR)/ft_calloc.c\
	$(SRCSDIR)/ft_bzero.c\
	$(SRCSDIR)/ft_putchar_fd.c\
	$(SRCSDIR)/ft_putendl_fd.c\
	$(SRCSDIR)/ft_putnbr_fd.c\
	$(SRCSDIR)/ft_putstr_fd.c\
	$(SRCSDIR)/init_map.c\
	$(SRCSDIR)/init_window.c\
	$(SRCSDIR)/event_key_press.c\
	$(SRCSDIR)/main_loop.c\
	$(SRCSDIR)/get_map_size.c\
	$(SRCSDIR)/get_next_line.c\
	$(SRCSDIR)/get_next_line_utils.c\
	$(SRCSDIR)/ft_xutils.c

OBJSDIR		= ./objs
OBJS 		= $(addprefix $(OBJSDIR)/, $(notdir $(SRCS:.c=.o)))


minilibx_DIR	= ./minilibx-linux
minilibx_A			= $(minilibx_DIR)/libmlx_Linux.a
#minilibx_A			= $(minilibx_DIR)/libmlx_Darwin.a
DEPENDS   		= $(OBJS:.o=.d)

LIBFT_DIR	= ./libft
LIBFT_A			= $(LIBFT_DIR)/libft.a
DEPENDS   		= $(OBJS:.o=.d)


CC 				= gcc
CFLAGS			= -Werror -Wall -Wextra -MMD -MP
CFLAGS_MLX		= -Imlx_linux
DEGUB_CFLAGS	= -g3 -fsanitize=address
RM				= /bin/rm -f
INCLUDES 		= -I./includes -I./minilibx-linux

CFLAGS += $(CFLAGS_MLX)

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS) $(minilibx_A)
	$(CC) $(CFLAGS) -o  $@  $(OBJS) $(INCLUDES) $(minilibx_A)  -L/usr/lib -Imlx_linux -lXext -lX11 -lm
#	$(CC) $(CFLAGS) -o  $@  $(OBJS) $(INCLUDES) $(minilibx_A)  -L/usr/X11R6/lib -lX11 -lXext -framework OpenGL -framework AppKit


$(OBJSDIR)/%.o: $(SRCSDIR)/%.c
	@mkdir -p $(OBJSDIR)
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES)

$(minilibx_A):
	make -C $(minilibx_DIR)

$(LIBFT_A):
	make -C $(LIBFT_DIR)

.PHONY:clean
clean:
	$(RM) $(OBJS)
	$(RM) $(LIBFT_OBJS)
	$(RM) $(DEPENDS)
	make -C $(minilibx_DIR) clean

.PHONY:fclean
fclean:clean
	$(RM) $(NAME)
#make -C $(LIBFT_DIR) fclean

.PHONY:re
re:fclean all

.PHONY: test
test: $(NAME)
	@mkdir -p ./tests/actual
	bash ./tests/main.sh

-include $(DEPENDS)
