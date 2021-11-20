/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:42:06 by takkatao          #+#    #+#             */
/*   Updated: 2021/11/04 09:15:14 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	size;

	if (s1 == NULL)
		return (NULL);
	start = 0;
	while (ft_strchr(set, *(s1 + start)) && *(s1 + start) != '\0')
		start++;
	size = ft_strlen(s1 + start);
	while (size > 0 && ft_strchr(set, *(s1 + start + size - 1)))
		size--;
	return (ft_substr(s1, start, size));
}
