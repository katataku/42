/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:08:11 by takkatao          #+#    #+#             */
/*   Updated: 2021/11/23 09:58:46 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<assert.h>
#include<string.h>
# include <unistd.h>
# include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "libft.h"




char	*get_next_line_core(int fd, size_t buffer_size)
{
	static char *buffer;
	static char *ans;
	ssize_t	rc;
	char	*next_n_ptr;
	char	*tmp;
	size_t	next_n_index;

	rc = 1;
	while (true)
	{
		if (buffer == NULL)
		{
			buffer = (char *)malloc(buffer_size + 1);
			if (buffer == NULL)
				return (NULL);
			rc = read(fd, buffer, buffer_size);
			if (rc < 0)
				return (NULL);
			if (rc == 0)
				break ;
			buffer[buffer_size] = '\0';
			next_n_index = 0;
		}
		if (ans == NULL)
			ans = "";
		tmp = ft_strjoin(ans, &buffer[next_n_index]);
		free(ans);
		ans = tmp;
		if (strchr(buffer, '\n'))
		{
			next_n_ptr = strchr(buffer, '\n') + 1;//次のためにbufferを整理
			next_n_index = next_n_ptr - buffer;
			next_n_ptr = strchr(ans, '\n') + 1;//今回のためにansを整理
			*next_n_ptr = '\0';//今回のためにansを整理
			break ;
		}
		free (buffer);
		buffer = NULL;
	}
	return (ans);
}

char	*get_next_line(int fd)
{
	return (get_next_line_core(fd, BUFFER_SIZE));
}

int	main(void)
{
	int	fd;



	write(1,"1",1);
	fd = open("../test/inputs/test_1_a", O_RDONLY);
	assert(strcmp(get_next_line(fd), "a") == 0);

	write(1,"2",1);
	fd = open("../test/inputs/test_1_b", O_RDONLY);
	assert(strcmp(get_next_line(fd), "b") == 0);

	write(1,"3",1);
	fd = open("../test/inputs/test_1_aa", O_RDONLY);
	assert(strcmp(get_next_line(fd), "aa") == 0);

	write(1,"4",1);
	fd = open("../test/inputs/test_1_aa", O_RDONLY);
	assert(strcmp(get_next_line_core(fd, 1), "aa") == 0);

	write(1,"5",1);
	fd = open("../test/inputs/test_3_a", O_RDONLY);
	assert(strcmp(get_next_line_core(fd, 1), "a\n") == 0);
	assert(strcmp(get_next_line_core(fd, 1), "b\n") == 0);
	assert(strcmp(get_next_line_core(fd, 1), "c\n") == 0);

	write(1,"6",1);
	fd = open("../test/inputs/test_3_aaa", O_RDONLY);
	assert(strcmp(get_next_line_core(fd, 5), "aaa\n") == 0);
	assert(strcmp(get_next_line_core(fd, 5), "b\n") == 0);
	assert(strcmp(get_next_line_core(fd, 5), "c\n") == 0);

	// write(1,"7",1);
	// fd = open("../test/inputs/test_empty", O_RDONLY);
//	assert(get_next_line_core(fd, 5) == NULL);

	printf("\nAll Green\n");

/*
	todo:
		[ ] INTMAX 以上来た時にbuffersize +1だとオーバーフローする.size_tにcast
		[ ] リーク

*/

	return (0);
	// int	main(void)
// {
// 	int	index;//読み込み回数を確認する用
// 	//static int i;
// 	int	fd = open("test.txt", O_RDONLY);
// 	printf("fd = %d\n", fd);

// 	char	*receiver = NULL;
// 	index = 0;
// 	//printf("static=%d\n", i);//staticの初期値を調べている。デフォルトがある。
// 	while (1){
// 		receiver = get_next_line(fd);
// 		if (!receiver){
// 			printf("EOF or ERROR\n");
// 			break ;
// 		}
// 		printf("[%d]%s", index, receiver);
// 		index ++;
// 		free(receiver);
// 	}
// 	system("leaks a.out");
// 	close(fd);
// }
}
