/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 09:41:40 by takkatao          #+#    #+#             */
/*   Updated: 2022/01/02 17:12:34 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit (1);
}

static	bool	is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (true);
	return (false);
}

static long	add_safety(long a, long b)
{
	if ((a > 0) && (b > (INT_MAX - a)))
	{
		ft_putstr_fd("Error\n", 2);
		exit (1);
	}
	if ((a < 0) && (b < (INT_MIN - a)))
	{
		ft_putstr_fd("Error\n", 2);
		exit (1);
	}
	return (a + b);
}

static long	mul_safety(long a, long b)
{
	if ((a > 0) && (a > (INT_MAX / b)))
	{
		ft_putstr_fd("Error\n", 2);
		exit (1);
	}
	if ((a < 0) && (a < (INT_MIN / b)))
	{
		ft_putstr_fd("Error\n", 2);
		exit (1);
	}
	return (a * b);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	int		sign;
	long	cnt;

	i = 0;
	while (is_space(str[i]))
		i++;
	sign = 1;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	cnt = 0;
	while (ft_isdigit(str[i]))
	{
		cnt = mul_safety(cnt, 10);
		cnt = add_safety(cnt, (str[i++] - '0') * sign);
		if (sign == 1 && cnt == LONG_MAX)
			return ((int) LONG_MAX);
		if (sign == -1 && cnt == LONG_MIN)
			return ((int) LONG_MIN);
	}
	if (str[i] != '\0')
		error();
	return (cnt);
}

/*
#include <stdio.h>
#include <assert.h> 

void	my_test(const char *input)
{
	int a = ft_atoi(input);
	int b = atoi(input);
	
	printf("%s\n", input);
	printf("  %d：ft_atoi\n", a);
	printf("  %d：atoi\n", b);
	assert(a == b);
}

int	main(void)
{
	my_test("0");
	my_test("1");
	my_test("-1");
	my_test("8");
	my_test("127");
	my_test("128");
	my_test("129");

	my_test("254");
	my_test("255");
	my_test("256");

	my_test("2147483646");
	my_test("2147483647");//INT_MAX
	my_test("2147483648");

	my_test("4294967294");
	my_test("4294967295");//UNSIGNED INT_MAX
	my_test("4294967296");

	my_test("9223372036854775806");
	my_test("9223372036854775807");//LONG MAX
	my_test("9223372036854775808");

	my_test("18446744073709551614");
	my_test("18446744073709551615");//UNSIGNED LONG MAX
	my_test("18446744073709551616");

	my_test(" -2147483649");
	my_test(" -2147483648");//INT_MIN
	my_test(" -2147483647");

	my_test(" -9223372036854775809");
	my_test(" -9223372036854775808");//LONG NIN
	my_test(" -9223372036854775807");

	my_test(" -922337203685477580009");
	my_test(" -922337203685477580008");//LONG NIN
	my_test(" -922337203685477580007");

	my_test(" 634106827633765826700");
	my_test(" 63410682763376582680");
	my_test(" 63410682763376582678");
	my_test(" 922337203685477580008");
	my_test(" 922337203685477580007");

	my_test(" -634106827633765826700");
	my_test(" -63410682763376582679");
	my_test(" -63410682763376582680");
	my_test(" -63410682763376582678");
	my_test(" -922337203685477580008");
	my_test(" -922337203685477580007");

	my_test("9223372036854775812");
	my_test("922337203685477570");
	my_test("922337203685477577");

	my_test("-9223372036854775807");
	my_test("-9223372036854775807");
	my_test("9223372036854775806");
	my_test("9223372036854775806");

	my_test("-2147483649");
	my_test("-2147483649");
	my_test("2147483648");
	my_test("2147483648");

    my_test("-2147483658");
    my_test("-2147483658");
    my_test("2147483657");
    my_test("2147483657");

	my_test("9223372036854775808");
	my_test("9223372036854775808");
	my_test("92233720368547758000");
	my_test("92233720368547758000");
	my_test("-9223372036854775809");
	my_test("-9223372036854775809");
	my_test("-92233720368547758000");
	my_test("-92233720368547758000");

	my_test("4772185884");
	my_test("9544371768");
	my_test("14316557653");
}
*/