/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 22:04:59 by takkatao          #+#    #+#             */
/*   Updated: 2021/11/21 21:39:51 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include<stdlib.h>
# include<string.h>
# include<stdarg.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_gnl_status
{
	size_t				index;
	ssize_t				read_ret;
	char				*buffer;
	size_t				line_len;
	bool				is_eof;
	

	int					ret_len;
	char				*va_char_ptr;
	int					va_char;
	unsigned int		va_uint;
	int					va_int;
	unsigned long long	va_ull;
	long long			va_long_long;
	void				*va_void_ptr;
	va_list				ap;
	bool				is_loop_continue;

}	t_gnl_status;

char	*get_next_line(int fd);
#endif
