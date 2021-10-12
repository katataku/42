/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:42:06 by takkatao          #+#    #+#             */
/*   Updated: 2021/10/12 15:51:57 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in(char c, char const *set)
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
	start = 0;
	while (is_in(*(s1 + start), set) && *(s1 + start) != '\0')
		start++;
	size = ft_strlen((char *)s1 + start);
	while (size > 0 && is_in(*(s1 + start + size - 1), set))
		size--;
	ans = ft_substr(s1, start, size);
	return (ans);
}
