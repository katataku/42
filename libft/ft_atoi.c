/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 09:41:40 by takkatao          #+#    #+#             */
/*   Updated: 2021/10/08 11:20:35 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	get_next_to_space(char *str)
{
	long	i;
	long	flag;

	i = -1;
	flag = 1;
	while (flag)
	{
		i++;
		flag = 0;
		if (str[i] == '\t' || str[i] == '\n' || str[i] == '\v')
			flag = 1;
		if (str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
			flag = 1;
	}
	return (i);
}

int	ft_atoi(char *str)
{
	long			i;
	long			neg1_or_1;
	unsigned long	cnt;

	i = get_next_to_space(str);
	neg1_or_1 = 1;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg1_or_1 *= -1;
		i++;
	}
	cnt = 0;
	while (ft_isdigit(str[i]))
	{
		cnt *= 10;
		cnt += str[i] - '0';
		if (cnt > (unsigned long) LONG_MIN * -1 && neg1_or_1 == -1)
			return ((int) LONG_MIN);
		if (cnt > LONG_MAX && neg1_or_1 == 1)
			return ((int) LONG_MAX);
		i++;
	}
	return ((int)(cnt * neg1_or_1));
}
