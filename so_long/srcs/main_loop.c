#include "so_long.h"

int	main_loop(t_vars *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->rows)
	{
		j = 0;
		while (j < game->cols)
		{
			if (i != game->player_y || j != game->player_x)
			{
				mlx_put_image_to_window(game->mlx, game->win,
					game->images[game->map[i][j]],
					TILE_SIZE * j, TILE_SIZE * i);
			}
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->images[PLAYER],
		TILE_SIZE * game->player_x, TILE_SIZE * game->player_y);
	return (0);
}
