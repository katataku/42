/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:45:53 by takkatao          #+#    #+#             */
/*   Updated: 2021/11/01 10:27:53 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ans;
	size_t	malloc_size;

	malloc_size = count * size;
	if (malloc_size == 0)
		malloc_size = 1;
	if (count && size > SIZE_MAX / count)
		malloc_size = SIZE_MAX;
	ans = malloc(malloc_size);
	if (ans != NULL)
		ft_bzero(ans, malloc_size);
	return (ans);
}
