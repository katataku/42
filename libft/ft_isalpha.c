/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 17:22:42 by takkatao          #+#    #+#             */
/*   Updated: 2021/10/07 17:27:50 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
int	ft_isalpha(int c)
{
	int	ans;

	ans = TRUE;
	if (c >= 'A' && c <= 'Z')
	{
	}
	else if (c >= 'a' && c <= 'z')
	{
	}
	else
	{
		ans = FALSE;
	}
	return (ans);
}
