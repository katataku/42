
#include <gtest/gtest.h>
#include <sys/types.h>
#include <unistd.h> 
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <assert.h> 

extern "C" size_t		ft_strlcpy(char *dest, char *src, size_t size);
extern "C" char			*ft_strdup(const char *s1);

	void	my_test(char *dest1, char *dest2,char *src, size_t size)
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
	}

	int	test_strlcpy(void)
	{

		char *dest1;
		char *dest2;
		char *src = ft_strdup(" World");
		size_t	size = 6;

		dest1 = ft_strdup("Hello");
		dest2 = ft_strdup("Hello");
		my_test(dest1, dest2, src, size+100);

		dest1 = ft_strdup("Hello");
		dest2 = ft_strdup("Hello");
		my_test(dest1, dest2, src, size);


		dest1 = ft_strdup("Hello");
		dest2 = ft_strdup("Hello");
		my_test(dest1, dest2, src, 1);

		dest1 = ft_strdup("Hello");
		dest2 = ft_strdup("Hello");
		my_test(dest1, dest2, src, 0);

		dest1 = ft_strdup("");
		dest2 = ft_strdup("");
		my_test(dest1, dest2, src, size+100);

		dest1 = ft_strdup("");
		dest2 = ft_strdup("");
		my_test(dest1, dest2, src, size);


		dest1 = ft_strdup("");
		dest2 = ft_strdup("");
		my_test(dest1, dest2, src, 1);

		dest1 = ft_strdup("");
		dest2 = ft_strdup("");
		my_test(dest1, dest2, src, 0);

		dest1 = ft_strdup("Hello");
		dest2 = ft_strdup("Hello");
		my_test(dest1, dest2, NULL, size+100);

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
		return (0);
	}

TEST(strlcpy,strlcpy)
{
	EXPECT_EQ(test_strlcpy(),0);
}