/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:08:11 by takkatao          #+#    #+#             */
/*   Updated: 2021/11/18 19:46:22 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

typedef struct s_print_status
{
	size_t		index;
	int			return_len;
	char		*va_char_ptr;
	int			va_char;
	int			va_unsigned_int;
	int			va_int;
	unsigned long long va_unsigned_long_long;
	long long	va_long_long;
	void		*va_void_ptr;
	va_list		ap;

}	t_print_status;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static int	ft_putnbr_base_rec(unsigned long long nbr, char *base)
{
	unsigned long long		base_num;
	int		ans;

	ans = 0;
	base_num = ft_strlen(base);
	if (nbr > 0)
	{
		ans = ft_putnbr_base_rec(nbr / base_num, base);
		ft_putchar(base[nbr % base_num]);
		ans += 1;
	}
	return (ans);
}

int	ft_putnbr_base(unsigned long long nbr, char *base)
{
	if (nbr == 0)
	{
		ft_putchar('0');
		return (1);
	}
	return (ft_putnbr_base_rec(nbr, base));
}

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
			else if (format[status.index] == 'c')
			{
				status.va_char = va_arg(status.ap, int);
				ft_putchar_fd(status.va_char, 1);
			}
			else if (format[status.index] == 's')
			{
				status.va_char_ptr = va_arg(status.ap, char *);
				ft_putstr_fd(status.va_char_ptr, 1);
				status.return_len += ft_strlen(status.va_char_ptr) - 1;
			}
			else if (format[status.index] == 'p')
			{
				status.va_unsigned_long_long = va_arg(status.ap, unsigned long long);
				ft_putstr_fd("0x", 1);
				status.return_len += 2;
				status.return_len += ft_putnbr_base(status.va_unsigned_long_long, "0123456789abcdef") - 1;
			}
			else if (format[status.index] == 'd' || format[status.index] == 'i')
			{
				status.va_int = va_arg(status.ap, int);
				ft_putnbr_fd(status.va_int, 1);
				while (status.va_int != 0)
				{
					if (-10 < status.va_int && status.va_int < 0)
						status.va_int *= -1;
					else
						status.va_int /= 10;
					status.return_len += 1;
				}
				status.return_len -= 1;
			}
			else if (format[status.index] == 'u')
			{
				status.va_unsigned_int = va_arg(status.ap, unsigned int);
				status.return_len += ft_putnbr_base((unsigned int)status.va_unsigned_int, "0123456789") - 1;
			}
			else if (format[status.index] == 'x')
			{
				status.va_unsigned_int = va_arg(status.ap, unsigned int);
				status.return_len += ft_putnbr_base((unsigned int)status.va_unsigned_int, "0123456789abcdef") - 1;
			}
			else if (format[status.index] == 'X')
			{
				status.va_unsigned_int = va_arg(status.ap, unsigned int);
				status.return_len += ft_putnbr_base((unsigned int)status.va_unsigned_int, "0123456789ABCDEF") - 1;
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
