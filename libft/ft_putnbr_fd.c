/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:46:16 by takkatao          #+#    #+#             */
/*   Updated: 2021/10/08 16:00:59 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	long	tmp;

	tmp = nb;
	if (tmp < 0)
	{
		ft_putchar_fd('-', fd);
		tmp *= -1;
	}
	if (tmp > 9)
		ft_putnbr_fd(tmp / 10, fd);
	tmp %= 10;
	ft_putchar_fd(tmp + '0', fd);
}
