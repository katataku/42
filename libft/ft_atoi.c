/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 09:41:40 by takkatao          #+#    #+#             */
/*   Updated: 2021/10/30 17:28:11 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v')
		return (TRUE);
	if (c == '\f' || c == '\r' || c == ' ')
		return (TRUE);
	return (FALSE);
}

int	ft_atoi(const char *str)
{
	size_t			i;
	int				is_neg;
	unsigned long	cnt;
	unsigned long	pre;

	i = 0;
	while (is_space(str[i]))
		i++;
	if (!ft_isdigit(str[i]) && str[i] != '+' && str[i] != '-')
		return (0);
	is_neg = FALSE;
	if (!ft_isdigit(str[i]) && str[i++] == '-')
		is_neg = TRUE;
	cnt = 0;
	while (ft_isdigit(str[i]))
	{
		pre = cnt;
		cnt = (cnt * 10) + str[i++] - '0';
		if (!is_neg && (cnt > LONG_MAX || pre > cnt))
			return ((int) LONG_MAX);
		if (is_neg && (cnt > (unsigned long) LONG_MAX + 1 || pre > cnt))
			return ((int) LONG_MIN);
	}
	return ((int)(cnt * ((-2 * is_neg) + 1)));
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
}
*/