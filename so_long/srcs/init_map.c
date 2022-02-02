#include "so_long.h"

void	count_map(t_vars *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->rows)
	{
		j = -1;
		while (++j < game->cols)
		{
			if (game->map[i][j] == ITEM)
				game->item_num++;
			if (game->map[i][j] == PLAYER)
			{
				game->player_num++;
				game->player_x = j;
				game->player_y = i;
				game->map[i][j] = FREE;
			}
			if (game->map[i][j] == GOAL)
				game->goal_num++;
		}
	}
}

void	get_map_size(t_vars *game)
{
	int		fd1;
	char	*receiver;
	int		column;
	int		ret;

	fd1 = xopen(game->map_filepath, O_RDONLY, game);
	receiver = NULL;
	game->rows = 0;
	game->cols = -1;
	ret = 1;
	while (ret == 1)
	{
		ret = xget_next_line(fd1, &receiver);
		if (ft_strlen(receiver) > 0)
		{
			column = ft_strlen(receiver);
			free(receiver);
			if (game->cols != -1 && game->cols != column)
				my_close(game, "Error: map is not rectangle\n");
			game->cols = column;
			game->rows++;
		}
	}
	xclose(fd1, game);
}

void	read_map_loop_handler(t_vars *game, char *receiver, int row, int column)
{
	if (receiver[column] == '0')
		game->map[row][column] = FREE;
	else if (receiver[column] == '1')
		game->map[row][column] = WALL;
	else if (receiver[column] == 'C')
		game->map[row][column] = ITEM;
	else if (receiver[column] == 'E')
		game->map[row][column] = GOAL;
	else if (receiver[column] == 'P')
		game->map[row][column] = PLAYER;
	else
		my_close(game, "Error: illegal charactor.\n");
	if (row == 0 || row == game->rows
		|| column == 0 || column == game->cols - 1)
	{
		if (game->map[row][column] != WALL)
			my_close(game, "Error: map is not surrounded WALLs\n");
	}
}

void	read_map(t_vars *game)
{
	int		fd2;
	char	*receiver;
	int		row;
	int		column;
	int		ret;

	fd2 = open(game->map_filepath, O_RDONLY);
	if (fd2 == -1)
		my_close(game, "error open file\n");
	row = 0;
	receiver = NULL;
	ret = 1;
	while (ret == 1)
	{
		ret = xget_next_line(fd2, &receiver);
		if (ft_strlen(receiver) > 0)
		{
			column = -1;
			while (receiver[++column] != '\0')
				read_map_loop_handler(game, receiver, row, column);
			row++;
		}
		free(receiver);
	}
	xclose(fd2, game);
}

void	check_map(t_vars *game)
{
	if (game->item_num <= 0)
		my_close(game, "Error: too few items\n");
	if (game->player_num != 1)
		my_close(game, "Error: player must be only one\n");
	if (game->goal_num <= 0)
		my_close(game, "Error: too many goals\n");
}
