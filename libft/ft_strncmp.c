/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 13:03:11 by takkatao          #+#    #+#             */
/*   Updated: 2021/10/27 17:42:46 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s1[i] == s2[i])
	{
		if (i == n - 1)
			return (0);
		i++;
	}
	return ((int)((unsigned char)s1[i] - (unsigned char)s2[i]));
}

/*
#include <string.h>
#include <stdio.h>
#include <assert.h> 

void	my_test(const void *s1, const void *s2, size_t n)
{
	int	a = ft_strncmp(s1, s2, n);
	int	b = strncmp(s1, s2, n);

	printf("  %d：ft_mstrnmp\n", a);
	printf("  %d：strncmp\n", b);
	assert(a == b);
}

int	main(void)
{
	char *s1 = calloc(2,sizeof(char));
	char *s2 = calloc(2,sizeof(char));

	*s1='\200';
	*s2='\0';
	my_test((const void*) s1,(const void*) s2,1);
}
*/