/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:42:06 by takkatao          #+#    #+#             */
/*   Updated: 2021/11/01 10:14:11 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		i;
	char				*ans;

	if (f == NULL || s == NULL)
		return (NULL);
	ans = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (ans != NULL)
	{
		i = 0;
		while (s[i] != '\0')
		{
			ans[i] = f(i, s[i]);
			i++;
		}
	}
	return (ans);
}
