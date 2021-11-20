/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 17:22:42 by takkatao          #+#    #+#             */
/*   Updated: 2021/11/20 13:47:08 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"



#include <sys/types.h>
#include <unistd.h> 
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <assert.h> 

void	my_test_memmove(char *dest1, char *dest2,const char *src, size_t size)
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
	free(dest1);
	free(dest2);
}

int	testmain_memmove(void)
{
	char *dest1;
	char *dest2;
	const char *src = ft_strdup(" World");
	size_t	size = 6;

	dest1 = ft_strdup("Hello");
	dest2 = ft_strdup("Hello");
	my_test_memmove(dest1, dest2, src, size);

	dest1 = ft_strdup("Hello");
	dest2 = ft_strdup("Hello");
	my_test_memmove(dest1, dest2, NULL, size);


	dest1 = ft_strdup("Hello");
	dest2 = ft_strdup("Hello");
	my_test_memmove(dest1, dest2, NULL, 1);

	dest1 = ft_strdup("Hello");
	dest2 = ft_strdup("Hello");
	my_test_memmove(dest1, dest2, NULL, 0);

	my_test_memmove(NULL, NULL, src, size);
	my_test_memmove(NULL, NULL, src, 1);
	my_test_memmove(NULL, NULL, src, 0);


	my_test_memmove(NULL, NULL, NULL, size);
	my_test_memmove(NULL, NULL, NULL, 1);
	my_test_memmove(NULL, NULL, NULL, 0);

	free(src);
	return(0);
}

#include <stdio.h>
#include <assert.h> 

void	my_test_atoi(const char *input)
{
	int a = ft_atoi(input);
	int b = atoi(input);
	
	printf("%s\n", input);
	printf("  %d：ft_atoi\n", a);
	printf("  %d：atoi\n", b);
	assert(a == b);
}

int	testmain_atoi(void)
{
	my_test_atoi("0");
	my_test_atoi("1");
	my_test_atoi("-1");
	my_test_atoi("8");
	my_test_atoi("127");
	my_test_atoi("128");
	my_test_atoi("129");

	my_test_atoi("254");
	my_test_atoi("255");
	my_test_atoi("256");

	my_test_atoi("2147483646");
	my_test_atoi("2147483647");//INT_MAX
	my_test_atoi("2147483648");

	my_test_atoi("4294967294");
	my_test_atoi("4294967295");//UNSIGNED INT_MAX
	my_test_atoi("4294967296");

	my_test_atoi("9223372036854775806");
	my_test_atoi("9223372036854775807");//LONG MAX
	my_test_atoi("9223372036854775808");

	my_test_atoi("18446744073709551614");
	my_test_atoi("18446744073709551615");//UNSIGNED LONG MAX
	my_test_atoi("18446744073709551616");

	my_test_atoi(" -2147483649");
	my_test_atoi(" -2147483648");//INT_MIN
	my_test_atoi(" -2147483647");

	my_test_atoi(" -9223372036854775809");
	my_test_atoi(" -9223372036854775808");//LONG NIN
	my_test_atoi(" -9223372036854775807");

	my_test_atoi(" -922337203685477580009");
	my_test_atoi(" -922337203685477580008");//LONG NIN
	my_test_atoi(" -922337203685477580007");

	my_test_atoi(" 634106827633765826700");
	my_test_atoi(" 63410682763376582680");
	my_test_atoi(" 63410682763376582678");
	my_test_atoi(" 922337203685477580008");
	my_test_atoi(" 922337203685477580007");

	my_test_atoi(" -634106827633765826700");
	my_test_atoi(" -63410682763376582679");
	my_test_atoi(" -63410682763376582680");
	my_test_atoi(" -63410682763376582678");
	my_test_atoi(" -922337203685477580008");
	my_test_atoi(" -922337203685477580007");

	my_test_atoi("9223372036854775812");
	my_test_atoi("922337203685477570");
	my_test_atoi("922337203685477577");

	my_test_atoi("-9223372036854775807");
	my_test_atoi("-9223372036854775807");
	my_test_atoi("9223372036854775806");
	my_test_atoi("9223372036854775806");

	my_test_atoi("-2147483649");
	my_test_atoi("-2147483649");
	my_test_atoi("2147483648");
	my_test_atoi("2147483648");

    my_test_atoi("-2147483658");
    my_test_atoi("-2147483658");
    my_test_atoi("2147483657");
    my_test_atoi("2147483657");

	my_test_atoi("9223372036854775808");
	my_test_atoi("9223372036854775808");
	my_test_atoi("92233720368547758000");
	my_test_atoi("92233720368547758000");
	my_test_atoi("-9223372036854775809");
	my_test_atoi("-9223372036854775809");
	my_test_atoi("-92233720368547758000");
	my_test_atoi("-92233720368547758000");
	
	my_test_atoi("4772185884");
	my_test_atoi("9544371768");
	my_test_atoi("14316557653");
	return (0);
}

#include <stdio.h>
#include <assert.h> 

void	my_test_itoa(long long input)
{
	char	*a = ft_itoa((int)input);
//	char	*b = itoa((int)input);

	printf("%lld(as lld)\n", input);
	printf("%d:(as int)\n", (int)input);
	printf("  %s：ft_atoi\n", a);
	assert((int)input == atoi(a));
	free(a);
}

int	testmain_itoa(void)
{
	my_test_itoa(0);
	my_test_itoa(1);
	my_test_itoa(-1);
	my_test_itoa(8);
	my_test_itoa(127);
	my_test_itoa(128);
	my_test_itoa(129);

	my_test_itoa(254);
	my_test_itoa(255);
	my_test_itoa(256);

	my_test_itoa(2147483646);
	my_test_itoa(2147483647);//INT_MAX
	my_test_itoa(2147483648);

	my_test_itoa(4294967294);
	my_test_itoa(4294967295);//UNSIGNED INT_MAX
	my_test_itoa(4294967296);

	my_test_itoa(9223372036854775806);
	my_test_itoa(9223372036854775807);//LONG MAX
	my_test_itoa(9223372036854775808);

	my_test_itoa(18446744073709551614);
	my_test_itoa(18446744073709551615);//UNSIGNED LONG MAX
//	my_test(18446744073709551616);

	my_test_itoa( -2147483649);
	my_test_itoa( -2147483648);//INT_MIN
	my_test_itoa( -2147483647);

	my_test_itoa( -9223372036854775809);
	my_test_itoa( -9223372036854775808);//LONG NIN
	my_test_itoa( -9223372036854775807);
	return (0);
}

#include <string.h>
#include <xlocale.h>
#include <stdio.h>
#include <assert.h> 

void	print_and_free(char **a)
{
	int		i;

	if (a != NULL)
	{
		i = 0;
		while (a[i] != NULL)
		{
			printf("  %s\n",a[i]);
			free(a[i++]);
		}
	}
	free(a);
	printf("  ---free completed---\n");

}

int	testmain_split(void)
{
	char	**a;

	a = ft_split("hello world", ' ');
	assert(!strcmp(a[0], "hello"));
	assert(!strcmp(a[1], "world"));
	print_and_free(a);

	a = ft_split("abcdaba", 'a');
	assert(!strcmp(a[0], "bcd"));
	assert(!strcmp(a[1], "b"));
	print_and_free(a);

	a = ft_split("abcdaba", '\0');
	assert(!strcmp(a[0], "abcdaba"));
	print_and_free(a);

	a = ft_split("", 'a');
	assert(*a == NULL);
	print_and_free(a);

	a = ft_split(NULL, 'a');
	assert(*a == NULL);
	print_and_free(a);

	a = ft_split("      ", ' ');
	assert(*a == NULL);
	print_and_free(a);

	a = ft_split("\0aa\0bbb", '\0');
	assert(*a == NULL);
	print_and_free(a);


	return (0);
}


#include <sys/types.h>
#include <unistd.h> 
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <assert.h> 

void	my_test_strlcat(char *dest1, char *dest2,const char *src, size_t size)
{
	
	pid_t pid;
	pid_t wait_pid;
	int     status_expect = 0;
	int     status_actual = 0;

	size_t	expect;
	size_t	actual;

	printf("====test(%s,%s,%s,%zu)\n",dest1, dest2, src, size);
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
		assert(expect == actual);
	}
	else
	{
		printf(" Sig Abort \n");
		printf(" WTERMSIG:%d\n",WTERMSIG(status_actual));
	}
	free(dest1);
	free(dest2);
}

int	testmain_strlcat(void)
{

	char *dest1;
	char *dest2;
	const char *src = ft_strdup(" World");
	size_t	size = 6;

	dest1 = ft_strdup("Hello");
	dest2 = ft_strdup("Hello");
	my_test_strlcat(dest1, dest2, src, size);

	dest1 = ft_strdup("Hello");
	dest2 = ft_strdup("Hello");
	my_test_strlcat(dest1, dest2, NULL, size);

	dest1 = ft_strdup("Hello");
	dest2 = ft_strdup("Hello");
	my_test_strlcat(dest1, dest2, NULL, 1);// セグフォが起きるが正しい

	dest1 = ft_strdup("Hello");
	dest2 = ft_strdup("Hello");
	my_test_strlcat(dest1, dest2, NULL, 0);// セグフォが起きるが正しい

	my_test_strlcat(NULL, NULL, src, size);
	my_test_strlcat(NULL, NULL, src, 1);// セグフォが起きるが正しい
	my_test_strlcat(NULL, NULL, src, 0);// セグフォが起きないが正しい

	my_test_strlcat(NULL, NULL, NULL, size);
	my_test_strlcat(NULL, NULL, NULL, 1);// セグフォが起きるが正しい
	my_test_strlcat(NULL, NULL, NULL, 0);// セグフォが起きるが正しい
	free(src);
}


#include <sys/types.h>
#include <unistd.h> 
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <assert.h> 

void	my_test_strlcpy(char *dest1, char *dest2,char *src, size_t size)
{
	
	pid_t pid;
	pid_t wait_pid;
	int     status_expect = 0;
	int     status_actual = 0;

	size_t	expect;
	size_t	actual;

	printf("====test(%s,%s,%s,%zu)\n",dest1, dest2, src, size);
	pid = fork();
	if (pid == 0)
	{
		expect = strlcpy(dest1, src, size);
		exit(0);
	}
	else
	{
		wait_pid = wait(&status_expect);
	}

	pid = fork();
	if (pid == 0)
	{
		actual = ft_strlcpy(dest2, src, size);
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
		expect = strlcpy(dest1, src, size);
		actual = ft_strlcpy(dest2, src, size);
		printf("  %zu：expect\n", expect);
		printf("  %zu：actual\n", actual);
		assert(expect == actual);
	}
	else if(WIFSIGNALED(status_expect))
	{
		printf(" Sig Abort \n");
		assert(WTERMSIG(status_actual) == WTERMSIG(status_expect));
		printf(" WTERMSIG:%d\n",WTERMSIG(status_actual) );
	}
	free(dest1);
	free(dest2);
}

int	testmain_strlcpy(void)
{

	char *dest1;
	char *dest2;
	char *src = ft_strdup(" World");
	size_t	size = 6;

	dest1 = ft_strdup("Hello");
	dest2 = ft_strdup("Hello");
	my_test_strlcpy(dest1, dest2, src, size+100);

	dest1 = ft_strdup("Hello");
	dest2 = ft_strdup("Hello");
	my_test_strlcpy(dest1, dest2, src, size);


	dest1 = ft_strdup("Hello");
	dest2 = ft_strdup("Hello");
	my_test_strlcpy(dest1, dest2, src, 1);

	dest1 = ft_strdup("Hello");
	dest2 = ft_strdup("Hello");
	my_test_strlcpy(dest1, dest2, src, 0);

	dest1 = ft_strdup("");
	dest2 = ft_strdup("");
	my_test_strlcpy(dest1, dest2, src, size+100);

	dest1 = ft_strdup("");
	dest2 = ft_strdup("");
	my_test_strlcpy(dest1, dest2, src, size);


	dest1 = ft_strdup("");
	dest2 = ft_strdup("");
	my_test_strlcpy(dest1, dest2, src, 1);

	dest1 = ft_strdup("");
	dest2 = ft_strdup("");
	my_test_strlcpy(dest1, dest2, src, 0);

	dest1 = ft_strdup("Hello");
	dest2 = ft_strdup("Hello");
	my_test_strlcpy(dest1, dest2, NULL, size+100);

	dest1 = ft_strdup("Hello");
	dest2 = ft_strdup("Hello");
	my_test_strlcpy(dest1, dest2, NULL, size);

	dest1 = ft_strdup("Hello");
	dest2 = ft_strdup("Hello");
	my_test_strlcpy(dest1, dest2, NULL, 1);

	dest1 = ft_strdup("Hello");
	dest2 = ft_strdup("Hello");
	my_test_strlcpy(dest1, dest2, NULL, 0);

	my_test_strlcpy(NULL, NULL, src, size);
	my_test_strlcpy(NULL, NULL, src, 1);
	my_test_strlcpy(NULL, NULL, src, 0);

	my_test_strlcpy(NULL, NULL, NULL, size);
	my_test_strlcpy(NULL, NULL, NULL, 1);
	my_test_strlcpy(NULL, NULL, NULL, 0);
	free(src);
}


#include <string.h>
#include <xlocale.h>
#include <stdio.h>
#include <assert.h> 

void	my_test_strnstr(const char *haystack, const char *needle, size_t len)
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


int	testmain_strnstr(void)
{
	const char *s1 = ft_strdup("2");
	const char *s2 = ft_strdup("2");

	my_test_strnstr(s1,s2,3);
	my_test_strnstr(s1,s2,2);
	my_test_strnstr(s1,s2,1);
	my_test_strnstr(s1,s2,0);
	my_test_strnstr(s1,NULL,0);
	my_test_strnstr(NULL,s2,0);
	my_test_strnstr(NULL,NULL,0);
	my_test_strnstr(s1,NULL,1);
	my_test_strnstr(NULL,s2,1);
	my_test_strnstr(NULL,NULL,1);
	my_test_strnstr(s1,NULL,2);
	my_test_strnstr(NULL,s2,2);
	my_test_strnstr(NULL,NULL,2);
	my_test_strnstr(s1,NULL,3);
	my_test_strnstr(NULL,s2,3);
	my_test_strnstr(NULL,NULL,3);
	my_test_strnstr("abbbcdefg", "bbc", 1);
	my_test_strnstr("abbbcdefg", "bbc", 5);
	my_test_strnstr("abbbcdefg", "bbc", 100);
	my_test_strnstr("ab", "abcdefgh", 1);
	my_test_strnstr("ab", "abcdefgh", 5);
	my_test_strnstr("ab", "abcdefgh", 100);
	free(s1);
	free(s2);
}


int	main(void)
{
	testmain_atoi();
	testmain_itoa();
	testmain_memmove();
	testmain_split();
	testmain_strlcat();
	testmain_strlcpy();
	testmain_strnstr();

	system("leaks a.out");
	return (0);
}
