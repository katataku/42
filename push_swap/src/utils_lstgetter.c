/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lstgetter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:08:11 by takkatao          #+#    #+#             */
/*   Updated: 2021/12/27 17:13:40 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	getter(t_list *lst, int i)
{
	if (i == 0)
	{
		return (ft_atoi(lst->content));
	}
	if (i > 0)
		return (getter(lst->next, i - 1));
	return (getter(lst, ft_lstsize(lst) + i));
}

int	get_top(t_list *lst)
{
	assert(lst != NULL);
	return (getter(lst, 0));
}

int	get_last(t_list *lst)
{
	return (getter(lst, -1));
}

int	get_sec(t_list *lst)
{
	return (getter(lst, 1));
}

int	get_third(t_list *lst)
{
	return (getter(lst, 2));
}
