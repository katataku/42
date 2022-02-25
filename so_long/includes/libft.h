/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 22:04:59 by takkatao          #+#    #+#             */
/*   Updated: 2022/02/25 19:06:59 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

//My Bool
# include "stdlib.h"
# include "limits.h"
# include <unistd.h>
# include <stdbool.h>

void			ft_bzero(void *buf, size_t n);
void			*ft_calloc(size_t count, size_t size);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *str, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
size_t			ft_strlen(const char *s);



#endif
