/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 22:04:59 by takkatao          #+#    #+#             */
/*   Updated: 2021/11/19 11:41:31 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//My Bool
# include "libft.h"
# include <stdarg.h>

typedef struct s_print_status
{
	size_t				index;
	int					ret_len;
	char				*va_char_ptr;
	int					va_char;
	unsigned int		va_uint;
	int					va_int;
	unsigned long long	va_ull;
	long long			va_long_long;
	void				*va_void_ptr;
	va_list				ap;
	bool				is_loop_continue;

}	t_print_status;

void	print_c(t_print_status *status);
void	print_s(t_print_status *status);
void	print_p(t_print_status *status);
void	print_d(t_print_status *status);
void	print_percent(t_print_status *status, const char *format);
void	print_uxX(t_print_status *status, const char *format);
int		ft_putnbr_base(unsigned long long nbr, char *base);
int		count_digit(int n);
int		ft_printf(const char *format, ...);

#endif
