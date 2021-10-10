/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:45:53 by takkatao          #+#    #+#             */
/*   Updated: 2021/10/09 14:55:05 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	size;
	char	*tmp;
	char	*s1_cp;

	s1_cp = (char *)s1;
	size = sizeof(char) * (ft_strlen(s1_cp) + 1);
	tmp = (char *)malloc(size);
	if (tmp != NULL)
		ft_memcpy(tmp, s1, size);
	return (tmp);
}
