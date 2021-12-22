/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:45:53 by takkatao          #+#    #+#             */
/*   Updated: 2021/11/05 14:24:44 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	if (dst == src || n == 0 )
		return (dst);
	while (src < dst && dst <= src + n)
	{
		ft_memcpy(dst + n - 1, src + n - 1, 1);
		n--;
	}
	ft_memcpy(dst, src, n);
	return (dst);
}

/*
#include <sys/types.h>
#include <unistd.h> 
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <assert.h> 

void	my_test(char *dest1, char *dest2,const char *src, size_t size)
{
	
	pid_t pid;
	pid_t wait_pid;
	int     status_expect = 0;
	int     status_actual = 0;

	char*	expect;
	char*	actual;

	printf("====test(%s,%s,%s,%zu)\n",dest1, dest2, src, size);
	pid = fork();
	if (pid == 0)
	{
		memmove(dest1, src, size);
		exit(0);
	}
	else
	{
		wait_pid = wait(&status_expect);
	}

	pid = fork();
	if (pid == 0)
	{
		ft_memmove(dest2, src, size);
		exit(0);
	}
	else
	{
		wait_pid = wait(&status_actual);
	}

	assert(WIFEXITED(status_expect) == WIFEXITED(status_actual));
	assert(WIFSIGNALED(status_expect) == WIFSIGNALED(status_actual));
	if (WIFEXITED(status_expect))
	{
		if (dest1 == NULL && dest2 == NULL)
		{
			printf("  Returned NULL \n");	
			assert(dest1 == dest2);
		}
		else
		{
			memmove(dest1, src, size);
			ft_memmove(dest2, src, size);
			printf("  %s：expect\n", dest1);
			printf("  %s：actual\n", dest2);
			assert(!strncmp(dest1, dest2, size));
		}
	}
	else
	{
		printf("  Sig Abort \n");
		printf("  WTERMSIG:%d\n",WTERMSIG(status_actual));
	}
}

int	main(void)
{
	char *dest1;
	char *dest2;
	const char *src = ft_strdup(" World");
	size_t	size = 6;

	dest1 = ft_strdup("Hello");
	dest2 = ft_strdup("Hello");
	my_test(dest1, dest2, src, size);

	dest1 = ft_strdup("Hello");
	dest2 = ft_strdup("Hello");
	my_test(dest1, dest2, NULL, size);

	dest1 = ft_strdup("Hello");
	dest2 = ft_strdup("Hello");
	my_test(dest1, dest2, NULL, 1);

	dest1 = ft_strdup("Hello");
	dest2 = ft_strdup("Hello");
	my_test(dest1, dest2, NULL, 0);

	my_test(NULL, NULL, src, size);
	my_test(NULL, NULL, src, 1);
	my_test(NULL, NULL, src, 0);


	my_test(NULL, NULL, NULL, size);
	my_test(NULL, NULL, NULL, 1);
	my_test(NULL, NULL, NULL, 0);
}
*/