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
TEST(test_printf, 4)
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
TEST(test_printf, 5)
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

//"aaa%s","bbb"
TEST(test_printf, 6)
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
TEST(test_printf, 7)
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


//"aaa%c",'a'
TEST(test_printf, 8)
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
