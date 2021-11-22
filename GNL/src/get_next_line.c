/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:08:11 by takkatao          #+#    #+#             */
/*   Updated: 2021/11/22 11:01:21 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

char	*get_next_line_core(int fd, size_t buffer_size)
{
	char				*ans;
	static t_gnl_status	status;

	ans = NULL;
	while (true)
	{
		if (status.buffer == NULL)
		{
			status.buffer = (char *)ft_calloc(sizeof(char), (buffer_size + 1));
			status.read_ret = read(fd, status.buffer, buffer_size);
			status.index = 0;
		}
		if (status.read_ret <= 0)
		{
			free(status.buffer);
			status.buffer = NULL;
			if (status.ans_work != NULL && status.read_ret == 0)
				ans = ft_strdup(status.ans_work);
			break ;
		}
		status.first_n = ft_strchr(&status.buffer[status.index], '\n');
		if (status.first_n != NULL)
		{
			*status.first_n = '\0';
			status.ans_work = ft_strjoin(status.ans_work, &status.buffer[status.index]);
			status.index = status.first_n - status.buffer + 1;
			ans = ft_strdup(status.ans_work);
			break ;
		}
		status.ans_work = ft_strjoin(status.ans_work, &status.buffer[status.index]);
		free(status.buffer);
		status.buffer = NULL;
	}
	free(status.ans_work);
	status.ans_work = NULL;
	return (ans);
}

char	*get_next_line(int fd)
{
	char	*ans;
	size_t	buffer_size;

	buffer_size = BUFFER_SIZE;
	ans = get_next_line_core(fd, buffer_size);
	return (ans);
}

/*
int main(void)
{
	get_next_line(0);
	return (0);
}
*/