/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:08:11 by takkatao          #+#    #+#             */
/*   Updated: 2021/11/19 05:31:55 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

typedef struct s_print_status
{
	size_t				index;
	int					ret_len;
	char				*va_char_ptr;
	int					va_char;
	unsigned int		va_unsigned_int;
	int					va_int;
	unsigned long long	va_ull;
	long long			va_long_long;
	void				*va_void_ptr;
	va_list				ap;

}	t_print_status;

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

static int	ft_putnbr_base(unsigned long long nbr, char *base)
{
	if (nbr == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	return (ft_putnbr_base_rec(nbr, base));
}

static int	count_digit(int n)
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

int	ft_printf(const char *format, ...)
{
	t_print_status	status;

	va_start(status.ap, format);
	status.index = 0;
	status.ret_len = 0;
	while (true)
	{
		if (format[status.index] == '\0')
			break ;
		if (format[status.index] == '%')
		{
			status.index++;
			if (format[status.index] == '%')
				ft_putchar_fd(format[status.index], 1);
			else if (format[status.index] == 'c')
			{
				status.va_char = va_arg(status.ap, int);
				ft_putchar_fd(status.va_char, 1);
			}
			else if (format[status.index] == 's')
			{
				status.va_char_ptr = va_arg(status.ap, char *);
				if (status.va_char_ptr == NULL)
					status.va_char_ptr = ft_strdup("(null)");
				ft_putstr_fd(status.va_char_ptr, 1);
				status.ret_len += ft_strlen(status.va_char_ptr) - 1;
			}
			else if (format[status.index] == 'p')
			{
				status.va_ull = va_arg(status.ap, unsigned long long);
				ft_putstr_fd("0x", 1);
				status.ret_len += 2 + ft_putnbr_base(status.va_ull, "0123456789abcdef") - 1;
			}
			else if (format[status.index] == 'd' || format[status.index] == 'i')
			{
				status.va_int = va_arg(status.ap, int);
				ft_putnbr_fd(status.va_int, 1);
				status.ret_len += count_digit(status.va_int) - 1;
			}
			else if (format[status.index] == 'u')
			{
				status.va_unsigned_int = va_arg(status.ap, unsigned int);
				status.ret_len += ft_putnbr_base(status.va_unsigned_int, "0123456789") - 1;
			}
			else if (format[status.index] == 'x')
			{
				status.va_unsigned_int = va_arg(status.ap, unsigned int);
				status.ret_len += ft_putnbr_base(status.va_unsigned_int, "0123456789abcdef") - 1;
			}
			else if (format[status.index] == 'X')
			{
				status.va_unsigned_int = va_arg(status.ap, unsigned int);
				status.ret_len += ft_putnbr_base(status.va_unsigned_int, "0123456789ABCDEF") - 1;
			}
			else
			{
				status.ret_len = 0;
				break ;
			}
		}
		else
			ft_putchar_fd(format[status.index], 1);
		status.index++;
		status.ret_len++;
	}
	va_end(status.ap);
	return (status.ret_len);
}
