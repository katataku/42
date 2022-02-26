#include "so_long.h"

int	my_close(t_vars *game, char *message)
{
	int	i;

	if (game->mlx)
	{
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		i = -1;
		while (++i < 5)
		{
			if (game->images[i])
				mlx_destroy_image(game->mlx, game->images[i]);
		}
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	i = -1;
	if (game->map)
	{
		while (game->map[++i])
			free(game->map[i]);
		free(game->map);
	}
	ft_putstr_fd(message, 1);
	free(game);
	exit(0);
}

int	simple_close(t_vars *game)
{
	my_close(game, "\n");
	exit(0);
}

void	register_hooks(t_vars *game)
{
	mlx_hook(game->win, X_EVENT_KEY_PRESS, 1, &deal_key, game);
	mlx_hook(game->win, X_EVENT_KEY_EXIT, 1, &simple_close, game);
	mlx_loop_hook(game->mlx, &main_loop, game);
	mlx_loop(game->mlx);
}

int	is_valid_arg(int argc, char **argv)
{
	int	len;

	if (argc != 2)
		return (0);
	len = ft_strlen(argv[1]);
	if (len < 4)
		return (0);
	if (argv[1][len - 4] == '.' && argv[1][len - 3] == 'b' \
		&& argv[1][len - 2] == 'e' && argv[1][len - 1] == 'r')
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	*game;
	int		i;

	game = (t_vars *)ft_xcalloc(sizeof(t_vars), 1);
	if (is_valid_arg(argc, argv) != 1)
		my_close(game, "illegal arguments\n");
	game->map_filepath = argv[1];
	game->key_flag = 1;
	get_map_size(game);
	game->map = (int **)ft_xcalloc(sizeof(int *), game->rows + 1);
	i = 0;
	while (i < game->rows)
	{
		game->map[i] = (int *)ft_xcalloc(sizeof(int), game->cols + 1);
		i++;
	}
	read_map(game);
	count_map(game);
	check_map(game);
	make_window(game);
	init_images(game);
	register_hooks(game);
}
