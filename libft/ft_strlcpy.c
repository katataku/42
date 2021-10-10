/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:03:47 by takkatao          #+#    #+#             */
/*   Updated: 2021/10/08 15:03:51 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		if (i == size - 1)
		{
			dest[size - 1] = '\0';
			break ;
		}
		if (src[i] == '\0')
		{
			dest[i] = '\0';
			break ;
		}
		else
			dest[i] = src[i];
		i++;
	}
	i = 0;
	while (src[i] != '\0')
		i++;
	return (i);
}
