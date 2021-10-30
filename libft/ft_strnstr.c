/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:47:31 by takkatao          #+#    #+#             */
/*   Updated: 2021/10/30 00:14:45 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	start;
	int		flag;

	i = 0;
	start = -1;
	if (needle[0] == '\0')
		return ((char *) haystack);
	while (TRUE)
	{
		flag = TRUE;
		i = -1;
		start += 1;
		while (needle[++i] != '\0')
			if (haystack[start + i] != needle[i])
				flag = FALSE;
		if (flag == TRUE && start + i <= len)
			return ((char *)(haystack + start));
		if (haystack[start] == '\0')
			break ;
	}
	return (NULL);
}

/*
#include <string.h>
#include <xlocale.h>
#include <stdio.h>
#include <assert.h> 

void	my_test(const char *haystack, const char *needle, size_t len)
{
	char	*a = ft_strnstr(haystack, needle, len);
	char	*b = strnstr(haystack, needle, len);

	printf("  %s：ft_mstrnmp\n", a);
	printf("  %s：strncmp\n", b);
}

int	main(void)
{
	char *s1 = calloc(2,sizeof(char));
	char *s2 = calloc(2,sizeof(char));

	*s1='2';
	*s2='2';
	my_test(s1,s2,1);
	my_test(s1,s2,0);
//	my_test(s1,NULL,0);
	my_test(NULL,s2,0);
	my_test("abbbcdefg", "bbc", 20);
}
*/