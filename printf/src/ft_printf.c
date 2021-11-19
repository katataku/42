/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:08:11 by takkatao          #+#    #+#             */
/*   Updated: 2021/11/19 09:12:51 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	loop_handler(t_print_status *status, const char *format)
{
	if (ft_strchr("cspdiuxX%", format[status->index]) == NULL \
		|| format[status->index] == '\0')
	{
		status->ret_len = 0;
		status->is_loop_continue = false;
		return ;
	}
	if (format[status->index] == '%')
		print_percent(status, format);
	if (format[status->index] == 'c')
		print_c(status);
	if (format[status->index] == 's')
		print_s(status);
	if (format[status->index] == 'p')
		print_p(status);
	if (ft_strchr("di", format[status->index]) != NULL)
		print_d(status);
	if (ft_strchr("uxX", format[status->index]) != NULL)
		print_uxX(status, format);
}

int	ft_printf(const char *format, ...)
{
	t_print_status	tmp;
	t_print_status	*status;

	status = &tmp;
	va_start(status->ap, format);
	status->index = -1;
	status->ret_len = 0;
	status->is_loop_continue = true;
	while (status->is_loop_continue && format[++(status->index)] != '\0')
	{
		if (format[status->index] != '%')
		{
			ft_putchar_fd(format[status->index], 1);
			status->ret_len++;
		}
		else
		{
			status->index++;
			loop_handler(status, format);
		}
	}
	va_end(status->ap);
	return (status->ret_len);
}
