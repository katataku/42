#include "so_long.h"

void	get_row_size(t_vars *game)
{
	int		fd;
	char	*receiver;
	int		ret;

	fd = xopen(game->map_filepath, O_RDONLY, game);
	receiver = NULL;
	game->rows = 0;
	ret = 1;
	while (ret == 1)
	{
		ret = xget_next_line(fd, &receiver);
		if (ft_strlen(receiver) > 0)
			game->rows++;
		free(receiver);
	}
	xclose(fd, game);
}

void	get_column_size(t_vars *game)
{
	int		fd;
	char	*receiver;
	int		ret;

	fd = xopen(game->map_filepath, O_RDONLY, game);
	receiver = NULL;
	game->cols = -1;
	ret = 1;
	while (ret == 1)
	{
		ret = xget_next_line(fd, &receiver);
		if (ft_strlen(receiver) > 0)
			game->cols = ft_strlen(receiver);
		free(receiver);
	}
	xclose(fd, game);
}

void	check_is_rectangle(t_vars *game)
{
	int		fd;
	char	*receiver;
	int		column;

	fd = xopen(game->map_filepath, O_RDONLY, game);
	receiver = NULL;
	while (xget_next_line(fd, &receiver) != 0)
	{
		column = ft_strlen(receiver);
		if (game->cols != column)
			my_close(game, "Error: map is not rectangle\n");
		free(receiver);
	}
	free(receiver);
	xclose(fd, game);
}

void	get_map_size(t_vars *game)
{
	get_row_size(game);
	get_column_size(game);
	check_is_rectangle(game);
}
