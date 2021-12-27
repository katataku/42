/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:08:11 by takkatao          #+#    #+#             */
/*   Updated: 2021/12/27 17:13:54 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find(t_list *lst, int i)
{
	if (lst == NULL)
		return (0);
	if (ft_atoi(lst->content) == i)
		return (0);
	return (1 + find(lst->next, i));
}

int	get_min(t_list *lst)
{
	int	min;

	min = INT_MAX;
	while (lst != NULL)
	{
		if (min > ft_atoi(lst->content))
			min = ft_atoi(lst->content);
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
		if (max < ft_atoi(lst->content))
			max = ft_atoi(lst->content);
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
		if (cur > ft_atoi(lst->content))
			return (0);
		cur = ft_atoi(lst->content);
		lst = lst->next;
	}
	return (1);
}

int	get_avg(t_list **lst)
{
	t_list	*tar;
	int		sum;
	int		cnt;

	tar = *lst;
	sum = 0;
	cnt = 0;
	while (tar != NULL)
	{
		if (ft_atoi(tar->content) == get_min(*lst))
			break ;
		sum += ft_atoi(tar->content);
		tar = tar->next;
		cnt++;
	}
	return (sum / cnt);
}
