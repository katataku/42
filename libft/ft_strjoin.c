/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:42:06 by takkatao          #+#    #+#             */
/*   Updated: 2021/10/10 09:02:15 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*ans;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = ft_strlen((char *)s1);
	size += ft_strlen((char *)s2);
	ans = (char *)ft_calloc(sizeof(char), size);
	if (ans != NULL)
	{
		ft_memcpy(ans, s1, ft_strlen((char *)s1));
		ft_memcpy(ans + ft_strlen((char *)s1), s2, ft_strlen((char *)s2));
	}
	return (ans);
}
