/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:42:06 by takkatao          #+#    #+#             */
/*   Updated: 2021/10/27 19:28:24 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*ans;

	if (s1 == NULL && s2 == NULL)
		return (ft_strdup(""));
	size = 0;
	if (s1 != NULL)
		size += (size_t)ft_strlen((char *)s1);
	if (s2 != NULL)
		size += (size_t)ft_strlen((char *)s2);
	ans = (char *)ft_calloc(sizeof(char), size + 1);
	if (ans != NULL)
	{
		if (s1 != NULL)
		{
			size = ft_strlen((char *)s1);
			ft_memcpy(ans, s1, size);
			if (s2 != NULL)
				ft_memcpy(ans + size, s2, ft_strlen((char *)s2));
		}
		else
			ft_memcpy(ans, s2, ft_strlen((char *)s2));
	}
	return (ans);
}
