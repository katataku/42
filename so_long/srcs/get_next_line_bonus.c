#include "get_next_line.h"

int	file_read(t_gnl_status *status, t_gnl_status_var *status_var)
{
	ssize_t	rc;

	if (status->buffer == NULL)
	{
		status->next_n = 0;
		status->buffer = (char *)malloc((size_t)BUFFER_SIZE + 1);
		if (status->buffer == NULL)
			return (-1);
		rc = read(status_var->fd, status->buffer, BUFFER_SIZE);
		if (rc <= 0)
		{
			free(status->buffer);
			status->buffer = NULL;
			if (rc == 0)
				return (0);
			return (-1);
		}
		status->buffer[rc] = '\0';
	}
	return (1);
}

int	organizer(t_gnl_status *st, t_gnl_status_var *status_var)
{
	char					*tmp;

	if (ft_strchr(&st->buffer[st->next_n], '\n'))
	{
		st->next_n = ft_strchr(&st->buffer[st->next_n], '\n') + 1 - st->buffer;
		if (st->next_n == BUFFER_SIZE)
		{
			free(st->buffer);
			st->buffer = NULL;
		}
		tmp = ft_strchr(status_var->ans, '\n') + 1;
		*tmp = '\0';
		return (0);
	}
	if (st->buffer[st->next_n] == '\0')
	{
		free(st->buffer);
		st->buffer = NULL;
		free(status_var->ans);
		status_var->ans = NULL;
		return (0);
	}
	return (1);
}

int	loop_handler(t_gnl_status *status, t_gnl_status_var *status_var)
{
	int		ret;
	char	*tmp;

	ret = file_read(status, status_var);
	if (ret < 0)
		return (-1);
	if (ret == 0)
		return (0);
	if (status_var->ans == NULL)
		status_var->ans = ft_strdup("");
	tmp = ft_strjoin(status_var->ans, &status->buffer[status->next_n]);
	if (tmp == NULL)
		return (-1);
	free(status_var->ans);
	status_var->ans = tmp;
	ret = organizer(status, status_var);
	if (ret == 0)
		return (0);
	free (status->buffer);
	status->buffer = NULL;
	return (1);
}

char	*get_next_line(int fd)
{
	static t_gnl_status		status_list[INT_MAX];
	static t_gnl_status		status;
	t_gnl_status_var		status_var;
	int						ret;

	status = status_list[fd];
	status_var.fd = fd;
	status_var.ans = NULL;
	while (true)
	{
		ret = loop_handler(&status, &status_var);
		if (ret < 0)
			break ;
		if (ret == 0)
			return (status_var.ans);
	}
	free(status.buffer);
	status.buffer = NULL;
	free(status_var.ans);
	status_var.ans = NULL;
	return (NULL);
}

/*
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int	index;//読み込み回数を確認する用
	//static int i;
	int	fd = open("test.txt", O_RDONLY);
	printf("fd = %d\n", fd);

	char	*receiver = NULL;
	index = 0;
	//printf("static=%d\n", i);//staticの初期値を調べている。デフォルトがある。
	while (1){
		receiver = get_next_line(fd);
		if (!receiver){
			printf("EOF or ERROR\n");
			break ;
		}
		printf("[%d]%s", index, receiver);
		index ++;
		free(receiver);
	}
	system("leaks a.out");
	close(fd);
}
*/