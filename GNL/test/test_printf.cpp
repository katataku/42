#include <gtest/gtest.h>
#include <gtest/internal/gtest-port.h>
#include <sys/types.h>
#include <unistd.h> 
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <assert.h> 

extern "C" int	ft_printf(const char *format, ...);

typedef struct s_behavior
{
	const char   *stdout;
	int			return_value;
}	t_behavior;


TEST(test_dry_run, DISABLED_always_true)
{
	const char *expect_stdout;
	const char *actual_stdout;

	testing::internal::CaptureStdout();
	printf("1");
	actual_stdout = testing::internal::GetCapturedStdout().c_str();
	testing::internal::CaptureStdout();
	printf("1");
	expect_stdout = testing::internal::GetCapturedStdout().c_str();

	EXPECT_STREQ(actual_stdout,expect_stdout);
}

//1
TEST(test_printf, 1)
{
	const char *expect_stdout;
	const char *actual_stdout;
	int expect_return_value;
	int actual_return_value;

	testing::internal::CaptureStdout();
	actual_return_value = ft_printf("1");
	actual_stdout = testing::internal::GetCapturedStdout().c_str();
	testing::internal::CaptureStdout();
	expect_return_value = printf("1");
	expect_stdout = testing::internal::GetCapturedStdout().c_str();

	EXPECT_STREQ(actual_stdout,expect_stdout);
	EXPECT_EQ(actual_return_value,expect_return_value);
}

//11
TEST(test_printf, 2)
{
	const char *expect_stdout;
	const char *actual_stdout;
	int expect_return_value;
	int actual_return_value;

	testing::internal::CaptureStdout();
	actual_return_value = ft_printf("11");
	actual_stdout = testing::internal::GetCapturedStdout().c_str();
	testing::internal::CaptureStdout();
	expect_return_value = printf("11");
	expect_stdout = testing::internal::GetCapturedStdout().c_str();

	EXPECT_STREQ(actual_stdout,expect_stdout);
	EXPECT_EQ(actual_return_value,expect_return_value);
}

//aaa%%
TEST(test_printf, 3)
{
	const char *expect_stdout;
	const char *actual_stdout;
	int expect_return_value;
	int actual_return_value;

	testing::internal::CaptureStdout();
	actual_return_value = ft_printf("aaa%%");
	actual_stdout = testing::internal::GetCapturedStdout().c_str();
	testing::internal::CaptureStdout();
	expect_return_value = printf("aaa%%");
	expect_stdout = testing::internal::GetCapturedStdout().c_str();

	EXPECT_STREQ(actual_stdout,expect_stdout);
	EXPECT_EQ(actual_return_value,expect_return_value);
}

//aaa%d 5
TEST(test_printf, d_1)
{
	const char *expect_stdout;
	const char *actual_stdout;
	int expect_return_value;
	int actual_return_value;

	testing::internal::CaptureStdout();
	actual_return_value = ft_printf("aaa%d", 5);
	actual_stdout = testing::internal::GetCapturedStdout().c_str();

	testing::internal::CaptureStdout();
	expect_return_value = printf("aaa%d", 5);
	expect_stdout = testing::internal::GetCapturedStdout().c_str();

	EXPECT_STREQ(actual_stdout,expect_stdout);
	EXPECT_EQ(actual_return_value,expect_return_value);
}

//aaa%daa%d,5,5
TEST(test_printf, d_2)
{
	const char *expect_stdout;
	const char *actual_stdout;
	int expect_return_value;
	int actual_return_value;

	testing::internal::CaptureStdout();
	actual_return_value = ft_printf("aaa%daa%d",5,5);
	actual_stdout = testing::internal::GetCapturedStdout().c_str();
	
	testing::internal::CaptureStdout();
	expect_return_value = printf("aaa%daa%d",5,5);
	expect_stdout = testing::internal::GetCapturedStdout().c_str();

	EXPECT_STREQ(actual_stdout,expect_stdout);
	EXPECT_EQ(actual_return_value,expect_return_value);
}

