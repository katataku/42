#include "so_long.h"

void	check_key_code(int key_code, t_vars *game)
{
	if (key_code == KEY_ESC)
		my_close(game, "");
	else if (key_code == KEY_W)
		game->player_y -= 1;
	else if (key_code == KEY_S)
		game->player_y += 1;
	else if (key_code == KEY_A)
		game->player_x -= 1;
	else if (key_code == KEY_D)
		game->player_x += 1;
	game->key_flag = 1;
}

int	deal_key(int key_code, t_vars *game)
{
	int	old_player_x;
	int	old_player_y;

	old_player_x = game->player_x;
	old_player_y = game->player_y;
	check_key_code(key_code, game);
	if (game->map[game->player_y][game->player_x] == WALL)
	{
		game->player_x = old_player_x;
		game->player_y = old_player_y;
	}
	if (game->player_x != old_player_x || game->player_y != old_player_y)
	{
		ft_putnbr_fd(++(game->step_count), 1);
		ft_putstr_fd("\n", 1);
	}
	if (game->map[game->player_y][game->player_x] == ITEM)
	{
		game->item_num--;
		game->map[game->player_y][game->player_x] = FREE;
	}
	if (game->map[game->player_y][game->player_x] == GOAL \
		&& game->item_num <= 0)
		my_close(game, "Congraturations!!\n");
	return (0);
}
