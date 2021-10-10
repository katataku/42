/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:47:31 by takkatao          #+#    #+#             */
/*   Updated: 2021/10/10 17:19:41 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
static int	str_count(char const *s, char c)
{
	int	ans;
	int	index;

	ans = 0;
	index = -1;
	while (s[++index] != '\0')
	{
		if (s[index] == c)
			ans++;
	}
	return (ans);
}

char	**ft_split(char const *s, char c)
{
	char	**ans;
	int		start;
	int		end;
	int		i;

	if (s == NULL)
		return (NULL);
	ans = (char **)malloc(sizeof(char *) * str_count(s, c));
	if (ans != NULL)
	{
		i = -1;
		end = -1;
		while (end < ft_strlen((char *)s))
		{
			start = end;
			end = ft_strchr(s + start, c) - s ;
			if (start == end)
				end = start + 1 ;
			else
			{
				ans[++i] = ft_substr(s, start, end - start + 1);
				ans[i][end - start] = '\0';
			}
		}		
	}
	return (ans);
}
