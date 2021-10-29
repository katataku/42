/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:45:53 by takkatao          #+#    #+#             */
/*   Updated: 2021/10/29 11:49:32 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;

	if (s == NULL)
		return (NULL);
	ptr = (char *)s;
	if (start > (unsigned int) ft_strlen(ptr))
		return (ft_strdup(""));
	if (len > ft_strlen(ptr + start))
		len = ft_strlen(ptr + start);
	ptr = (char *)ft_calloc(sizeof(char), (len + 1));
	if (ptr != NULL)
		ft_strlcpy(ptr, (char *)s + start, len + 1);
	return (ptr);
}
