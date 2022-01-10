/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:08:11 by takkatao          #+#    #+#             */
/*   Updated: 2022/01/10 18:40:56 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find(t_list *lst, int i)
{
	if (lst == NULL)
		return (0);
	if (*(int *)(lst->content) == i)
		return (0);
	return (1 + find(lst->next, i));
}

int	get_min(t_list *lst)
{
	int	min;

	min = INT_MAX;
	while (lst != NULL)
	{
		if (min > *(int *)(lst->content))
			min = *(int *)(lst->content);
		lst = lst->next;
	}
	return (min);
}

int	get_max(t_list *lst)
{
	int	max;

	max = INT_MIN;
	while (lst != NULL)
	{
		if (max < *(int *)(lst->content))
			max = *(int *)(lst->content);
		lst = lst->next;
	}
	return (max);
}

int	is_sorted(t_list *lst)
{
	int	cur;

	cur = INT_MIN;
	while (lst != NULL)
	{
		if (cur > *(int *)(lst->content))
			return (0);
		cur = *(int *)(lst->content);
		lst = lst->next;
	}
	return (1);
}
