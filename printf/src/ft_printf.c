/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:08:11 by takkatao          #+#    #+#             */
/*   Updated: 2021/11/18 11:37:37 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

typedef struct s_print_status
{
	size_t		index;
	int			return_len;
	char		*va_char_ptr;
	int			va_char;
	va_list		ap;

}	t_print_status;

int	ft_printf(const char *format, ...)
{
	t_print_status	status;

	va_start(status.ap, format);
	status.index = 0;
	status.return_len = 0;
	while (true)
	{
		if (format[status.index] == '\0')
			return (status.return_len);
		if (format[status.index] == '%')
		{
			status.index++;
			if (format[status.index] == '%')
				ft_putchar_fd(format[status.index], 1);
			else if (format[status.index] == 'd')
			{
				ft_putnbr_fd(va_arg(status.ap, int), 1);
			}
			else if (format[status.index] == 'c')
			{
				status.va_char = va_arg(status.ap, int);
				ft_putchar_fd(status.va_char, 1);
			}
			else if (format[status.index] == 's')
			{
				status.va_char_ptr = va_arg(status.ap, char *);
				ft_putstr_fd(status.va_char_ptr, 1);
				status.index++;
				status.return_len += ft_strlen(status.va_char_ptr);
				continue ;
			}
			else
				return (0);
		}
		else
			ft_putchar_fd(format[status.index], 1);
		status.index++;
		status.return_len++;
	}
	va_end(status.ap);
}
