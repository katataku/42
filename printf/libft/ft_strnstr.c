/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:47:31 by takkatao          #+#    #+#             */
/*   Updated: 2021/11/08 06:39:40 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t			start;
	const size_t	len_needle = ft_strlen(needle);

	start = -1;
	if (needle[0] == '\0')
		return ((char *) haystack);
	if (len == 0)
		return (0);
	while (true)
	{
		if (!ft_strncmp(&haystack[++start], needle, len_needle))
			return ((char *)(haystack + start));
		if (haystack[start] == '\0' || start + len_needle >= len)
			return (NULL);
	}
}

/*
#include <string.h>
#include <xlocale.h>
#include <stdio.h>
#include <assert.h> 

void	my_test(const char *haystack, const char *needle, size_t len)
{
	
	pid_t	pid;
	pid_t	wait_pid;
	int     status_expect = 0;
	int     status_actual = 0;
	char	*expect;
	char	*actual;

	printf("====test(%s,%s,%zu)\n",haystack, needle, len);
	pid = fork();
	if (pid == 0)
	{
		expect = strnstr(haystack, needle, len);
		exit(0);
	}
	else
	{
		wait_pid = wait(&status_expect);
	}

	pid = fork();
	if (pid == 0)
	{
		actual = ft_strnstr(haystack, needle, len);
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
		expect = strnstr(haystack, needle, len);
		actual = ft_strnstr(haystack, needle, len);
		printf("  %s：expect\n", expect);
		printf("  %s：actual\n", actual);
		if (expect == NULL &&  actual == NULL)
			return ;
		if (expect == NULL || actual == NULL)
			assert(0);
		assert(!strncmp(expect, actual,len));
	}
	else
	{
		printf(" Sig Abort \n");
		printf(" WTERMSIG:%d\n",WTERMSIG(status_actual));
	}
}


int	main(void)
{
	const char *s1 = ft_strdup("2");
	const char *s2 = ft_strdup("2");

	my_test(s1,s2,3);
	my_test(s1,s2,2);
	my_test(s1,s2,1);
	my_test(s1,s2,0);
	my_test(s1,NULL,0);
	my_test(NULL,s2,0);
	my_test(NULL,NULL,0);
	my_test(s1,NULL,1);
	my_test(NULL,s2,1);
	my_test(NULL,NULL,1);
	my_test(s1,NULL,2);
	my_test(NULL,s2,2);
	my_test(NULL,NULL,2);
	my_test(s1,NULL,3);
	my_test(NULL,s2,3);
	my_test(NULL,NULL,3);
	my_test("abbbcdefg", "bbc", 1);
	my_test("abbbcdefg", "bbc", 5);
	my_test("abbbcdefg", "bbc", 100);
	my_test("ab", "abcdefgh", 1);
	my_test("ab", "abcdefgh", 5);
	my_test("ab", "abcdefgh", 100);
	system("leaks a.out");
}
*/