//aaa%d 0
TEST(test_printf, d_3)
{
	const char *expect_stdout;
	const char *actual_stdout;
	int expect_return_value;
	int actual_return_value;

	testing::internal::CaptureStdout();
	actual_return_value = ft_printf("aaa%d", 0);
	actual_stdout = testing::internal::GetCapturedStdout().c_str();
	
	testing::internal::CaptureStdout();
	expect_return_value = printf("aaa%d", 0);
	expect_stdout = testing::internal::GetCapturedStdout().c_str();

	EXPECT_STREQ(actual_stdout,expect_stdout);
	EXPECT_EQ(actual_return_value,expect_return_value);
}


//"aaa%s","bbb"
TEST(test_printf, s_1)
{
	const char *expect_stdout;
	const char *actual_stdout;
	int expect_return_value;
	int actual_return_value;

	testing::internal::CaptureStdout();
	actual_return_value = ft_printf("aaa%s","bbb");
	actual_stdout = testing::internal::GetCapturedStdout().c_str();
	
	testing::internal::CaptureStdout();
	expect_return_value = printf("aaa%s","bbb");
	expect_stdout = testing::internal::GetCapturedStdout().c_str();

	EXPECT_STREQ(actual_stdout,expect_stdout);
	EXPECT_EQ(actual_return_value,expect_return_value);
}

//"aaa%sccc%s","bbb","ddd"
TEST(test_printf, s_2)
{
	const char *expect_stdout;
	const char *actual_stdout;
	int expect_return_value;
	int actual_return_value;

	testing::internal::CaptureStdout();
	actual_return_value = ft_printf("aaa%sccc%s","bbb","ddd");
	actual_stdout = testing::internal::GetCapturedStdout().c_str();
	
	testing::internal::CaptureStdout();
	expect_return_value = printf("aaa%sccc%s","bbb","ddd");
	expect_stdout = testing::internal::GetCapturedStdout().c_str();

	EXPECT_STREQ(actual_stdout,expect_stdout);
	EXPECT_EQ(actual_return_value,expect_return_value);
}


TEST(test_printf, s_3)
{
	const char *expect_stdout;
	const char *actual_stdout;
	int expect_return_value;
	int actual_return_value;

	testing::internal::CaptureStdout();
	actual_return_value = ft_printf("%s","hello world");
	actual_stdout = testing::internal::GetCapturedStdout().c_str();
	
	testing::internal::CaptureStdout();
	expect_return_value = printf("%s","hello world");
	expect_stdout = testing::internal::GetCapturedStdout().c_str();

	EXPECT_STREQ(actual_stdout,expect_stdout);
	EXPECT_EQ(actual_return_value,expect_return_value);
}

TEST(test_printf, s_4)
{
	const char *expect_stdout;
	const char *actual_stdout;
	int expect_return_value;
	int actual_return_value;

	testing::internal::CaptureStdout();
	actual_return_value = ft_printf("%s","");
	actual_stdout = testing::internal::GetCapturedStdout().c_str();
	
	testing::internal::CaptureStdout();
	expect_return_value = printf("%s","");
	expect_stdout = testing::internal::GetCapturedStdout().c_str();

	EXPECT_STREQ(actual_stdout,expect_stdout);
	EXPECT_EQ(actual_return_value,expect_return_value);
}

TEST(test_printf, s_5)
{
	const char *expect_stdout;
	const char *actual_stdout;
	int expect_return_value;
	int actual_return_value;
	char *null_str = NULL;

	testing::internal::CaptureStdout();
	actual_return_value = ft_printf("%s",null_str);
	actual_stdout = testing::internal::GetCapturedStdout().c_str();
	
	testing::internal::CaptureStdout();
	expect_return_value = printf("%s",null_str);
	expect_stdout = testing::internal::GetCapturedStdout().c_str();

	EXPECT_STREQ(actual_stdout,expect_stdout);
	EXPECT_EQ(actual_return_value,expect_return_value);
}


