#include "so_long.h"

void	make_window(t_vars *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		my_close(game, "malloc error");
	game->win = mlx_new_window(game->mlx, game->cols * TILE_SIZE,
			game->rows * TILE_SIZE, "so_long");
	if (game->win == NULL)
		my_close(game, "malloc error");
}

void	init_images(t_vars *game)
{
	int	img_width;
	int	img_height;
	int	i;

	game->images[GOAL] = mlx_xpm_file_to_image(game->mlx, GOAL_PATH,
			&img_width, &img_height);
	game->images[WALL] = mlx_xpm_file_to_image(game->mlx, WALL_PATH,
			&img_width, &img_height);
	game->images[ITEM] = mlx_xpm_file_to_image(game->mlx, ITEM_PATH,
			&img_width, &img_height);
	game->images[PLAYER] = mlx_xpm_file_to_image(game->mlx, PLAYER_PATH,
			&img_width, &img_height);
	game->images[FREE] = mlx_xpm_file_to_image(game->mlx, FREE_PATH,
			&img_width, &img_height);
	i = 0;
	while (i < E_IMAGE_COUNT)
	{
		if (game->images[i] == NULL)
			my_close(game, "image load error");
		i++;
	}
}
