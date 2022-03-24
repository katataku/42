/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:52:12 by takkatao          #+#    #+#             */
/*   Updated: 2022/02/25 17:10:14 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_xcalloc(size_t count, size_t size)
{
	char	*tmp;

	tmp = ft_calloc(count, size);
	if (tmp == NULL)
	{
		perror("malloc error");
		exit(1);
	}
	return (tmp);
}

int	xget_next_line(int fd, char **line)
{
	int	tmp;

	tmp = get_next_line(fd, line);
	if (tmp == -1)
	{
		perror("read error");
		exit(1);
	}
	return (tmp);
}

int	xopen(const char *filename, int flag, t_vars *game)
{
	int	fd;

	fd = open(filename, flag);
	if (fd == -1)
		my_close(game, "error open file\n");
	return (fd);
}

void	xclose(int fd, t_vars *game)
{
	if (close(fd) == -1)
		my_close(game, "close error\n");
}
