/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 09:41:40 by takkatao          #+#    #+#             */
/*   Updated: 2021/10/10 09:13:00 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*ans;
	int		index;

	ans = (char *)calloc(12, sizeof(char));
	if (ans == NULL)
		return (NULL);
	index = 0;
	if (n < 0)
	{
		ans[index++] = '-';
		ft_strlcpy(&ans[index], ft_itoa(n / 10), 12 - index);
	}
	if (n > 9)
		ft_strlcpy(&ans[index + 1], ft_itoa(n / 10), 12 - index);
	ans[index] = ((n % 10) + '0');
	return (ans);
}
