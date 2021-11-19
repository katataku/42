/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils_cspd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 09:08:52 by takkatao          #+#    #+#             */
/*   Updated: 2021/11/19 09:13:46 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_c(t_print_status *status)
{
	status->va_char = va_arg(status->ap, int);
	ft_putchar_fd(status->va_char, 1);
	status->ret_len += 1;
}

void	print_s(t_print_status *status)
{
	const char	*str_null = "(null)";

	status->va_char_ptr = va_arg(status->ap, char *);
	if (status->va_char_ptr == NULL)
		status->va_char_ptr = (char *)str_null;
	ft_putstr_fd(status->va_char_ptr, 1);
	status->ret_len += ft_strlen(status->va_char_ptr);
}

void	print_p(t_print_status *status)
{
	status->va_ull = va_arg(status->ap, unsigned long long);
	ft_putstr_fd("0x", 1);
	status->ret_len += 2 + ft_putnbr_base(status->va_ull, "0123456789abcdef");
}

void	print_d(t_print_status *status)
{
	status->va_int = va_arg(status->ap, int);
	ft_putnbr_fd(status->va_int, 1);
	status->ret_len += count_digit(status->va_int);
}
