/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:08:11 by takkatao          #+#    #+#             */
/*   Updated: 2021/11/18 10:43:22 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

typedef struct s_print_status
{
	size_t		index;
	int			return_len;
}	t_print_status;

int	ft_printf(const char *format, ...)
{
	t_print_status	status;

	status.index = 0;
	status.return_len = 0;
	while (true)
	{
		if (format[status.index] == '\0')
			return (status.return_len);
		if (format[status.index] == '%' && format[status.index + 1] == '%')
			status.index++;
		ft_putchar_fd(format[status.index], 1);
		status.index++;
		status.return_len++;
	}
}
