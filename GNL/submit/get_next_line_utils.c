/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 09:05:24 by takkatao          #+#    #+#             */
/*   Updated: 2021/11/22 11:48:25 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *buf, int ch, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *) buf;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char)ch;
		i++;
	}
	return (buf);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ans;
	size_t	malloc_size;

	malloc_size = count * size;
	if (malloc_size == 0)
		malloc_size = 1;
	if (count && size > SIZE_MAX / count)
		malloc_size = SIZE_MAX;
	ans = malloc(malloc_size);
	if (ans != NULL)
		ft_memset(ans, '\0', malloc_size);
	return (ans);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		if (i == size - 1 || src[i] == '\0')
		{
			dest[i] = '\0';
			return (ft_strlen(src));
		}
		i++;
	}
	return (ft_strlen(src));
}

char	*ft_strdup(const char *s1)
{
	size_t	size;
	char	*tmp;

	size = (ft_strlen(s1) + 1);
	tmp = (char *)malloc(size * sizeof(char));
	if (tmp != NULL)
		ft_strlcpy(tmp, (char *)s1, size);
	return (tmp);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*ans;

	if (s1 == NULL && s2 == NULL)
		return (ft_strdup(""));
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	ans = (char *)ft_calloc(sizeof(char), size);
	if (ans == NULL)
		return (NULL);
	ft_strlcpy(ans, (char *) s1, ft_strlen(s1) + 1);
	ft_strlcpy(ans + ft_strlen(s1), (char *) s2, size);
	return (ans);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != (char)c)
	{
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *) s + i);
}