//"aaa%c",'a'
TEST(test_printf, c_1)
{
	const char *expect_stdout;
	const char *actual_stdout;
	int expect_return_value;
	int actual_return_value;

	testing::internal::CaptureStdout();
	actual_return_value = ft_printf("aaa%c",'a');
	actual_stdout = testing::internal::GetCapturedStdout().c_str();
	
	testing::internal::CaptureStdout();
	expect_return_value = printf("aaa%c",'a');
	expect_stdout = testing::internal::GetCapturedStdout().c_str();

	EXPECT_STREQ(actual_stdout,expect_stdout);
	EXPECT_EQ(actual_return_value,expect_return_value);
}

//aaa%i 5
TEST(test_printf, 9)
{
	const char *expect_stdout;
	const char *actual_stdout;
	int expect_return_value;
	int actual_return_value;

	testing::internal::CaptureStdout();
	actual_return_value = ft_printf("aaa%i", 5);
	actual_stdout = testing::internal::GetCapturedStdout().c_str();

	testing::internal::CaptureStdout();
	expect_return_value = printf("aaa%i", 5);
	expect_stdout = testing::internal::GetCapturedStdout().c_str();

	EXPECT_STREQ(actual_stdout,expect_stdout);
	EXPECT_EQ(actual_return_value,expect_return_value);
}

//aaa%iaa%i,5,5
TEST(test_printf, 10)
{
	const char *expect_stdout;
	const char *actual_stdout;
	int expect_return_value;
	int actual_return_value;

	testing::internal::CaptureStdout();
	actual_return_value = ft_printf("aaa%iaa%i",5,5);
	actual_stdout = testing::internal::GetCapturedStdout().c_str();
	
	testing::internal::CaptureStdout();
	expect_return_value = printf("aaa%iaa%i",5,5);
	expect_stdout = testing::internal::GetCapturedStdout().c_str();

	EXPECT_STREQ(actual_stdout,expect_stdout);
	EXPECT_EQ(actual_return_value,expect_return_value);
}

//("%x",)
TEST(test_printf, 11)
{
	const char *expect_stdout;
	const char *actual_stdout;
	int expect_return_value;
	int actual_return_value;

	testing::internal::CaptureStdout();
	actual_return_value = ft_printf("aaa%x",127);
	actual_stdout = testing::internal::GetCapturedStdout().c_str();
	
	testing::internal::CaptureStdout();
	expect_return_value = printf("aaa%x",127);
	expect_stdout = testing::internal::GetCapturedStdout().c_str();

	EXPECT_STREQ(actual_stdout,expect_stdout);
	EXPECT_EQ(actual_return_value,expect_return_value);
}

//("%x",)
TEST(test_printf, 12)
{
	const char *expect_stdout;
	const char *actual_stdout;
	int expect_return_value;
	int actual_return_value;

	testing::internal::CaptureStdout();
	actual_return_value = ft_printf("aaa%x",0);
	actual_stdout = testing::internal::GetCapturedStdout().c_str();
	
	testing::internal::CaptureStdout();
	expect_return_value = printf("aaa%x",0);
	expect_stdout = testing::internal::GetCapturedStdout().c_str();

	EXPECT_STREQ(actual_stdout,expect_stdout);
	EXPECT_EQ(actual_return_value,expect_return_value);
}

//("%x",)
TEST(test_printf, 13)
{
	const char *expect_stdout;
	const char *actual_stdout;
	int expect_return_value;
	int actual_return_value;

	testing::internal::CaptureStdout();
	actual_return_value = ft_printf("aaa%x",9999);
	actual_stdout = testing::internal::GetCapturedStdout().c_str();
	
	testing::internal::CaptureStdout();
	expect_return_value = printf("aaa%x",9999);
	expect_stdout = testing::internal::GetCapturedStdout().c_str();

	EXPECT_STREQ(actual_stdout,expect_stdout);
	EXPECT_EQ(actual_return_value,expect_return_value);
}



//("%X",)
TEST(test_printf, 14)
{
	const char *expect_stdout;
	const char *actual_stdout;
	int expect_return_value;
	int actual_return_value;

	testing::internal::CaptureStdout();
	actual_return_value = ft_printf("aaa%X",127);
	actual_stdout = testing::internal::GetCapturedStdout().c_str();
	
	testing::internal::CaptureStdout();
	expect_return_value = printf("aaa%X",127);
	expect_stdout = testing::internal::GetCapturedStdout().c_str();

	EXPECT_STREQ(actual_stdout,expect_stdout);
	EXPECT_EQ(actual_return_value,expect_return_value);
}

