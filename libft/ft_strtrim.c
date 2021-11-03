/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:42:06 by takkatao          #+#    #+#             */
/*   Updated: 2021/11/03 14:19:02 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	is_in(char c, char const *set)
{
	size_t	i;

	if (set == NULL)
		return (false);
	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (true);
		i++;
	}
	return (false);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	size;
	char	*ans;
	size_t	start;

	if (s1 == NULL)
		return (NULL);
	start = 0;
	while (is_in(*(s1 + start), set) && *(s1 + start) != '\0')
		start++;
	size = ft_strlen(s1 + start);
	while (size > 0 && is_in(*(s1 + start + size - 1), set))
		size--;
	ans = ft_substr(s1, start, size);
	return (ans);
}
