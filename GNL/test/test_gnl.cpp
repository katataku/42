#include <gtest/gtest.h>
#include <gtest/internal/gtest-port.h>
#include <sys/types.h>
#include <unistd.h> 
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <assert.h> 
#include <fcntl.h>

extern "C" char *get_next_line(int fd);
extern "C" char *get_next_line_core(int fd,size_t buffer_size);

typedef struct s_behavior
{
	const char	*stdout;
	char	*return_value;
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


TEST(test_printf, standard_1_a)
{
	t_behavior actual;
	t_behavior expect;
	const char *path = "test/inputs/test_1_a";
	int fd = open(path,O_RDONLY);
	assert(fd != -1);
	expect.return_value = strdup("a");

	testing::internal::CaptureStdout();
	actual.return_value = get_next_line_core(fd,10);
	actual.stdout = testing::internal::GetCapturedStdout().c_str();

	EXPECT_STREQ(actual.return_value,expect.return_value);
}


TEST(test_printf, standard_1_b)
{
	t_behavior actual;
	t_behavior expect;
	const char *path = "test/inputs/test_1_b";
	int fd = open(path,O_RDONLY);
	assert(fd != -1);
	expect.return_value = strdup("b");

	testing::internal::CaptureStdout();
	actual.return_value = get_next_line(fd);
	actual.stdout = testing::internal::GetCapturedStdout().c_str();

	EXPECT_STREQ(actual.return_value,expect.return_value);
}


TEST(test_printf, standard_1_aaa_buf10)
{
	t_behavior actual;
	t_behavior expect;
	const char *path = "test/inputs/test_1_aaa";
	int fd = open(path,O_RDONLY);
	assert(fd != -1);
	expect.return_value = strdup("aaa");

	testing::internal::CaptureStdout();
	actual.return_value = get_next_line_core(fd,10);
	actual.stdout = testing::internal::GetCapturedStdout().c_str();

	EXPECT_STREQ(actual.return_value,expect.return_value);
}

TEST(test_printf, standard_1_aaa_buf1)
{
	t_behavior actual;
	t_behavior expect;
	const char *path = "test/inputs/test_1_aaa";
	int fd = open(path,O_RDONLY);
	assert(fd != -1);
	expect.return_value = strdup("aaa");

	testing::internal::CaptureStdout();
	actual.return_value = get_next_line_core(fd,1);
	actual.stdout = testing::internal::GetCapturedStdout().c_str();

	EXPECT_STREQ(actual.return_value,expect.return_value);
}


TEST(test_printf, standard_3_aaa_buf1024)
{
	t_behavior actual;
	t_behavior expect;
	const char *path = "test/inputs/test_3_aaa";
	int fd = open(path,O_RDONLY);
	assert(fd != -1);

	expect.return_value = strdup("a");
	testing::internal::CaptureStdout();
	actual.return_value = get_next_line_core(fd, 1024);
	actual.stdout = testing::internal::GetCapturedStdout().c_str();
	EXPECT_STREQ(actual.return_value,expect.return_value);

	expect.return_value = strdup("aa");
	testing::internal::CaptureStdout();
	actual.return_value = get_next_line_core(fd, 1024);
	actual.stdout = testing::internal::GetCapturedStdout().c_str();
	EXPECT_STREQ(actual.return_value,expect.return_value);

	expect.return_value = strdup("aaa");
	testing::internal::CaptureStdout();
	actual.return_value = get_next_line_core(fd, 1024);
	actual.stdout = testing::internal::GetCapturedStdout().c_str();
	EXPECT_STREQ(actual.return_value,expect.return_value);
}

TEST(test_printf, standard_3_aaa_buf1)
{
	t_behavior actual;
	t_behavior expect;
	const char *path = "test/inputs/test_3_aaa";
	int fd = open(path,O_RDONLY);
	assert(fd != -1);

	expect.return_value = strdup("a");
	testing::internal::CaptureStdout();
	actual.return_value = get_next_line_core(fd, 1);
	actual.stdout = testing::internal::GetCapturedStdout().c_str();
	EXPECT_STREQ(actual.return_value,expect.return_value);

	expect.return_value = strdup("aa");
	testing::internal::CaptureStdout();
	actual.return_value = get_next_line_core(fd, 1);
	actual.stdout = testing::internal::GetCapturedStdout().c_str();
	EXPECT_STREQ(actual.return_value,expect.return_value);

	expect.return_value = strdup("aaa");
	testing::internal::CaptureStdout();
	actual.return_value = get_next_line_core(fd, 1);
	actual.stdout = testing::internal::GetCapturedStdout().c_str();
	EXPECT_STREQ(actual.return_value,expect.return_value);
}


TEST(test_printf, standard_3_aaa_buf2)
{
	t_behavior actual;
	t_behavior expect;
	const char *path = "test/inputs/test_3_aaa";
	int fd = open(path,O_RDONLY);
	assert(fd != -1);

	expect.return_value = strdup("a");
	testing::internal::CaptureStdout();
	actual.return_value = get_next_line_core(fd, 2);
	actual.stdout = testing::internal::GetCapturedStdout().c_str();
	EXPECT_STREQ(actual.return_value,expect.return_value);

	expect.return_value = strdup("aa");
	testing::internal::CaptureStdout();
	actual.return_value = get_next_line_core(fd, 2);
	actual.stdout = testing::internal::GetCapturedStdout().c_str();
	EXPECT_STREQ(actual.return_value,expect.return_value);

	expect.return_value = strdup("aaa");
	testing::internal::CaptureStdout();
	actual.return_value = get_next_line_core(fd, 2);
	actual.stdout = testing::internal::GetCapturedStdout().c_str();
	EXPECT_STREQ(actual.return_value,expect.return_value);
}

TEST(test_printf, standard_3_aaa_buf3)
{
	t_behavior actual;
	t_behavior expect;
	int buffer_size = 3;
	const char *path = "test/inputs/test_3_aaa";
	int fd = open(path,O_RDONLY);
	assert(fd != -1);

	expect.return_value = strdup("a");
	actual.return_value = get_next_line_core(fd, buffer_size);
	EXPECT_STREQ(actual.return_value,expect.return_value);

	expect.return_value = strdup("aa");
	actual.return_value = get_next_line_core(fd, buffer_size);
	EXPECT_STREQ(actual.return_value,expect.return_value);

	expect.return_value = strdup("aaa");
	actual.return_value = get_next_line_core(fd, buffer_size);
	EXPECT_STREQ(actual.return_value,expect.return_value);
}

TEST(test_printf, standard_3_aaa_buf4)
{
	t_behavior actual;
	t_behavior expect;
	int buffer_size = 4;
	const char *path = "test/inputs/test_3_aaa";
	int fd = open(path,O_RDONLY);
	assert(fd != -1);

	expect.return_value = strdup("a");
	actual.return_value = get_next_line_core(fd, buffer_size);
	EXPECT_STREQ(actual.return_value,expect.return_value);

	expect.return_value = strdup("aa");
	actual.return_value = get_next_line_core(fd, buffer_size);
	EXPECT_STREQ(actual.return_value,expect.return_value);

	expect.return_value = strdup("aaa");
	actual.return_value = get_next_line_core(fd, buffer_size);
	EXPECT_STREQ(actual.return_value,expect.return_value);
}

TEST(test_printf, standard_3_aaa_buf5)
{
	t_behavior actual;
	t_behavior expect;
	int buffer_size = 5;
	const char *path = "test/inputs/test_3_aaa";
	int fd = open(path,O_RDONLY);
	assert(fd != -1);

	expect.return_value = strdup("a");
	actual.return_value = get_next_line_core(fd, buffer_size);
	EXPECT_STREQ(actual.return_value,expect.return_value);

	expect.return_value = strdup("aa");
	actual.return_value = get_next_line_core(fd, buffer_size);
	EXPECT_STREQ(actual.return_value,expect.return_value);

	expect.return_value = strdup("aaa");
	actual.return_value = get_next_line_core(fd, buffer_size);
	EXPECT_STREQ(actual.return_value,expect.return_value);
}



TEST(test_printf, standard_3_aaa_withnl_buf1024)
{
	t_behavior actual;
	t_behavior expect;
	int buffer_size = 1024;
	const char *path = "test/inputs/test_3_aaa_withnl";
	int fd = open(path,O_RDONLY);
	assert(fd != -1);

	expect.return_value = strdup("a");
	actual.return_value = get_next_line_core(fd, buffer_size);
	EXPECT_STREQ(actual.return_value,expect.return_value);

	expect.return_value = strdup("");
	actual.return_value = get_next_line_core(fd, buffer_size);
	EXPECT_STREQ(actual.return_value,expect.return_value);


	expect.return_value = strdup("aa");
	actual.return_value = get_next_line_core(fd, buffer_size);
	EXPECT_STREQ(actual.return_value,expect.return_value);

	expect.return_value = strdup("");
	actual.return_value = get_next_line_core(fd, buffer_size);
	EXPECT_STREQ(actual.return_value,expect.return_value);

	expect.return_value = strdup("");
	actual.return_value = get_next_line_core(fd, buffer_size);
	EXPECT_STREQ(actual.return_value,expect.return_value);

	expect.return_value = strdup("aaa");
	actual.return_value = get_next_line_core(fd, buffer_size);
	EXPECT_STREQ(actual.return_value,expect.return_value);

	expect.return_value = strdup("");
	actual.return_value = get_next_line_core(fd, buffer_size);
	EXPECT_STREQ(actual.return_value,expect.return_value);
}



TEST(test_printf, standard_3_aaa_withnl_buf1)
{
	t_behavior actual;
	t_behavior expect;
	int buffer_size = 1;
	const char *path = "test/inputs/test_3_aaa_withnl";
	int fd = open(path,O_RDONLY);
	assert(fd != -1);

	expect.return_value = strdup("a");
	actual.return_value = get_next_line_core(fd, buffer_size);
	EXPECT_STREQ(actual.return_value,expect.return_value);

	expect.return_value = strdup("");
	actual.return_value = get_next_line_core(fd, buffer_size);
	EXPECT_STREQ(actual.return_value,expect.return_value);


	expect.return_value = strdup("aa");
	actual.return_value = get_next_line_core(fd, buffer_size);
	EXPECT_STREQ(actual.return_value,expect.return_value);

	expect.return_value = strdup("");
	actual.return_value = get_next_line_core(fd, buffer_size);
	EXPECT_STREQ(actual.return_value,expect.return_value);

	expect.return_value = strdup("");
	actual.return_value = get_next_line_core(fd, buffer_size);
	EXPECT_STREQ(actual.return_value,expect.return_value);

	expect.return_value = strdup("aaa");
	actual.return_value = get_next_line_core(fd, buffer_size);
	EXPECT_STREQ(actual.return_value,expect.return_value);

	expect.return_value = strdup("");
	actual.return_value = get_next_line_core(fd, buffer_size);
	EXPECT_STREQ(actual.return_value,expect.return_value);

	expect.return_value = NULL;
	actual.return_value = get_next_line_core(fd, buffer_size);
	EXPECT_EQ(actual.return_value,expect.return_value);
}


TEST(test_printf, standard_3_aaa_withnl_buf2)
{
	t_behavior actual;
	t_behavior expect;
	int buffer_size = 2;
	const char *path = "test/inputs/test_3_aaa_withnl";
	int fd = open(path,O_RDONLY);
	assert(fd != -1);

	expect.return_value = strdup("a");
	actual.return_value = get_next_line_core(fd, buffer_size);
	EXPECT_STREQ(actual.return_value,expect.return_value);

	expect.return_value = strdup("");
	actual.return_value = get_next_line_core(fd, buffer_size);
	EXPECT_STREQ(actual.return_value,expect.return_value);


	expect.return_value = strdup("aa");
	actual.return_value = get_next_line_core(fd, buffer_size);
	EXPECT_STREQ(actual.return_value,expect.return_value);

	expect.return_value = strdup("");
	actual.return_value = get_next_line_core(fd, buffer_size);
	EXPECT_STREQ(actual.return_value,expect.return_value);

	expect.return_value = strdup("");
	actual.return_value = get_next_line_core(fd, buffer_size);
	EXPECT_STREQ(actual.return_value,expect.return_value);

	expect.return_value = strdup("aaa");
	actual.return_value = get_next_line_core(fd, buffer_size);
	EXPECT_STREQ(actual.return_value,expect.return_value);

	expect.return_value = strdup("");
	actual.return_value = get_next_line_core(fd, buffer_size);
	EXPECT_STREQ(actual.return_value,expect.return_value);
}


TEST(test_printf, standard_3_aaa_withnl_buf4)
{
	t_behavior actual;
	t_behavior expect;
	int buffer_size = 4;
	const char *path = "test/inputs/test_3_aaa_withnl";
	int fd = open(path,O_RDONLY);
	assert(fd != -1);

	expect.return_value = strdup("a");
	actual.return_value = get_next_line_core(fd, buffer_size);
	EXPECT_STREQ(actual.return_value,expect.return_value);

	expect.return_value = strdup("");
	actual.return_value = get_next_line_core(fd, buffer_size);
	EXPECT_STREQ(actual.return_value,expect.return_value);


	expect.return_value = strdup("aa");
	actual.return_value = get_next_line_core(fd, buffer_size);
	EXPECT_STREQ(actual.return_value,expect.return_value);

	expect.return_value = strdup("");
	actual.return_value = get_next_line_core(fd, buffer_size);
	EXPECT_STREQ(actual.return_value,expect.return_value);

	expect.return_value = strdup("");
	actual.return_value = get_next_line_core(fd, buffer_size);
	EXPECT_STREQ(actual.return_value,expect.return_value);

	expect.return_value = strdup("aaa");
	actual.return_value = get_next_line_core(fd, buffer_size);
	EXPECT_STREQ(actual.return_value,expect.return_value);

	expect.return_value = strdup("");
	actual.return_value = get_next_line_core(fd, buffer_size);
	EXPECT_STREQ(actual.return_value,expect.return_value);
}

TEST(test_printf, standard_3_aaa_withnl_buf5)
{
	t_behavior actual;
	t_behavior expect;
	int buffer_size = 5;
	const char *path = "test/inputs/test_3_aaa_withnl";
	int fd = open(path,O_RDONLY);
	assert(fd != -1);

	expect.return_value = strdup("a");
	actual.return_value = get_next_line_core(fd, buffer_size);
	EXPECT_STREQ(actual.return_value,expect.return_value);

	expect.return_value = strdup("");
	actual.return_value = get_next_line_core(fd, buffer_size);
	EXPECT_STREQ(actual.return_value,expect.return_value);


	expect.return_value = strdup("aa");
	actual.return_value = get_next_line_core(fd, buffer_size);
	EXPECT_STREQ(actual.return_value,expect.return_value);

	expect.return_value = strdup("");
	actual.return_value = get_next_line_core(fd, buffer_size);
	EXPECT_STREQ(actual.return_value,expect.return_value);

	expect.return_value = strdup("");
	actual.return_value = get_next_line_core(fd, buffer_size);
	EXPECT_STREQ(actual.return_value,expect.return_value);

	expect.return_value = strdup("aaa");
	actual.return_value = get_next_line_core(fd, buffer_size);
	EXPECT_STREQ(actual.return_value,expect.return_value);

	expect.return_value = strdup("");
	actual.return_value = get_next_line_core(fd, buffer_size);
	EXPECT_STREQ(actual.return_value,expect.return_value);
}