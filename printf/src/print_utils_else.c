/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils_else.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 09:08:52 by takkatao          #+#    #+#             */
/*   Updated: 2021/11/19 09:13:49 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_percent(t_print_status *status, const char *format)
{
	ft_putchar_fd(format[status->index], 1);
	status->ret_len += 1;
}

void	print_uxX(t_print_status *status, const char *format)
{
	status->va_uint = va_arg(status->ap, unsigned int);
	if (format[status->index] == 'u')
		status->ret_len += ft_putnbr_base(status->va_uint, "0123456789");
	if (format[status->index] == 'x')
		status->ret_len += ft_putnbr_base(status->va_uint, "0123456789abcdef");
	if (format[status->index] == 'X')
		status->ret_len += ft_putnbr_base(status->va_uint, "0123456789ABCDEF");
}
