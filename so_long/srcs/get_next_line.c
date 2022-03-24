#include "get_next_line.h"

static int	init(char **line, char **buff)
{
	*line = (char *)malloc(sizeof(char));
	if (*line == NULL)
		return (-1);
	*line[0] = '\0';
	*buff = (char *)malloc(BUFFER_SIZE + 1);
	if (*buff == NULL)
	{
		free(*line);
		return (-1);
	}
	return (1);
}

static size_t	ft_strindex(char *buff, char c)
{
	size_t	i;

	i = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == c)
			return (i);
		i++;
	}
	return (i);
}

static bool	ft_put_line(char **line, char **memo, char *buff)
{
	bool	is_continued;
	size_t	n_index;
	char	*tmp;

	n_index = ft_strindex(buff, '\n');
	tmp = ft_strnjoin(*line, buff, n_index);
	if (tmp == NULL)
		return (-1);
	free(*line);
	*line = tmp;
	tmp = NULL;
	is_continued = false;
	if (buff[n_index] == '\n')
	{
		tmp = ft_strdup(&buff[n_index + 1]);
		if (tmp == NULL)
			return (-1);
		is_continued = true;
	}
	free(*memo);
	*memo = tmp;
	tmp = NULL;
	return (is_continued);
}

static void	ft_free_buff(bool flag, char **buff, char **memo, char **line)
{
	free(*buff);
	*buff = NULL;
	if (flag == false)
	{
		free(*memo);
		*memo = NULL;
		free(*line);
		*line = NULL;
	}
}

int	get_next_line(int fd, char **line)
{
	static char	*memo[256];
	char		*buff;
	bool		is_continued;
	ssize_t		read_size;

	if (fd < 0 || 256 <= fd || line == NULL || BUFFER_SIZE <= 0
		|| init(line, &buff) == -1)
		return (-1);
	is_continued = false;
	if (memo[fd])
		is_continued = ft_put_line(line, &memo[fd], memo[fd]);
	read_size = 0;
	if (is_continued == 0)
		read_size = read(fd, buff, BUFFER_SIZE);
	while (read_size > 0 && is_continued == 0)
	{
		buff[read_size] = '\0';
		is_continued = ft_put_line(line, &memo[fd], buff);
		if (is_continued == 0)
			read_size = read(fd, buff, BUFFER_SIZE);
	}
	ft_free_buff(is_continued, &buff, &memo[fd], line);
	if (read_size == -1)
		return (-1);
	return (is_continued);
}
