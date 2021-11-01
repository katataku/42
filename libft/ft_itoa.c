/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 09:41:40 by takkatao          #+#    #+#             */
/*   Updated: 2021/11/01 11:22:58 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*join_and_free(char *s1, char *s2)
{
	char	*ans;

	ans = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (ans);
}

static char	*digit2str(char c)
{
	char	*ans;

	ans = (char *)ft_calloc(2, sizeof(char));
	if (ans == NULL)
		return (NULL);
	ans[0] = c + '0';
	return (ans);
}

char	*ft_itoa(int n)
{
	char	*ans;

	if (n == INT_MIN)
		return (join_and_free(ft_itoa(n / 10), digit2str((n % 10) * -1)));
	if (n < 0)
		return (join_and_free(ft_strdup("-"), ft_itoa(n * -1)));
	ans = (digit2str(n % 10));
	if (n > 9)
		ans = join_and_free(ft_itoa(n / 10), ans);
	return (ans);
}

/*
#include <stdio.h>
#include <assert.h> 

void	my_test(long long input)
{
	char	*a = ft_itoa((int)input);
//	char	*b = itoa((int)input);

	printf("%lld(as lld)\n", input);
	printf("%d:(as int)\n", (int)input);
	printf("  %s：ft_atoi\n", a);
	assert((int)input == atoi(a));
}

int	main(void)
{
	my_test(0);
	my_test(1);
	my_test(-1);
	my_test(8);
	my_test(127);
	my_test(128);
	my_test(129);

	my_test(254);
	my_test(255);
	my_test(256);

	my_test(2147483646);
	my_test(2147483647);//INT_MAX
	my_test(2147483648);

	my_test(4294967294);
	my_test(4294967295);//UNSIGNED INT_MAX
	my_test(4294967296);

	my_test(9223372036854775806);
	my_test(9223372036854775807);//LONG MAX
	my_test(9223372036854775808);

	my_test(18446744073709551614);
	my_test(18446744073709551615);//UNSIGNED LONG MAX
//	my_test(18446744073709551616);

	my_test( -2147483649);
	my_test( -2147483648);//INT_MIN
	my_test( -2147483647);

	my_test( -9223372036854775809);
	my_test( -9223372036854775808);//LONG NIN
	my_test( -9223372036854775807);
}
*/