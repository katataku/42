/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:45:53 by takkatao          #+#    #+#             */
/*   Updated: 2021/10/07 20:44:37 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int ch, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *) buf;
	i = 0;
	while (i < n)
	{
		ptr[i] = ch;
		i++;
	}
	return (buf);
}
