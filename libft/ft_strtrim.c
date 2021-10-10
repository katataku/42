/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:42:06 by takkatao          #+#    #+#             */
/*   Updated: 2021/10/09 14:25:59 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int is_in(char c, char const *set)
{
	int	flag;
	int	i;

	if (set == NULL)
		return (FALSE);
	flag = FALSE;
	i = -1;
	while (set[++i] != '\0')
	{
		if (c == set[i])
			flag = TRUE;
	}
	return (flag);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	size;
	char	*ans;
	int		start;

	if (s1 == NULL)
		return (NULL);
	ans = ft_strdup(s1);
	if (ans != NULL )
	{
		start = 0;
		while (is_in(*(ans + start), set) && *(ans + start) != '\0')
			start++;
		size = ft_strlen(ans + start);
		while (is_in(*(ans + start + size - 1), set) && size > 0)
		{
			ans[start + size - 1] = '\0';
			size--;
		}
		ft_memmove(ans, s1 + start, size);
	}
	return (ans);
}