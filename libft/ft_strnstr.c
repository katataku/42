/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:47:31 by takkatao          #+#    #+#             */
/*   Updated: 2021/10/08 12:43:24 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		start;
	int		flag;

	i = 0;
	start = -1;
	if (needle[0] == '\0')
		return ((char *) haystack);
	while (TRUE)
	{
		flag = TRUE;
		i = -1;
		start += 1;
		while (needle[++i] != '\0')
			if (haystack[start + i] != needle[i])
				flag = FALSE;
		if (flag == TRUE && start + i <= len)
			return ((char *)(haystack + start));
		if (haystack[start] == '\0')
			break ;
	}
	return (NULL);
}
