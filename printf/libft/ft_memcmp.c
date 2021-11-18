/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 12:45:23 by takkatao          #+#    #+#             */
/*   Updated: 2021/10/27 17:36:03 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *) s1;
	ptr2 = (unsigned char *) s2;
	i = 0;
	if (n == 0)
		return (0);
	while (ptr1[i] == ptr2[i])
		if (++i == n)
			return (0);
	return ((int)(ptr1[i] - ptr2[i]));
}

/*
#include <string.h>
#include <stdio.h>
#include <assert.h> 

void	my_test(const void *s1, const void *s2, size_t n)
{
	int	a = ft_memcmp(s1, s2, n);
	int	b = memcmp(s1, s2, n);

	printf("  %d：ft_memcmp\n", a);
	printf("  %d：memcmp\n", b);
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