//("%X",)
TEST(test_printf, 15)
{
	const char *expect_stdout;
	const char *actual_stdout;
	int expect_return_value;
	int actual_return_value;

	testing::internal::CaptureStdout();
	actual_return_value = ft_printf("aaa%X",0);
	actual_stdout = testing::internal::GetCapturedStdout().c_str();
	
	testing::internal::CaptureStdout();
	expect_return_value = printf("aaa%X",0);
	expect_stdout = testing::internal::GetCapturedStdout().c_str();

	EXPECT_STREQ(actual_stdout,expect_stdout);
	EXPECT_EQ(actual_return_value,expect_return_value);
}

//("%X",)
TEST(test_printf, 16)
{
	const char *expect_stdout;
	const char *actual_stdout;
	int expect_return_value;
	int actual_return_value;

	testing::internal::CaptureStdout();
	actual_return_value = ft_printf("aaa%X",9999);
	actual_stdout = testing::internal::GetCapturedStdout().c_str();
	
	testing::internal::CaptureStdout();
	expect_return_value = printf("aaa%X",9999);
	expect_stdout = testing::internal::GetCapturedStdout().c_str();

	EXPECT_STREQ(actual_stdout,expect_stdout);
	EXPECT_EQ(actual_return_value,expect_return_value);
}


//("%u",)
TEST(test_printf, 17)
{
	const char *expect_stdout;
	const char *actual_stdout;
	int expect_return_value;
	int actual_return_value;

	testing::internal::CaptureStdout();
	actual_return_value = ft_printf("aaa%u",127);
	actual_stdout = testing::internal::GetCapturedStdout().c_str();
	
	testing::internal::CaptureStdout();
	expect_return_value = printf("aaa%u",127);
	expect_stdout = testing::internal::GetCapturedStdout().c_str();

	EXPECT_STREQ(actual_stdout,expect_stdout);
	EXPECT_EQ(actual_return_value,expect_return_value);
}

//("%u",)
TEST(test_printf, 18)
{
	const char *expect_stdout;
	const char *actual_stdout;
	int expect_return_value;
	int actual_return_value;

	testing::internal::CaptureStdout();
	actual_return_value = ft_printf("aaa%u",0);
	actual_stdout = testing::internal::GetCapturedStdout().c_str();
	
	testing::internal::CaptureStdout();
	expect_return_value = printf("aaa%u",0);
	expect_stdout = testing::internal::GetCapturedStdout().c_str();

	EXPECT_STREQ(actual_stdout,expect_stdout);
	EXPECT_EQ(actual_return_value,expect_return_value);
}

//("%u",)
TEST(test_printf, 19)
{
	const char *expect_stdout;
	const char *actual_stdout;
	int expect_return_value;
	int actual_return_value;

	testing::internal::CaptureStdout();
	actual_return_value = ft_printf("aaa%u",9999);
	actual_stdout = testing::internal::GetCapturedStdout().c_str();
	
	testing::internal::CaptureStdout();
	expect_return_value = printf("aaa%u",9999);
	expect_stdout = testing::internal::GetCapturedStdout().c_str();

	EXPECT_STREQ(actual_stdout,expect_stdout);
	EXPECT_EQ(actual_return_value,expect_return_value);
}


//("%p",)
TEST(test_printf, 20)
{
	const char *expect_stdout;
	const char *actual_stdout;
	int expect_return_value;
	int actual_return_value;
	const char *str = "pointer";

	testing::internal::CaptureStdout();
	actual_return_value = ft_printf("aaa%p",str);
	actual_stdout = testing::internal::GetCapturedStdout().c_str();
	
	testing::internal::CaptureStdout();
	expect_return_value = printf("aaa%p",str);
	expect_stdout = testing::internal::GetCapturedStdout().c_str();

	EXPECT_STREQ(actual_stdout,expect_stdout);
	EXPECT_EQ(actual_return_value,expect_return_value);
}

