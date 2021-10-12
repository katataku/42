/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 09:41:40 by takkatao          #+#    #+#             */
/*   Updated: 2021/10/12 12:46:00 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*join_and_free(char *s1, char *s2)
{
	char	*ans;

	ans = ft_strjoin(s1, s2);
	if (s1 != NULL)
		free(s1);
	if (s2 != NULL)
		free(s2);
	return (ans);
}

static char	*char2str(char c)
{
	char	*ans;

	ans = (char *)ft_calloc(2, sizeof(char));
	if (ans == NULL)
		return (NULL);
	ans[0] = c;
	return (ans);
}

char	*ft_itoa(int n)
{
	char	*ans;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		return (join_and_free(ft_strdup("-"), ft_itoa(n * -1)));
	ans = (char2str((n % 10) + '0'));
	if (n > 9)
		ans = join_and_free(ft_itoa(n / 10), ans);
	return (ans);
}
