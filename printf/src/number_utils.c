/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 09:05:24 by takkatao          #+#    #+#             */
/*   Updated: 2021/11/19 09:05:29 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_putnbr_base_rec(unsigned long long nbr, char *base)
{
	size_t		base_num;
	int			ans;

	ans = 0;
	base_num = ft_strlen(base);
	if (nbr > 0)
	{
		ans = ft_putnbr_base_rec(nbr / base_num, base);
		ft_putchar_fd(base[nbr % base_num], 1);
		ans += 1;
	}
	return (ans);
}

int	ft_putnbr_base(unsigned long long nbr, char *base)
{
	if (nbr == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	return (ft_putnbr_base_rec(nbr, base));
}

int	count_digit(int n)
{
	int	cnt;

	if (n == 0)
		return (1);
	cnt = 0;
	while (n != 0)
	{
		if (-10 < n && n < 0)
			n *= -1;
		else
			n /= 10;
		cnt++;
	}
	return (cnt);
}