//aaa%d INTMAX
TEST(test_printf, 21)
{
	const char *expect_stdout;
	const char *actual_stdout;
	int expect_return_value;
	int actual_return_value;

	testing::internal::CaptureStdout();
	actual_return_value = ft_printf("aaa%d", INT_MAX);
	actual_stdout = testing::internal::GetCapturedStdout().c_str();

	testing::internal::CaptureStdout();
	expect_return_value = printf("aaa%d", INT_MAX);
	expect_stdout = testing::internal::GetCapturedStdout().c_str();

	EXPECT_STREQ(actual_stdout,expect_stdout);
	EXPECT_EQ(actual_return_value,expect_return_value);
}


//aaa%d INTMAX + 1
TEST(test_printf, 22)
{
	const char *expect_stdout;
	const char *actual_stdout;
	int expect_return_value;
	int actual_return_value;

	testing::internal::CaptureStdout();
	actual_return_value = ft_printf("aaa%d", INT_MAX + 1);
	actual_stdout = testing::internal::GetCapturedStdout().c_str();

	testing::internal::CaptureStdout();
	expect_return_value = printf("aaa%d", INT_MAX + 1);
	expect_stdout = testing::internal::GetCapturedStdout().c_str();

	EXPECT_STREQ(actual_stdout,expect_stdout);
	EXPECT_EQ(actual_return_value,expect_return_value);
}

//aaa%d INTMAX + 1
TEST(test_printf, 23)
{
	const char *expect_stdout;
	const char *actual_stdout;
	int expect_return_value;
	int actual_return_value;

	testing::internal::CaptureStdout();
	actual_return_value = ft_printf("aaa%d", 2147483648);
	actual_stdout = testing::internal::GetCapturedStdout().c_str();

	testing::internal::CaptureStdout();
	expect_return_value = printf("aaa%d", 2147483648);
	expect_stdout = testing::internal::GetCapturedStdout().c_str();

	EXPECT_STREQ(actual_stdout,expect_stdout);
	EXPECT_EQ(actual_return_value,expect_return_value);
}



//"%"
TEST(test_printf, err_1)
{
	const char *expect_stdout;
	const char *actual_stdout;
	int expect_return_value;
	int actual_return_value;

	testing::internal::CaptureStdout();
	actual_return_value = ft_printf("%");
	actual_stdout = testing::internal::GetCapturedStdout().c_str();
	
	testing::internal::CaptureStdout();
	expect_return_value = printf("%");
	expect_stdout = testing::internal::GetCapturedStdout().c_str();

	EXPECT_STREQ(actual_stdout,expect_stdout);
	EXPECT_EQ(actual_return_value,expect_return_value);
}

// %d %d %d 5 5
TEST(test_printf, err_2)
{
	const char *expect_stdout;
	const char *actual_stdout;
	int expect_return_value;
	int actual_return_value;

	testing::internal::CaptureStdout();
	actual_return_value = ft_printf("%d %d %d", 5, 5);
	actual_stdout = testing::internal::GetCapturedStdout().c_str();
	
	testing::internal::CaptureStdout();
	expect_return_value = printf("%d %d %d", 5, 5);
	expect_stdout = testing::internal::GetCapturedStdout().c_str();

	EXPECT_EQ(actual_return_value < 0,expect_return_value < 0);
}


//NULL
TEST(test_printf, DISABLED_err_1)
{
	const char *expect_stdout;
	const char *actual_stdout;
	int expect_return_value;
	int actual_return_value;

	testing::internal::CaptureStdout();
	actual_return_value = ft_printf(NULL);
	actual_stdout = testing::internal::GetCapturedStdout().c_str();
	
	testing::internal::CaptureStdout();
	expect_return_value = printf(NULL);
	expect_stdout = testing::internal::GetCapturedStdout().c_str();

	EXPECT_STREQ(actual_stdout,expect_stdout);
	EXPECT_EQ(actual_return_value,expect_return_value);
}
