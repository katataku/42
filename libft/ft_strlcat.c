/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 21:26:26 by takkatao          #+#    #+#             */
/*   Updated: 2021/11/03 23:41:33 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dest);
	if (i >= size)
		return (size + ft_strlen(src));
	j = 0;
	while (src[j] != '\0' && i + j < size - 1)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (i + ft_strlen(src));
}



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

	size_t	expect;
	size_t	actual;


	pid = fork();
	if (pid == 0)
	{
		expect = strlcat(dest1, src, size);
		exit(0);
	}
	else
	{
		wait_pid = wait(&status_expect);
	}

	pid = fork();
	if (pid == 0)
	{
		actual = ft_strlcat(dest2, src, size);
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
		expect = strlcat(dest1, src, size);
		actual = ft_strlcat(dest2, src, size);
		printf("  %zu：expect\n", expect);
		printf("  %zu：actual\n", actual);
		assert(expect==actual);
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
	my_test(NULL, NULL, src, size);

	dest1 = ft_strdup("Hello");
	dest2 = ft_strdup("Hello");
	my_test(dest1, dest2, src, 0);
}
